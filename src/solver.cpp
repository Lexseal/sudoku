#include <stack>
#include "solver.hpp"

Solver::Solver(SudokuBoard board) : board(board) {
    solved = false; // not solved
    size = board.getSize();
}

const SudokuBoard& Solver::getBoard() const {
    return board;
}

bool Solver::solve(int linearIdx) {
    if (linearIdx >= size*size) return true; // solved
    
    if (board.occupied(linearIdx)) { // if occupied already
        return solve(linearIdx+1); // skip it!
    }

    // now this cell is blank
    for (int num = 1; num <= size; num++) { // try all different numbers
        if (board.place(linearIdx, num) == false) continue; // if fail to place
        
        //cout << board << endl; // print trace

        // has placement
        if (solve(linearIdx+1)) return true; // found solution!
        board.erase(linearIdx); // otherwise, erase the entry and try again
    }
    return false; // no solution
}

bool Solver::solve() {
    solved = solve(0);
    return solved;

    // vector<int> emptyEntries;
    // for (int i = 0; i < size*size; i++) {
    //     if (board.occupied(i)) continue;
    //     emptyEntries.push_back(i);
    // }

    // int emptyIdx = 0;
    // while (emptyIdx < emptyEntries.size()) {
    //     int linearIdx = emptyEntries[emptyIdx];

    //     int startNum = 1;
    //     if (board.occupied(linearIdx)) { // fallen from the last one
    //         startNum = board.get(linearIdx)+1;
    //         board.erase(linearIdx);
    //     }

    //     bool canPlace = false;
    //     for (int i = startNum; i <= size; i++) {
    //         if (board.place(linearIdx, i)) {
    //             canPlace = true;
    //             break;
    //         }
    //     }
    //     //cout << board << endl;
        
    //     if (canPlace) emptyIdx++; // go to the next one
    //     else emptyIdx--; // go to the prev one
    // }

    // return true; // filled in all the empty entries
}

bool Solver::isSolved() const {
    return solved;
}
