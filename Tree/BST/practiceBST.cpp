#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *leftChild;
    Node *rightChild;
    Node(int val)
    {
        this->val = val;
        this->leftChild = NULL;
        this->rightChild = NULL;
    }
};
void inOrder(Node *root)
{

    if (root->leftChild)
    {
        inOrder(root->leftChild);
    }
    cout << root->val << " ";
    if (root->rightChild)
    {
        inOrder(root->rightChild);
    }
}
// 11 5 4 43 34 1 2 7 21
Node *insertBinary(Node *root, int value)
{
    Node *newNode = new Node(value);
    if (root == NULL)
    {
        root = newNode;
        return root;
    }

    if (root->val > value)
    {
        root->leftChild = insertBinary(root->leftChild, value);
    }
    else if (root->val < value)
    {
        root->rightChild = insertBinary(root->rightChild, value);
    }
    return root;
}

bool searchBst(Node *root, int value, int &lev)
{
    static int level = 0;
    if (root == NULL)
    {
        lev = -1;
        return false;
    }
    if (root->val == value)
    {
        lev = level;
        return true;
    }
    if (root->val > value)
    {
        level++;
        searchBst(root->leftChild, value, lev);
    }
    else if (root->val < value)
    {
        level++;
        searchBst(root->rightChild, value, lev);
    }
}
Node *findSuccessEr(Node *root)
{
    while (root->leftChild != NULL)
    {
        root = root->leftChild;
    }
    return root;
}
Node *deleBst(Node *root, int value)
{

    if (root->val > value)
    {
        root->leftChild = deleBst(root->leftChild, value);
    }
    else if (root->val < value)
    {
        root->rightChild = deleBst(root->rightChild, value);
    }
    else
    {
        if (root->leftChild == NULL)
        {
            Node *temp = root->rightChild;
            free(root);
            return temp;
        }
        else if (root->rightChild == NULL)
        {
            Node *temp = root->leftChild;
            free(root);
            return temp;
        }
        else
        {
            Node *successR = findSuccessEr(root->rightChild);
            root->val = successR->val;
            root->rightChild = deleBst(root->rightChild, successR->val);
        }
    }
    return root;
}
int main()
{

    int n;
    cin >> n;
    Node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        root = insertBinary(root, value);
    }
    inOrder(root);
    // cout << endl;
    // int key = 50;
    // int count;
    // bool save = searchBst(root, key, count);
    // cout << save << " " << count << endl;

    // root = deleBst(root, key);
    // cout << endl;
    // inOrder(root);

    return 0;
}

/*
9
11 5 4 43 34 1 2 7 21
*/