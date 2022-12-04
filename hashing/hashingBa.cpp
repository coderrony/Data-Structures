#include <bits/stdc++.h>
using namespace std;

int main()
{

    // map<int, int> M;
    unordered_map<int, int> M;

    M[3] = 9;
    M[2] = 30;
    M[4] = 40;
    M.insert(make_pair(1, 100));

    for (auto i : M)
    {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}