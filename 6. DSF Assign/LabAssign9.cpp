#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) 
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void build_heap(int arr[], int n)
{
    for(int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
    for(int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void display(int arr[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout<<"\n";
}


int main()
{
    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Enter Element "<<i+1<<" : ";
        cin>>arr[i];
    }
    
    build_heap(arr,n);
    cout<<"Before Sorting : ";
    display(arr,n);
    
    heapSort(arr,n);
    
    cout<<"\nAfter Sorting : ";
    display(arr,n);

    return 0;
}
