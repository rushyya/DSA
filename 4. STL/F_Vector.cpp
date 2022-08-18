// vector is a dynamic array...isme jaisehi apna vector bhar jata he...tb ye vector apna size double kr lega
#include<iostream>
#include<vector>//including vector library
using namespace std;

int main(){

    // creating a vector...whwnever we create a new vector its size will be zero
    vector<int> v;//1st way to initialize

    cout<<"Capacity-> "<<v.capacity()<<endl;
    cout<<"Size-> "<< v.size()<<endl;

    v.push_back(1);
    cout<<"Capacity-> "<<v.capacity()<<endl;
    cout<<"Size-> "<< v.size()<<endl;

    v.push_back(2);
    cout<<"Capacity-> "<<v.capacity()<<endl;
    cout<<"Size-> "<< v.size()<<endl;

    v.push_back(3);
    cout<<"Capacity-> "<<v.capacity()<<endl;
    cout<<"Size-> "<< v.size()<<endl;
    // size batata he kitne elements pade he...capacity batata he ki kitna elements ke liye space assign hua pada he

    cout<<"Elemnt at 2nd Index-> "<<v.at(2)<<endl;

    cout<<"first element-> "<<v.front()<<endl;
    cout<<"last element-> "<<v.back()<<endl;

    // we can also remove element from vector
    cout<<"before pop"<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;

    v.pop_back();

    cout<<"After pop"<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;

    // to clear a vector
    cout<<"before clear size-> "<< v.size() <<endl;
    v.clear();
    cout<<"After clear size-> "<< v.size() <<endl;

    vector<int> a(5, 1);//2nd way to initialize and create a vector
    // if we didnt write 1 here then by default all elements would have been intialized by 0
    cout<<"print a"<<endl;
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }cout<<endl;

    // copy one vector into another
    vector<int> last(a);
    cout<<"print last"<<endl;
    for(int i=0; i<last.size(); i++){
        cout<<last[i]<<" ";
    }cout<<endl;

    return 0;
}