// Using Quick Sort
#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void displayPass(int A[],int end)
{
    printf("Pass: {");
    for (int i = 0; i <= end; i++)
    {
        printf(" %d,", A[i]);
    }
    printf("}\n");
}

int partition(int A[], int start, int end)
{
    int pivot = A[end];
    int pIndex = start;
    for (int i = start; i < end; i++)
    {
        if (A[i] < pivot)
        {
            swap(&A[i], &A[pIndex]);
            pIndex++;
        }
    }
    swap(&A[pIndex], &A[end]);
    return pIndex;
}
void quicksort(int A[], int start, int end)
{
    if (start < end)
    {   
        displayPass(A,end);
        int pIndex = partition(A, start, end);
        quicksort(A, start, pIndex - 1);
        quicksort(A, pIndex + 1, end);
    }
}

int main()
{
    int A[] = {11, 6, 15, 7, 4, 2, 13, 5, 9};
    quicksort(A, 0, 8);
    printf("Sorted: {");
    for (int i = 0; i < 9; i++)
    {
        printf(" %d,", A[i]);
    }
    printf("}\n");
}