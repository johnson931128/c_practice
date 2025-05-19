#include <iostream>
using namespace std;

int is_triangle(int matrix[5][5])
{
    bool up = true;
    bool down = true;

    // 這裡的判斷是你原本的問題，bool 變數沒用對
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            // 檢查是否為上三角矩陣，應該是檢查下三角區域是否為 0
            if (i > j && matrix[i][j] != 0) // 改成 != 0
            {
                up = false; // 刪掉 bool，直接修改外部的 down
            }
            // 檢查是否為下三角矩陣，應該是檢查上三角區域是否為 0
            if (j > i && matrix[i][j] != 0) // 改成 != 0
            {
                down = false; // 刪掉 bool，直接修改外部的 up
            }
        }
    }

    if (up)
    {
        return 0; // 上三角矩陣
    }
    else if (down)
    {
        return 1; // 下三角矩陣
    }
    else
    {
        return -1; // 不是三角矩陣
    }
}

int main()
{
    int matrix[5][5];
    // 讀取 5x5 的矩陣
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // 正確的函數呼叫
    int result = is_triangle(matrix); // 呼叫函數
    cout << result << endl;           // 輸出結果

    return 0;
}
