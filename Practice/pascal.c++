#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> pascal(numRows);

    for (int i = 0; i < numRows; i++)
    {
        pascal[i].resize(i + 1); // i-row have i+1 elements
        pascal[i][0] = pascal[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }
    }
    return pascal;
}

int main()
{
    int numRows;
    cout << "Enter number of rows: ";
    cin >> numRows;
    vector<vector<int>> result = generate(numRows);
    for (const auto &row : result)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}