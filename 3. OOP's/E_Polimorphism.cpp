#include <iostream>
using namespace std;

// Abstract Class
class IEmployee{
    virtual void AskForPromotion()=0; // pure virtual function
};

//employee class
class Employee:IEmployee
{
private:
    string Company;
    int Age;

protected:
    string Name;

public:
    //constructor
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }

    //getters and setters
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

    // Introduce function
    void IntroduceUrself()
    {
        cout << "Name: " << Name << endl;
        cout << "Company: " << Company << endl;
        cout << "Age: " << Age << endl;
    }

    //overiding of abstract function
    void AskForPromotion(){
        if(Age>30){
            cout<<Name<<" got Promoted!"<<endl;
        }
        else{
            cout<<Name<<", sorry No promotion for You :("<<endl;
        }
    }
    //understand why we used virtual...if we would have wouldn't then for e1 and e2 we would have got this work function
    virtual  void work(){
        cout<<Name<<" is checking email, task backlog, performing tasks....."<<endl;
    }
};
// Developer Class
class Developer:public Employee{
public:
    string FavProgrammingLanguage;

    // constructor
    Developer(string name, string company, int age, string favProgrammingLanguage)
        :Employee(name, company, age)  
    {
        FavProgrammingLanguage=favProgrammingLanguage;
    }

    // behaviour
    void fixBug(){
        cout<< Name <<" Fixed a bug using "<<FavProgrammingLanguage<<endl;//we have made Name protected so we were able to acess it here directly else we were nedded to use getters and setters
    }
    void work(){
        cout<<Name<<" is coding in "<< FavProgrammingLanguage<<endl;
    }
};

// Teacher Class
class Teacher:public Employee{
public:
    string Subject;

    // constructor
    Teacher(string name, string company, int age, string subject)
        :Employee(name, company, age)
    {
        Subject= subject;
    }
    // behaviour
    void PrepareLesson(){
        cout<< Name <<" has prepared "<< Subject <<endl;
    }
    void work(){
        cout<<Name<<" is teaching "<< Subject<<endl;
    }
};

int main()
{
    // created a developer
    Developer d = Developer("Rushi", "Google", 25, "C++");

    // created a Teacher
    Teacher t = Teacher("Jack", "Cool School", 35, "History");

    d.work();
    t.work();
    // the most common use of polymorphism is when a parent class reference is used to refer to a child class object

    Employee *e1= &d;
    Employee *e2= &t;

    e1->work();
    e2->work();
}