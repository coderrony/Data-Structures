#include <bits/stdc++.h>
using namespace std;

template <typename N>
class Node
{
public:
    N value;
    Node *prev;
    Node *next;
    Node(N value)
    {
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};
template <typename S>
class Stack
{
    Node<S> *head;
    Node<S> *top;
    int count = 0;

public:
    Stack()
    {
        this->head = NULL;
        this->top = NULL;
    }
    // push
    void push(S value)
    {
        Node<S> *newNode = new Node<S>(value);
        if (head == NULL)
        {
            head = top = newNode;
            count += 1;
            return;
        }

        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        count += 1;
    }
    // pop
    S pop()
    {
        Node<S> *deleNode = top;
        S CHK;
        if (head == NULL)
        {
            cout << "Stack Underflow" << endl;
            return CHK;
        }

        if (top == head)
        {

            head = top = NULL;
        }
        else
        {
            top = deleNode->prev;
            top->next = NULL;
        }
        S save = deleNode->value;

        delete (deleNode);
        count -= 1;
        return save;
    }
    // empty
    bool empty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // size
    int size()
    {
        return count;
    }
    // top
    S Top()
    {
        S check;
        if (top == NULL)
        {
            cout << "Stack Underflow there is no element in top" << endl;
        }
        else
        {
            check = top->value;
        }
        return check;
    }
};
