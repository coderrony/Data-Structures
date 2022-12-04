#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PAIR;
int main()
{
    // vector<int> v(3, -1); // size 3 and all value set -1
    // v.push_back(100);
    // vector<int>::iterator it;
    // for (it = v.begin(); it != v.end(); it++)
    // {
    //     cout << *it << " ";
    // }

    // auto register
    // for (auto element : v)
    // {
    //     cout << element << " ";
    // }
    // cout << endl;
    // priority_queue<int, vector<int>> Pq;

    // Pq.push(2);
    // Pq.push(10);
    // Pq.push(1);
    // Pq.push(5);
    // Pq.push(4);

    // while (!Pq.empty())
    // {
    //     cout << Pq.top() << " ";
    //     Pq.pop();
    // }

    priority_queue<PAIR, vector<PAIR>, greater<PAIR>> Pq;
    Pq.push(make_pair(1, 9));
    Pq.push(make_pair(6, 2));
    Pq.push(make_pair(4, 1));

    while (!Pq.empty())
    {
        cout << Pq.top().first << " | " << Pq.top().second << endl;
        Pq.pop();
    }
    return 0;
}

/*
 9
2 10 1 5 4 8 3 8 7
*/