// Print elements of a linked list in forward and reverse order using recursion

#include <stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;    
}Node;

Node* head;

void Insert(int data, int n)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    //handled special case when we want to add at the begining of the list
    if (n == 1)
    {
        temp->next = head;
        head = temp;
        return;
    }

    Node *temp1 = head;
    for (int i = 0; i < n - 2; i++)
    {
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}

void Print(Node* p){
    
    if(p==NULL) return; //exit condition for recursion

    printf("%d ", p->data);//1st print the value in the node
    Print(p->next);//Recursive Call
    

}

void ReversePrint(Node* p){

    if(p==NULL) return;

    Print(p->next);
    printf("%d ", p->data);
}
int main()
{
    head = NULL; //empty list
    Insert(2, 1);
    Insert(3, 2);
    Insert(4, 1);
    Insert(5, 2);
    Print(head);
    printf("\n");
    ReversePrint(head);
}