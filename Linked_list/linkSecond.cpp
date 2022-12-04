#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;

    // constructor creation
    Node(int val)
    {
        value = val;
        Next = NULL;
    }
};

// struct Test
// {
//     int position[1000];
// };
class Test
{
public:
    int position[1000];
};

void insertAtTail(Node *&head, int val);
void insertAtHead(Node *&head, int val);
int countLength(Node *&head);
void insertAtSpecificPosition(Node *&head, int position, int val);
int searchByValueUnique(Node *&head, int key);
void searchByValueDuplicate(Node *&head, int key);
void insertByValue(Node *&head, int value, int key);
void insertByValueUnique(Node *&head, int searchValue, int value);
void insertValueByDuplicate(Node *&head, int searchValue, int value);
void remove_node_by_value(Node *&head, int position);
void remove_duplicate_value(Node *&head, int value);

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
}

void insertAtHead(Node *&head, int val)
{
    // s1: newNode Creation
    Node *newNode = new Node(val);

    // s2:update of newNOde -> Next;
    newNode->Next = head;
    // s3: update of head
    head = newNode;
}
int countLength(Node *&head)

{
    int count = 0;
    Node *tem = head;
    while (tem != NULL)
    {
        count++;
        tem = tem->Next;
    }
    return count;
}
void insertAtSpecificPosition(Node *&head, int position, int val)
{

    int len = countLength(head);
    if (len < position)
    {
        cout << "This position is not available" << endl;
        return;
    }

    int i = 0;
    Node *temp = head;
    while (i < position - 2)
    {
        temp = temp->Next;
        i++;
    }
    Node *newNode = new Node(val);
    newNode->Next = temp->Next;
    temp->Next = newNode;
}
int searchByValueUnique(Node *&head, int key)
{
    int count = 1;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            return count;
        }
        count++;
        temp = temp->Next;
    }
    return -1;
}
void searchByValueDuplicate(Node *&head, int key)
{
    Node *temp = head;
    int size = countLength(head);
    int position[size + 1];
    int k = 1;
    int count = 1;
    int flag = 0;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            // cout << count << " ";
            position[k] = count;
            k++;
            flag = 1;
        }
        temp = temp->Next;
        count++;
    }
    cout << endl;
    if (flag == 0)
    {
        cout << "the search value not found yet in the list";
    }
    else
    {
        position[0] = k;
        cout << "The value is found at position: ";
        for (int i = 1; i < position[0]; i++)
        {
            cout << position[i];
            if (position[0] - 1 > i)
            {
                cout << ",";
            }
        }
    }
}
Test searchValueDuplicateReturn(Node *&head, int key)
{
    Node *temp = head;
    Test t;

    int k = 1;
    int count = 1;

    while (temp != NULL)
    {
        if (temp->value == key)
        {
            t.position[k] = count;
            k++;
        }
        temp = temp->Next;
        count++;
    }

    t.position[0] = k;

    return t;
}
void remove_node(Node *&head, int position) // remove node by position
{
    int len = countLength(head);
    int i = 1;
    Node *temp = head;
    Node *prev = NULL;

    if (len == 0)
    {
        cout << "there is no value in the linked list!!" << endl;
        return;
    }
    if (position < 1 || position > len)
    {
        cout << "This position is not present yet in the node" << endl;
        return;
    }

    if (position == 1)
    {
        head = temp->Next;
        delete (temp);
        return;
    }
    while (i < position)
    {
        prev = temp;
        temp = temp->Next;
        i++;
    }
    if (len == position)
    {

        prev->Next = NULL;
        delete (temp);
        return;
    }

    prev->Next = temp->Next;
    delete (temp);
    return;
}
void insertByValueUnique(Node *&head, int searchValue, int value)
{

    int position = searchByValueUnique(head, searchValue);
    insertAtSpecificPosition(head, position + 1, value);
}
void insertValueByDuplicate(Node *&head, int searchValue, int value)
{
    Test save = searchValueDuplicateReturn(head, searchValue);

    if (save.position[0] != 1)
    {
        for (int i = 1; i < save.position[0]; i++)
        {
            insertAtSpecificPosition(head, save.position[i] + i, value);
        }
        return;
    }
}

