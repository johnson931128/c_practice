#include <iostream>
#include <vector>
using namespace std;

const int N = 8;

bool isSafe(vector<int> &board, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i] == col)
            return false;
        if (abs(board[i] - col) == abs(i - row))
            return false;
        // row - row = col - col
    }
    return true;
}

bool solveNQueens(vector<int> &board, int row)
{
    if (row == N)
        return true;

    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row] = col;
            if (solveNQueens(board, row + 1))
                return true;
            board[row] = -1; // false
        }
    }
    return false;
}

void printBoard(const vector<int> &board)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i] == j)
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main()
{
    int startCol;
    cin >> startCol;

    vector<int> board(N, -1);
    board[0] = startCol;

    if (solveNQueens(board, 1))
    {
        printBoard(board);
    }
    else
    {
        cout << "No solution found" << endl;
    }

    return 0;
}