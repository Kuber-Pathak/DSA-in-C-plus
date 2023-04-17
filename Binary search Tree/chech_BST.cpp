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
bool checkBST(Node *root, Node *min = NULL, Node *max = NULL)
{
    if (root == NULL)
    {
        return true;
    }
    if (min != NULL && root->data < min->data)
    {
        return false;
    }
    if (max != NULL && root->data > max->data)
    {
        return false;
    }

    bool checkleft = checkBST(root->left, min, root);
    bool checkright = checkBST(root->right, root, max);

    return checkleft and checkright;
}
int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    if (checkBST(root, NULL, NULL))
    {
        cout << "Valid BST" << endl;
    }
    else
    {
        cout << "Invalid BST" << endl;
    }
    return 0;
}