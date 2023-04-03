// Balanced :for each node the difference between the heights of the left subtree and right subtreee <= 1
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

// Time complexity O(n^2)
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return (max(lh, rh) + 1);
}
bool isBalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (isBalanced(root->left) == false)
    {
        return false;
    }
    if (isBalanced(root->right) == false)
    {
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Time Complexity O(n)
bool IsBalanced(Node *root, int *height)
{
    if (root == NULL)
    {
        return true;
    }
    int lh = 0, rh = 0;
    if (IsBalanced(root->right, &rh) == false)
    {
        return false;
    }
    if (IsBalanced(root->left, &lh) == false)
    {
        return false;
    }
    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    // Tree 1
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Heigth Balaced Tree O(n^2)
    if (isBalanced(root))
    {
        cout << "Balanced Tree" << endl;
    }
    else
    {
        cout << "Not Balanced Tree" << endl;
    }
    // Heigth Balaced Tree O(n)
    int height = 0;
    if (IsBalanced(root, &height) == true)
    {
        cout << "Balanced Tree" << endl;
    }
    else
    {
        cout << "Not Balanced Tree" << endl;
    }

    return 0;
}
