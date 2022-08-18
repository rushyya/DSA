#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    char data;
    Node *left;
    Node *right;
};

class Tree
{
};
void PreOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << endl;
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(Node *root)
{
    if (root == NULL)
        return;

    InOrder(root->left);
    cout << root->data << endl;
    InOrder(root->right);
}

void PostOrder(Node *root)
{
    if (root == NULL)
        return;

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << endl;
}

int main()
{

    return 0;
}