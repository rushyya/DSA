#include <bits/stdc++.h>
using namespace std;

//Abstract class 
class IEmployee{
    virtual void AskForPromotion()=0; // pure virtual function
};

//employee class
class Employee:IEmployee
{
public:
    string Name;
    string Company;
    int Age;

    //overiding
    void AskForPromotion(){
        if(Age>30){
            cout<<Name<<" got Promoted!"<<endl;
        }
        else{
            cout<<Name<<", sorry No promotion for You :("<<endl;
        }
    }
    //constructor
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }

};

int main()
{
    // created object
    Employee emp1 = Employee("Rushi", "Google", 20);
    Employee emp2 = Employee("Jack", "Amazon", 35);

    emp1.AskForPromotion();
    emp2.AskForPromotion();
}