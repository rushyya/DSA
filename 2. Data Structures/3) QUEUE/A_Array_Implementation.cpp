// Array implementation of Queue
#include <bits/stdc++.h>
using namespace std;

int A[10];
int N = 10;
int front = -1;
int rear = -1;

bool isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int isFull()
{
    if ((rear + 1) % N == front)
    {
        return true;
    }
}

void Enqueue(int x)
{
    if (isFull())
    {
        return;
    }
    else if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % N;
    }
    A[rear] = x;
}

void Dequeue()
{
    if (isEmpty())
    {
        return;
    }
    else if (front == rear)
    {
        front == rear = -1;
    }
    else
    {
        front = (front + 1) % N;
    }
}

int main()
{

    return 0;
}