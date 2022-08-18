// Linked List in C/C++ - Inserting a node at beginning
#include<stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;    
}Node;

Node* head;//global head pointer variable
// inserting at the beginning
void insert(int x){
    Node* temp;
    temp = (Node*) malloc(sizeof(Node));
    temp->data= x;
    
    temp->next= head;
    
    head= temp;

}
// printing
void print(){
    Node* temp= head;
    printf("List is: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp= temp->next;
    }
    printf("\n");
}

int main(){
    int x, i, n;
    printf("How many no's: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("Enter the no: ");
        scanf("%d", &x);
        insert(x);
        print(x);
    }
    return 0;
}