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
void Insert_at_head(Node *&head, int value)
{
    Node *n = new Node(value);
    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}
void Insert_at_tail(Node *&head, int value)
{
    Node *n = new Node(value);

    if (head == NULL)
    {
        Insert_at_head(head, value);
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}
void deleteAtHead(Node *&head)
{
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    Node *toDelete = head;
    temp->next = head->next;
    head = head->next;
    delete toDelete;
}
void Deletion(Node *head, int pos)
{
    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }
    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}
void display(Node *&head)
{
    Node *temp = head;
    do
    {
        cout << temp->value << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main()
{
    Node *head = NULL;
    Insert_at_tail(head, 2);
    Insert_at_tail(head, 3);
    Insert_at_tail(head, 4);
    display(head);
    Insert_at_head(head, 5);
    display(head);
    Deletion(head, 4);
    display(head);
    deleteAtHead(head);
    display(head);
    return 0;
}