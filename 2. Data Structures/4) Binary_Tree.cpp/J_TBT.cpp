#include <bits/stdc++.h>
using namespace std;
struct Node{
    bool lbit;
    Node* left;
    int data;
    Node* right;
    bool rbit;
};

void inOrder(Node* head){
    Node* T = head;         //dummy
    T = T->left;            //root
    while(T->lbit == 1){        //inorder starts with leftmost node
        T = T->left;
    }
    while(T != head){       //dummy
        cout<< T->data<<endl;
        T = inorder_Succesor(T);
    }
}

Node* inorder_Succesor(Node* T){
    if(T->rbit == 0){       //right thread
        return T->right;
    }

    T= T->right;            //right is link
    while(T->lbit == 1){    //find leftmost node of right link
        T= T->left;
    }
    return T;
}

Node* preOrder(Node* head){
    Node* T = head;   //dummy
    T = T->left;   //root
    while(T != head){     //preorder starts with root
        cout<<T->data<<endl;
        T = preorder_successor(T);  //preorder successor
    }
}

Node* preorder_successor(Node* T){
    if(T->lbit == 1){   //normal left child
        return T->left;
    }
    while(T->rbit == 0){   //climb up till right node is a link
        T = T->right;
    }
    return T->right ;
}

