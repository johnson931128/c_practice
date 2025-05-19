#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    string input;
    cin >> input;

    list<char> password;
    auto cursor = password.begin();

    for (char ch : input)
    {
        if (ch == 'L')
        {
            if (cursor != password.begin())
            {
                --cursor; // gpt said it is faster than cursor--
            }
        }
        else if (ch == 'R')
        {
            if (cursor != password.end())
            {
                ++cursor;
            }
        }
        else if (ch == 'B')
        {
            if (cursor != password.begin())
            {
                cursor = password.erase(--cursor);
            }
        }
        else
        {
            password.insert(cursor, ch);
        }
    }

    for (char ch : password)
    {
        cout << ch;
    }
    cout << endl;
    return 0;
}