#include <stdio.h>


int inter(int arr1[], int arr2[], int n1, int n2, int arr3[]);
int uni(int arr1[], int arr2[], int n1, int n2, int arr3[]);
int diff(int arr1[], int n1, int arr2[], int n2, int arr3[]);
void accept(int arr[], int n);
void display(int arr[], int n);


int inter(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
    int n3 = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                arr3[n3] = arr1[i];
                n3++;
            }
        }
    }
    return n3;
}

int uni(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
    int i, j, n3;
    for (i = 0; i < n1; i++)
    {
        arr3[i] = arr1[i];
    }
    n3 = n1;

    for (i = 0; i < n2; i++)
    {
        for (j = 0; j < n3; j++)
        {
            if (arr3[j] == arr2[i])
            {
                break;
            }
        }
        if (j == n3)
        {
            arr3[n3] = arr2[i];
            n3++;
        }
    }
    return n3;
}

int diff(int arr1[], int n1, int arr2[], int n2, int arr3[])
{
    int k = 0;
    for (int i = 0; i < n1; i++)
    {
        int l = 0;
        for (int j = 0; j < n2; j++)
        {
            if (arr1[i] != arr2[j])
            {
                l++;
            }
        }
        if (l == n2)
        {
            arr3[k] = arr1[i];
            k++;
        }
    }
    return k;
}

void accept(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void display(int arr[], int n)
{
    printf("{");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("}\n");
}

int main()
{

    int set1[10], set2[10], set3[10], set4[10], set5[10], n1, n2, n3, n4, n5, choice;
    printf("Enter No of students who like Maths : ");
    scanf("%d", &n1);
    printf("Enter the roll no of %d students who like Maths : ", n1);
    accept(set1, n1);

    printf("Enter No of students who like Science : ");
    scanf("%d", &n2);
    printf("Enter the roll no of %d students who like Science : ", n2);
    accept(set2, n2);

    do
    {
        printf("\n1.Students who like Maths or Science \n2. Students who like Maths only\n");
        printf("3. Students who like Science only\n4. Students who like both Maths and Science \n5. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            n3 = uni(set1, set2, n1, n2, set3);
            printf("Roll No of students who like Maths or Science : ");
            display(set3, n3);
            printf("\n");
            break;

        case 2:
            n3 = diff(set1, n1, set2, n2, set3);
            printf("\n Roll No of students who like Maths only: ");
            display(set3, n3);
            printf("\n");
            break;

        case 3:
            n4 = diff(set2, n2, set1, n1, set4);
            printf("\n Roll No of students who like Science only: ");
            display(set4, n4);
            printf("\n");
            break;
        case 4:
            n3 = inter(set1, set2, n1, n2, set3);

            printf("\n Roll No of students who like both Maths and Science : ");
            display(set3, n3);
            printf("\n");
            break;
        }
    } while (choice != 5);
}
