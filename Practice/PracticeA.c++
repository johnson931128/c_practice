#include <iostream>
#include <string>

using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n > 0)
    {
        string s;
        cin >> s;
        int len = s.length();
        int odd = 0;
        int even = 0;

        for (int i = 0; i < len; i++)
        {
            if (i % 2 == 0)
            {
                even += s[i] - '0';
            }
            else
            {
                odd += s[i] - '0';
            }
        }
        if ((even - odd) % 11 == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
        n--;
    }
}