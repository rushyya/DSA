#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    Node *left;
    Node *right;
    Node(char x)
    {
        data = x;
        left = right = NULL;
    }
};


int searchInorder(int InArray[], int inStart, int inEnd, int val){
    for(int i=inStart; i<=inEnd; i++){
        if(InArray[i] == val){
            return i;
        }
    }
    return -1;
}

Node* CreateTree(int Inorder[], int inStart, int inEnd, int Preorder[]){
    static int preIndex=0;

    if(inStart > inEnd) return nullptr;

    Node* node = new Node(Preorder[preIndex++]);

    if(inStart == inEnd) return node;

    int inIndex = searchInorder(Inorder, inStart, inEnd, node->data);

    node->left = CreateTree(Inorder, inStart, inIndex-1, Preorder);
    node->right = CreateTree(Inorder, inIndex+1, inEnd, Preorder);

    return node;
}

int  main(){
    
    return 0;
}