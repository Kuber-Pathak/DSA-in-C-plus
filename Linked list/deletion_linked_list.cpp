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
void deleteAtHead(Node *&head)
{
    Node *todelete = head;
    head = head->next;
    delete todelete;
}
void delete_node(Node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }
    Node *temp = head;
    while (temp->next->value != val)
    {
        temp = temp->next;
    }
    Node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
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
    Insert_at_tail(head, 2);
    Insert_at_tail(head, 3);
    Insert_at_tail(head, 4);
    display(head);
    delete_node(head, 3);
    deleteAtHead(head);
    display(head);
}