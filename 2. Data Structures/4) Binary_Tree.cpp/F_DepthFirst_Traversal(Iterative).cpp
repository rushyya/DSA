#include<iostream>
#include<stack>



using namespace std;

struct Node{
    Node* left;
    int data;
    Node* right;
};

class Tree{
    Node* root;
public:
    void preorder(Node* t);
    void Inorder(Node* t);
    void Postorder(Node* t);
    void iterativePostorder(Node* t);
};

void Tree::preorder(Node* t){
    stack <Node*> s;

    while(!s.empty() || t!=NULL){
        if(t!=NULL){
            cout<<t->data<<", ";
            s.push(t);
            t=t->left;
        }
        else{
            t=s.top();
            s.pop();
            t=t->right;
        }
    }

}
void Tree::Inorder(Node* t){
    stack <Node*> s;

    while(!s.empty() || t!=NULL){
        if(t!=NULL){
            s.push(t);
            t=t->left;
        }
        else{
            t=s.top();
            s.pop();
            cout<<t->data<<", ";
            t=t->right;
        }
    }

}

void Tree :: Postorder(Node* p){
    stack <long int> s;
    long int temp;
    if(!s.empty() || p!= NULL){
        if(p!=NULL){
            s.push((long int)p);
            p=p->left;
        }
        else{
            temp= s.top();
            s.pop();
            if(temp>0){
                s.push(-temp);
                p=((Node*)temp)->right;
            }
            else{
                cout<<((Node*)(-1 * temp))->data<<","<<endl;
                p=NULL;
            }

        }
    }
}


void Tree::iterativePostorder(Node *p) {
    stack<long int> stk;
    long int temp;
    while (p != nullptr || ! stk.empty()){
        if (p != nullptr){
            stk.emplace((long int)p);
            p = p->left;
        } else {
            temp = stk.top();
            stk.pop();
            if (temp > 0){
                stk.emplace(-temp);
                p = ((Node*)temp)->right;
            } else {
                cout << ((Node*)(-1 * temp))->data << ", " << flush;
                p = nullptr;
            }
        }
    }
    cout << endl;
}
