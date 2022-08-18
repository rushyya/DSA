// basic string functions
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    string s1= "fam";
    string s2= "ily";
    s1.append(s2);//append function adds s2 to s1 and makes new s1
    cout<<s1<<endl;

    cout<<s1[0]<<endl;//accesing a element in the string

    string s3="asldjaj flkajf j";
    s3.clear();//clears the whole string
    cout<<s3;  

    string s4="RushiGobare";
    s4.insert(5,"Bhau");//inserts charecters or strings at a particular index
    cout<<s4<<endl;
    cout<<s4.size()<<endl;//to find length of the string
    cout<<s4.length()<<endl;

    cout<<s4.substr(9,6);//to get a substring of a string

    string s5="786";
    int i=stoi(s5);//to convert a string of number to integer
    cout<<i<<endl;

    int j=987;
    string s6=to_string(j);//to convert a integer to string

    string s7="sadgkahak";
    sort(s7.begin(), s7.end());//to sortb the string in alphabetical order
    cout<<s7<<endl;
}