#include<stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* top;

void Push(int data){
    Node* temp= (Node*)malloc(sizeof(Node));
    temp->data= data;
    temp->next= top;
    top=temp;
}

void Pop(){
    if(top==NULL){
        return;
    }
    Node* temp=top;
    top=temp->next;
    free(temp);
}

int Top(){
    return top->data;
}

void print(){
    Node* temp= top;
    printf("Stack\n");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp= temp->next;
    }
    printf("\n");
}

int main(){
    top=NULL;
    Push(2);print();
    Push(6);print();
    Push(8);print();
    Pop();print();
    Push(9);print();

    return 0;
}