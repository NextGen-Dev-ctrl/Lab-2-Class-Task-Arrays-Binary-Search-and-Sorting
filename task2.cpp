// Recursive binary search
#include<iostream>
using namespace std;
int binary_search(int arr[], int low, int high,int value)
{
    if (low > high) 
    {
        return -1;
    }
    int mid = low + (high - low) / 2;

    if (arr[mid] == value) 
    {
        return mid; 
    }

    if (arr[mid] < value) 
    {
        return binary_search(arr, mid + 1, high, value);
    }
    return binary_search(arr, low, mid - 1, value);
}
int main()
{
    int arr[] = {50,120,175,240,300,450,620};
    int size_of_arry = sizeof(arr)/sizeof(arr[0]);
    // sort in acending order
    for(int i = 0; i < size_of_arry; i++)
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
    int value;
    cout << "Enter the number you want to search for: ";
    cin >> value;
    int result = binary_search(arr,0,size_of_arry - 1,value);
    if (result != -1) 
    {
        cout <<arr[result]<< " found at index: " << result << endl;
    } else 
    {
        cout << "Element not found in the array." << endl;
    }
}