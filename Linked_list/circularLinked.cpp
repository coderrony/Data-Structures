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

int count_total_node(Node *&head);
void insert_At_head(Node *&head, int value);
void insert_At_tail(Node *&head, int value);
void delete_head(Node *&head);
void delete_tail(Node *&head);
void insert_At_specific_position(Node *&head, int position, int value);
void delete_at_specific_position(Node *&head, int position);

void insert_At_head(Node *&head, int value)
{
    Node *newNode = new Node(value);
    Node *temp = head;

    if (temp == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    while (temp->next != head)
    {
        temp = temp->next;
    }
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}
void insert_At_tail(Node *&head, int value)
{
    Node *newNode = new Node(value);
    Node *temp = head;
    if (temp == NULL)
    {

        head = newNode;
        newNode->next = head;
        return;
    }

    while (temp->next != head)
    {
        temp = temp->next;
    }
    newNode->next = head;
    temp->next = newNode;
}

void insert_At_specific_position(Node *&head, int position, int value)
{
    Node *temp = head;
    Node *newNode = new Node(value);
    int i = 1;

    if (position == 1)
    {
        insert_At_head(head, value);
        return;
    }

    if (position < 1)
    {
        cout << "invalid position" << endl;
        return;
    }

    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }

    if (temp->next == head)
    {
        temp->next = newNode;
        newNode->next = head;
    }
    else
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void delete_head(Node *&head)
{
    Node *temp = head;
    Node *deleHead = head;
    if (temp == NULL)
    {
        cout << "empty linked list" << endl;
        return;
    }

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = deleHead->next;
    head = deleHead->next;
    delete (deleHead);
}

void delete_tail(Node *&head)
{
    Node *temp = head;

    if (temp == NULL)
    {
        cout << "empty linked list" << endl;
        return;
    }
    if (temp->next == head)
    {
        head = NULL;
        delete (temp);
        return;
    }

    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    Node *deleHead = temp->next;
    temp->next = head;
    delete (deleHead);
}

int count_total_node(Node *&head)
{
    int count = 0;
    Node *temp = head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

void delete_at_specific_position(Node *&head, int position)
{
    Node *temp = head;
    int i = 1;
    if (head == NULL)
    {
        cout << "Empty file" << endl;
        return;
    }

    if (position == 1)
    {
        delete_head(head);
        return;
    }

    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }

    Node *deleNode = temp->next;
    if (temp->next->next == head)
    {
        temp->next = head;
    }
    else
    {
        temp->next = deleNode->next;
    }
    delete (deleNode);
}

void display_node(Node *&head)
{
    Node *temp = head;
    if (temp == NULL)
    {
        cout << "empty linked list" << endl;
        return;
    }

    do
    {
        cout << temp->data;
        if (temp->next != head)
            cout << " -> ";
        temp = temp->next;
    } while (temp != head);
}

int main()
{
    Node *head = NULL;
    int choose, position, value, save, total_node;
    cout << "choose 1: insert At head " << endl;
    cout << "choose 2: insert At tail " << endl;
    cout << "choose 3: insert At Specific position " << endl;
    cout << "choose 4: deletion at head " << endl;
    cout << "choose 5: deletion at tail " << endl;
    cout << "choose 6: deletion at specific position " << endl;
    cout << "choose 7: deletion by value (Unique list) " << endl;
    while (1)
    {

        cout << "Next Choose: ";
        cin >> choose;
        if (choose == 0)
            break;
        switch (choose)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> value;
            insert_At_head(head, value);
            break;
        case 2:
            cout << "Enter the value: ";
            cin >> value;
            insert_At_tail(head, value);
            break;
        case 3:

            cout << "Enter the position: ";
            cin >> position;
            cout << "Enter the value: ";
            cin >> value;
            insert_At_specific_position(head, position, value);

            break;
        case 4:
            delete_tail(head);
            break;
        case 5:
            delete_tail(head);
            break;
        case 6:
            cout << "Enter the position: ";
            cin >> position;
            delete_at_specific_position(head, position);
            break;
        default:
            break;
        }
    }

    display_node(head);
    cout << endl;
    // cout << count_total_node(head) << endl;
    return 0;
}