#include <iostream>
using namespace std;

int BinarySearch(int A[],int low,int High,int x){
    if(low>High) return -1;
    int mid=low+ (High-low)/2;
    
    if(x==A[mid]){
        return mid;
    } 
    else if(x<A[mid]){
        return BinarySearch(A,low,mid-1,x);
    } 
    else{
        return BinarySearch(A, mid+1, High,x);
    } 

}
int main(){
    int A[]={2,3,4,5,6,7,9};
    cout<<"Enter the no to search: ";
    int x; 
    cin>>x;
    int index = BinarySearch(A,0,7,x);

    if(index != -1){
        cout<<"the no "<<x<<" is at index "<<index;
    }
    else{
       cout<<"the no "<<x<<" was not found!"; 
    } 
}