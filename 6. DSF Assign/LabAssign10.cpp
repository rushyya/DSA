#include <iostream>
#include <fstream>
using namespace std;
struct Student
{
    char name[20];
    int roll_no, marks;
};
struct Student_Index
{
    int roll_no, position;
};
void insert()
{
    int n;
    Student s;
    Student_Index s_index;
    fstream file, index_file;
    file.open("Student.txt", ios::app);
    index_file.open("Student_Index.txt", ios::app);
    cout << "Enter Records:- " << endl;
    cout << "Enter name:- " << endl;
    cin >> s.name;
    cout << "Enter roll number:- " << endl;
    cin >> s.roll_no;
    cout << "Enter marks:- " << endl;
    cin >> s.marks;
    index_file.seekp(0, ios::end);
    file.seekp(0, ios::end);
    n = file.tellg() / (sizeof(s));
    file.write((char *)&s, sizeof(s));
    s_index.roll_no = s.roll_no;
    s_index.position = n;
    index_file.write((char *)&s_index, sizeof(s_index));
    n++;
    file.close();
    index_file.close();
}
void display()
{
    Student s;
    fstream file;
    file.open("Student.txt", ios::in | ios::out | ios::binary);
    while (file.read((char *)&s, sizeof(s)))
    {
        if (s.roll_no != -1)
        {
            cout << "\nName: " << s.name;
            cout << "\nRoll no: " << s.roll_no;
            cout << "\nMarks: " << s.marks;
            cout << "\n";
        }
    }
    file.close();
}
void update()
{
    int roll, position = -1, ind, ofset;
    Student s;
    Student_Index s_index;
    fstream file, index_file;
    file.open("Student.txt", ios::in | ios::out | ios::binary);
    index_file.open("Student_Index.txt", ios::in);
    cout << "Enter Roll no. to Update:- " << endl;
    cin >> roll;
    while (index_file.read((char *)&s_index, sizeof(s_index)))
    {
        if (roll == s_index.roll_no)
        {
            position = s_index.position;
            break;
        }
    }
    if (position == -1)
    {
        cout << "\n The record is not present in the file";
        return;
    }
    else
    {
        ofset = position * (sizeof(s));
        file.seekp(ofset);
        cout << "\n Enter the values for updation...";
        cout << "\n Name: ";
        cin >> s.name;
        cout << "\n Marks: ";
        cin >> s.marks;
        s.roll_no = roll;
        file.write((char *)&s, sizeof(s));
    }
    file.close();
    index_file.close();
}
void search(int roll)
{
    int position = -1, ofset;
    Student s;
    Student_Index s_index;
    fstream file, index_file;
    file.open("Student.txt", ios::in | ios::out | ios::binary);
    index_file.open("Student_Index.txt", ios::in);
    while (index_file.read((char *)&s_index, sizeof(s_index)))
    {
        if (roll == s_index.roll_no)
        {
            position = s_index.position;
            break;
        }
    }
    if (position == -1)
    {
        cout << "\n The record is not present in the file";
        return;
    }
    else
    {
        ofset = position * (sizeof(s));
        file.seekg(ofset, ios::beg);
        file.read((char *)&s, sizeof(s));
        if (s.roll_no == -1)
        {
            cout << "\n Record is not present in the file";
            return;
        }
        cout << "\n The Record is present in the file and it is...";
        cout << "\n Name: " << s.name;
        cout << "\n Roll No: " << s.roll_no;
        cout << "\n Marks: " << s.marks;
    }
    file.close();
    index_file.close();
}
void del(int roll)
{
    int position = -1, ofset;
    Student s;
    Student_Index s_index;
    fstream file, index_file;
    file.open("Student.txt", ios::in | ios::out | ios::binary);
    index_file.open("Student_Index.txt", ios::in);
    while (index_file.read((char *)&s_index, sizeof(s_index)))
    {
        if (roll == s_index.roll_no)
        {
            position = s_index.position;
            break;
        }
    }
    if (position == -1)
    {
        cout << "\n The record is not present in the file";
        return;
    }
    else
    {
        ofset = position * (sizeof(s));
        file.seekp(ofset);
        s.marks = -1;
        s.roll_no = -1;
        file.write((char *)&s, sizeof(s));
        ofset = position * sizeof(s_index);
        index_file.seekp(ofset);
        s_index.position = position;
        s_index.roll_no = -1;
        index_file.write((char *)&s_index, sizeof(s_index));
    }
    file.close();
    index_file.close();
}
int main()
{
    int choice, a;
    do
    {
cout<<"\n1)Enter Student's Information\n2)Display Student's Information\n3)Search Data\n4)Edit Data\n5)Delete Data\n6)Exit"<<endl;
cin>>choice;
cout << endl;
switch (choice)
{
case 1:
    insert();
    break;
case 2:
    display();
    break;
case 3:
    cout << "Enter roll no to search for data:- " << endl;
    cin >> a;
    search(a);
    break;
case 4:
    update();
    break;
case 5:
    cout << "Enter roll no to delete data:- " << endl;
    cin >> a;
    del(a);
    break;
}
    } while (choice != 6);
    return 0;
}
