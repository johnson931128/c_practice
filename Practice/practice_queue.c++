#include <iostream>
#include <vector>
using namespace std;

// queue only

int main()
{
    int f = -1;
    int b = -1;
    vector<int> a;

    char op;
    cin >> op;

    while (op != 'e')
    {
        switch (op)
        {
        case 'p':
            int ele;
            cin >> ele;
            a.push_back(ele);
            b++;
            break;
        case 'd':
            if (b > f)
            {
                cout << a[f + 1] << endl;
                a[f + 1] = 0;
                f++;
                break;
            }
            else
            {
                cout << "no element" << endl;
                break;
            }
        }
        cin >> op;
    }
    return 0;
}