// Program to put even postion node after odd positio nodes
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
void evenAfterOdd(Node *&head)
{
    Node *odd = head;
    Node *even = head->next;
    Node *evenstart = even;
    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenstart;
    if (odd->next != NULL)
    {
        even->next = NULL;
    }
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
    Insert_at_tail(head, 5);
    Insert_at_tail(head, 7);
    Insert_at_tail(head, 2);
    Insert_at_tail(head, 3);
    Insert_at_tail(head, 4);
    display(head);
    evenAfterOdd(head);
    display(head);
    return 0;
}