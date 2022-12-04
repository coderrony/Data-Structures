#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PAIR;
int main()
{

    int k;
    cin >> k;
    vector<vector<int>> allValues(k);
    for (int i = 0; i < k; i++)
    {
        int size;
        cin >> size;
        allValues[i] = vector<int>(size);
        for (int j = 0; j < size; j++)
        {
            cin >> allValues[i][j];
        }
    }

    vector<int> indexTracker(k, 0);
    priority_queue<PAIR, vector<PAIR>, greater<PAIR>> Pq;

    for (int i = 0; i < k; i++)
    {
        Pq.push(make_pair(allValues[i][0], i));
    }

    vector<int> ans;
    while (!Pq.empty())
    {
        PAIR x = Pq.top();
        Pq.pop();
        ans.push_back(x.first);
        if (indexTracker[x.second] + 1 < allValues[x.second].size())
        {
            Pq.push(make_pair(allValues[x.second][indexTracker[x.second] + 1], x.second));
        }
        indexTracker[x.second] += 1;
    }

    for (auto element : ans)
    {
        cout << element << " ";
    }
    return 0;
}

/*

3
3
1 4 7
2
3 5
3
2 6 7


*/