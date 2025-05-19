#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> m;

    while (true)
    {
        int coeff;
        cin >> coeff;
        if (coeff == -1)
            break;
        m.push_back(coeff);
    }

    // 列印輸入的係數
    cout << "Coefficients: ";
    cout << "The size of m is : " << m.size() << endl;
    for (int i = 0; i < m.size(); i++)
    {

        cout << m[i] << " ";
    }
    cout << endl;

    return 0;
}
