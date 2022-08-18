#include <bits/stdc++.h>
using namespace std;
void print(unordered_map<int, string> &m){
    cout<<m.size()<<endl;
    for(auto &pr: m){//O(nlogn)
        cout<<pr.first<<" "<<pr.second<<endl;
    }
}

int  main(){
    unordered_map<int, string> m;
    m[1] = "abc"; //O(logn)
    m[5] = "cdc";
    m.insert({3, "acd"});
    m[5] = "cde";

    auto it = m.find(5);//O(logn)

    // if(it == m.end()){
    //     cout<<"No value";
    // }else{
    //     cout<<(*it).first<<" "<<(*it).second<<endl;
    // }
    // m.erase(3);
    // if(it != m.end())
    //     m.erase(it);
    // m.clear();
    print(m);
}