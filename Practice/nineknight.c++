#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int width = 5, length = 5;
    vector<string> board(width);

    for (int i = 0; i < width; i++)
    {
        cin >> board[i];
    }

    int dx[] = {2, 2, 1, -1, -2, -2, -1, 1};
    int dy[] = {1, -1, -2, -2, -1, 1, 2, 2};

    int knightCount = 0;
    bool isValid = true;

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (board[i][j] == 'k')
            {
                knightCount++;

                for (int k = 0; k < 8; k++)
                {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < width && nj >= 0 && nj < length && board[ni][nj] == 'k')
                    {
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    if (knightCount == 9)
    {
        cout << "valid" << endl;
    }
    else
    {
        cout << "invalid" << endl;
    }

    return 0;
}