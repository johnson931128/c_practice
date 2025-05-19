#include <iostream>
#include <vector>
using namespace std;

struct Car
{
    int front = -1;
    int back = -1;
};

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<Car> train(N + 1);

    for (int i = 0; i < Q; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y;
            cin >> x >> y;
            // 後街前
            train[x].back = y;
            train[y].front = x;
        }
        else if (op == 2)
        {
            int x, y;
            cin >> x >> y;
            // 段接
            train[x].back = -1;
            train[y].front = -1;
        }
        else if (op == 3)
        {
            int x;
            cin >> x;
            int now = x;
            while (train[now].front != -1)
            {
                now = train[now].front;
            }

            vector<int> newtrain;

            while (now != -1)
            {
                newtrain.push_back(now);
                now = train[now].back;
            }

            cout << newtrain.size();
            for (int car : newtrain)
            {
                cout << " " << car;
            }
            cout << endl;
        }
    }
    return 0;
}