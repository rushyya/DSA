#include <iostream>
using namespace std;

int binarySearch(int A[], int n, int x){
    int low=0;
    int high= n-1; int result=-1;
    while(low<=high){
        int mid= low+(high-low)/2;
        if(x == A[mid]){
            result=mid; 
            high= mid-1;//go on searching towards left (Lower indices);           
        }
        else if(x < A[mid]){
            high=mid-1;
        } 
        else{
            low=mid+1;
        } 
    }
    return result;
}

int main(){
    int A[]={4,4,4,4,6,7,9};
    cout<<"Enter the no to search: ";
    int x; 
    cin>>x;
    int index = binarySearch(A,7,x);

    if(index != -1){
        cout<<"the no "<<x<<" is at index "<<index;
    }
    else{
       cout<<"the no "<<x<<" was not found!"; 
    } 
}
