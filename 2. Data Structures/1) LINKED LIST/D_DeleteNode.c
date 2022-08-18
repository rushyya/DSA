// Delete Node at nth position

#include<stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* head;
void Insert(int data);
void print();
void delete(int n);

int main(){
    head= NULL;
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);
    print();
    int n;
    printf("Enter the position to delete: \n");
    scanf("%d", &n);
    delete(n);
    print();
    return 0;
}

void delete(int n){
    Node* temp1= head;

    if(n==1){
        head= temp1->next;
        free(temp1);
        return;
    }

    for(int i=0; i<n-2; i++){
        temp1= temp1->next;
    }
    Node* temp2= temp1->next;
    temp1->next= temp2->next;
    free(temp2);
    
}

void Insert(int data){
    Node* temp1= head;
    Node* temp= (Node*)malloc(sizeof(Node));
    temp->data= data;
    temp->next= NULL;
    if(temp1 == NULL){
        head= temp;
        return;
    }

    while(temp1->next != NULL){
        temp1= temp1->next;
    }
    temp1->next=temp;
}

void print()
{
    Node *temp = head;
    printf("The list id: \n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}