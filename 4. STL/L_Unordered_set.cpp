#include <bits/stdc++.h>
using namespace std;

void print(unordered_set<string> &s){
    // M1: TO print
    for(string value : s){
        cout<< value<<endl;
    }
    // M2: TO print
    // for(auto it = s.begin(); it!=s.end(); ++it){
    //     cout<<(*it)<<endl;
    // }  
}
int  main(){
    unordered_set<string> s;
    s.insert("abc"); //O(1)
    s.insert("zsdf");
    s.insert("bcd");
    s.insert("abc");
// accesing element directly
    auto it = s.find("abc"); //O(1)
    if(it!= s.end()){//check lagaya he
        // cout<<(*it);
        s.erase(it);
    }
    s.erase("abc");//O(1)
    print(s);
    return 0;
}