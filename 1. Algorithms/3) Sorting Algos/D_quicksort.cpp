#include<iostream>
using namespace std;

int partition(int A[], int start, int end){
    int pivot=A[end];
    int pIndex=start;
    for(int i=start; i<end; i++){
        if(A[i]<pivot){
            swap(A[i],A[pIndex]); 
            pIndex++;
        }
    }
    swap(A[pIndex],A[end]);
    return pIndex;
}
void quicksort(int A[], int start, int end){
    if(start<end){
        int pIndex= partition(A,start,end);
        quicksort(A,start,pIndex-1);
        quicksort(A,pIndex+1,end);
    }
}

int main(){
    int A[]={2,6,7,3,4,1,8,5};
    quicksort(A,0,7);
    for(int i=0; i<8; i++){
        cout<<A[i]<<" ";
    }
}