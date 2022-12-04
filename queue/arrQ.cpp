#include <bits/stdc++.h>
using namespace std;
#include "circularQueueArr.h"
int main()
{
    Queue q;

    q.enqueue(1);
    // q.enqueue(2);
    // q.enqueue(3);

    cout << q.dequeue() << endl;
    // cout << q.dequeue() << endl;
    // cout << q.dequeue() << endl;
    // cout << q.dequeue() << endl;

    cout << q.empty() << endl;
    return 0;
}