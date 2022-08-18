#include <stdio.h>
#include <conio.h>
#include<string.h>

void accept(char arr[5][10], int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d : ", i+1);
        scanf(" %s", arr[i]);
    }
}

void display(char arr[5][10], int n){
    int i;
    for(i=0; i<n; i++){
        printf("%s ", arr[i]);
    }
}

void insertionsort(char arr[5][10], int n){
    int i,j;
    char key[10];
    for(i=1;i<n;i++){
        strcpy(key, arr[i]);
        j=i-1;
        while(j>=0 && strcmp(arr[j], key)>0){
            strcpy(arr[j+1], arr[j]);
            j=j-1;
        }
        strcpy(arr[j+1], key);
        printf("\n");
        printf("\n Pass %d: ", i);
        for(int p=0; p<n; p++){
            printf("%s ", arr[p]);
        }
    }
    printf("\n");
}

void selectionsort(char arr[5][10], int n){
    int i,j,pos;
    char new[10];
    for(int i=0; i<n-1;i++){
        pos=i;
        strcpy(new, arr[i]);
        for(j=i+1; j<n; j++){
            if(strcmp(new, arr[j])<0){
                strcpy(new, arr[j]);
                pos=j;
            }
        }
        if(pos!=i)
        {
            char temp[10];
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[pos]);
            strcpy(arr[pos], temp);
        }
        printf("\n");
        printf("\n Pass %d: ", i+1);
        for(int p=0; p<n;p++){
            printf("%s ",arr[p]);
        }

    }
    printf("\n");
}

void binarysearch1(char arr[5][10], int n){
    int l, h, mid, flag=0;
    char find[10];
    printf("\n Enter the string u want to search: ");
    scanf("%s", &find);

    l=0;
    h=n-1;
    while(l<=h){
        mid=(l+h)/2;
        if(strcmp(find, arr[mid])>0){
            l=mid+1;
        }
        else if(strcmp(find, arr[mid])<0){
            h=mid-1;
        }
        else{
            flag=1;
            break;
        }
    }
    if(flag==1){
        printf("string found at position %d", (mid+1));
    }
    else{
        printf("\nstring not found");
    }
}

int binarysearch(char arr[5][10], int l, int r, char new[10]){
    if(r>=1){
        int mid= l+(r-l)/2;
        if(strcmp(arr[mid], new)==0){
            return mid;
        }
        if(strcmp(arr[mid], new)>0){
            return binarysearch(arr, 1, mid-1, new);
        }
        return binarysearch(arr, mid+1, r, new);
    }
    return -1;
}

void main(){
    int n, ch;
    char arr[5][10], key[10];
    char new[10];
    do{
        printf("\nMENU");
        printf("\n1.Create Data \n2.Insertion sort in Ascending Order\n");
        printf("3.Selection sort in descending order\n4.Binary search without recursion");
        printf("\n5.Binary search with recursion\n6.Exit");
        printf("\nEnter your choice:- ");
        printf("\n");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            printf("Enter the Number of Strings ");
            scanf("%d", &n);
            accept(arr, n);
            printf("\nGiven data are\n");
            display(arr, n);
            break;
        case 2:
            insertionsort(arr, n);
            printf("\nSorted Strings in ASCENDING ORDER are: ");
            display(arr,n);
            break;
        case 3:
            selectionsort(arr, n);
            printf("\nSorted strings in DESCENDING ORDER are: ");
            display(arr, n);
            break;
        case 4:
            insertionsort(arr, n);
            printf("\nGiven data are \n");
            display(arr,n);

            binarysearch1(arr, n);
            break;
        case 5:
            insertionsort(arr, n);
            printf("\n Given data are \n");
            display(arr, n);

            printf("\nEntered the string to be searched: ");
            scanf("%s", &new);
            int result= binarysearch(arr, 0, n-1, new);
            if(result==-1){
                printf("\nString not found");
            }
            else{
                printf("\nString found at position %d", result+1);
            }
            break;
        case 6:
            break;
        default:
            printf("\nEnter Valid Option");
        }
    }
    while(ch!=0);
}

