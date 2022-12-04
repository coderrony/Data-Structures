#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

void insert_node(Node *&head, int value)
{
    Node *temp = head;
    Node *newNode = new Node(value);
    if (temp == NULL)
    {
        head = newNode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
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

Node *reverseKNode(Node *&head, int position)
{
    Node *temp = head;

    int i = 1;
    while (i < position)
    {
        temp = temp->next;
        i++;
    }
    Node *revNode = reverse_node(head);
    Node *lastNode = revNode;
    Node *returnNode = temp;

    while (revNode->next != temp)
    {
        revNode = revNode->next;
    }
    revNode->next = NULL;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = lastNode;

    return returnNode;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value;
        if (temp->next != NULL)
            cout << "->";
        temp = temp->next;
    }
}

int main()
{

    Node *head = NULL;
    int n, value, k;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        insert_node(head, value);
    }
    cin >> k;

    head = reverseKNode(head, k);
    display(head);

    return 0;
}