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
struct Info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBST(Node *root)
{
    if (root == NULL)
    {
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if (root->left == NULL && root->right == NULL)
    {
        return {1, root->data, root->data, 1, true};
    }

    Info leftdata = largestBST(root->left);
    Info rightdata = largestBST(root->right);

    Info curr;
    curr.size = (leftdata.size + rightdata.size + 1);
    if (leftdata.isBST && rightdata.isBST && rightdata.min > root->data && leftdata.max < root->data)
    {
        curr.min = min(leftdata.min, min(rightdata.min, root->data));
        curr.max = max(rightdata.max, max(leftdata.max, root->data));

        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }

    curr.ans = max(leftdata.ans, rightdata.ans);
    curr.isBST = false;
    return curr;
}
int main()
{
    Node *root = new Node(15);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(5);

    cout << "Largest BST in BT : " << largestBST(root).ans << endl;

    return 0;
}
