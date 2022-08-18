#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
};

void LevelOrder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        cout << curr << " ";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
        q.pop();
    }
}
