#include <iostream>

using namespace std;

int LinearSearch(int A[], int n, int x){
    for(int i=0;i<n;i++){
        if(A[i]==x){
            return i;
        }
    }
    return -1;
}

int main(){
    int A[]={2,3,4,1,5,6,7};
    cout<<"Enter the no to scan: ";
    int x; 
    cin>>x;
    int index = LinearSearch(A,7,x);
    
    if(index != -1){
        cout<<"the no "<<x<<" is at index "<<index;
    }
    else{
       cout<<"the no "<<x<<" was not found!"; 
    } 
}