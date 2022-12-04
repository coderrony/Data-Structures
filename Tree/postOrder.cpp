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

void printTree(treeNode *root, int level);
void spacePrint(int level);

void printTree(treeNode *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (root->leftChild == NULL && root->rightChild == NULL)
    {

        cout << root->data << endl;
        return;
    }

    // else
    // {
    //     cout << endl;
    //     cout << "Root: " << root->data << endl;
    // }

    if (root->leftChild != NULL)
    {
        spacePrint(level);
        if (root->leftChild->leftChild == NULL)
            cout << "left: ";
        printTree(root->leftChild, level + 1);
    }

    if (root->rightChild != NULL)
    {
        spacePrint(level);
        if (root->rightChild->rightChild == NULL)
            cout << "right: ";
        printTree(root->rightChild, level + 1);
    }

    cout << "Root: " << root->data << endl;
}
void spacePrint(int level)
{
    for (int i = 0; i < level; i++)
    {
        cout << " ";
    }
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

    printTree(allNodes[0], 0);
    return 0;
}

/*
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

0
1 2
3 4 5 6
-1 -1 -1 -1 7 8 -1 -1
-1 -1 -1 -1

*/
