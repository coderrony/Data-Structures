#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode *leftChild;
    TreeNode *rightChild;
    TreeNode(int val)
    {
        this->value = val;
        this->leftChild = NULL;
        this->rightChild = NULL;
    }
};
void printSpace(int value)
{
    for (int i = 0; i < value; i++)
    {
        cout << " ";
    }
}
void printTree(TreeNode *root, int spaces)
{
    if (root == NULL)
        return;
    if (root->leftChild == NULL && root->rightChild == NULL)
    {

        cout << root->value << endl;
        return;
    }
    else
    {
        cout << endl;
        printSpace(spaces);
        cout << "root: " << root->value << endl;
    }

    if (root->leftChild != NULL)
    {
        printSpace(spaces);
        cout << "left: ";
        printTree(root->leftChild, spaces += 1);
    }

    if (root->rightChild != NULL)
    {
        printSpace(spaces);
        cout << "right: ";
        printTree(root->rightChild, spaces += 1);
    }
}

int deptSearch(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int x = deptSearch(root->leftChild);
    int y = deptSearch(root->rightChild);

    return max(x, y) + 1;
}
void inOrder(TreeNode *root)
{
    if (root == NULL)
        return;

    inOrder(root->leftChild);

    cout << root->value << " ";

    inOrder(root->rightChild);
}

int main()
{
    int n;
    cin >> n;
    TreeNode *allNode[n];
    for (int i = 0; i < n; i++)
    {

        allNode[i] = new TreeNode(-1);
    }

    for (int i = 0; i < n; i++)
    {
        int left, right, v;
        cin >> v >> left >> right;
        if (left > n - 1 || right > n - 1)
            break;

        allNode[i]->value = v;

        if (left != -1)
        {
            allNode[i]->leftChild = allNode[left];
        }
        if (left != -1)
        {
            allNode[i]->rightChild = allNode[right];
        }
    }

    // printTree(allNode[0], 0);
    inOrder(allNode[0]);

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

*/