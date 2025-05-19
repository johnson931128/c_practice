#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> B(H);
    for (int i = 0; i < H; i++)
    {
        cin >> B[i];
    }
    //   左下 左 左上 政下 政上 右下 又 右上 8
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (B[i][j] == '.')
            {
                int sum = 0;
                for (int d = 0; d < 8; d++)
                {
                    int nx = i + dx[d];
                    int ny = j + dy[d];

                    if (nx >= 0 && ny >= 0 && nx < H && ny < W && B[nx][ny] == '#')
                    {
                        sum++;
                    }
                }
                B[i][j] = sum + '0';
            }
        }
    }

    for (int i = 0; i < H; i++)
    {
        cout << B[i] << "\n";
    }
    return 0;
}