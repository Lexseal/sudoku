#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <string>
#include "sudokuBoard.hpp"

using namespace std;

class Solver {
private:
    int size;
    bool solved;
    SudokuBoard board;

    bool solve(int linearIdx);
public:
    Solver(SudokuBoard board);
    ~Solver() = default;

    const SudokuBoard& getBoard() const; // read only copy
    bool solve();
    bool isSolved() const;
};

#endif