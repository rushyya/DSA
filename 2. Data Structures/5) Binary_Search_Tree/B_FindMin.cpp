#include<iostream>
using namespace std;
struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};

int FindMin(BstNode* root){
    if(root==NULL){
        cout<<"Empty tree"<<endl;
        return -1;
    }
    while(root->left!=NULL){
        root=root->left;
    }
    return root->data;
}

int FindMinRec(BstNode* root){
    if(root==NULL){
        cout<<"Empty tree"<<endl;
        return -1;
    }
    else if(root->left==NULL){
        return root->data;
    }
    return FindMinRec(root->left);
}