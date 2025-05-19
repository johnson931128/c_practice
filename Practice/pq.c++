#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    /*
    ios::sync_with_stdio(false);：關閉 C++ 的輸入輸出與 C 的標準輸入輸出流的同步，從而加速 cin 和 cout。
    cin.tie(0);：解綁 cin 和 cout，使得 cin 不需要等待 cout 完成輸出後才能執行，進一步提高速度。
    */
    int n;
    cin >> n;
    cin.ignore(); // 清除換行符號

    for (int i = 0; i < n; i++)
    {
        string s;
        int num = 0;
        stack<char> pair; // 每組測試重新初始化 stack 移到for回圈內

        getline(cin, s); // 讀取每行字串

        for (const char a : s)
        {
            if (a == 'p')
            {
                pair.push(a);
            }
            else if (a == 'q')
            {
                if (!pair.empty() && pair.top() == 'p')
                {
                    pair.pop();
                    num++;
                }
            }
        }
        cout << num << "\n";
    }

    return 0;
}
