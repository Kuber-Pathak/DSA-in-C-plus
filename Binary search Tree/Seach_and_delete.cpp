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
bool search(Node *root, int val)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == val)
    {
        return true;
    }

    if (root->data < val)
    {
        return search(root->right, val);
    }
    return search(root->left, val);
}
Node *inorderSUC(Node *root)
{
    Node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
Node *deleteBST(Node *root, int val)
{
    if (val < root->data)
    {
        root->left = deleteBST(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = deleteBST(root->right, val);
    }
    else
    {

        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = inorderSUC(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
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
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    // searcing
    int key = 3;
    if (search(root, key) == false)
    {
        cout << "Key doesn't exist" << endl;
    }
    else
    {
        cout << "Key exists" << endl;
    }

    // deleting
    inorder(root);
    cout << endl;
    root = deleteBST(root, 2);
    inorder(root);
    return 0;
}