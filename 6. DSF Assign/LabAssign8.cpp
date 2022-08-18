#include <iostream>
#include <stdio.h>
#define SIZE 10
#define FALSE 0
#define TRUE 1
#define h(x) x%SIZE
using namespace std;

//With Replacement
void insert(int data[], int flag[], int chain[], int x)
{
    int i=0, j,start;
    start=h(x);
    
    if(flag[start]==0)
    {
        data[start]=x;
        flag[start]=1;
        return;
    }
    
    if(h(data[start])!=h(x))
    {
        i=0;
        j=start;
        while(flag[j] && i<SIZE)
        {
            j=(j+1)%SIZE;
            i++;
        }
        if(i==SIZE)
        {
            cout<<"\nThe Hash Table is FULL";
            return;
        }
        
        i=data[start]%SIZE;
        while(chain[i]!=start)
            i=chain[i];
        chain[i]=chain[start];
        
        while(chain[i]!=-1)
            i=chain[i];
        chain[i]=j;
        data[j]=data[start];
        chain[start]=-1;
        flag[j]=1;
        chain[j]=-1;
        
        data[start]=x;
        chain[start]=-1;
        return;
    }
    
    i=0;
    j=start;
    while(flag[j] && i<SIZE)
    {
        j=(j+1)%SIZE;
        i++;
    }
    if(i==SIZE)
    {
        cout<<"\nThe Hash Table is FULL";
        return;
    }
    data[j]=x;
    flag[j]=1;
    chain[j]=-1;
    //go to end of the chain
    i=start;
    while(chain[i]!= -1)
        i=chain[i];
    chain[i]=j;
    
}


int search(int data[], int flag[], int chain[], int x)
{
    int i=0,j;
    j=h(x);
    
    while(i<SIZE && flag[j] && data[j]%SIZE != x%SIZE)
    {
        i++;
        j=(j+1)%SIZE;
    }
    
    if(flag[j]!=1 || i==SIZE)
        return (-1);
    
    while(j!=-1)
    {
        if(data[j]==x)
            return(j);
        j=chain[j];
    }
    return(-1);
}

int main()
{
    int i,j,x,op,loc, data[SIZE], flag[SIZE], chain[SIZE];
    for(i=0;i<SIZE;i++)
    {
        flag[i]=FALSE;
        chain[i]=-1;
    }
    
    do{
        cout<<"\n1)Insert\n2)Search\n3)Quit\n";
        cout<<"Enter your choice : ";
        cin>>op;
        switch(op)
        {
            case 1:
                cout<<"\nEnter a number to be inserted : ";
                cin>>x;
                insert(data,flag,chain,x);
            break;
            
            case 2:
                cout<<"\nEnter a number to be searched : ";
                cin>>x;
                loc=search(data,flag,chain,x);
                if(loc==-1)
                {
                    cout<<"\nElement not found ";
                }
                else{
                    cout<<"\nElement found at location = "<<loc;
                }
            break;
            
           
        }
    }while(op!=3);
    
    return 0;
}  