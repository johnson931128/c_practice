#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

double applyOperation(double a, double b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return 0;
}

double evaluatePostfix(const string &exp)
{
    stack<double> s;
    for (char ch : exp)
    {
        if (isdigit(ch))
        {
            s.push(ch - '0');
        }
        else
        {
            double b = s.top();
            s.pop();
            double a = s.top();
            s.pop();
            s.push(applyOperation(a, b, ch));
        }
    }
    return s.top();
}

double evaluatePrefix(const string &exp)
{
    stack<double> s;
    for (int i = exp.size() - 1; i >= 0; --i)
    {
        if (isdigit(exp[i]))
        {
            s.push(exp[i] - '0');
        }
        else
        {
            double a = s.top();
            s.pop();
            double b = s.top();
            s.pop();
            s.push(applyOperation(a, b, exp[i]));
        }
    }
    return s.top();
}

double evaluateInfix(const string &exp)
{

    stack<double> values;
    stack<char> ops;

    for (int i = 0; i < exp.size(); i++)
    {
        if (isdigit(exp[i]))
        {
            values.push(exp[i] - '0');
        }
        else if (exp[i] == '(')
        {
            ops.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                double a = values.top();
                values.pop();
                double b = values.top();
                values.pop();
                values.push(applyOperation(a, b, ops.top()));
                ops.pop();
            }
            ops.pop();
        }
        else
        {
            while (!ops.empty())
            {
                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();
                values.push(applyOperation(a, b, ops.top()));
                ops.pop();
            }
            ops.push(exp[i]);
        }
    }
    while (!ops.empty())
    {
        double b = values.top();
        values.pop();
        double a = values.top();
        values.pop();
        values.push(applyOperation(a, b, ops.top()));
        ops.pop();
    }

    return values.top();
}

int main()
{
    int type;
    string expr;
    cout << "Enter type (0 for prefix, 1 for infix, 2 for postfix): ";
    cin >> type;
    cout << "Enter expression: ";
    cin >> expr;

    double result = 0;
    if (type == 0)
        result = evaluatePrefix(expr);
    else if (type == 1)
        result = evaluateInfix(expr);
    else if (type == 2)
        result = evaluatePostfix(expr);
    cout << "Result : " << result << endl;
    return 0;
}
