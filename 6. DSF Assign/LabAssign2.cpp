#include <iostream>
#include<stack>
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

class bST{
    Node* root;
    
public:
    bST(){
        root = NULL;
    }
    Node *rootVal(){
        return root;
    }
    Node* Insert_Iterative(Node* root, int val);
    Node* Insert_rec(Node* root,int data);
    void inOrder(Node *root);
    void Search_rec(Node* root,int val);
    Node* Search_Iterative(Node* p, int val);
    int height_rec(Node* root);
    int height_Iterative(Node* root);
    void LevelOrder(Node *root);
    Node* deleteNode(Node* root, int data);
    Node* mirror_rec(Node *T);
    void display_mirror(Node* root);
};

Node* bST :: Insert_Iterative(Node* root, int val){

    Node *p, *t;
    p=root; 
    if(p==NULL){
        p = new Node(val);
        return p;
    }

    while(p!=NULL){
        t=p;
        if(val == p->data){
            return NULL;
        }
        else if(val < p->data){
            p=p->left;
        }
        else{
            p=p->right;
        }
    }
    p = new Node(val);
    if(val < t->data){
        t->left=p;
    }
    else{
        t->right=p;
    }
    return p;
}

Node* bST :: Insert_rec(Node* root,int data) {
	if(root == NULL){
		root = new Node(data);
	}
	else if(data <= root->data) {
		root->left = Insert_rec(root->left,data);
	}
	else {
		root->right = Insert_rec(root->right,data);
	}
	return root;
}

void bST :: inOrder(Node *root){
    if(root!=NULL){
        inOrder(root->left);
        cout<< root->data <<" ";
        inOrder(root->right);
    }
}

void bST :: Search_rec(Node* root,int val){
	if(root == NULL) {
		cout << "Element not found";
	}
	else if(root->data == val) {
		cout << "Element found";
	}
	else if(val <= root->data) {
		 Search_rec(root->left,val);
	}
	else {
		 Search_rec(root->right,val);
	}
}

Node* bST :: Search_Iterative(Node* p, int val){

    while(p!=NULL){
        if(p->data== val){
            return p;
        }
        else if(val< p->data){
            p=p->left;
        }
        else{
            p=p->right;
        }
    }
    return NULL;
}

int bST :: height_rec(Node* root){
    
    int leftHeight, rightHeight;
    if(root == NULL){
        return -1;
    }
    
    leftHeight = height_rec(root->left);
    rightHeight = height_rec(root->right);
    
    return max(leftHeight, rightHeight)+1;
}

int bST :: height_Iterative(Node* root){
    int res = -1;
    if(root== NULL)
        return res;

    queue <Node*> q;
    q.push(root);
    
    while(!q.empty()){
        res++;
        int n = q.size();
        for(int i=0; i<n; i++){
            Node* t = q.front();
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

void bST :: LevelOrder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        cout << curr->data << " ";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
        q.pop();
    }
}
Node* FindMin(Node* root){

    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

Node* bST :: deleteNode(Node* root, int data){
    
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



Node* bST :: mirror_rec(Node *T){  
    if (T==NULL) return NULL;
    Node *p;
    p=new Node(T->data); 
    p->left = mirror_rec(T->right); 
    p->right = mirror_rec(T->left); 
    return p;
}

void bST:: display_mirror(Node* root){
    Node* temp;
    temp = mirror_rec(root);

    cout<<"\nInorder traversal of mirrored bst"<<endl;
    inOrder(temp);
    cout<<"\nLevel order traversal of mirrored bst"<<endl;
    LevelOrder(temp);
}
int main()
{
    bST t ;
    Node* root1 = t.rootVal();
    root1 = t.Insert_Iterative(root1, 15);
    t.Insert_Iterative(root1, 10);
    t.Insert_Iterative(root1, 20);
    t.Insert_Iterative(root1, 25);
    t.Insert_Iterative(root1, 8);
    t.Insert_Iterative(root1, 12);

    int ch;

    do{
        cout<<"\n\nEnter Your Choice: \n";
        cout<<"1) Insert node in BST\n2) Display BST in inOrder\n3) Search Recursiive\n4)Search Non-Recurssive\n5) Mirror\n6) Level Order Traversal\n7) Delete Element\n8) Height Recurssive\n9) Exit \n";
        cin>>ch;

        switch(ch){
        case 1:
            int a;
            cout<<"Enter the Element to insert: \n";
            cin>>a;
            t.Insert_Iterative(root1, a);
            cout<< "Element Inserted Successfully!";
            break;

        case 2:
            t.inOrder(root1);
            break;
        case 3:
            int s;
            cout<<"Enter Element to be searched: \n";
            cin>>s;
            t.Search_rec(root1, s);
            break;
        case 4:
            int s1;
            cout<<"Enter Element to be searched: \n";
            cin>>s1;
            t.Search_rec(root1, s1);
            break;
        case 5:
            t.display_mirror(root1);
            break;
        case 6:
            t.LevelOrder(root1);
            break;
        case 7:
            int d;
            cout<<"Enter element to be deleted: \n";
            cin>>d;
            t.deleteNode(root1, d);
            cout<<"Element Deleted";
            break;
        case 8:
            int h1 = t.height_rec(root1);
            cout<<"Height of bst is: "<<h1<<endl;
            break;
        }
    }while(ch!=9);
    return 0;
}

