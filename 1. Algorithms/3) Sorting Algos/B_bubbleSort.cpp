#include <iostream>

using namespace std;

void bubbleSort(int A[], int n){
    for(int i=1; i<n;i++){
        int flag=0;
        for(int j=0;j<n-i; j++){
            if(A[j]>A[j+1]){
                int temp=A[j];  //swap
                A[j]=A[j+1];
                A[j+1]=temp;
                flag=1;               
            }
        }
        if(flag==0)break;
    }
}

int main()
{
    int A[]= {2,4,7,1,5,3};
    bubbleSort(A,6);
    for(int i=0; i<6; i++){
        cout<<A[i]<<" ";
    }
    return 0;
}  