#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    Node* left;
    int data;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};
int height_Iterative(Node* root){
    int res = -1;
    if(root== NULL){
        return res;
    }
    Node* t = root;
    queue <Node*> q;
    q.push(root);
    
    while(!q.empty()){
        res++;
        int n = q.size();
        for(int i=0; i<n; i++){
            t = q.front();
            q.pop();
            
            if(t->left != NULL){
                q.push(t->left);
            }
            if(t->right != NULL){
                q.push(t->right);
            }
        }
    }
    return res;
}

int height_rec(Node* root){
    
    int leftHeight, rightHeight;
    if(root == NULL){
        return -1;
    }
    
    leftHeight = height_rec(root->left);
    rightHeight = height_rec(root->right);
    
    return max(leftHeight, rightHeight)+1;
}