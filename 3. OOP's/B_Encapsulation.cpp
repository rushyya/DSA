#include <iostream>
using namespace std;

class Employee
{
private:
    string Name;
    string Company;
    int Age;

public:
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }

    void setName(string name)
    {
        Name = name;
    }
    string getName()
    {
        return Name;
    }

    void setCompany(string company)
    {
        Company = company;
    }
    string getCompany()
    {
        return Company;
    }

    void setAge(int age)
    {
        if (age >= 18)
            Age = age;
    }
    int getAge()
    {
        return Age;
    }

    void IntroduceUrself()
    {
        cout << "Name: " << Name << endl;
        cout << "Company: " << Company << endl;
        cout << "Age: " << Age << endl;
    }
};

int main()
{
    Employee emp1 = Employee("Rushi", "Google", 20);
    emp1.setAge(35);
    cout << "now age: " << emp1.getAge() << endl;
    emp1.setAge(17);
    cout << "modified age: " << emp1.getAge() << endl;
}