#include <bits/stdc++.h>
using namespace std;

set<string> solve(string s)
{
    int n = s.length();
    sort(s.begin(), s.end());
    set<string> nuiqueStrings;
    do
    {
        nuiqueStrings.insert(s);
    } while (next_permutation(s.begin(), s.end()));
    return nuiqueStrings;
} // set will automatically remove the same string

int main()
{
    string s;
    getline(cin, s);
    set<string> uniqueStrings = solve(s);
    cout << uniqueStrings.size() << "\n";
    for (string s : uniqueStrings)
    {
        cout << s << "\n";
    }
    return 0;
}