#include <bits/stdc++.h>
using namespace std;
#define stack_size 4

class myStack
{
public:
    int top;
    int arr[stack_size];
};

void push(myStack *&s, int value)
{

    if (s->top < stack_size)
    {
        s->arr[s->top] = value;
        s->top += 1;
    }
    else
    {
        cout << "stack is full" << endl;
    }
}
int pop(myStack *&s)
{
    if (s->top == 0 || s->top > stack_size - 1)
    {
        cout << "invalid stack" << endl;
        return -1;
    }
    else
    {
        int item = s->arr[s->top - 1];
        s->top -= 1;
        return item;
    }
}
int main()
{

    myStack *s1;
    s1->top = 0;

    int item;

    push(s1, 1);
    push(s1, 2);
    push(s1, 3);

    item = pop(s1);
    cout << item << endl;
    item = pop(s1);
    cout << item << endl;
    item = pop(s1);
    cout << item << endl;
    item = pop(s1);
    cout << item << endl;

    return 0;
}