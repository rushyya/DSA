// Reverse a linked list using recursion
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;    
}Node;

Node* head;

void reverse(Node* p){
    if(p->next=NULL){
        head=p;
        return;
    }
    reverse(p->next);
    Node* q= p->next;
    q->next=p;
    p->next= NULL;
}
int main(){
    
    return 0;
}