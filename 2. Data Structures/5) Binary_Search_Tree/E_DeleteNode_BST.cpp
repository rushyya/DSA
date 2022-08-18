#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* deleteNode(Node* root, int data){
    
    if(root==NULL) return root;
    else if(data < root->data){
        root->left= deleteNode(root->left, data);
    }
    else if(data > root->data){
        root->right= deleteNode(root->right, data);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            delete(root);
            root=NULL;
            return NULL;
        }
        else if(root->left==NULL){
            Node* temp=root;
            root=root->right;
            delete(temp);
            return root;
        }
        else if(root->right==NULL){
            Node* temp=root;
            root=root->left;
            delete(temp);
            return root;
        }
        else{
            Node* temp= FindMin(root->right);
            root->data= temp->data;
            root->right = deleteNode(root->right, root->data);
        }
    }
    return root;
}

Node* FindMin(Node* root){

    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}