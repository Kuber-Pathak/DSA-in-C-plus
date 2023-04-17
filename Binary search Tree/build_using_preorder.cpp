#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *right, *left;

    Node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};
Node *buildPreOrder(int preorder[], int *preorderIDX, int key, int min, int max, int n)
{
    if (*preorderIDX >= n)
    {
        return NULL;
    }
    Node *root = NULL;
    if (key > min && key < max)
    {
        root = new Node(key);
        *preorderIDX = *preorderIDX + 1;

        if (*preorderIDX < n)
        {
            root->left = buildPreOrder(preorder, preorderIDX, preorder[*preorderIDX], min, key, n);
        }
        if (*preorderIDX < n)
        {
            root->right = buildPreOrder(preorder, preorderIDX, preorder[*preorderIDX], key, max, n);
        }
    }
    return root;
}

void preorderPrint(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main()
{
    int preorder[] = {10, 2, 1, 13, 11};
    int n = 5;
    int preorderIDX = 0;
    Node *root = buildPreOrder(preorder, &preorderIDX, preorder[0], INT_MIN, INT_MAX, n);
    preorderPrint(root);
    cout << endl;
    return 0;
}