#include <bits/stdc++.h>
using namespace std;

//what is std::string or any variable?
class Employee
{
public:
    // properties
    string Name;
    string Company;
    int Age;
    
    //constructors
    Employee(string name, string company, int age){
        Name= name;
        Company= company;
        Age= age;
    }

    //behavious
    void IntroduceUrself(){
        cout<<"Name: "<<Name<<endl;
        cout<<"Company: "<<Company<<endl;
        cout<<"Age: "<<Age<<endl;
    }
};

int main()
{
    Employee employee1= Employee("Rushi", "Google", 20);
    // employee1.Name="Rushi";
    // employee1.Company="Google";
    // employee1.Age= 20;
    employee1.IntroduceUrself();

    Employee employee2= Employee("Kedar", "Amazon", 24);
    // employee2.Name="Kedar";
    // employee2.Company="Amazon";
    // employee2.Age=24;
    employee2.IntroduceUrself();

    return 0;
}