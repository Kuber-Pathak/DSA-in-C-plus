
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

// to calculate height of binary tree
int heightTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lHeight = heightTree(root->left);
    int rHeight = heightTree(root->right);
    return max(lHeight, rHeight) + 1;
}

// to calculate Diameter of binary tree
// Diameter is the number of nodes in the longest path between any 2 leaves

// Time complexity O(n^2)
int calcDiameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lHeight = heightTree(root->left);
    int rHright = heightTree(root->right);
    int currDiameter = lHeight + rHright + 1;

    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);
    return max(currDiameter, max(lDiameter, rDiameter));
}
// Time Complexity O(n)
int calDiameter(Node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int lDiameter = calDiameter(root->left, &lh);
    int rDiameter = calDiameter(root->right, &rh);

    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;
    return max(currDiameter, max(lDiameter, rDiameter));
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
    cout << "The height of tree is: " << heightTree(root) << endl;
    cout << "The diameter of tree is: " << calcDiameter(root) << endl;
    int height = 0;
    cout << "The Diameter of tree is: " << calDiameter(root, &height) << endl;
    return 0;
}