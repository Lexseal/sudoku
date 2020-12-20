#include <fstream>
#include <algorithm>
#include "sudokuBoard.hpp"
#include "imgToNum.hpp"

SudokuBoard::SudokuBoard(int size) {
    this->size = size;
    cellGroup = (sqrt(size)+0.5);
    board.resize(size, vector<int>(size));
    rowVecs.resize(size, vector<bool>(size));
    colVecs.resize(size, vector<bool>(size));
    cellVecs.resize(size, vector<bool>(size));
}

SudokuBoard::SudokuBoard() : SudokuBoard(DEFAULT_SIZE) {}

void SudokuBoard::readFromTxt(string fileName) {
    ifstream file;
    file.open(fileName);
    string line;
    int i = 0;
    while (getline(file, line)) {
        for (char c : line) {
            bool success = true;
            if (c == '.') i++;
            else if (isdigit(c)) {
                success = place(i/size, i%size, int(c)-'0');
                i++;
            }
            if (!success) {
                cerr << "corrupted file" << endl;
                exit(1);
            }
        }
    }
}

void SudokuBoard::readFromImg(string fileName) {
    ImgToNum scanner(fileName, size);
    board = scanner.scan();
}

SudokuBoard::SudokuBoard(string fileName) : SudokuBoard(DEFAULT_SIZE) {
    if (fileName.substr(fileName.find_last_of('.')) == ".txt") {
        readFromTxt(fileName);
    } else {
        readFromImg(fileName);
    }
}

int SudokuBoard::get(int row, int col) const {
    return board[row][col];
}

const vector<int>& SudokuBoard::getRow(int row) const {
    return board[row];
}

const vector<int> SudokuBoard::getCol(int col) const {
    vector<int> colVec(size);
    for (int r = 0; r < size; r++) 
        colVec[r] = board[r][col];
    return colVec;
}

const vector<int> SudokuBoard::getCell(int cell) const {
    vector<int> cellVec;
    int row = cell/cellGroup * cellGroup;
    int col = cell%cellGroup * cellGroup;
    for (int r = row; r < row+cellGroup; r++)
        for (int c = col; c < col+cellGroup; c++)
            cellVec.push_back(get(r, c));
    return cellVec;
}

int SudokuBoard::getCellNum(int row, int col) const {
    return row/cellGroup*cellGroup + col/cellGroup;
}

const vector<int> SudokuBoard::getCell(int row, int col) const {
    return getCell(getCellNum(row, col));
}

bool SudokuBoard::place(int row, int col, int value) {
    if (rowVecs[row][value-1] == true) return false; // verify row
    if (colVecs[col][value-1] == true) return false; // verify col
    if (cellVecs[getCellNum(row, col)][value-1] == true) return false; // verify cell

    rowVecs[row][value-1] = true;
    colVecs[col][value-1] = true;
    cellVecs[getCellNum(row, col)][value-1] = true;

    board[row][col] = value; // set the value

    return true; // and return true
}

bool SudokuBoard::place(int linearIdx, int value) {
    return place(linearIdx/size, linearIdx%size, value);
}

bool SudokuBoard::occupied(int row, int col) {
    return board[row][col] != 0;
}

bool SudokuBoard::occupied(int linearIdx) {
    return occupied(linearIdx/size, linearIdx%size);
}

void SudokuBoard::erase(int row, int col) {
    int value = board[row][col];
    if (value == 0) return; // nothing to do
    
    board[row][col] = 0; // erase
    rowVecs[row][value-1] = false;
    colVecs[col][value-1] = false;
    cellVecs[getCellNum(row, col)][value-1] = false;
}

void SudokuBoard::erase(int linearIdx) {
    erase(linearIdx/size, linearIdx%size);
}

const vector<vector<int>>& SudokuBoard::getBoard() const {
    return board;
}

int SudokuBoard::getSize() const {
    return size;
}

int SudokuBoard::getCellWidth() const {
    return cellGroup;
}

ostream & operator << (ostream & _stream, SudokuBoard const &board) {
        int size = board.getSize();
        int cellWidth = board.getCellWidth();
        for (int r = 0; r < size; r++) {
            for (int c = 0; c < size; c++) {
                int num = board.get(r, c);
                if (num == 0) _stream << '.';
                else _stream << num; // normal printing
                if (c != size-1) _stream << ' '; // print space

                if ((c+1) % cellWidth == 0 && (c+1) < size) {
                    _stream << "| "; // print barrier every cell
                }
            }
            _stream << '\n';

            if ((r+1)%cellWidth == 0 && (r+1) < size) {
                for (int c = 0; c < size; c++) {
                    _stream << '-';
                    if (c != size-1) _stream << '-';
                    if ((c+1) % cellWidth == 0  && (c+1) < size) {
                        _stream << "|-";
                    }
                }
                _stream << '\n';
            }
        }
        return _stream;
    }
