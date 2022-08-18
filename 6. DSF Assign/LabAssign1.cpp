#include <iostream>
#define MAX_SIZE 101

using namespace std;

class Node
{
public:
    Node *left;
    char data;
    Node *right;

    Node(char val)
    {
        data = val;
        left = right = nullptr;
    }
};

class Stack
{
private:
    Node *A[MAX_SIZE]; 
	int top;   
public:
	Stack()
	{
		top = -1; 
	}

	void push(Node* x) 
	{
	  if(top == MAX_SIZE -1) { 
			printf("Error: stack overflow\n");
			return;
		}
		A[++top] = x;
	}
	void pop() 
	{
		if(top == -1) { 
			printf("Error: No element to pop\n");
			return;
		}
		top--;
	}

	Node* Top() 
	{
		return A[top];
	}

	int empty()
	{
		if(top == -1) return 1;
		return 0;
	}

};

class Tree
{
    Node *root;

public:
    Tree()
    {
        root = NULL;
    }
    void create(); //using postfix expression
    Node *rootVal()
    {
        return root;
    }
    void preOrder(Node *root);
    void inOrder(Node *root);
    void postOrder(Node *root);
    void rec_preOrder();
    void rec_inOrder();
    void rec_postOrder();
};

void Tree ::create()
{
    Stack s;
    Node *temp, *temp1, *temp2;
    char exp[30];
    cout << "\nEnter the postfix Expression: ";
    cin >> exp;
    int i = 0;
    char ch;

    while ((ch = exp[i]) != '\0')//doubt
    {
        if (isalnum(ch))//doubt
        {
            Node *node = new Node(ch);
            s.push(node);
        }
        else
        {
            temp2 = s.Top();
            s.pop();
            temp1 = s.Top();
            s.pop();
            temp = new Node(ch);
            temp->left = temp1;
            temp->right = temp2;

            s.push(temp);
        }
        i++;
    }
    root = s.Top();
}

void Tree::preOrder(Node *root){
    if(root!=NULL){
        cout<< root->data <<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void Tree::inOrder(Node *root){
    if(root!=NULL){
        inOrder(root->left);
        cout<< root->data <<" ";
        inOrder(root->right);
    }
}

void Tree::postOrder(Node *root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout<< root->data <<" ";
    }
}

void Tree::rec_preOrder(){
    Stack s1;
    Node* t = root;

    while(!s1.empty() || t!=NULL){
        if(t!=NULL){
            s1.push(t);
            cout<<t->data<<" ";
            t=t->left;
        }
        else{
            t = s1.Top();
            s1.pop();
            t=t->right;
        }
    }
}

void Tree::rec_inOrder(){
    Stack  s2;
    Node* t = root;
    
    while(!s2.empty() || t!=NULL){
        if(t!=NULL){
            s2.push(t);
            t=t->left;
        }
        else{
            t = s2.Top();
            s2.pop();
            cout<<t->data<<" ";
            t=t->right;
        }
    }
}

void Tree::rec_postOrder(){
    Stack s1, s2;
    Node* t = root;
    if(root==NULL) return;
    s1.push(t);

    while(!s1.empty()){
        t = s1.Top();
        s1.pop();
        s2.push(t);

        if(t->left!=NULL){
            s1.push(t->left);
        }
        if(t->right!=NULL){
            s1.push(t->right);
        }
    }
    while(!s2.empty()){
        cout<<s2.Top()->data<<" ";
        s2.pop();
    }
}

int main(){
    Tree t;
    Node* root1;
    int ch;

    do{
        cout<<"\n\n1. Create\n2. Recursive_PreOrder\n3. Recursive_InOrder\n4. Recursive_PostOrder\n5. Non-Recursive_Preorder\n6. Non-Recursive__Inorder\n7. Non-Recursive__PostOrder\n8.Exit"<<endl;
        cout<<"Enter Your Choice : ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            t.create();
            root1= t.rootVal();
            break;
        case 2:
            cout<<"\nPreorder Traversal: "<<endl;
            t.preOrder(root1);
            break;
        case 3:
            cout<<"\nInorder Traversal: "<<endl; 
            t.inOrder(root1);   
            break;
        case 4:
            cout<<"\nPostorder Traversal: "<<endl;
            t.postOrder(root1);
            break;
        case 5:
            cout<<"\nNon-Recursive Preorder Traversal: "<<endl;
            t.rec_preOrder();            
            break;
        case 6:
            cout<<"\nNon-Recursive Inorder Traversal:: "<<endl;
            t.rec_inOrder();
            break;
        case 7:
            cout<<"\nNon-Recursive Postorder Traversal: "<<endl;
            t.rec_postOrder();
            break;
        }
    }while(ch!=8);
}
