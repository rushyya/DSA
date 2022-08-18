#include<iostream>
#include<list>

using namespace std;

int main(){
    list <int> l;
     
    l.push_back(1);
    l.push_front(2);

    l.erase(l.begin());

    cout<<"size :"<<l.size();

    // copy
    list <int> n(l);
}