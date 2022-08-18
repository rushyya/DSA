#include <bits/stdc++.h>
using namespace std;

int  main(){
    vector<int> v ={1,2,3,4};
    // vector<int> :: iterator it ;
    // for(it = v.begin(); it!=v.end(); it++){
    //     cout<<(*it)<<" ";
    // }

    vector<pair<int,int>> v_p = {{1,2},{2,3},{3,4}};
    vector<pair<int,int>> :: iterator it;
    for( it = v_p.begin(); it != v_p.end(); ++it){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }

    // video2
    
    return 0;
}