#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};
bool isIdentical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    else
    {
        bool cond1 = (root1->data == root2->data);
        bool cond2 = isIdentical(root1->left, root2->left);
        bool cond3 = isIdentical(root1->right, root2->right);

        if (cond1 && cond2 && cond3)
        {
            return true;
        }
        return false;
    }
}
int main()
{
    Node *root = new Node(12);
    root->left = new Node(9);
    root->right = new Node(15);
    root->left->left = new Node(5);
    root->left->right = new Node(10);

    if (isIdentical(root, root))
    {
        cout << "Indetical BST" << endl;
    }
    else
    {
        cout << "Not Identical BST" << endl;
    }
    return 0;
}
