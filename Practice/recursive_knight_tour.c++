#include <iostream>
#include <iomanip>
using namespace std;

int borad[8][8] = {0};
// 騎士可走的八個方向
int ktmove1[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int ktmove2[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValidMove(int x, int y)
{
    return (x >= 0 && x < 8 && y >= 0 && y < 8 && borad[x][y] == 0);
}

bool knightmove(int x, int y, int movement)
{
    borad[x][y] = movement;
    if (movement == 64)
    {
        return true;
    }

    // try 8's direction
    for (int i = 0; i < 8; i++)
    {
        int nextx = x + ktmove1[i];
        int nexty = y + ktmove2[i];
        if (isValidMove(nextx, nexty))
        {
            if (knightmove(nextx, nexty, movement + 1))
            {
                return true;
            }
        }
    }
    borad[x][y] = 0;
    return false;
}

int main()
{
    int startx, starty;
    cout << "輸入起始點：";
    cin >> startx >> starty;

    // 嘗試從給定的起始點開始遊歷
    if (knightmove(startx, starty, 1))
    {
        cout << "遊歷完成！" << endl;
    }
    else
    {
        cout << "遊歷失敗！" << endl;
    }

    // 打印棋盤
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << setw(3) << borad[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}