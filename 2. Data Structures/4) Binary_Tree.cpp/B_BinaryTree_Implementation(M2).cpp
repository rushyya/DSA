#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *left;
    Node *right;
    Node(char x)
    {
        data = x;
        left = right = NULL;
    }
};

class tree
{
    Node *root;
    Node *create_();
    void Preorder_(Node *rootPtr);
    void Inorder_(Node *rootPtr);
    void Postorder_(Node *rootPtr);

public:
    tree()
    {
        root = NULL;
    }
    void create()
    {
        root = create_();
    }
    void Preorder()
    {
        Preorder_(root);// Passing Private Parameter in Constructor(There is a reason why we are doing this)...we dont want the user to enter the root value but we need it and it is private
    }
    void Inorder()
    {
        Inorder_(root);
    }
    void Postorder()
    {
        Postorder_(root);
    }
};

Node *tree::create_()
{
    char x;
    cout << "Enter data to be entered (N for No data or NULL Node):" << endl;
    cin >> x;
    if (x == 'N')
    {
        return NULL;
    }

    Node *p = new Node(x);
    cout << "\nLeft Child of " << x <<" :"<< endl;
    p->left = create_();
    cout << "\nRight Child of " << x <<" :"<< endl;
    p->right = create_();

    return p;
}

void tree::Preorder_(Node *rootPtr)
{
    if (rootPtr == NULL)
        return;

    cout << rootPtr->data << " ";
    Preorder_(rootPtr->left);
    Preorder_(rootPtr->right);
}

void tree::Inorder_(Node *rootPtr)
{
    if (rootPtr == NULL)
        return;

    Inorder_(rootPtr->left);
    cout << rootPtr->data << " ";
    Inorder_(rootPtr->right);
}

void tree::Postorder_(Node *rootPtr)
{
    if (rootPtr == NULL)
        return;

    Postorder_(rootPtr->left);
    Postorder_(rootPtr->right);
    cout << rootPtr->data << " ";
}

int main(){
    int choice;
    tree t;
    do{
        cout<<"\n1. Create Tree\n2. Preorder(recurssive)\n3. Inorder(recurssive)\n4. Postorder(recurssive)\n5. Exit :(\n"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            t.create();
            cout<<endl;
            break;
        case 2:
            t.Preorder();
            cout<<endl;
            break;
        case 3:
            t.Inorder();
            cout<<endl;
            break;
        case 4:
            t.Postorder();
            cout<<endl;
            break;    
        default:
            break;
        }
    }while(choice!=5);
}