// Insert Node at nth position in linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head;

void Insert(int data, int n);
void print();

int main()
{
    head = NULL; //empty list
    Insert(2, 1);
    Insert(3, 2);
    Insert(4, 1);
    Insert(5, 2);
    print();
}

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