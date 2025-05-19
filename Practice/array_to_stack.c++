#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int g[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        cout << "Stack is full" << endl;
        exit(EXIT_FAILURE);
    }
    g[top + 1] = value;
    top++;
}

int pop()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    cout << g[top];
    cout << "\n";
    top--;
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    pop();
    pop();
    return 0;
}
