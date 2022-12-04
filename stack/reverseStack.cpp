#include <bits/stdc++.h>
#include "mystack.h"
using namespace std;

void insertAtBottom(Stack<int> &chk, int chkElement)
{
    if (chk.empty())
    {
        chk.push(chkElement);
        return;
    }
    int topElement = chk.Top();
    chk.pop();
    insertAtBottom(chk, chkElement);
    chk.push(topElement);
}

void reverseStackFun(Stack<int> &chk)
{
    if (chk.empty())
        return;
    int topElement = chk.Top();
    chk.pop();
    reverseStackFun(chk);
    insertAtBottom(chk, topElement);
}

int main()
{

    Stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reverseStackFun(st);

    while (!st.empty())
    {
        cout << st.pop() << endl;
    }
    return 0;
}