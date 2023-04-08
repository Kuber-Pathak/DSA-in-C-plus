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

// Method 1
bool findPath(Node *root, int key, vector<int> &path)
{
    if (root == NULL)
    {
        return false;
    }
    path.push_back(root->data);
    if (root->data == key)
    {
        return true;
    }
    if (findPath(root->left, key, path) || findPath(root->right, key, path))
    {
        return true;
    }
    path.pop_back();
    return false;
}

int LCA(Node *root, int n1, int n2)
{
    vector<int> path1, path2;
    if (!findPath(root, n1, path1) || !findPath(root, n2, path2))
    {
        return -1;
    }
    int pc;
    for (pc = 0; pc < path1.size() && path2.size(); pc++)
    {
        if (path1[pc] != path2[pc])
        {
            break;
        }
    }

    return path2[pc - 1];
}
// Method 2
Node *LCA2(Node *root, int n2, int n1)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *leftLCA = LCA2(root->left, n2, n1);
    Node *rightLCA = LCA2(root->right, n2, n1);

    if (leftLCA && rightLCA)
    {
        return root;
    }
    if (leftLCA != NULL)
    {
        return leftLCA;
    }
    return rightLCA;
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
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(9);

    // Lowest common Ancestor methode 1
    int n1 = 8;
    int n2 = 9;
    int lca = LCA(root, n1, n2);
    if (lca == -1)
    {
        cout << "LCA doesn't exits" << endl;
    }
    else
    {
        cout << "LCA : " << lca << endl;
    }

    // Lowest common Ancestor methode 2
    Node *lca2 = LCA2(root, n1, n2);
    if (lca2 == NULL)
    {
        cout << "LCA doesn't exits" << endl;
    }
    else
    {
        cout << "LCA : " << lca2->data << endl;
    }

    return 0;
}
