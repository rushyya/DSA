/*  
    Creating a Binary Tree using pointers(2 pointers).... here we are creating Binary tree level by level
*/

#include<iostream>
#include<queue>
using namespace std;

struct Node{
    Node* left;
    int data;
    Node* right;
};

class Tree{
    Node* root;
public:
    void create();
};

void Tree::create(){
    Node *p, *t;
    int x;
    queue <Node*> q;
    cout<<"enter root value "<<endl;
    cin>>x;

    root= new Node();
    root->data=x;
    root->left=root->right=NULL;
    q.push(root);

    while(!q.empty()){
        p= q.front();
        q.pop();
        cout<<"Enter Left Child "<< p->data<<" :"<<endl;
        cin>>x;
        if(x!=-1){
            t= new Node();
            t->data=x;
            t->left=t->right=NULL;
            p->left= t;
            q.push(t);
        }
        cout<<"Enter Right Child"<<endl;
        cin>>x;
        if(x!=-1){
            t=new Node();
            t->data=x;
            t->left=t->right=NULL;
            p->right=t;
            q.push(t);
        }
    }
}
