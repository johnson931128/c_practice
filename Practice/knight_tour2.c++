#include <iostream>
#include <iomanip> // for setw()
#include <vector>
#include <algorithm> // for sort()
using namespace std;

int board[8][8] = {0};

// 騎士可移動的八個方向
int ktmove1[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int ktmove2[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// 檢查是否為有效移動位置
bool isValidMove(int x, int y)
{
    return (x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] == 0);
}

// 計算騎士從當前位置 (x, y) 可以移動的有效格子數量，用於Warnsdorff's Rule
int countValidMoves(int x, int y)
{
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + ktmove1[i];
        int ny = y + ktmove2[i];
        if (isValidMove(nx, ny))
        {
            count++;
        }
    }
    return count;
}

// 根據Warnsdorff's Rule進行騎士巡邏
bool knightmove(int x, int y, int movement)
{
    board[x][y] = movement; // 標記當前步數
    if (movement == 64)
    {
        return true; // 如果完成64步則成功
    }

    // 儲存騎士所有可能的下一步選擇
    vector<pair<int, pair<int, int>>> nextMoves;
    // how many path        // nx, ny
    for (int i = 0; i < 8; i++)
    {
        int nx = x + ktmove1[i];
        int ny = y + ktmove2[i];
        if (isValidMove(nx, ny))
        {
            nextMoves.push_back({countValidMoves(nx, ny), {nx, ny}});
            // creating a pair which is like pair(int, {nx, ny});
            //                                    *path, *next_posotion
        }
    }

    // 根據Warnsdorff's Rule排序，優先選擇有效步數少的格子
    sort(nextMoves.begin(), nextMoves.end());

    // 遍歷排序後的可能步數
    for (auto &move : nextMoves)
    // move = pair(int, {nx, ny})
    //             first \ second(first, second)
    {
        int nx = move.second.first;
        int ny = move.second.second;
        if (knightmove(nx, ny, movement + 1))
        {
            return true;
        }
    }

    // 回溯，將格子重新標記為0 "重要!!!!!!"
    board[x][y] = 0;
    return false;
}

int main()
{
    int startx, starty;
    cout << "輸入起始點：";
    cin >> startx >> starty;

    if (knightmove(startx, starty, 1))
    {
        cout << "遊歷完成！" << endl;
    }
    else
    {
        cout << "遊歷失敗！" << endl;
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << setw(3) << board[i][j] << " "; // setw()可以控制間距!
        }
        cout << endl; // '\n'考試應該用換行
    }

    return 0;
}
