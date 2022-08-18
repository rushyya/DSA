// Searching and inserting using iterative method

#include<iostream>
using namespace std;

struct Node {
	int data; 
	Node* left;
	Node* right;
};
// M2: Searching in BST using iteration
Node* ISearch(Node* p, int data){

    while(p!=NULL){
        if(p->data== data){
            return p;
        }
        else if(data< p->data){
            p=p->left;
        }
        else{
            p=p->right;
        }
    }
    return NULL;
}
// M2: Inserting in BST using Iteration
Node* Insert(Node* root, int data){

    Node *p, *t;
    p=root; 
    if(p==NULL){
        p = new Node();
        p->data= data;
        p->left=p->right=NULL;
        return p;
    }

    while(p!=NULL){
        t=p;
        if(data == p->data){
            return NULL;
        }
        else if(data < p->data){
            p=p->left;
        }
        else{
            p=p->right;
        }
    }
    p = new Node();
    p->data= data;
    p->left=p->right=NULL;
    if(data < t->data){
        t->left=p;
    }
    else{
        t->right=p;
    }
}

