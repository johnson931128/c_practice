#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of cards: ";
    cin >> n;

    if (n < 2 || n > 50)
        return 1;
    queue<int> cards;
    for (int i = 1; i <= n; i++)
    {
        cards.push(i);
    }

    cout << "Discarded cards: ";
    bool first = true;
    while (cards.size() > 1)
    {
        if (!first)
        {
            cout << ", ";
        }
        cout << cards.front(); // print top
        cards.pop();           // remove top
        first = false;
        int top = cards.front(); // added next top
        cards.pop();             // remove it
        cards.push(top);         // top will be added back
    }

    cout << endl;
    cout << "Remaining card: " << cards.front() << endl;
    return 0;
}