#include <bits/stdc++.h>
using namespace std;

class doublyNode
{
public:
    int value;
    doublyNode *prev;
    doublyNode *next;

    doublyNode(int val)
    {
        this->value = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insert_At_head(doublyNode *&head, int value);
void insert_At_tail(doublyNode *&head, int value);
void display_node(doublyNode *&head);
int size_of_node(doublyNode *&head);

bool isSorted(doublyNode *&head, int size);

void insert_At_head(doublyNode *&head, int value)
{
    doublyNode *newNode = new doublyNode(value);

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    // newNode->prev = head;
}

void insert_At_tail(doublyNode *&head, int value)
{
    doublyNode *newNode = new doublyNode(value);
    doublyNode *temp = head;
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
    newNode->prev = temp;
}
void reverseOrderStore(doublyNode *&head, int value)
{
    doublyNode *newNode = new doublyNode(value);
    doublyNode *temp = head;
    if (temp == NULL)
    {
        head = newNode;
        return;
    }

    while (temp->prev != NULL)
    {
        temp = temp->prev;
    }
    temp->prev = newNode;
    newNode->next = temp;
    head = newNode;
}

void display_node(doublyNode *&head)
{
    doublyNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void display_reverse(doublyNode *&head)
{
    doublyNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        cout << temp->value;
        if (temp->prev != NULL)
            cout << "<-";
        temp = temp->prev;
    }
    cout << "<-NULL" << endl;
}

int size_of_node(doublyNode *&head)
{
    int i = 0;
    doublyNode *temp = head;
    while (temp != NULL)
    {
        i++;
        temp = temp->next;
    }

    return i;
}

int main()
{
    int choose, position, value, save;
    doublyNode *head = NULL;

    cout << "choose 1: insert At head " << endl;
    cout << "choose 2: insert At tail " << endl;
    cout << "choose 3: reverse print node " << endl;
    cout << "choose 0: Exit" << endl;

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
            display_reverse(head);
            break;

        default:
            break;
        }
    }
    display_node(head);
}

// 2
// 8
// 2
// 5
// 2
// 7
// 2
// 1
// 2
// 9