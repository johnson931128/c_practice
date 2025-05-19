#include <iostream>
#include <vector>
using namespace std;

struct Point
{
    int x;
    int y;
};

bool isValidMove(int x, int y, vector<vector<int>> &maze, vector<vector<bool>> &visited)
{
    return (x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && !visited[x][y] && maze[x][y] == 0);
}

bool solvedMaze(int x, int y, vector<vector<int>> &maze, vector<vector<bool>> &visited, vector<Point> &path, int endX, int endY)
{
    if (x == endX && y == endY)
    {
        path.push_back({x, y});
        return true;
    }

    visited[x][y] = true;
    path.push_back({x, y});

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++)
    {
        int newx = x + dx[i];
        int newy = y + dy[i];

        if (isValidMove(newx, newy, maze, visited))
        {
            if (solvedMaze(newx, newy, maze, visited, path, endX, endY))
            {
                return true;
            }
        }
    }

    path.pop_back();
    visited[x][y] = false;
    return false;
}

int main()
{
    int startX, startY, endX, endY;
    cin >> startX >> startY;
    cin >> endX >> endY;

    vector<vector<int>> maze = {
        {2, 2, 2, 2, 2, 2, 2},
        {2, 0, 0, 0, 0, 0, 2},
        {2, 0, 2, 0, 2, 0, 2},
        {2, 0, 0, 2, 0, 2, 2},
        {2, 2, 0, 2, 0, 2, 2},
        {2, 0, 0, 0, 0, 0, 2},
        {2, 2, 2, 2, 2, 2, 2}};

    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
    vector<Point> path;

    if (solvedMaze(startX, startY, maze, visited, path, endX, endY))
    {
        for (const auto &p : path)
        //         Point
        {
            cout << "(" << p.x << ", " << p.y << ") ";
        }
        cout << endl;
    }
    else
    {
        cout << "-1" << endl;
    }

    return 0;
}