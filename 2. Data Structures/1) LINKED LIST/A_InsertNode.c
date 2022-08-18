// Linked list - implementation in C inserting node at the end
#include<stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* A;

void print(){
    struct Node* temp= A;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp= temp->next;
    }
}

int main(){

    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data= 2;
    temp->next= NULL;
    A=temp;

    temp= (struct Node*)malloc(sizeof(struct Node));
    temp->data=4;
    temp->next=NULL;

    struct Node* temp1= A;
    while(temp1->next != NULL ){
        temp1= temp1->next;
    }

    temp1->next= temp;

    print(A);

    return 0;
}