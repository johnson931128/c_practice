#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    stack<int> st;
    int k = 1;
    vector<int> A;
    while (true)
    {
        int ele;
        cin >> ele;
        if (ele == -1)
        {
            break;
        }
        A.push_back(ele);
    }
    for (int i = 1; i <= A.size(); i++)
    {
        st.push(i);
        while (!st.empty() && st.top() == A[k])
            k++, st.pop();
    }
    if (k == A.size())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}