#include<iostream>
using namespace std;

int BinarySearch(int A[],int n, int x){
    int high, low, mid;
    low=0; high=n-1;
    while(low<=high){
        mid=low+(high-low)/2;

        if(x==A[mid]){
            return mid;
        } 
        else if(x<A[mid]){
            high=mid-1;  //common error
        } 
        else{
            low=mid+1;  //common error
        } 
    }
    return -1;
}

int main(){
    int A[]={2,3,4,5,6,7,9};
    cout<<"Enter the no to search: ";
    int x; 
    cin>>x;
    int index = BinarySearch(A,7,x);

    if(index != -1){
        cout<<"the no "<<x<<" is at index "<<index;
    }
    else{
       cout<<"the no "<<x<<" was not found!"; 
    } 
}