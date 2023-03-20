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
Node *reverseK(Node *&head, int k)
{
    Node *previous = NULL;
    Node *current = head;
    Node *next;
    int count = 0;
    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
        count++;
    }
    if (next != NULL)
    {
        head->next = reverseK(next, k);
    }
    return previous;
}
int main()
{
    Node *head = NULL;
    Insert_at_tail(head, 1);
    Insert_at_tail(head, 2);
    Insert_at_tail(head, 3);
    Insert_at_tail(head, 4);
    Insert_at_tail(head, 5);
    display(head);
    int k = 2;
    Node *newhead = reverseK(head, k);
    display(newhead);
    return 0;
}