//Merge sort algorithm
#include<iostream>
using namespace std;

void merge(int A[], int L[], int nL, int R[], int nR){
    int i,j,k;
    i=0;
    j=0;
    k=0;

    while(i<nL && j<nR){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
            k++;
        }
        else{
            A[k]=R[j];
            j++;
            k++;
        }
    }
    while(i<nL){
        A[k]=L[i];
        k++;
        i++;
    }
    while(j<nR){
        A[k]=R[j];
        k++;
        j++;
    }
}

void mergesort(int A[], int n ){
    int mid=n/2;
    if(n<2){
        return; 
    }
    int left[mid];
    int right[n-mid];
    for(int i=0; i<mid; i++){
        left[i]=A[i];
    }
    for(int j=0; j<(n-mid);j++){
        right[j]=A[mid+j];
    }
    mergesort(left, mid);
    mergesort(right, n-mid);
    merge(A,left,mid,right,n-mid);
}

int main(){
    int A[]={8,2,5,9,3,6,4,1};
    mergesort(A,8);
    for(int i=0;i<8; i++){
        cout<<A[i]<<", ";
    }
}