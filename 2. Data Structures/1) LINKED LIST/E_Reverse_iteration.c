// Reverse a linked list by iteration
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* head;
void print();
void Insert(int data);
void Reverse();

int main(){
    head= NULL;
    Insert(2);
    Insert(4);
    Insert(5);
    Insert(7);
    print();
    Reverse();
    print();

    return 0;
}

void print(){
    Node* temp= head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp= temp->next;
    }
    printf("\n");
}

void Insert(int data){
    
    Node* temp1= head;
    Node* temp2= (Node*)malloc(sizeof(Node));
    temp2->data= data;
    temp2->next=NULL;

    if(temp1==NULL){
        head= temp2;
        return;
    }

    while(temp1->next != NULL){
        temp1= temp1->next;
    }
    temp1->next= temp2;
}

void Reverse()
{
    Node *current, *prev, *next;
    current= head;
    prev= NULL;
    while(current!=NULL){
        next= current->next;
        current->next= prev;
        prev= current;
        current= next;
    }
    head= prev;
}