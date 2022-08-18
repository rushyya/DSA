// Very imp in terms of nesting

#include <bits/stdc++.h>
using namespace std;

int  main(){
    map<pair<string, string>, vector<int>> m;
    set<pair<int,int>> st;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string fn, ln;
        int ct;
        cin>>fn>>ln>>ct;
        for(int j=0; j<ct; i++){
            int x;
            cin>>x;
            m[{fn, ln}].push_back(x);
        }
    }
    for(auto &pr: m){
        auto &full_name = pr.first;
        auto &list = pr.second;
        cout<<full_name.first<<" "<<full_name.second<<endl;
        cout<<list.size()<<endl;
        for(auto &element: list){
            cout<<element<<" ";
        }
        cout<<endl;
    }
    return 0;
}