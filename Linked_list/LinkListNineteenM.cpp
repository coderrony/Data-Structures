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
class duplicateValue
{
public:
    int position[1000];
};

int count_total_node(Node *&head);
void display_node(Node *&head);
void insert_At_head(Node *&head, int value);
void insert_At_tail(Node *&head, int value);
void insert_At_specific_position(Node *&head, int position, int value);
int search_value(Node *&head, int value);
duplicateValue search_duplicate_value(Node *&head, int value);
void insert_after_specific_value(Node *&head, int position, int value);
void insert_after_duplicate_value(Node *&head, int position, int value);
void insert_duplicate(Node *&head, int position, int value); // this function insert value after duplicate value its work for insert_after_duplicate_value() function.
void delete_At_head(Node *&head);
void delete_At_tail(Node *&head);
void delete_At_specific_position(Node *&head, int position);
void delete_At_specific_value(Node *&head, int value);
void delete_At_duplicate_value(Node *&head, int value);
Node *reverseByStack(Node *&head);

// module 19 link list
Node *reverseNoneRecursive(Node *&head);
Node *reverse_recursive(Node *&head);

// module 21 advance linked list
int findMid(Node *&head);
void makeCycle(Node *&head);
bool detect_cycle(Node *&head);
void remove_cycle(Node *&head);

int count_total_node(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void display_node(Node *&head)
{

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    // if (head == NULL)
    // {
    //     cout << "there is no node" << endl;
    //     return;
    // }
    // Node *temp = head;
    // do
    // {
    //     cout << temp->data;
    //     temp = temp->next;
    //     if (temp != head)
    //     {
    //         cout << " -> ";
    //     }
    // } while (temp != head);
}

void insert_At_head(Node *&head, int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void insert_At_tail(Node *&head, int value)
{
    Node *newNode = new Node(value);
    Node *temp = head;
    if (head == NULL)
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

void insert_At_specific_position(Node *&head, int position, int value)
{
    int node_length = count_total_node(head);
    Node *newNode = new Node(value);
    Node *temp = head;
    int i = 1;
    if (position > node_length || position < 1)
    {
        cout << "this position not present yet in the list" << endl;
        return;
    }
    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    while (i < position - 1)
    {

        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return;
}

int search_value(Node *&head, int value)
{
    Node *temp = head;
    int i = 1;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return i;
        }
        temp = temp->next;
        i++;
    }
    return -1;
}

duplicateValue search_duplicate_value(Node *&head, int value)
{
    duplicateValue save;
    int i = 1, count = 1;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            save.position[i] = count;
            i++;
        }
        temp = temp->next;
        count++;
    }

    save.position[0] = i;
    return save;
}

void insert_after_specific_value(Node *&head, int position, int value)
{
    int length = count_total_node(head);
    int save = search_value(head, position);
    if (length == save)
    {

        insert_At_tail(head, value);
    }
    else
    {
        insert_At_specific_position(head, save + 1, value);
    }
}

void insert_after_duplicate_value(Node *&head, int position, int value)
{
    duplicateValue save = search_duplicate_value(head, position);

    if (save.position[0] != 1)
    {
        for (int i = 1; i < save.position[0]; i++)
        {
            insert_duplicate(head, save.position[i] + i, value);
        }

        return;
    }
}

void insert_duplicate(Node *&head, int position, int value)
{
    int save = search_value(head, value);
    int i = 1;
    Node *temp = head;
    Node *newNode = new Node(value);
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }

    if (temp->next == NULL)
    {
        insert_At_tail(head, value);
        return;
    }
    else
    {
        newNode->next = temp->next;
        temp->next = newNode;
        return;
    }
}

void delete_At_head(Node *&head)
{
    Node *temp = head;
    head = temp->next;
    delete (temp);

    cout << "Delete Head Node Successfully" << endl;
    return;
}

void delete_At_tail(Node *&head)
{
    int length = count_total_node(head);
    if (length == 0)
    {
        cout << "there are no node available" << endl;
        return;
    }
    Node *temp = head;
    Node *prev = NULL;
    if (temp->next == NULL)
    {
        cout << "Delete head node in Tail  Successfully" << endl;

        head = temp->next;
        delete (temp);
        return;
    }
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    delete (temp);
    cout << "Delete Tail Node Successfully" << endl;
    return;
}

void delete_At_specific_position(Node *&head, int position)
{
    Node *temp = head;
    Node *prev = NULL;
    int i = 1;
    int length = count_total_node(head);

    if (position < 1 || position > length)
    {
        cout << "This position is not available" << endl;
        return;
    }

    if (position == 1)
    {
        delete_At_head(head);
        return;
    }
    if (position == length)
    {
        delete_At_tail(head);
        return;
    }

    while (i < position)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }

    prev->next = temp->next;
    delete (temp);
    return;
}

void delete_At_specific_value(Node *&head, int value)
{
    int save = search_value(head, value);
    delete_At_specific_position(head, save);
}

void delete_At_duplicate_value(Node *&head, int value)
{
    duplicateValue save = search_duplicate_value(head, value);

    if (save.position[0] != 1)
    {
        for (int i = 1; i < save.position[0]; i++)
        {
            delete_At_specific_position(head, save.position[i]);

            int j = i;
            while (j < save.position[0])
            {
                save.position[j + 1]--;
                j++;
            }
        }
    }
}

