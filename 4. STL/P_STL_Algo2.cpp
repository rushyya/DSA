#include <bits/stdc++.h>
using namespace std;
bool is_positive(int x){
        return x>0;
}

int  main(){
    // lambda function - it is basically a temporary function  
    // cout<< [](int x, int y){ return x+y;}(4,7)<<endl;
    // to reuse a lambda function assign it
    // we can also use lambda functio in cmparators
    auto sum = [](int x, int y){ return x+y;};
    cout<<sum(2,3)<<endl;
    
    // ye sare abhi niche wale functions true false return krte he... (true, false)
    // ALL_of function
    vector<int> v = {2,-1,-5};
    cout<< all_of(v.begin(), v.end(),[](int x){return x>0;})<<endl;
    // OR
    cout<< all_of(v.begin(), v.end(), is_positive)<<endl;

    // ANY_OF function
    cout<< any_of(v.begin(), v.end(),[](int x){return x>0;})<<endl;

    // NONE_OF function
    cout<< none_of(v.begin(), v.end(),[](int x){return x>0;})<<endl;

    // we can apply all these algos on array also
}