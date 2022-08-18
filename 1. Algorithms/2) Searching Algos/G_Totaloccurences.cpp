//Count occurrences of a number in a sorted array with duplicates using Binary Search
#include<iostream>
using namespace std;

//by using linear Search 
int linearsearch(int A[], int n, int x){
    int count=0;
    for(int i=0; i<n; i++){
        if(A[i]==x){
            count++;
        }
    }
    return count;
}

//by using Binary search
int BinarySearch(int A[], int n, int x, bool FirstOcc){
    int low=0;
    int high= n-1;
    int result=-1;
    while(low<=high){
        int mid= low+(high-low)/2;
        if(x==A[mid]){
            result=mid;
            if(FirstOcc){
                high=mid-1;//go on searching towards left (lower indices)
            }
            else{
                low=mid+1;//go on searching towards Right (higher indices)
            }
        }
        else if(x<A[mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return result;
}

int main(){
    int A[]={1,3,3,3,5,5,5,8,8,9};
    int x;
    cout<<"Enter the no to find: ";
    cin>>x;
    int firstIndex= BinarySearch(A,sizeof(A)/sizeof(A[0]),x,true);
    if(firstIndex==-1){
        cout<<"Number "<<x<<" is not present in the array! ";
    }
    else{
        int lastindex=BinarySearch(A,sizeof(A)/sizeof(A[0]),x,false);
        int count= lastindex - firstIndex + 1;
        cout<<"count of no "<<x<<" is "<<count;  
    }

}