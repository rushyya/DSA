#include <bits/stdc++.h>
using namespace std;

// bool should_i_swap(int a, int b){
//     if(a>b) return true;
//     return false;
// }
// bool should_i_swap(pair<int, int> a, pair<int, int> b){
//     if(a.first != a.second){
//         if(a.first > b.first) return true;
//         return false;
//     }
//     else{
//         if(a.second < b.second) return true;
//         return false;
//     }
// }
// pehle ke according increasing and dusre ke according decreasing
bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first != a.second){
        // if(a.first > b.first) return false;
        // return true;
        return a.first < b.first;
    }
    else{
        // if(a.second < b.second) return false;
        // return true;
        return a.second > b.second;
    }
}

int  main(){
    int n;
    cin>>n;
    vector<pair<int, int>> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i].first>>a[i].second;
    }
    // for(int i=0; i<n; i++){
    //     for(int j = i+1; j<n; j++){
    //         if(should_i_swap(a[i], a[j])){//logic to swap....comparator function
    //             swap(a[i], a[j]);
    //         }
    //     }
    // }
    
    for(int i=0; i<n; i++){
        cout<<a[i] <<endl;
    }

    return 0;
}