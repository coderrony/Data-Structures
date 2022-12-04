#include <bits/stdc++.h>
#include "C:\Users\ronyd\OneDrive\Desktop\cProgramming\DSA_C++\Datastructure\stack\mystack.h"
using namespace std;

int precision(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '^')
    {
        return 3;
    }
    else
    {
        return -1;
    }
}

string postFixCal(string str)
{

    Stack<char> st;
    string result;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            result += str[i];
        }
        else if (str[i] == '(')
        {
            st.push(str[i]);
        }
        else if (str[i] == ')')
        {
            while (!st.empty() && '(' != st.Top())
            {
                result += st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && precision(st.Top()) >= precision(str[i]))
            {
                result += st.pop();
            }
            st.push(str[i]);
        }
    }

    while (!st.empty())
    {
        result += st.pop();
    }
    return result;
}

int postFixResult(string str)
{
    Stack<int> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            st.push(str[i] - '0');
        }
        else
        {
            int a = st.pop();
            int b = st.pop();

            switch (str[i])
            {
            case '+':
                st.push(b + a);
                break;
            case '-':
                st.push(b - a);
                break;
            case '*':
                st.push(b * a);
                break;
            case '/':
                st.push(b / a);
                break;
            case '^':
                st.push(pow(b, a));
                break;
            default:
                break;
            }
        }
    }
    return st.Top();
}

int main()
{
    string s = "(5*((6^2)+(7-(2/6))))-((7*(8+1))+(5*4))";

    string postFi = postFixCal(s);

    cout << postFi << endl;
    cout << postFixResult(postFi) << endl;
    return 0;
}

/*

(4*(3+5))-(2+0)

(7+(4*5)-(2+0))

(5*((6^2)+(7-(2/6))))-((7*(8+1))+(5*4))

*/