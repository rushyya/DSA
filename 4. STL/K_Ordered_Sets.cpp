#include <bits/stdc++.h>
using namespace std;

void print(set<string> &s){
    // M1: TO print
    for(string value : s){
        cout<< value <<endl;
    }
    // M2: TO print
    // for(auto it = s.begin(); it!=s.end(); ++it){
    //     cout<<(*it)<<endl;
    // }
}
 
int  main(){
    set<string> s;
    s.insert("abc"); //O(logn)
    s.insert("zsdf");
    s.insert("bcd");
    s.insert("abc");
// accesing element directly
    // auto it = s.find("abc"); //O(logn)
    // if(it!= s.end()){//check lagaya he
    //     // cout<<(*it);
    //     s.erase(it);
    // }
    s.erase("abc");
    print(s);
    return 0;
}