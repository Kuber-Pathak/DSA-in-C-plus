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
void Insert_at_head(Node *&head, int value)
{
    Node *n = new Node(value);
    n->next = head;
    head = n;
}
bool search(Node *&head, int val)
{
    Node *temp = head;
    while (temp != 0)
    {
        if (temp->value == val)
        {
            return true;
        }

        temp = temp->next;
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
    Insert_at_tail(head, 2);
    Insert_at_tail(head, 3);
    Insert_at_tail(head, 4);
    display(head);
    Insert_at_head(head, 5);
    display(head);
    cout << search(head, 5) << endl;
    ;
}