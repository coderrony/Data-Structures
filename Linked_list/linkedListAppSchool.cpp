#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

void insertAtTail(Node *&head, int val);
void insertAtHead(Node *&head, int val);
int findLength(Node *&head);
void insertRandom(Node *&head, int position, int val);

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

bool searching(Node *head, int key)
{
    Node *tem = head;
    while (tem != NULL)
    {
        if (tem->data == key)
        {
            return true;
        }
        tem = tem->next;
    }

    return false;
}

void remove_node_by_value(Node *&head, int val) // remove node ny value
{
    Node *tem = head;
    Node *prev = NULL;

    if (tem->next != NULL && tem->data == val)
    {
        head = tem->next;
        delete (tem);
        return;
    }
    else
    {
        while (tem->next != NULL && tem->data != val)
        {
            prev = tem;
            tem = tem->next;
        }

        if (tem == NULL)
            return;

        prev->next = tem->next;
        delete (tem);
        return;
    }
}
void remove_node_by_position(Node *&head, int position) // remove node by position
{
    int len = findLength(head);
    int i = 1;
    Node *tem = head;
    Node *prev = NULL;
    if (position < 1 || position > len)
    {
        return;
    }
    if (position == 1)
    {
        head = tem->next;
        delete (tem);
        return;
    }

    while (i < position)
    {
        prev = tem;
        tem = tem->next;
        i++;
    }
    if (len == position)
    {
        prev->next = NULL;
        delete (tem);
        return;
    }
    prev->next = tem->next;
    delete (tem);
    return;
}
int findLength(Node *&head)
{
    int i = 0;
    Node *tem = head;
    while (tem != NULL)
    {
        i++;
        tem = tem->next;
    }
    return i;
}
void insertRandom(Node *&head, int position, int val)
{

    int length = findLength(head);
    if (position == 1)
    {
        insertAtHead(head, val);
        return;
    }

    if (position < 1 || position > length)
    {
        return;
    }
    if (position == length)
    {
        insertAtTail(head, val);
        return;
    }

    Node *temp = head;
    int i = 0;
    while (i < position - 2)
    {
        temp = temp->next;
        i++;
    }

    Node *newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

void display(Node *head)
{

    Node *tem = head;
    while (tem != NULL)
    {
        cout << tem->data << " -> ";
        tem = tem->next;
    }
    cout << "NULL" << endl;
}
void reversedListPrint(Node *node)
{
    if (node == NULL)
        return;
    reversedListPrint(node->next);
    cout << node->data << " <- ";
}

Node *reverse_node(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;
    if (current == NULL)
        return current;
    Node *next = current->next;

    while (1)
    {
        current->next = prev;
        prev = current;
        current = next;
        if (current == NULL)
            break;
        next = next->next;
    }
    return prev;
}

Node *recursive_reverse_node(Node *&head)
{
    Node *temp = head;
    if (temp == NULL || temp->next == NULL)
        return temp;

    Node *headNode = recursive_reverse_node(temp->next);
    temp->next->next = temp;
    temp->next = NULL;
    return headNode;
}

int main()
{
    Node *head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    head = recursive_reverse_node(head);

    // remove_node_by_value(head, 10);

    // insertRandom(head, 4, 100);
    // insertRandom(head, 5, 200);
    // insertRandom(head, 2, 2000);
    // remove_node_by_value(head, 100);
    // remove_node_by_position(head, 1);
    // remove_node_by_position(head, 6);
    display(head);
}