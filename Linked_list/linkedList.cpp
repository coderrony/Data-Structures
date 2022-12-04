#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;
};
void display(Node *node)
{
    while (node != NULL)
    {
        cout << node->value << endl;

        node = node->Next;
    }
}
int main()
{

    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;
    Node *middle = new Node;

    head->value = 1;
    head->Next = second;
    second->value = 2;

    second->Next = third;
    third->value = 3;
    third->Next = fourth;
    fourth->value = 4;
    fourth->Next = NULL;

    cout << head->Next->Next->value << endl;
    display(head);
    return 0;
}