// We are given n, where n is nodes in tree.And we have to build the BSts

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
vector<Node *> buildBSTs(int start, int end)
{

    vector<Node *> trees;
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }
    for (int i = start; i <= end; i++)
    {
        vector<Node *> leftTree = buildBSTs(start, i - 1);
        vector<Node *> rightTree = buildBSTs(i + 1, end);
        for (int j = 0; j < leftTree.size(); j++)
        {
            Node *left = leftTree[j];
            for (int k = 0; k < rightTree.size(); k++)
            {
                Node *right = rightTree[k];
                Node *node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }
    return trees;
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
    vector<Node *> totalTrees = buildBSTs(1, 3);
    for (int i = 0; i < totalTrees.size(); i++)
    {
        cout << (i + 1) << " :"
             << " ";
        preorderPrint(totalTrees[i]);
        cout << endl;
    }
    return 0;
}