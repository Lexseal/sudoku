#include <tesseract/baseapi.h>
#include "imgToNum.hpp"

ImgToNum::ImgToNum(string fileName, int size) {
    color_img = imread(fileName, IMREAD_COLOR);
    if(color_img.empty()) {
        cerr << "Could not read the image: " << fileName << endl;
        exit(1);
    }

    this->size = size;
    numberGrid.resize(size, vector<int>(size));
}

Mat ImgToNum::makeBinary(Mat img) {
    Mat bin;
    cvtColor(img, bin, COLOR_BGR2GRAY); // convert color
    GaussianBlur(bin, bin, Size(5, 5), 0, 0); // blur

    adaptiveThreshold(bin, bin, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 3, 2); // make binary
    bin = ~bin; // invert color
    return bin;
}

vector<Point> ImgToNum::getMaxContour(Mat bin) {
    vector<vector<Point>> contours; // to store the contours
    findContours(bin, contours, RETR_TREE, CHAIN_APPROX_SIMPLE); // find it

    double maxArea = 0;
    vector<Point> maxContour;
    for (auto contour : contours) {
        double area = contourArea(contour);
        if (area > maxArea) {
            maxArea = area;
            maxContour = contour;
        }
    } // now we have the best contour
    approxPolyDP(maxContour, maxContour, 3, true); // force rectangle

    return maxContour;
}

bool ImgToNum::isNumber(string str) {
    bool hasDigits = false;
    for (char c : str) {
        if (c == ' ' || c == '\n') continue;
        else if (isdigit(c)) hasDigits = true;
        else return false; // has non digits
    }
    return hasDigits; // checked everything so is digit
}

const vector<vector<int>>& ImgToNum::scan() {
    Mat bin = makeBinary(color_img);
    Rect rect = boundingRect(getMaxContour(bin));
    Mat cropped = color_img(rect);

    // imshow("cropped", cropped);

    tesseract::TessBaseAPI ocr;
    ocr.Init(NULL, "eng", tesseract::OEM_LSTM_ONLY);
    ocr.SetVariable("user_defined_dpi", "70"); // to suppress the warning

    int cellWidth = (double(cropped.cols)/double(size)+0.5);
    int widthMargin = double(cropped.cols)/double(size)*0.18+0.5;
    int cellHeight = (double(cropped.rows)/double(size)+0.5);
    int heightMargin = double(cropped.rows)/double(size)*0.18+0.5;
    // cout << "img width: " << cropped.cols << " img height: " << cropped.rows << endl;
    // cout << "cell width: " << cellWidth << " cell height: " << cellHeight << endl;
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            // cout << "x: " << c*cellWidth + widthMargin << " y: " << r*cellHeight + widthMargin << endl;
            Rect cellRect(c*cellWidth + widthMargin, r*cellHeight + heightMargin, 
                          cellWidth - 2*widthMargin, cellHeight - 2*heightMargin); // x, y, width, height
            Mat cell = cropped(cellRect); // a cell of the binary image
            //imshow(""+r*c, cell);

            ocr.SetImage(cell.data, cell.cols, cell.rows, 3, cell.step); // 3 byte per pixel
            string result = string(ocr.GetUTF8Text()); // get result
            if (isNumber(result)) {
                // cout << result << " " << stoi(result) << endl;
                numberGrid[r][c] = stoi(result); // write it in if it is a number
            }
        }
    }
    //waitKey(0);

    // for (auto row : numberGrid) {
    //     for (int num : row) {
    //         cout << num << " ";
    //     }
    //     cout << endl;
    // }
    return numberGrid;
}
