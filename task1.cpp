//Iterative binary search (ages)
#include<iostream>
using namespace std;
int binary_search(int arr[],int size,int value)
{
    int low = 0;
    int high = size - 1;

    while (low <= high) 
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == value) 
        {
            return mid; 
        }

        if (arr[mid] < value) 
        {
            low = mid + 1;
        }
        else 
        {
            high = mid - 1;
        }
    }

    return -1;
}
int main()
{
    int arr[] = {12,15,18,21,25,30,34,41};
    int size_of_arry = sizeof(arr)/sizeof(arr[0]);
    // sort in acending order
    for(int i = 0; i < size_of_arry; i++)  // if the array is not sorted
    {
        int smallest = arr[0];
        for(int j = i + 1; j < size_of_arry; j++)
        {
            if(arr[j] < smallest)
            {
                arr[i] = arr[j];
                arr[j] = smallest;
                smallest = arr[i];
            }
        }
    }
    cout<<"Sorted : [ ";
    for(int k : arr)
    {
        cout<<k<<" ";
    }
    cout<<" ]"<<endl;
    int value;
    cout << "Enter the number you want to search for: ";
    cin >> value;
    int result = binary_search(arr,size_of_arry,value);
    if (result != -1) 
    {
        cout <<arr[result]<< " found at index: " << result << endl;
    } else 
    {
        cout << "Element not found in the array." << endl;
    }
}