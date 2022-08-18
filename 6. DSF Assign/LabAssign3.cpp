#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *left, *right;
    int lth, rth;

    node(int x){
        data =x;
        lth =1;
        rth =1;
    }

};

class thread{
public:
    node *root, *dummy;

    thread(){
        root = NULL;
        dummy = new node(-1);
        dummy->rth = 0;
        dummy->lth = 1;
        dummy->left = dummy;
        dummy->right = dummy;
    }
    void insertnode();
    void insert(node *, node *);
    void preorder();
    void inorder();
    void postorder();
};

void thread :: insertnode(){
    node * newnode;
    int data;
    cout<<"Enter the node data: ";
    cin>>data;
    newnode = new node(data);

    if(dummy->lth == 1){
        root = newnode;
        root->left = dummy;
        root->right = dummy;
        dummy->left = root;
        dummy->lth =0;
    }
    else{
        insert(root, newnode);
    }
}

void thread :: insert(node *root, node *newnode){
    if(newnode->data < root->data){
        if(root->lth == 1){
            newnode->lth = root->lth;
            newnode->left = root->left;
            newnode->right = root;
            newnode->rth = 1;
            root->left = newnode;
            root->lth = 0;
        }
        else{
            insert(root->left, newnode);
        }
    }
    else{
        if(root->rth == 1){
            newnode->rth = root->rth;
            newnode->right = root->right;
            newnode->left =root;
            newnode->lth = 1;
            root->right = newnode;
            root->rth = 0;
        }
        else{
            insert(root->right, newnode);
        }
    }
}

node* inorder_Succesor(node* T){
    if(T->rth == 1){       //right thread
        return T->right;
    }

    T= T->right;            //right is link
    while(T->lth == 0){    //find leftmost node of right link
        T= T->left;
    }
    return T;
}


void thread :: inorder(){
    node* T = dummy;         //dummy
    T = T->left;            //root
    while(T->lth == 0){        //inorder starts with leftmost node
        T = T->left;
    }
    while(T != dummy){       //dummy
        cout<< T->data<<" ";
        T = inorder_Succesor(T);
    }
}


node* preorder_successor(node* T){
    if(T->lth == 0){   //normal left child
        return T->left;
    }
    while(T->rth == 1){   //climb up till right node is a link
        T = T->right;
    }
    return T->right ;
}

void thread :: preorder(){
    node* T = dummy;   //dummy
    T = T->left;   //root
    while(T != dummy){     //preorder starts with root
        cout<<T->data<<" ";
        T = preorder_successor(T);  //preorder successor
    }
}


int  main(){
    int ch;
    thread t1;
    do{
        cout<<"\n-------MENU-------\n";
        cout<<"\n1. Insert Node\n2. Inorder\n3. Preorder\n4. Exit\n";
        cout<<"Enter Your Choice: ";
        cin>>ch;

        switch (ch)
        {
        case 1:
            cout<<"\nEnter No of nodes: ";
            int n;
            cin>>n;
            for(int i=0; i<n; i++){
                t1.insertnode();
            }
            break;
        case 2:
            cout<<"\nInorder is: "<<endl;
            t1.inorder();
            break;
        case 3:
            cout<<"\nPreOrder is: "<<endl;
            t1.preorder();
            break;
        }
    }while(ch!=4);
    return 0;
}


