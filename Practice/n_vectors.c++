#include <bits/stdc++.h>
#include <sstream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of vectors: ";
    cin >> n;
    cin.ignore();

    vector<vector<int>> vectorlist(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter elements for vector " << i + 1 << " (end with enter): ";
        string input;
        getline(cin, input);
        stringstream ss(input);
        int value;
        while (ss >> value)
        {
            vectorlist[i].push_back(value);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Vector " << i + 1 << ": ";
        for (int ele : vectorlist[i])
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}