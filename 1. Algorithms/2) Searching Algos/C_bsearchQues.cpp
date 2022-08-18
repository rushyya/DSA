#include<iostream>
using namespace std;

int binarysearch(int A[],int n){
    int high=n-1;
    int low=0;
    if(A[low]<=A[high]){
        return low;
    }
    int mid= low+ (high-low)/2;
    if(A[mid]<A[mid+1] && A[mid]<A[mid-1]){
        return mid;
    }
    else if(A[mid]<A[high]){
        high=mid-1;
    }
    else if(A[mid]>A[low]){
        low=mid+1;
    }
}

int main(){
        
}