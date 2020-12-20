#include <string>
#include <vector>
#include <opencv4/opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class ImgToNum {
private:
    int size;
    Mat color_img;
    vector<vector<int>> numberGrid;

    Mat makeBinary(Mat img);
    vector<Point> getMaxContour(Mat bin);
    bool isNumber(string str);
public:
    ImgToNum(string fileName, int size);
    ~ImgToNum() = default;

    const vector<vector<int>>& scan();
};
