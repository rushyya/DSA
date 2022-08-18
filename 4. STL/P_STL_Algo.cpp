#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    vector <int> v;
    //wkt for binary search the prequisite is that the list must be sorted
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout<<"Finding 6-> "<<binary_search(v.begin(), v.end(), 6)<<endl;

    cout<<"lower bound-> "<<lower_bound(v.begin(), v.end(), 6)-v.begin()<<endl;
    cout<<"lower bound-> "<<upper_bound(v.begin(), v.end(), 6)-v.begin()<<endl;

    int a=3;
    int b=5;

    cout<<"max-> "<<max(a,b)<<endl;
    cout<<"min-> "<<min(a,b)<<endl;

    swap(a,b);//similarly we can swap vectors or stack and other containers which we saw previously
    cout<<"a->"<<a<<endl;

    string s="abcd";
    reverse(s.begin(), s.end());
    cout<<"string-> "<<s<<endl;

    rotate(v.begin(),v.begin()+1,v.end());
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;
    
    sort(v.begin(), v.end());
    cout<<"After Sorting: "<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}