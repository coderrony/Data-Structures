#include <bits/stdc++.h>
using namespace std;
#include "myQueue.h"
int main()
{
    typedef pair<int, int> myType;
    Queue<myType> q;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int c1, c2;
        cin >> c1 >> c2;
        q.push(make_pair(c1, c2));
    }

    while (!q.Empty())
    {
        myType chk = q.pop();
        cout << chk.first << " | " << chk.second << endl;
    }

    // cout << q.pop() << endl;
    // if (!q.Empty())
    // {
    //     cout << q.Front().first << " " << q.Front().second << endl;
    // }
    // if (!q.Empty())
    // {
    //     cout << q.Back().first << " " << q.Back().second << endl;
    // }

    return 0;
}