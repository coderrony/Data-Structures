#include <bits/stdc++.h>
using namespace std;

#define queue_size 3

class Queue
{
    int head, tail;
    int data[queue_size + 1];

public:
    Queue()
    {
        this->head = 0;
        this->tail = 0;
    }
    void enqueue(int value)
    {
        if ((tail + 1) % (queue_size + 1) == head)
        {
            cout << "Queue is Full" << endl;
            return;
        }
        data[tail] = value;
        tail = (tail + 1) % (queue_size + 1);
    }
    int dequeue()
    {
        int item;
        if (head == tail)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        item = data[head];
        head = (head + 1) % (queue_size + 1);
        return item;
    }
    int peek()
    {
        if (head != tail)
        {
            return data[head];
        }
        else
        {
            return -1;
        }
    }

    bool empty()
    {
        if (head != tail)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
