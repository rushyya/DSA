#include <iostream>
#include <array> //including array library for stl wala array
using namespace std;

int main()
{
    // basic array
    int basic[3] = {1, 2, 3};

    // creating array in stl array< data_type, no_of_elements> Name
    array<int, 4> a = {1, 2, 3, 4};
    // this array is implemented using the basic array only ye array bhi static he...in cp we dont use this array

    // size of the array
    int size= a.size();

    // traversing or Printing the array
    for(int i=0; i<size; i++){
        cout<<a[i]<<endl;
    }

    // gets element at specific index in the array
    cout<<"Element at 2nd index-> "<< a.at(2) <<endl; //OR we can use a[2]

    //checks whether our array is empty or not
    cout<<"Empty or Not-> "<< a.empty()<<endl;

    // gets first and last element of the array
    cout<<"First Element-> "<<a.front()<<endl;
    cout<<"Last Element-> "<<a.back()<<endl;
    return 0;
}