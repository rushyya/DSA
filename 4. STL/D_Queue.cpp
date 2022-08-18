#include<iostream>
#include<queue>

using namespace std;

int main(){
     
    queue <string> q;

    q.push("love");
    q.push("babbar");
    q.push("kumar"); 

    cout<<"size before pop: "<<q.size()<<endl;

    cout<<"First Element: "<< q.front()<<endl;
    q.pop();
    cout<<"First Element: "<< q.front()<<endl;

    cout<<"size after pop: "<<q.size()<<endl;
    
}