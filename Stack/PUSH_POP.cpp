#include <iostream>
using namespace std;
class Stack
{
    int a[5];
    int tos;

public:
    Stack()
    {
        tos = -1;
    }
    void push(int x)
    {
        if (tos >= 4)
        {
            cout << "stack is full" << endl;
        }
        else
        {
            tos++;
            a[tos] = x;
        }
    }
    void pop()
    {
        if (tos < 0)
        {
            cout << "stack is empty" << endl;
        }
        else
        {
            cout << "Poped item is : " << a[tos] << endl;
            tos--;
        }
    }
    void display()
    {
        if (tos < 0)
        {
            cout << "stack is empty" << endl;
        }
        else
        {
            cout << "The elements of stack are:" << endl;
            for (int i = tos; i >= 0; i--)
            {
                cout << "The " << i + 1 << " element is " << a[i] << endl;
            }
        }
    }
};
int main()
{
    Stack s;
    int a;
    for (int i = 1; i <= 5; i++)
    {
        cout << "enter " << i << " element" << endl;
        cin >> a;
        s.push(a);
    }
    s.display();
    for (int i = 1; i <= 6; i++)
    {
        s.pop();
    }
    return 0;
}