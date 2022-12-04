#include <bits/stdc++.h>
using namespace std;

class treeNode
{
public:
    int data;
    treeNode *leftChild;
    treeNode *rightChild;
    treeNode(int value)
    {
        this->data = value;
        this->leftChild = NULL;
        this->rightChild = NULL;
    }
};

void verticalOrder(treeNode *root, int D, map<int, vector<int>> &M)
{
    if (root == NULL)
        return;

    M[D].push_back(root->data);
    verticalOrder(root->leftChild, D - 1, M);
    verticalOrder(root->rightChild, D + 1, M);
}
int main()
{
    int n;
    cin >> n;
    treeNode *allNodes[n];

    for (int i = 0; i < n; i++)
    {
        allNodes[i] = new treeNode(-1);
    }

    for (int i = 0; i < n; i++)
    {
        int value, left, right;
        cin >> value >> left >> right;
        allNodes[i]->data = value;

        if (left > n - 1 || right > n - 1)
        {
            cout << "invalid index" << endl;
        }
        if (left != -1)
        {
            allNodes[i]->leftChild = allNodes[left];
        }
        if (right != -1)
        {
            allNodes[i]->rightChild = allNodes[right];
        }
    }

    map<int, vector<int>> M;

    verticalOrder(allNodes[0], 0, M);
    cout << endl;
    for (auto i : M)
    {
        cout << i.first << ": ";
        for (int j = 0; j < i.second.size(); j++)
        {
            cout << i.second[j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*

9
0 1 3 4 2 5 7 8 6
3 1 4 0 7 5 8 2 6

pre order: 013425786
post order: 341785620
in order: 314075826


9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1

*/
