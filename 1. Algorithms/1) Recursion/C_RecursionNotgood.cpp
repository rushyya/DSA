//why recursion is not always good
#include<iostream>
using namespace std;

//by iteration
int fib1(int n){
    if(n<=1){
        return 1;
    }
    int f,f1,f2;
    f1=0;
    f2=1;
    for(int i=2; i<n; i++){
        f=f1+f2;
        f1=f2;
        f2=f;
    }
    return f;
}

//by recursion
int fib2(int n){
    if(n<=1){
        return 1;
    }
    return fib2(n-1)+fib2(n-2);
}

int main(){
    int n;
    cout<<"give me a no: ";
    cin>>n;

    int result= fib1(n);
    cout<<result;   
}