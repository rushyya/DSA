#include <conio.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
int count = 0;
struct node
{
    struct node *prev;
    int roll;
    float marks;
    char name[20], dept[10];
    struct node *next;
} * top, *temp, *temp1, *temp2, *temp4;
void create()
{
    int roll;
    float marks;
    char name[20], dept[10], work[20];
    temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\nEnter roll: \n");
    scanf("%d", &roll);
    printf("\nEnter name: \n");
    scanf("%s", name);
    printf("\nEnter department: \n");
    scanf("%s", dept);
    printf("\nEnter marks: \n");
    scanf("%f", &marks);
    temp->roll = roll;
    strcpy(temp->name, name);
    strcpy(temp->dept, dept);
    temp->marks = marks;
    count++;
}
void insertbeg()
{
    if (top == NULL)
    {
        create();
        top = temp;
        temp1 = top;
    }
    else
    {
        create();
        temp->next = top;
        top->prev = temp;
        top = temp;
    }
}
void insertend()
{
    if (top == NULL)
    {
        create();
        top = temp;
        temp1 = top;
    }
    else
    {
        create();
        temp1->next = temp;
        temp->prev = temp1;
        temp1 = temp;
    }
}
void displaybeg()
{
    temp2 = top;
    if (temp2 == NULL)
    {
        printf("\n list is empty\n");
        return;
    }
    printf("\n linked list elements "
           "from beginning:\n");
    while (temp2 != NULL)
    {
        printf("%d %s %s %f \n",
               temp2->roll, temp2->name,
               temp2->dept, temp2->marks);
        temp2 = temp2->next;
    }
    printf("Number of students=%d", count);
}
int deleteend()
{
    struct node *temp;
    temp = top;
    if (temp == NULL)
    {
        printf("list is empty\n");
        return 0;
    }
    if (temp->next == NULL)
    {
        printf("%d %s %s %f\n",
               temp->roll, temp->name,
               temp->dept, temp->marks);
        free(temp);
        top = NULL;
    }
    else
    {
        temp = temp1;
        temp2 = temp1->prev;
        temp2->next = NULL;
        printf("%d %s %s %f\n",
               temp->roll, temp->name,
               temp->dept, temp->marks);
        free(temp);
        temp1 = temp2;
    }
    count--;
    return 0;
}
int deletebeg()
{
    struct node *temp;
    temp = top;
    if (temp == NULL)
    {
        printf("list is empty\n");
        return 0;
    }
    if (temp->next == NULL)
    {
        printf("%d %s %s %f\n",
               temp->roll, temp->name,
               temp->dept, temp->marks);
        free(temp);
        top = NULL;
    }
    else
    {
        top = top->next;
        top->prev = NULL;
        printf("%d %s %s %f\n",
               temp->roll, temp->name,
               temp->dept, temp->marks);
        free(temp);
    }
    count--;
    return 0;
}
void StudentDetails()
{
    int ch, n, i;
    top = NULL;
    temp = temp1 = NULL;
    printf("Student Database\n");
    printf("\n 1.Create a DLL of students");
    printf("\n 2.Display from beginning");
    printf("\n 3.Insert at end");
    printf("\n 4.Delete at end");
    printf("\n 5.Insert at beginning");
    printf("\n 6.Delete at beginning");
    printf("\n 7.Exit\n");
    printf("----------------------\n");
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n Enter number of Students:");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
                insertend();
            break;
        case 2:
            displaybeg();
            break;
        case 3:
            insertend();
            break;
        case 4:
            deleteend();
            break;
        case 5:
            insertbeg();
            break;
        case 6:
            deletebeg();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid entry\n");
        }
    }
}
int main()
{
    StudentDetails();
    return 0;
}