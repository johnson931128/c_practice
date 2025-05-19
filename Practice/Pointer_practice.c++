#include <iostream>
using namespace std;

int main()
{
    int *r;
    r = new int;
    *r = 100;
    cout << r << endl;
    cout << *r << endl;

    int *s = r;
    *s = 200;
    cout << *r << endl;
    cout << r << endl;

    int *const m = new int;
    cout << m << endl;
    *m = 100;
    cout << *m << endl;
    *m = 200;
    cout << *m << endl;

    const int *n = m;
    cout << *n << endl;
    cout << n << endl;

    delete m;
    n = new int;
    cout << m << endl;

    /*
    for j = 2 to A.length do
        data = A[j]
        i = j - 1
        while i > 0 and A[i] > data do
            A[i + 1] = A[i]
            i = i - 1
        end while
        A[j+1] = data
    end for
    */

    /*

    for i = 0 to A.length do
        t = a[i]
        while t >= 1 do
            t/=2
        end while
    end for
    */

    return 0;
}