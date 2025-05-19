#include <iostream>
using namespace std;
int step = 0;
//(n, from, mid, to)
void hanoi(int n, char A, char B, char C)
{
    if (n == 1)
    {
        cout << A << " to " << C << '\n';
        step++;
    }
    else
    {
        hanoi(n - 1, A, C, B);
        hanoi(1, A, B, C);
        hanoi(n - 1, B, A, C);
    }
}
int main()
{
    int n;
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    cout << step << '\n';
}