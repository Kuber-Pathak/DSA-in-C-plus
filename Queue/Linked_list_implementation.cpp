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
class queue
{
    Node *front;
    Node *back;

public:
    queue()
    {
        front = NULL;
        back = NULL;
    }
    void push(int x)
    {
        Node *n = new Node(x);
        if (front == NULL)
        {
            back = n;
            front = n;
            return;
        }

        back->next = n;
        back = n;
    }
    void pop()
    {
        if (front == NULL)
        {
            cout << "Queue underflow" << endl;
            return;
        }
        Node *toDelete = front;
        front = front->next;
        delete toDelete;
    }
    int peek()
    {
        if (front == NULL)
        {
            cout << "No elements in stack" << endl;
            return -1;
        }
        return front->value;
    }
    bool empty()
    {
        if (front == NULL)
        {
            cout << "No elements in stack" << endl;
            return true;
        }
        return false;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.empty();
    return 0;
}