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

void inOrder(treeNode *root, string &chk);

///////////BST
treeNode *insertionBst(treeNode *root, int value);
treeNode *searchBst(treeNode *root, int value);
treeNode *deletionBst(treeNode *root, int value);

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
    chk += to_string(root->data) + " ";
    if (root->rightChild != NULL)
    {
        inOrder(root->rightChild, chk);
    }
    return;
}

treeNode *insertionBst(treeNode *root, int value)
{
    treeNode *newNode = new treeNode(value);
    if (root == NULL)
    {

        root = newNode;
        return root;
    }

    if (root->data > value) // value<root->date
    {
        root->leftChild = insertionBst(root->leftChild, value);
    }
    else if (root->data < value) // value > root->data
    {
        root->rightChild = insertionBst(root->rightChild, value);
    }

    return root;
}

treeNode *searchBst(treeNode *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == value)
    {
        cout << root->data << " ";
        return root;
    }

    if (root->data > value)
    {
        cout << root->data << "->";
        searchBst(root->leftChild, value);
    }
    else if (root->data < value)
    {
        cout << root->data << "->";
        searchBst(root->rightChild, value);
    }
}

treeNode *inOrderSucc(treeNode *root)
{
    treeNode *current = root;
    while (current->leftChild != NULL)
    {
        current = current->leftChild;
    }
    return current;
}

treeNode *deletionBst(treeNode *root, int value)
{
    // case 1 leaf node
    // case 2 if have one child
    // case 3 if have two child

    if (value < root->data)
    {
        root->leftChild = deletionBst(root->leftChild, value);
    }
    else if (value > root->data)
    {
        root->rightChild = deletionBst(root->rightChild, value);
    }
    else
    {
        if (root->leftChild == NULL)
        {
            treeNode *temp = root->rightChild;
            free(root);
            return temp;
        }
        else if (root->rightChild == NULL)
        {
            treeNode *temp = root->leftChild;
            free(root);
            return temp;
        }
        else
        {
            treeNode *temp = inOrderSucc(root->rightChild);
            root->data = temp->data;
            root->rightChild = deletionBst(root->rightChild, temp->data);
        }
    }

    return root;
}

void zigzagTraversal(treeNode *root)
{
    stack<treeNode *> currenStack;
    stack<treeNode *> nextStack;
    currenStack.push(root);
    bool flag = true;
    while (!currenStack.empty())
    {
        treeNode *curr = currenStack.top();
        currenStack.pop();

        if (curr)
        {
            cout << curr->data << " ";
            if (flag)
            {
                if (curr->leftChild != NULL)
                {
                    nextStack.push(curr->leftChild);
                }
                if (curr->rightChild != NULL)
                {
                    nextStack.push(curr->rightChild);
                }
            }
            else
            {
                if (curr->rightChild != NULL)
                {
                    nextStack.push(curr->rightChild);
                }
                if (curr->leftChild != NULL)
                {
                    nextStack.push(curr->leftChild);
                }
            }
        }

        if (currenStack.empty())
        {
            flag = !flag;
            swap(currenStack, nextStack);
        }
    }
}

int main()
{

    int n;
    cin >> n;
    treeNode *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        root = insertionBst(root, value);
    }

    string s = "";
    inOrder(root, s);
    cout << s << endl;
    zigzagTraversal(root);

    return 0;
}

/*

9
11 5 4 43 34 1 2 7 21

7
9 3 1 7 4 8 5

9
0 1 3 4 2 5 7 8 6
3 1 4 0 7 5 8 2 6





*/
