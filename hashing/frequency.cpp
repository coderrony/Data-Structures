#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    map<int, int> M;

    for (int i = 0; i < n; i++)
    {
        M[arr[i]]++;
    }

    map<int, int>::iterator it;
    for (it = M.begin(); it != M.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}