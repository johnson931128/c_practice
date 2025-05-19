#include <iostream>
#include <vector>
using namespace std;

bool isPlanted(vector<int> flower, int n)
{

    vector<int> cannot(flower.size(), 0);

    for (int i = 0; i < flower.size(); i++)
    {
        if (flower[i] == 1)
        {
            if (i - 1 != 0)
            {
                cannot[i - 1] = 1;
                cannot[i] = 1;
            }
            if (i + 1 < flower.size())
            {
                cannot[i + 1] = 1;
            }
        }
    }

    int available = 0;
    for (int i = 0; i < cannot.size(); i++)
    {
        if (cannot[i] == 0)
            available++;
    }

    return n <= available;
}

int main()
{
    vector<int> flower;
    int n, num;
    while (cin >> num)
    {
        flower.push_back(num);
        if (cin.peek() != '\n')
            break;
    }
    bool result = isPlanted(flower, n);
    cout << (result ? "true" : "false") << '\n';
    return 0;
}