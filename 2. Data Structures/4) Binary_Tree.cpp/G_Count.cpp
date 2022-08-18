#include<iostream>
using namespace std;

struct Node{
    Node* left;
    int data;
    Node* right;
};

int count(Node* p){
    int x, y;
    if(p!=NULL){
        x= count(p->left);
        y= count(p->right);

        return x+y+1;
    }
    return 0;
}
// OR
int count(Node* p){
    if(p==NULL) return 0;

    return count(p->left)+ count(p->right)+1;
}

int countdeg2(Node* p){
    int x, y;
    if(p!=NULL){
        x= count(p->left);
        y= count(p->right);

        if(p->left && p->right){
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
}

int countSum(Node* p){
    int x, y;
    if(p!=NULL){
        x= countSum(p->left);
        y= countSum(p->right);

        return x+y+p->data;
    }
    return 0;
}

int countHeight(Node* p){
    int x,y;
    if(p!=NULL){
        x= countHeight(p->left);
        y= countHeight(p->right);

        if(x>y){
            return x+1;
        }
        else{
            return y+1;
        }
    }
    return -1;
}

int countLeafNodes(Node* p){
    int x,y;
    if(p!=NULL){
        x= countLeafNodes(p->left);
        y= countLeafNodes(p->right);
        if(p->left==NULL && p->right==NULL){
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
    return 0;
}

int countDeg1or2(Node* p){
    int x,y;
    if(p!=NULL){
        x= countDeg1or2(p->left);
        y= countDeg1or2(p->right);
        if(p->left != NULL || p->right != NULL){
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
    return 0;
}

int countDeg1(Node* p){
    int x,y;
    if(p!=NULL){
        x= countDeg1(p->left);
        y= countDeg1(p->right);
        if(p->left != NULL ^ p->right != NULL){
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
    return 0;
}
