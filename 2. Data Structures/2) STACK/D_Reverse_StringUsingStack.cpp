#include<iostream>
#include<stack>
#include <string.h>
using namespace std;

void reverse(char A[], int n){

    stack<char> S;

    for(int i=0; i<n; i++){
        S.push(A[i]);
    }

    for(int i=0; i<n; i++){
        A[i]= S.top();
        S.pop();
    }
}

int main(){
    char A[51];
    cout<<"enter the string:"<<endl;
    gets(A);
    reverse(A, strlen(A));
    cout<<A<<endl;
    // for(int i=0; i<A.length(); i++){
    //     cout<<A[i];
    // }
    return 0;
}