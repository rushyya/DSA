#include<iostream>
using namespace std;

//Method 1: 0(n^2) time complexity 
struct Node{
    int data;
    Node* left;
    Node* right;
};

bool isSubTreeGreater(Node* root, int value){
    if(root==NULL) return true;

    if(root->data > value && isSubTreeGreater(root->left, value) && isSubTreeGreater(root->right, value)){
        return true;
    }
    else{
        return false;
    }
}
bool isSubTreeSmaller(Node* root, int value){
    if(root==NULL) return true;

    if(root->data <= value && isSubTreeSmaller(root->left, value) && isSubTreeSmaller(root->right, value)){
        return true;
    }
    else{
        return false;
    }
}

bool isBST(Node* root){
    if(root==NULL) return true;

    if(isSubTreeSmaller(root->left, root->data) && isSubTreeGreater(root->right, root->data) && isBST(root->left) && isBST(root->right)){
        return true;
    }else{
        return false;
    }

}

// Method 2: O(n) time complexity;
bool isBSTUtil(Node* root, int minValue, int maxValue){//UTILITY FUNCTION
    if(root==NULL) return NULL;

    if(root->data > minValue && root->data< maxValue && isBSTUtil(root->left, minValue, root->data) && isBSTUtil(root->right, root->data, maxValue)){
        return true;
    }
    else{
        return false;
    }
}
// AS the caller of this binary search tree function may only want to pass the adress of the root node
bool isBinaryST(Node* root){
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// Method 3: u can perfom inorder traversal of binary tree and if the tree is binary search tree u would read the data in sorted order.