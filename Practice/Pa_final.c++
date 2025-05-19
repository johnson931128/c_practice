// Use any of the sorting methods to sort the letters of the alphabet in A to Z or

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s;

    cin >> s;
    vector<char> st(s.begin(), s.end());

    for (int i = 0; i < st.size(); i++)
    {
        for (int j = 0; j < st.size() - 1; j++)
        {
            if (st[j] > st[j + 1])
            {
                char temp = st[j];
                st[j] = st[j + 1];
                st[j + 1] = temp;
            }
        }
    }

    for (char a : st)
    {
        cout << a;
    }
    cout << endl;
    return 0;
}