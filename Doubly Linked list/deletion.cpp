#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next, *previous;
    node(int a)
    {
        data = a;
        next = NULL;
        previous = NULL;
    }
};
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != NULL)
    {
        head->previous = n;
    }
    head = n;
}
void insertAtTail(node *&head, int val)
{
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    node *n = new node(val);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->previous = temp;
}
void deleteAtHead(node *&head)
{
    node *todel = head;
    head = head->next;
    head->previous = NULL;
    delete todel;
}
void deletion(node *&head, int pos)
{
    if (pos == 1)
    {
        deleteAtHead(head);
    }
    node *temp = head;
    int count = 1;
    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
    temp->previous->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->previous = temp->previous;
    }
    delete temp;
}

void display(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);
    deleteAtHead(head);
    display(head);
    deletion(head, 3);
    display(head);
    return 0;
}