#include <bits/stdc++.h>
using namespace std;

int  main(){
    int n;
    cin>>n;
    // this all operations we can similarly do with arays
    vector <int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int min = *min_element(v.begin(), v.end()); //returns iterator   
    cout<<min<<endl;
    int max = *max_element(v.begin(), v.end());
    cout<< max<<endl;

    int sum = accumulate(v.begin(), v.end(), 0);
    cout<<sum<<endl;

    int ct = count(v.begin(), v.end(), 6);
    cout<<ct<<endl;

    auto it = find(v.begin(), v.end(), 2);
    if(it != v.end()){
        cout<<*it<<endl;
    }
    else{
        cout<<"Element Not found"<<endl;
    }
    reverse(v.begin()+2, v.end());
    for(auto val : v){
        cout<< val<<" ";
    }
    cout<<endl;
    string s = "edasfa";
    reverse(s.begin(), s.end());
    cout<< s <<endl;
    // ye sare function/operatins ka tc O(n) he
}
// 6 2 3 1 6 7 6