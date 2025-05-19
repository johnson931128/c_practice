#include <iostream>
#include <vector>
using namespace std;

struct Point
{
    int x;
    int y;
};

bool isValidMove(int x, int y, vector<vector<int>> &maze, vector<vector<bool>> &visited, int m, int n)
{
    // 判斷該點是否在迷宮內，是否未被訪問過，並且該點無牆壁
    return (x < m && x >= 0 && y >= 0 && y < n && !visited[x][y] && maze[x][y] == 0);
}

bool solvedMaze(int x, int y, vector<vector<int>> &maze, vector<vector<bool>> &visited, int m, int n, vector<Point> &path)
{
    // 如果到達終點，將該點加入路徑並返回成功
    if (x == m - 2 && y == n - 2)
    {
        path.push_back({x, y}); // 保存終點
        return true;
    }

    visited[x][y] = true;   // 標記該點已經訪問過
    path.push_back({x, y}); // 保存當前座標

    // 定義四個移動方向
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++)
    {
        int newx = x + dx[i];
        int newy = y + dy[i];

        // 如果可以移動，則進行遞迴
        if (isValidMove(newx, newy, maze, visited, m, n))
        {
            if (solvedMaze(newx, newy, maze, visited, m, n, path))
            {
                return true; // 如果遞迴返回成功，則結束
            }
        }
    }

    // 如果該路徑失敗，則回溯並移除當前座標
    path.pop_back();
    visited[x][y] = false;
    return false;
}

int main()
{
    int m, n;
    cout << "Please enter the width and height (m x n) : ";
    cin >> m >> n;

    vector<vector<int>> maze(m, vector<int>(n));
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    cout << "Please enter the struct of maze(0:no wall, 1:wall) : " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }

    vector<Point> path; // 儲存從起點到終點的路徑

    // 檢查起點和終點是否可行
    if (maze[1][1] == 1 || maze[m - 2][n - 2] == 1)
    {
        cout << "Maze cannot be solved!(Start or End blocked)\n";
        return 0;
    }

    if (solvedMaze(1, 1, maze, visited, m, n, path))
    {
        cout << "Maze can be solved!\n";
        cout << "Path: ";
        for (const auto &p : path)
        {
            cout << "(" << p.x << ", " << p.y << ") ";
        }
        cout << endl;
    }
    else
    {
        cout << "Maze cannot be solved!\n";
    }

    return 0;
}
