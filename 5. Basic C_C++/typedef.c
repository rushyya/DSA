#include<stdio.h>

typedef struct Student{
    int id;
    int marks;
    char fav_no;
    char name[34];

} std;

int main(){
    
    //by using prv name
    struct Student s1, s2;
    s1.id=24;
    s2.id=65;
    printf("Value of s1 id is: %d\n", s1.id);
    printf("Value of s2 id is: %d\n", s2.id);

    //by using alias name
    std s3, s4;
    s3.id=34;
    s4.id=54;
    printf("Value of s3 id is: %d\n", s3.id);
    printf("Value of s4 id is: %d\n", s4.id);

    //using typedef for pointers
    typedef int* intpointer;
    intpointer a,b;
    int c= 56;
    a= &c;
    b= &c;
    // typedef unsigned long ul;
    // ul l1, l2, l3;

    // typedef int integer;
    // integer a=10;
    // printf("a: %d \n", a);


    return 0;
}
