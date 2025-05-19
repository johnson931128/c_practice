#include <iostream>
#include <vector>
using namespace std;

int islandPerimeter(vector<vector<int>> &island)
{
    int perimeter = 0;
    int rows = island.size();
    int cols = island[0].size();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (island[i][j] == 1)
            { // 找到一塊土地
                // 檢查上方
                if (i == 0 || island[i - 1][j] == 0)
                    perimeter++;
                // 檢查下方
                if (i == rows - 1 || island[i + 1][j] == 0)
                    perimeter++;
                // 檢查左方
                if (j == 0 || island[i][j - 1] == 0)
                    perimeter++;
                // 檢查右方
                if (j == cols - 1 || island[i][j + 1] == 0)
                    perimeter++;
            }
        }
    }
    return perimeter;
}

int main()
{
    vector<vector<int>> island = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}};

    int perimeter = islandPerimeter(island);
    cout << "Total perimeter: " << perimeter << endl;
    return 0;
}
