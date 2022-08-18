#include <iomanip>
#include <iostream>
#include <fstream>
#include <string.h>
#define SIZE 10
#define h(x) x % SIZE
using namespace std;
struct student
{
    int rollno;
    char name[20];
    float marks;
    int status; // flag  for  empty=1,  occupied=0
    int link;
};
class lin_probe
{
    char table[30]; // name  of  file
    fstream tab;
    student rec; // object  for  reading/  writing
public:
    lin_probe(char *a);
    void displayall();
    void insert(student rec1);
    void Delete(int rollno);
    int search(int rollno);
    void display(int recno)
    {
        int i = recno;
        tab.open(table, ios::binary | ios::in);
        tab.seekg(recno * sizeof(student), ios::beg);
        tab.read((char *)&rec, sizeof(student));
        if (rec.status == 0)
        {
            cout << "\n"
                 << i << ")" << rec.rollno << "	" << rec.name << "	" << setprecision(2) << rec.marks;
        }
        else
            cout << "  " << rec.link;
        cout << "\n"
             << i << ")  *****  Empty	********";
        tab.close();
    }
    void read(int recno)
    {
        tab.open(table, ios::binary | ios::in);
        tab.seekg(recno * sizeof(student), ios::beg);
        tab.read((char *)&rec, sizeof(student));
        tab.close();
    }
    void write(int recno)
    {

        tab.open(table, ios::binary | ios::out | ios::in);

        tab.seekp(recno * sizeof(student), ios::beg);
        tab.write((char *)&rec, sizeof(student));
        tab.close();
    }
};
lin_probe::lin_probe(char *a)
{
    int i;
    strcpy(table, a);
    rec.status = 1;
    rec.link = -1;
    tab.open(table, ios::binary | ios::out);

    for (i = 0; i < SIZE; i++)
        write(i);

    tab.close();
}
void lin_probe::displayall()
{
    int i = 1, n;
    cout << "\n*********Data  File*********\n";
    for (i = 0; i < SIZE; i++)
        display(i);
}

void lin_probe::insert(student rec1)
{
    int n, i, j, start, k;
    rec1.status = 0;
    rec1.link = -1;
    start = h(rec1.rollno);
    for (i = 0; i < SIZE; i++)
    {
        j = (start + i) % SIZE;
        read(j);
        if (rec.status == 0 && h(rec.rollno) == start)
            break;
    }
    if (i < 10)
    {
        while (rec.link != -1)
        {
            j = rec.link;
            read(j);
        }
        for (i = 0; i < SIZE; i++)
        {
            k = (start + i) % SIZE;
            read(k);
            if (rec.status == 1)
            {
                rec = rec1;
                write(k);
                read(j);
                rec.link = k;
                write(j);
                return;
            }
        }
        cout << "\nTable  is  full  ";
    }
    else
    {
        for (i = 0; i < SIZE; i++)
        {
            k = (start + i) % SIZE;
            read(k);
            if (rec.status == 1)
            {
                rec = rec1;
                write(k);
                return;
            }
        }
        cout << "\nTable  is  full  ";
    }
}
void lin_probe::Delete(int rollno)
{
    student rec1;
    int recno;
    int i, j, start, k;
    start = h(rollno);
    for (i = 0; i < SIZE; i++)
    {

        j = (start + i) % SIZE;
        read(j);
        if (rec.status == 0 && h(rec.rollno) == start) // synonim
            break;
    }

    if (i < 10)
    {
        if (rec.rollno == rollno)
        {
            rec.status = 1;
            write(j);
        }
        else
        {
            while (rec.rollno != rollno && rec.link != -1)
            {
                k = j;
                j = rec.link;
                read(j);
            }

            if (rec.rollno == rollno)
            {
                rec.status = 1;
                write(j);
                int nextlink = rec.link;
                read(k);
                rec.link = nextlink;
                write(k);
            }
            else
                cout << "\nElement  not  found";
        }
    }
    else
        cout << "\nRecord  Not  Found  ";
}
int lin_probe::search(int rollno)
{
    int start, i, j;
    start = h(rollno);
    for (i = 0; i < SIZE; i++)
    {

        j = (start + i) % SIZE;
        read(j);
        if (rec.status == 0 && h(rec.rollno) == start) // synonim
            break;
    }

    if (i < 10)
    {
        while (rec.rollno != rollno && rec.link != -1)
        {

            j = rec.link;
            read(j);
        }

        if (rec.rollno == rollno)
            return (j);

        else

            return -1;
    }
    else

        return -1;
}
int main()
{
    lin_probe object("table.txt");
    int rollno, op, recno;
    student rec1;
    do
    {
        cout << "\n\n1)Print\n2)Insert\n3)Delete";
        cout << "\n4)Search\n5)Quit";
        cout << "\nEnter  Your  Choice:";
        cin >> op;
        switch (op)
        {
        case 1:
            object.displayall();
            break;
        case 2:
            cout << "\nEnter  a  record  to  be  inserted(roll no,name,marks) : ";
            cin >> rec1.rollno >> rec1.name >> rec1.marks;
            object.insert(rec1);
            break;
        case 3:
            cout << "\nEnter  the  roll  no.:";
            cin >> rollno;
            object.Delete(rollno);
            break;
        case 4:
            cout << "\nEnter  a  roll  no.  :  ";
            cin >> rollno;
            recno = object.search(rollno);
            if (recno >= 0)
            {
                cout << "\n  Record  No.:	" << recno;
                object.display(recno);
            }
            else
                cout << "\nRecord  Not  Found  ";
            break;
        }
    } while (op != 5);
    return 0;
}
