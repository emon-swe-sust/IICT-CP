#include <bits/stdc++.h>
using namespace std;

int ld[30] = { 0 };
int rd[30] = { 0 };
int cl[30] = { 0 };

void printSolution(vector<vector<int>>& board) {
    int n = board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << " " << (board[i][j] == 1 ? "Q" : ".") << " ";
        cout << endl;
    }
}

bool solveNQUtil(vector<vector<int>>& board, int col) {
    int n = board.size();
    if (col >= n)
        return true;
    for (int i = 0; i < n; i++) {
        if ((ld[i - col + n - 1] != 1 && rd[i + col] != 1)
            && cl[i] != 1) {

            board[i][col] = 1;
            ld[i - col + n - 1] = rd[i + col] = cl[i] = 1;

            if (solveNQUtil(board, col + 1))
                return true;

            board[i][col] = 0; 
            ld[i - col + n - 1] = rd[i + col] = cl[i] = 0;
        }
    }
    return false;
}

bool solveNQ(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solveNQUtil(board, 0) == false) {
        cout << "Solution does not exist";
        return false;
    }

    printSolution(board);
    return true;
}

int main() {
    int n = 4;
    solveNQ(n);
    return 0;
}
