#include <iostream>
#include <stack>
#include <string>
using namespace std;

int pre(char &op)
{
    if (op == '*' || op == '/') // ''is for char "" is for string
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0; // for ()
}

string infixToposfix(string infix)
{
    stack<char> st;
    string postfix;
    for (char op : infix)
    {
        if (isalnum(op))
        {
            postfix += op;
        }
        else if (op == '(')
        {
            st.push(op);
        }
        else if (op == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // delete '('
        }
        else
        {
            while (!st.empty() && pre(st.top()) > pre(op))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(op);
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int main()
{
    string s;
    cin >> s;
    string postfix = infixToposfix(s);
    cout << postfix << endl;
    return 0;
}