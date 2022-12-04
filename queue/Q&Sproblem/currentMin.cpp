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
    stack<int> st;
    stack<int> minStack;

    int minValue = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= minValue)
        {
            minStack.push(arr[i]);
            minValue = min(minValue, arr[i]);
        }

        st.push(arr[i]);
    }

    while (!st.empty())
    {
        // if top of minStack and st is equal
        if (minStack.top() != st.top())
        {
            st.pop();
            cout << minStack.top() << " ";
        }
        else
        {
            cout << minStack.top() << " ";
            minStack.pop();
            st.pop();
        }
    }

    return 0;
}