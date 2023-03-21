#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *next;

    Node(int n)
    {
        value = n;
        next = NULL;
    }
};

void Insert_at_tail(Node *&head, int value)
{
    Node *n = new Node(value);

    if (head == NULL)
    {
        head = n;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
int length(Node *&head)
{
    int l = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}
Node *Append(Node *&head, int k)
{
    Node *tail = head;
    Node *newHead;
    Node *newTail;
    int l = length(head);
    k = k % l;
    int count = 1;
    while (tail->next != NULL)
    {
        if (count == l - k)
        {
            newTail = tail;
        }
        if (count == l - k + 1)
        {
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    newTail->next = NULL;
    tail->next = head;

    return newHead;
}

void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;
    Insert_at_tail(head, 1);
    Insert_at_tail(head, 2);
    Insert_at_tail(head, 3);
    Insert_at_tail(head, 4);
    Insert_at_tail(head, 5);
    Insert_at_tail(head, 6);
    display(head);
    Node *newHead = Append(head, 3);
    display(newHead);
    return 0;
}