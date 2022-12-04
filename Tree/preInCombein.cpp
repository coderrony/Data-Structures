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
void inOrder(treeNode *root, string &chk);
void preOrder(treeNode *root, string &chk);
void postOrder(treeNode *root, string &chk);
void levelOrderTraversal(treeNode *root, string &chk);
treeNode *buildTreePreIn(int *PreOrder, int *InOrder, int start, int end);
void boundaryTraversal(treeNode *root);

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
    else
    {
        cout << endl;
        cout << "Root: " << root->data << endl;
    }

    if (root->leftChild != NULL)
    {
        spacePrint(level);
        cout << "left: ";
        printTree(root->leftChild, level + 1);
    }

    if (root->rightChild != NULL)
    {
        spacePrint(level);
        cout << "Right: ";
        printTree(root->rightChild, level + 1);
    }
}
void spacePrint(int level)
{
    for (int i = 0; i < level; i++)
    {
        cout << " ";
    }
}

void inOrder(treeNode *root, string &chk)
{
    if (root == NULL)
    {
        return;
    }

    if (root->leftChild != NULL)
    {
        inOrder(root->leftChild, chk);
    }
    chk += to_string(root->data);
    if (root->leftChild != NULL)
    {
        inOrder(root->rightChild, chk);
    }
}

void preOrder(treeNode *root, string &chk)
{
    if (root == NULL)
    {
        return;
    }
    chk += to_string(root->data);
    if (root->leftChild != NULL)
    {
        preOrder(root->leftChild, chk);
    }

    if (root->leftChild != NULL)
    {
        preOrder(root->rightChild, chk);
    }
}

void postOrder(treeNode *root, string &chk)
{
    if (root == NULL)
    {
        return;
    }

    if (root->leftChild != NULL)
    {
        postOrder(root->leftChild, chk);
    }

    if (root->rightChild != NULL)
    {
        postOrder(root->rightChild, chk);
    }
    chk += to_string(root->data);
}

int levelOrderTraversal(treeNode *root, string &chk, int k)
{
    int count = 0;
    int maxValue = 0;
    if (root == NULL)
        return -1;

    queue<treeNode *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        treeNode *chkNode = q.front();
        q.pop();

        if (chkNode != NULL)
        {
            chk += to_string(chkNode->data);
            if (count == k)
            {
                maxValue = max(maxValue, chkNode->data);
            }

            if (chkNode->leftChild != NULL)
            {
                q.push(chkNode->leftChild);
            }
            if (chkNode->rightChild != NULL)
            {
                q.push(chkNode->rightChild);
            }
        }
        else
        {
            if (!q.empty())
            {
                q.push(NULL);
                count++;
            }
        }
    }
    return maxValue;
}

int searchInOrder(int *InOrder, int current, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        if (InOrder[i] == current)
        {
            return i;
        }
    }
    return -1;
}

treeNode *buildTreePreIn(int *PreOrder, int *InOrder, int start, int end)
{
    static int id = 0;

    int current = PreOrder[id];
    id++;
    treeNode *newNode = new treeNode(current);

    if (start == end)
    {
        return newNode;
    }
    // end->   8 2 0 2 8 6 4 6 8
    // start-> 0 0 0 2 4 4 4 6 8
    // id->    0 1 2 3 4 5 6 7 8
    // position 3 1 7 5
    int pos = searchInOrder(InOrder, current, start, end);

    newNode->leftChild = buildTreePreIn(PreOrder, InOrder, start, pos - 1);
    newNode->rightChild = buildTreePreIn(PreOrder, InOrder, pos + 1, end);

    return newNode;
}

void printLeaves(treeNode *root)
{
    if (root == NULL)
        return;
    if (root->leftChild == NULL && root->rightChild == NULL)
    {
        cout << root->data << " ";
        return;
    }
    printLeaves(root->leftChild);

    printLeaves(root->rightChild);
}
void printLeftNoneLeaves(treeNode *root)
{
    if (root == NULL)
        return;
    if (root->leftChild != NULL)
    {
        cout << root->data << " ";
        printLeftNoneLeaves(root->leftChild);
    }
    else if (root->rightChild != NULL)
    {
        cout << root->data << " ";
        printLeftNoneLeaves(root->rightChild);
    }
}
void printRightNoneLeaves(treeNode *root)
{
    if (root == NULL)
        return;
    if (root->rightChild != NULL)
    {
        cout << root->data << " ";
        printLeftNoneLeaves(root->rightChild);
    }
    else if (root->leftChild != NULL)
    {
        cout << root->data << " ";
        printLeftNoneLeaves(root->leftChild);
    }
}

void boundaryTraversal(treeNode *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    // LB None-leaves
    printLeftNoneLeaves(root->leftChild);
    // LB Leaves
    printLeaves(root->leftChild);
    // RB Leaves
    printLeaves(root->rightChild);
    // RB None-leaves
    printRightNoneLeaves(root->rightChild);
}

int main()
{
    // int n;
    // cin >> n;
    // int PreOrder[n], InOrder[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> PreOrder[i];
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> InOrder[i];
    // }
    // string preStr = "";
    // treeNode *root = buildTreePreIn(PreOrder, InOrder, 0, n - 1);
    // preOrder(root, preStr);
    // cout << preStr;

    ///////////
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

    boundaryTraversal(allNodes[0]);

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
