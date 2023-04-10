// For a tree to be binary search tree:
// 1.The left nodes of the root sholuld always be smaller than root and right nodes should be greater
// 2.Point 1 should be applicable for all child nodes and no duplicate node should exist
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
Node *insertion(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (root->data > val)
    {
        root->left = insertion(root->left, val);
    }
    else
    {
        // root->data<val
        root->right = insertion(root->right, val);
    }
    return root;
}
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    Node *root = NULL;
    root = insertion(root, 5);
    insertion(root, 1);
    insertion(root, 3);
    insertion(root, 4);
    insertion(root, 2);
    insertion(root, 7);

    // to chechk weather the BST is correct or not
    // if inorder is in ascending order it is ture else false
    inorder(root);
    cout << endl;
    return 0;
}