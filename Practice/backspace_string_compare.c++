#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 幫助函數，用來處理含有 '#' 的字串，返回退格後的結果
string buildString(const string &str)
{
    string result;
    for (char ch : str)
    {
        if (ch != '#')
        {
            result.push_back(ch); // 將字元加入結果字串
        }
        else if (!result.empty())
        {
            result.pop_back(); // 遇到 '#'，退格，刪除最後一個字元
        }
    }
    return result;
}

// 比較兩個字串是否在處理退格後相等
bool bsc(const string &s, const string &t)
{
    return buildString(s) == buildString(t);
}

int main()
{
    string s, t;

    // 輸入兩個字串
    cout << "請輸入第一個字串: ";
    cin >> s;
    cout << "請輸入第二個字串: ";
    cin >> t;

    // 呼叫 bsc 函數並輸出結果
    if (bsc(s, t))
    {
        cout << "兩個字串在退格後相等" << endl;
    }
    else
    {
        cout << "兩個字串在退格後不相等" << endl;
    }

    return 0;
}
