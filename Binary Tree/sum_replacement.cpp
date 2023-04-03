// Sum Replacement-Replce the value of each Node with the sum of all subtree nodes and itself
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void sumRepalce(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    sumRepalce(root->left);
    sumRepalce(root->right);

    if (root->left != NULL)
    {
        root->data += root->left->data;
    }
    if (root->right != NULL)
    {
        root->data += root->right->data;
    }
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // sum replacement
    cout << "Before sumreplacement" << endl;
    preorder(root);
    cout << endl;
    sumRepalce(root);
    cout << "After sumreplacement" << endl;
    preorder(root);
    cout << endl;
    return 0;
}
