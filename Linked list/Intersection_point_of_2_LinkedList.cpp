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
void intersect(Node *&head1, Node *&head2, int pos)
{
    Node *temp1 = head1;
    pos--;
    while (pos--)
    {
        temp1 = temp1->next;
    }
    Node *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
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
int intersection(Node *&head1, Node *&head2)
{
    int l1 = length(head1);
    int l2 = length(head2);
    int d = 0;
    Node *ptr1;
    Node *ptr2;
    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while (d)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }
        d--;
    }
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->value;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
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
    Node *head1 = NULL;
    Node *head2 = NULL;
    Insert_at_tail(head1, 1);
    Insert_at_tail(head1, 2);
    Insert_at_tail(head1, 3);
    Insert_at_tail(head2, 4);
    Insert_at_tail(head2, 5);
    Insert_at_tail(head2, 6);
    intersect(head1, head2, 2);
    display(head1);
    display(head2);
    cout << "The intersection point is: " << intersection(head1, head2) << endl;
    ;
    return 0;
}