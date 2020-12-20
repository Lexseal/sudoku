#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

#define DEFAULT_SIZE 9

class SudokuBoard
{
private:
    int cellGroup;
    int size;
    vector<vector<int>> board;
    vector<vector<bool>> rowVecs;
    vector<vector<bool>> colVecs;
    vector<vector<bool>> cellVecs;
    void readFromTxt(string fileName);
    void readFromImg(string fileName);
public:
    SudokuBoard(); // default size
    SudokuBoard(int size);
    SudokuBoard(string fileName);
    ~SudokuBoard() = default;

    int get(int row, int col) const;
    const vector<int>& getRow(int row) const;
    const vector<int> getCol(int col) const;
    const vector<int> getCell(int cell) const;
    int getCellNum(int row, int col) const;
    const vector<int> getCell(int row, int col) const;
    bool place(int row, int col, int value);
    bool place(int linearIdx, int value);
    bool occupied(int row, int col);
    bool occupied(int linearIdx);
    void erase(int row, int col);
    void erase(int linearIdx);
    const vector<vector<int>>& getBoard() const;
    int getSize() const;
    int getCellWidth() const;

    friend ostream & operator << (ostream & _stream, SudokuBoard const &board); // printing
};

#endif