#include <bits/stdc++.h>
#include <stack>

using namespace std;

int main()
{
    stack<int> st;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        if (ele == -1)
            break;
        st.push(ele);
    }
    for (int j = 0; j < n; j++)
    {
        st.pop();
        cout << "\n";
    }
    return 0;
}