#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string str;
    Node *next;
    Node *prev;
    Node(string str)
    {
        this->str = " " + str;
        this->next = NULL;
        this->prev = NULL;
    }
};

void push(Node *&head, string str)
{
    Node *newNode = new Node(str);

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    head->next = newNode;
    newNode->prev = head;
    head = newNode;
}
string pop(Node *&head)
{
    Node *deleNode = head;
    string save = deleNode->str;
    if (head == NULL)
    {
        return "-1";
    }
    if (head->prev == NULL)
    {

        delete (head);
        return save;
    }
    head = deleNode->prev;
    head->next = NULL;
    delete (deleNode);
    return save;
}
int main()
{

    Node *head = NULL;

    push(head, "rony");
    push(head, "bjoy");
    push(head, "ali");

    cout << pop(head) << endl;
    cout << pop(head) << endl;
    cout << pop(head) << endl;

    return 0;
}