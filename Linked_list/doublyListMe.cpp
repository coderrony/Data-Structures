
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

class DuplicatePosition
{
public:
    int *position = new int[100];
};

int size_of_node(doublyNode *&head);
void display_node(doublyNode *&head);
void insert_At_head(doublyNode *&head, int value);
void insert_At_tail(doublyNode *&head, int value);
void insert_at_specific_position(doublyNode *&head, int position, int value);
void display_reverse(doublyNode *&head);
int search_value(doublyNode *&head, int value);
DuplicatePosition duplicate_value(doublyNode *&head, int value);
void insert_after_specific_value(doublyNode *&head, int searchValue, int value);
void insert_after_duplicate_value(doublyNode *&head, int searchValue, int value);

void delete_at_head(doublyNode *&head);
void delete_at_tail(doublyNode *&head);
void delete_at_specific_position(doublyNode *&head, int position);
void delete_by_value(doublyNode *&head, int value);
void delete_by_duplicate_value(doublyNode *&head, int value);

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

void insert_At_head(doublyNode *&head, int value)
{
    doublyNode *newNode = new doublyNode(value);

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insert_At_tail(doublyNode *&head, int value)
{
    doublyNode *temp = head;
    doublyNode *newNode = new doublyNode(value);
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

void insert_at_specific_position(doublyNode *&head, int position, int value)
{
    doublyNode *temp = head;
    doublyNode *newNode = new doublyNode(value);
    int length = size_of_node(head);
    int i = 1;

    if (position < 1 || position > length)
    {
        cout << "this position is not present yet at the node" << endl;
        return;
    }
    if (position == 1)
    {
        head = newNode;
        head->next = temp;
        temp->prev = head;

        // newNode->next = head;
        // head->prev = newNode;
        // head = newNode;
        return;
    }

    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next->prev = newNode;
    newNode->prev = temp;
    temp->next = newNode;
}

int search_value(doublyNode *&head, int value)
{
    doublyNode *temp = head;
    int count = 1;
    while (temp != NULL)
    {
        if (temp->value == value)
        {
            return count;
        }
        count++;
        temp = temp->next;
    }
    return -1;
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

DuplicatePosition duplicate_value(doublyNode *&head, int value)
{

    doublyNode *temp = head;
    DuplicatePosition save;

    int count = 1, k = 1;

    while (temp != NULL)
    {
        if (temp->value == value)
        {
            save.position[k] = count;
            k++;
        }
        count++;
        temp = temp->next;
    }

    save.position[0] = k;
    return save;
}

void insert_after_specific_value(doublyNode *&head, int searchValue, int value)
{
    int save = search_value(head, searchValue);
    int length = size_of_node(head);

    if (save == -1)
    {
        cout << "This value is not present in the list" << endl;
        return;
    }

    if (save == length)
    {
        insert_At_tail(head, value);
    }
    else
    {
        insert_at_specific_position(head, save + 1, value);
    }
}

void insert_after_duplicate_value(doublyNode *&head, int searchValue, int value)
{
    DuplicatePosition save = duplicate_value(head, searchValue);
    int size = save.position[0];
    int length, checkVal;

    if (size == 1)
    {
        cout << "invalid value" << endl;
        return;
    }

    for (int i = 1; i < size; i++)
    {
        checkVal = save.position[i] + i;
        length = size_of_node(head);
        if (length < checkVal)
        {
            insert_At_tail(head, value);
        }
        else
        {
            insert_at_specific_position(head, checkVal, value);
        }
    }
}

void delete_at_head(doublyNode *&head)
{
    doublyNode *temp = head;
    head = temp->next;
    head->prev = NULL;
    cout << "delete head node successfully" << endl;
    delete (temp);
}

void delete_at_tail(doublyNode *&head)
{
    doublyNode *temp = head;
    int length = size_of_node(head);
    if (length == 0)
    {
        cout << "Empty linked list" << endl;
        return;
    }

    if (temp->next == NULL)
    {

        head = temp->next;
        cout << "delete head node successfully" << endl;
        delete (temp);
        return;
    }

    while (temp->next->next != NULL)
    {

        temp = temp->next;
    }

    temp->next = NULL;
    delete (temp->next);
    cout << "Deleted Tail node successfully" << endl;
    return;
}

void delete_at_specific_position(doublyNode *&head, int position)
{
    doublyNode *temp = head;
    doublyNode *prev = NULL;
    int length = size_of_node(head);
    int i = 1;
    if (position < 1 || position > length)
    {
        cout << "Invalid position" << endl;
        return;
    }
    if (position == 1)
    {
        delete_at_head(head);
        return;
    }
    if (position == length)
    {
        delete_at_tail(head);
        return;
    }
    while (i < position)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }

    prev->next = temp->next;
    temp->next->prev = prev;

    delete (temp);

    cout << "delete successfully" << endl;
    return;
}

void delete_by_value(doublyNode *&head, int value)
{
    int save = search_value(head, value);
    delete_at_specific_position(head, save);
}

void delete_by_duplicate_value(doublyNode *&head, int value)
{
    DuplicatePosition save = duplicate_value(head, value);
    if (save.position[0] != 1)
    {
        for (int i = 1; i < save.position[0]; i++)
        {
            delete_at_specific_position(head, save.position[i]);
            int j = i;
            while (j < save.position[0])
            {
                save.position[j + 1]--;
                j++;
            }
        }
    }
}

int main()
{
    int choose, position, value, save;
    doublyNode *head = NULL;
    DuplicatePosition store;
    cout << "choose 1: insert At head " << endl;
    cout << "choose 2: insert At tail " << endl;
    cout << "choose 3: insert at the specific position " << endl;
    cout << "choose 4: reverse node " << endl;
    cout << "choose 5: search a value (unique list) " << endl;
    cout << "choose 6: search duplicate value int the list " << endl;
    cout << "choose 7: insert at the after specific position " << endl;
    cout << "choose 8: insert at the after duplicate position " << endl;
    cout << "choose 9: delete head node " << endl;
    cout << "choose 10: delete tail node " << endl;
    cout << "choose 11: delete specific position" << endl;
    cout << "choose 12: delete by value " << endl;
    cout << "choose 13: delete duplicate value " << endl;
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
            cout << "Enter the position: ";
            cin >> position;
            cout << "Enter the value: ";
            cin >> value;
            insert_at_specific_position(head, position, value);
            break;
        case 4:
            display_reverse(head);
            break;
        case 5:
            cout << "Enter the value: ";
            cin >> value;

            save = search_value(head, value);
            if (save != -1)
            {
                cout << "node position is " << save << endl;
            }
            else
            {
                cout << "this value is not present in the list" << endl;
            }

            break;
        case 6:
            cout << "Enter the search value: ";
            cin >> value;

            store = duplicate_value(head, value);
            if (store.position[0] == 1)
            {
                cout << "invalid value" << endl;
            }
            else
            {
                cout << "position value is ";
                for (int i = 1; i < store.position[0]; i++)
                {
                    cout << store.position[i] << " ";
                }
                cout << endl;
            }
            break;
        case 7:
            cout << "Enter the search value: ";
            cin >> position;
            cout << "Enter the value: ";
            cin >> value;
            insert_after_specific_value(head, position, value);
            break;
        case 8:
            cout << "Enter the search value: ";
            cin >> position;
            cout << "Enter the value: ";
            cin >> value;
            insert_after_duplicate_value(head, position, value);
            break;
        case 9:
            delete_at_head(head);
            break;
        case 10:
            delete_at_tail(head);
            break;
        case 11:
            cout << "enter the position: ";
            cin >> position;
            delete_at_specific_position(head, position);
            break;
        case 12:
            cout << "enter the value: ";
            cin >> value;
            delete_by_value(head, value);

            break;
        case 13:
            cout << "enter the value: ";
            cin >> value;
            delete_by_duplicate_value(head, value);

            break;
        default:
            break;
        }
    }
    display_node(head);
    return 0;
}
