#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    int k = 1;
    int A[4];
    for (int i = 1; i <= 3; i++)
    {
        cin >> A[i];
    }
    for (int i = 1; i <= 3; i++)
    {
        st.push(i);
        while (!st.empty() && st.top() == A[k])
            k++, st.pop();
    }
    if (k == 4)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}