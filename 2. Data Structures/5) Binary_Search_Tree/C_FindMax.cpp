#include<iostream>
using namespace std;
struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};

int FindMax(BstNode* root){
    if(root==NULL){
        cout<<"Empty tree"<<endl;
        return -1;
    }
    while(root->right!=NULL){
        root=root->right;
    }
    return root->data;
}

int FindMaxRec(BstNode* root){
    if(root==NULL){
        cout<<"Empty tree"<<endl;
        return -1;
    }
    else if(root->right==NULL){
        return root->data;
    }
    return FindMaxRec(root->right);
}