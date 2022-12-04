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

    if (root->leftChild != NULL)
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

int main()
{

    // printTree(allNodes[0], 0);

    string strPre = "";
    string strPost = "";
    string strIn = "";
    string traverseByLevel = "";
    // preOrder(allNodes[0], strPre);
    // postOrder(allNodes[0], strPost);
    // inOrder(allNodes[0], strIn);
    // int maxValue = levelOrderTraversal(allNodes[0], traverseByLevel, 2);
    // cout << maxValue << " " << traverseByLevel;

    cout << "pre order: " << strPre << endl;
    cout << "post order: " << strPost << endl;
    cout << "in order: " << strIn << endl;
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