void insertByValue(Node *&head, int key, int value) // insert value by forward direction on the node
{
    Test save = searchValueDuplicateReturn(head, key);

    if (save.position[0] != 1)
    {
        for (int i = 1; i < save.position[0]; i++)
        {
            insertAtSpecificPosition(head, save.position[i], value);
        }
    }

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->value == key)
        {
            break;
        }
        temp = temp->Next;
    }
    if (temp == NULL)
        cout << "value not present!!" << endl;
    return;
    Node *newNode = new Node(value);
    newNode->Next = temp->Next;
    temp->Next = newNode;
}

void remove_node_by_value(Node *&head, int value)
{

    // find the position of the value
    int position = searchByValueUnique(head, value);
    // delete the node at that value
    if (position == -1)
        return;
    remove_node(head, position);
}
void remove_duplicate_value(Node *&head, int value)
{
    Test save = searchValueDuplicateReturn(head, value);

    if (save.position[0] != 1)
    {
        for (int i = 1; i < save.position[0]; i++)
        {

            remove_node(head, save.position[i]);
            if (i >= 1)
            {
                for (int j = i + 1; j < save.position[0]; j++)
                {
                    save.position[j]--;
                }
            }
        }
        return;
    }
}
void display(Node *node)
{

    Node *tem = node;
    while (tem != NULL)
    {
        cout << tem->value << " -> ";
        tem = tem->Next;
    }
    cout << "NULL";
}
int main()
{

    Node *head = NULL;
    int n, position;
    int choice = 2;
    cout << "Choice 1: insertion at head" << endl
         << "Choice 2: insertion at tail" << endl
         << "Choice 3: insertion specific postion" << endl
         << "Choice 4: search a value (unique list)" << endl
         << "Choice 5: remove node by position" << endl
         << "Choice 6: search  duplicate value" << endl
         << "Choice 7: insertion specific value after duplicate" << endl
         << "Choice 8: remove node by value" << endl
         << "Choice 9: remove node by duplicate value" << endl
         << "Chose 0: exit" << endl;
    while (choice != 0)
    {
        cout << "Next Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> n;
            insertAtHead(head, n);
            break;
        case 2:
            cout << "Enter the value: ";
            cin >> n;
            insertAtTail(head, n);
            break;
        case 3:
            cout << "Enter the desired position: ";
            cin >> position;
            cout << "Enter the value: ";
            cin >> n;
            insertAtSpecificPosition(head, position, n);
            break;
        case 4:

            cout << "Enter the value to search: ";
            cin >> n;
            position = searchByValueUnique(head, n);
            if (position != -1)
            {
                cout << "number of the position " << position << endl;
            }
            else
            {
                cout << "the number is not yet in the list" << endl;
            }
            break;
        case 5:
            cout << "Enter the position you remove: ";
            cin >> position;
            remove_node(head, position);
            break;
        case 6:
            cout << "enter the value to search: ";
            cin >> n;

            // searchByValueDuplicate(head, n);
            Test T;
            T = searchValueDuplicateReturn(head, n);

            if (T.position[0] == 1)
            {
                cout << "the search value not found yet in the list";
            }
            else
            {

                cout << "the value found at position: ";
                for (int i = 1; i < T.position[0]; i++)
                {
                    cout << T.position[i] << " ";
                }
                cout << endl;
            }

            cout << endl;
            break;
        case 7:
            cout << "Enter the value to search: ";
            cin >> position;
            cout << "Enter insert the value: ";
            cin >> n;
            insertValueByDuplicate(head, position, n);
            break;
        case 8:
            cout << "Enter the value you remove: ";
            cin >> position;
            remove_node_by_value(head, position);
            break;
        case 9:
            cout << "Enter the duplicate value you want to remove: ";
            cin >> position;
            remove_duplicate_value(head, position);
            break;
        default:
            break;
        }
    }
    cout << endl;

    display(head);

    return 0;
}