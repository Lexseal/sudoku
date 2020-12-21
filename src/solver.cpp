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
        return solve(linearIdx+1);
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
    // solved = solve(0);
    // return solved;

    int linearIdx = 0;
    while (linearIdx < size*size && board.occupied(linearIdx)) linearIdx++;
    if (linearIdx == size*size) return true; // trivially solved

    stack<pair<int, int>> computeStack;
    stack<int> traceStack;
    for (int num = 1; num <= size; num++) {
        if (board.place(linearIdx, num)) { // if can place
            computeStack.push({linearIdx, num});
            board.erase(linearIdx);
        }
    }

    while (!computeStack.empty()) {
        auto item = computeStack.top(); computeStack.pop();
        linearIdx = item.first;
        int num = item.second;

        if (linearIdx == 0 && num == 2) {
            cout << "here" << endl;
        }

        while (!traceStack.empty() && traceStack.top() > linearIdx) {
            board.erase(traceStack.top());
            traceStack.pop();
        }
        board.erase(linearIdx); // erase first
        board.place(linearIdx, num); // we know it is legal
        //cout << board << endl;
        
        int nextIdx = linearIdx+1;
        while (nextIdx < size*size && board.occupied(nextIdx)) nextIdx++;
        if (nextIdx == size*size) return true; // if all occupied

        bool canPlaceNext = false;
        for (int i = 1; i <= size; i++) {
            if (board.place(nextIdx, i)) {
                computeStack.push({nextIdx, i});
                board.erase(nextIdx);
                canPlaceNext = true;
            }
        }
        
        if (!canPlaceNext) board.erase(linearIdx);
        else traceStack.push(linearIdx); // write it into trace
    }

    return false; // exhauseted the stack. no solution found
}

bool Solver::isSolved() const {
    return solved;
}
