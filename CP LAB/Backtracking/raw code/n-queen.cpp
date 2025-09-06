#include <bits/stdc++.h>
using namespace std;

// Function to check if placing a queen at (row, col) is safe
bool isSafe(vector<int>& board, int row, int col) {
    for (int r = 0; r < row; r++) {
        int c = board[r];
        if (c == col || abs(c - col) == abs(r - row))
            return false;
    }
    return true;
}

// Backtracking function to place queens row by row
void solveNQueens(vector<int>& board, int row, int n) {
    if (row == n) {
        // Print current solution as column positions
        cout << "[ ";
        for (int i = 0; i < n; i++) {
            cout << board[i] +1  << " ";
        }
        cout << "]" << endl;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;          // Place queen
            solveNQueens(board, row + 1, n); // Recurse to next row
            board[row] = -1;           // Backtrack
        }
    }
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    vector<int> board(n, -1); // board[i] = column of queen in row i
    solveNQueens(board, 0, n);

    return 0;
}
/* Sample Input/Output:
Enter N: 4
[ 2 4 1 3 ]
[ 3 1 4 2 ]
*/