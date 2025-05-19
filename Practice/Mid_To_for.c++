#include <iostream>
#include <stack>
#include <string>
#include <cctype> // isdigit isalpha isalnum
using namespace std;

int precedence(char op)
{
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

string infixPostfix(const string &infix)
{
    stack<char> s;
    string postfix;

    for (char ch : infix)
    {
        if (isalnum(ch))
        {
            postfix += ch;
        }
        else
        {
            while (!s.empty() && precedence(s.top()) >= precedence(ch))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

string infixPrefix(const string &infix)
{
    stack<char> s;
    string prefix;
    string reversedInfix = string(infix.rbegin(), infix.rend());

    for (char ch : reversedInfix)
    {
        if (isalnum(ch))
        {
            prefix += ch;
        }
        else
        {
            while (!s.empty() && precendece(s.top()) >= precedence(ch))
            {
                prefix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty())
    {
        prefix += s.top();
        s.pop();
    }
    return string(prefix.rbegin(), prefix.rend());
}

int main()
{
    string infix;
    cout << "please enter infix stateement : ";
    getline(cin, infix);

    string postfix = infixPostfix(infix);
    string prefix = infixToPrefix(infix);

    cout << "後序表達式 : " << postfix << endl;
    cout << "前序表達式： " << prefix << endl;
    return 0;
}
