#include <bits/stdc++.h>
using namespace std;

template <typename N>

class Node
{
public:
    N value;
    Node *next;

    Node(N value)
    {
        this->value = value;
        this->next = NULL;
    }
};
template <typename Q>
class Queue
{
    Node<Q> *front;
    Node<Q> *rear;

public:
    Queue()
    {
        this->front = NULL;
        this->rear = NULL;
    }
    // enqueue -> push
    void push(Q val)
    {
        Node<Q> *newNode = new Node<Q>(val);
        if (front == NULL)
        {
            front = rear = newNode;
            return;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }
    // dequeue -> pop
    Q pop()
    {
        Node<Q> *deleNode = front;
        Q chk;
        if (rear == NULL)
        {
            cout << "Queue Underflow there is no element is the queue" << endl;
        }
        front = deleNode->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        chk = deleNode->value;
        delete (deleNode);
        return chk;
    }
    // peek --> front() back()
    Q Front()
    {
        return front->value;
    }
    Q Back()
    {
        return rear->value;
    }
    // empty
    bool Empty()
    {
        if (front == NULL && rear == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