// module 19 link list
Node *reverseNoneRecursive(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;
    if (head == NULL)
    {
        cout << "the listed is empty" << endl;
        return head;
    }

    Node *next = head->next;

    while (1)
    {
        current->next = prev;
        prev = current;
        current = next;
        if (current == NULL)
        {
            break;
        }

        next = next->next;
    }
    return prev;
}

Node *reverseByStack(Node *&head)
{
    Node *temp = head;
    stack<Node *> st;
    while (temp->next != NULL)
    {
        st.push(temp);
        temp = temp->next;
    }

    head = temp;
    while (!st.empty())
    {
        temp->next = st.top();
        st.pop();
        temp = temp->next;
    }
    temp->next = NULL;

    return head;
}

Node *reverse_recursive(Node *&head)
{
    Node *temp = head;
    if (temp->next == NULL || temp == NULL)
    {
        if (temp == NULL)
            cout << "Empty list" << endl;
        return temp;
    }

    Node *newHead = reverse_recursive(temp->next);
    temp->next->next = temp;
    temp->next = NULL;
    return newHead;
}

// module 21 advance linked list
int findMid(Node *&head)
{
    // case 1
    if (head == NULL)
        return -1;
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

void makeCycle(Node *&head, int position)
{
    Node *temp = head;
    Node *startNode;
    int count = 1;

    while (temp->next != NULL)
    {
        temp = temp->next;
        count++;
        if (count == position)
            startNode = temp;
    }
    temp->next = startNode;
}

bool detect_cycle(Node *&head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }

    return false;
}
void remove_cycle(Node *&head)
{
    Node *fast = head;
    Node *slow = head;

    // step 1: fast = slow
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (fast != slow);

    // step 2: re initialization of fast
    fast = head;
    // step 3: fast -> next = slow -> next
    while (fast->next != slow->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}

int main()
{
    int choose, position, value, save;
    Node *head = NULL;
    bool cycleStatus, sta;
    cout << "choose 1: insert At head " << endl;
    cout << "choose 2: insert At tail " << endl;
    cout << "choose 3: insert At Specific position " << endl;
    cout << "choose 4: search a value(unique list) " << endl;
    cout << "choose 5: search duplicate value in list " << endl;
    cout << "choose 6: insert after a specific value (unique list) " << endl;
    cout << "choose 7: insert after a specific value (duplication list) " << endl;
    cout << "choose 8: delete head node " << endl;
    cout << "choose 9: delete tail node " << endl;
    cout << "choose 10: delete node by specific position " << endl;
    cout << "choose 11: delete node by specific value (unique list) " << endl;
    cout << "choose 12: delete node by value (duplicate list) " << endl;
    cout << "choose 13: reverse linked list (none recursive) " << endl;
    cout << "choose 14: reverse linked list by recursive " << endl;
    cout << "choose 15: find the middle show first pointer method " << endl;
    cout << "choose 16: make cycle" << endl;
    cout << "choose 17: detected cycle in the list" << endl;
    cout << "choose 18: remove cycle in the list" << endl;
    cout << "Exit: 0" << endl;
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
            cout << "Enter the search value: ";
            cin >> value;
            save = search_value(head, value);
            if (save != -1)
            {
                cout << "value position " << save << endl;
            }
            else
            {
                cout << "this value not found yet in the list !!" << endl;
            }
            break;
        case 5:

            cout << "Enter the search value: ";
            cin >> value;
            duplicateValue store;
            store = search_duplicate_value(head, value);
            if (store.position[0] == 1)
            {
                cout << "this value not found at the list" << endl;
            }
            else
            {
                cout << "the value at the position ";
                for (int i = 1; i < store.position[0]; i++)
                {
                    cout << store.position[i] << " ";
                }
                cout << endl;
            }
            break;
        case 6:
            cout << "Enter the search value: ";
            cin >> position;
            cout << "Enter insert the value : ";
            cin >> value;
            insert_after_specific_value(head, position, value);
            break;
        case 7:
            cout << "Enter the search value: ";
            cin >> position;
            cout << "Enter insert the value : ";
            cin >> value;
            insert_after_duplicate_value(head, position, value);
            break;
        case 8:
            delete_At_head(head);
            break;
        case 9:
            delete_At_tail(head);
            break;
        case 10:
            cout << "Enter the position you delete: ";
            cin >> position;
            delete_At_specific_position(head, position);
            break;
        case 11:
            cout << "Enter the value you delete: ";
            cin >> value;
            delete_At_specific_value(head, value);
            break;
        case 12:
            cout << "Enter the value you delete: ";
            cin >> value;
            delete_At_duplicate_value(head, value);
            break;
        case 13:
            head = reverseNoneRecursive(head);

            break;
        case 14:
            head = reverse_recursive(head);

            break;
        case 15:
            int mid;
            mid = findMid(head);
            if (mid == -1)
            {
                cout << "the link list is empty" << endl;
            }
            else
            {
                cout << "mid value is " << mid << endl;
            }

            break;
        case 16:

            cout << "Enter the position: ";
            cin >> position;
            makeCycle(head, position);
            break;
        case 17:

            cycleStatus = detect_cycle(head);
            if (cycleStatus == true)
            {
                cout << "There is a cycle in the list" << endl;
            }
            else
            {
                cout << "There is No cycle in the list!!" << endl;
            }
            break;
        case 18:
            sta = detect_cycle(head);
            if (sta == true)
            {
                remove_cycle(head);
                cout << "remove cycle successfully" << endl;
            }
            else
            {
                cout << "There is No cycle in the list!!" << endl;
            }

            break;

        default:
            break;
        }
    }
    display_node(head);
}

/*



*/