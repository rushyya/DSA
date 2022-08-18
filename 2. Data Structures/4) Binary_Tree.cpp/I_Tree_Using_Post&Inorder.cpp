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

Node* CreateTree(int Inorder[], int PostOrder[], int n){
    int PostIndex = n-1;
    return CreateTreeUtil(Inorder, 0, n-1, PostOrder, &PostIndex);
}

Node* CreateTreeUtil(int Inorder[], int inStart, int inEnd, int PostOrder[], int* PostIndex ){
    
    if(inStart > inEnd) return nullptr;

    Node* node = new Node(PostOrder[*PostIndex]);
    (*PostIndex)--;

    int inIndex = searchInorder(Inorder, inStart, inEnd, node->data);
    // very imp yaha pea apn pehle node->right lete he post&Inorder me
    node->right = CreateTreeUtil(Inorder, inIndex+1, inEnd, PostOrder, PostIndex);
    node->left = CreateTreeUtil(Inorder, inStart, inIndex-1, PostOrder, PostIndex);

    return node;

}
int main(){
    
    return 0;
}