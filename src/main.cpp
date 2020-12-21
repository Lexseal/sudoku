#include <chrono>
#include "solver.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        cerr << "please input a file name" << endl;
        return 1;
    }
    
    auto start = chrono::high_resolution_clock::now();
    for (int i = 1; i < 1000; i++) {
        //cout << "number " << i << endl;
        SudokuBoard board(argv[1]);
        //cout << board << endl;
        Solver solver(board);
        solver.solve();
        //cout << solver.getBoard() << endl;
        //cout << endl;
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end-start);
    cout << duration.count()/1000.0 << 's' << endl;

    return 0;
}
