#include <bits/stdc++.h>
#include "C:\Users\ronyd\OneDrive\Desktop\cProgramming\DSA_C++\Datastructure\stack\mystack.h"
using namespace std;

int prefixEvaluation(string chk)
{
    Stack<int> st;
    for (int i = chk.size() - 1; i >= 0; i--)
    {

        if (chk[i] >= '0' && chk[i] <= '9') // chk[i]  0 to 9 ->> operand
        {
            st.push(chk[i] - '0');
        }
        else
        {
            int a = st.pop();
            int b = st.pop();

            switch (chk[i])
            {
            case '+':
                st.push(a + b);
                break;

            case '-':
                st.push(a - b);
                break;
            case '*':
                st.push(a * b);
                break;
            case '/':
                st.push(a / b);
                break;
            case '^':
                st.push(pow(a, b));
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

    cout << prefixEvaluation("-+7*45+20");
}