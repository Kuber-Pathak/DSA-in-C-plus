#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *left, *right;
    int data;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calculatePointer(Node *root, Node **first, Node **mid, Node **last, Node **prev)
{
    if (root == NULL)
    {
        return;
    }

    calculatePointer(root->left, first, mid, last, prev);
    if (*prev && root->data < (*prev)->data)
    {
        if (!*first)
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root;
        }
    }
    *prev = root;
    calculatePointer(root->right, first, mid, last, prev);
}

void recoverBST(Node *root)
{
    Node *first, *mid, *last, *prev;
    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;

    calculatePointer(root, &first, &mid, &last, &prev);

    if (first && last)
    {
        swap(&(first->data), &(last->data));
    }
    else if (first && mid)
    {
        swap(&(first->data), &(mid->data));
    }
}
void inorderPrint(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}
int main()
{
    Node *root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(9);
    root->left->left = new Node(13);
    root->left->right = new Node(4);
    root->right->right = new Node(1);

    inorderPrint(root);
    cout << endl;

    recoverBST(root);
    inorderPrint(root);
    cout << endl;

    return 0;
}