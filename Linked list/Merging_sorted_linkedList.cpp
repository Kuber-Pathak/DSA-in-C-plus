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
// Iterative way
Node *merge(Node *&head1, Node *&head2)
{
    Node *p1 = head1;
    Node *p2 = head2;
    Node *dummyNode = new Node(-1);
    Node *p3 = dummyNode;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->value < p2->value)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummyNode->next;
}
// Recursive way
Node *mergeRecursion(Node *&head1, Node *&head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    Node *result;
    if (head1->value < head2->value)
    {
        result = head1;
        result->next = mergeRecursion(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = mergeRecursion(head1, head2->next);
    }
    return result;
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
    int arr1[] = {1, 4, 5, 7};
    int arr2[] = {2, 3, 6};
    for (int i = 0; i < 4; i++)
    {
        Insert_at_tail(head1, arr1[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        Insert_at_tail(head2, arr2[i]);
    }
    display(head1);
    display(head2);
    // Node *newHead = merge(head1, head2);
    Node *newHead = mergeRecursion(head1, head2);
    display(newHead);
    return 0;
}