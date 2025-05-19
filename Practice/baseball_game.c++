#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int calPoints(vector<string> &operations)
{
    vector<int> record;
    for (const string &op : operations)
    {
        if (op == "C") // "" is str, '' is char
        {
            record.pop_back();
        }
        else if (op == "D")
        {
            record.push_back(2 * record.back());
        }
        else if (op == "+")
        {
            int n = record.size();
            record.push_back(record[n - 2] + record[n - 1]);
        }
        else
        {
            record.push_back(stoi(op)); // stoi() could automatically change variable to int
        }
    }

    int total = 0;
    for (const int &val : record)
    {
        total += val;
    }
    return total;
}

int main()
{
    vector<string> ops;
    string input;

    cout << "請輸入操作（輸入'0'結束）:" << endl;
    cin >> input;
    ops.push_back(input);
    int result = calPoints(ops);
    cout << "總分: " << result << endl;

    return 0;
}
