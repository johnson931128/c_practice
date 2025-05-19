#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && a[s.top()] >= a[i])
        {
            s.pop();
        }

        if (!s.empty())
        {
            result[i] = s.top() + 1;
        }
        else
        {
            result[i] = 0;
        }
        s.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}