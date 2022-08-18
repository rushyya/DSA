#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string str="jadhgasyuigd";
    cout<<'a'-'A'<<endl;

    //to convet a string to Uppercase
    for(int i=0; i<str.size(); i++){
        if(str[i]>='a' && str[i]<='z'){
            str[i]=str[i]-32;
        }
    }
    cout<<str<<endl;

    //to convert to lowercase
    for(int i=0;i<str.size();i++){
        if(str[i]>='A' && str[i]<='Z'){
            str[i]=str[i]+32;
        }
    }
    cout<<str<<endl;

    //by inbuilt function
    string s="sakdghaikus";
    // convert to lower
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout<<s<<endl;
    //convert to upper
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout<<s<<endl;

    //to Form the biggest number from the numeric string
    string s1="15324";
    sort(s1.begin(), s1.end(), greater<int>());//as we have to sort this in decreasing order so we have to pass an extra argument that is greater
    cout<<s1<<endl;

    //to find the max occuring charecter in a string and also its frequency
    string s0="jkldfsajdkfkdkdkk";
    int freq[26];
    for(int i=0; i<26;i++){
        freq[i]=0;
    }
    for(int i=0;i<s0.length();i++){
        freq[s0[i]-'a']++;
    }
    char letter='a';
    int Maxcount=0;
    for(int i=0;i<26;i++){
        if(freq[i]>Maxcount){
            Maxcount=freq[i];
            letter='a'+i;
        }
    }
    cout<<letter<<" "<<Maxcount<<endl;
    
}