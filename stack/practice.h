#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T value;
    Node<T> *next;
    Node<T> *prev;

    Node(T value)
    {
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};
template <typename T>
class Stack
{
    Node<T> *head;
    Node<T> *top;
    int count = 0;

public:
    Stack()
    {
        this->head = NULL;
        this->top = NULL;
    }
    void push(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (head == NULL)
        {
            head = top = newNode;
            count++;
            return;
        }

        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        count++;
        return;
    }
    T pop()
    {
        Node<T> *deleNode = top;
        T save = deleNode->value;
        if (head == NULL)
        {

            cout << "Empty stack" << endl;
        }
        if (head == top)
        {
            count--;
            save = head->value;
            top = head = NULL;
            delete (deleNode);
            return save;
        }
        top = deleNode->prev;
        top->next = NULL;
        count--;
        delete (deleNode);
        return save;
    }

    int size()
    {

        return count;
    }

    bool empty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    T Top()
    {
        if (head == NULL)
        {
            cout << "Empty top" << endl;
        }
        else
        {
            return top->value;
        }
    }

    T mid()
    {
        Node<T> *slow = top;
        Node<T> *fast = top;
        while (1)
        {
            slow = slow->prev;
            fast = fast->prev->prev;
            if (slow == NULL || slow->prev == NULL || fast == NULL || fast->prev == NULL || fast->prev->prev == NULL)
            {
                break;
            }
        }
        return slow->value;
    }
    T midDelete()
    {
        Node<T> *slow = top;
        Node<T> *fast = top;
        while (1)
        {
            slow = slow->prev;
            fast = fast->prev->prev;
            if (slow == NULL || slow->prev == NULL || fast == NULL || fast->prev == NULL || fast->prev->prev == NULL)
            {
                count--;
                break;
            }
        }
        T saveValue = slow->value;
        Node<T> *save = slow->prev;
        save->next = slow->next;

        save->next->prev = save;
        delete (slow);
        return saveValue;
    }
};