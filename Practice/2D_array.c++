#include <iostream>
using namespace std;

int board[8][8] = {0};

int travel(int &x, int &y)
{
    // 橫向移動 x
    int ktmove1[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    // 縱向移動 y
    int ktmove2[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    int nexti[8] = {0};
    int nextj[8] = {0};

    int exists[8] = {0};

    int i, j, l, m, k;
    int count, tempi, tempj;
    int min, tmp;

    i = x;
    j = y;
    board[i][j] = 1; // 記錄起始點

    for (m = 2; m <= 64; m++)
    {
        for (l = 0; l < 8; l++)
        {
            exists[l] = 0;
        }
        l = 0;

        for (k = 0; k < 8; k++)
        {
            tempi = i + ktmove1[k];
            tempj = j + ktmove2[k];

            if (tempi < 0 || tempi > 7 || tempj < 0 || tempj > 7)
            {
                continue; // 直接跳到下一個k
            }

            if (board[tempi][tempj] == 0)
            {
                nexti[l] = tempi;
                nextj[l] = tempj;
                l++;
            }
        }

        count = l;

        if (count == 0)
        {
            return 0;
        }
        else if (count == 1)
        {
            min = 0;
        }
        else
        {
            for (l = 0; l < count; l++)
            {
                for (k = 0; k < 8; k++)
                {
                    tempi = nexti[l] + ktmove1[k];
                    tempj = nextj[l] + ktmove2[k];

                    if (tempi < 0 || tempj < 0 || tempi > 7 || tempj > 7)
                    {
                        continue;
                    }

                    if (board[tempi][tempj] == 0)
                    {
                        exists[l]++;
                    }
                }
            }

            tmp = exists[0];
            min = 0;

            for (l = 1; l < count; l++)
            {
                if (exists[l] < tmp)
                {
                    tmp = exists[l];
                    min = l;
                }
            }
        }

        i = nexti[min];
        j = nextj[min];
        board[i][j] = m;
    }
    return 1;
}

int main()
{
    int startx, starty;
    int i, j;

    cout << "輸入起始點：";
    cin >> startx >> starty;

    if (travel(startx, starty))
    {
        cout << "遊歷完成！" << endl;
    }
    else
    {
        cout << "遊歷失敗！" << endl;
    }

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
