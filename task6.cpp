// combine all things
#include<iostream>
using namespace std;
const int SIZE = 8;
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
void selectionSort(int arr[], int size) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        int minIndex = i;
        
        for (int j = i + 1; j < size; j++) 
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }
        
        if (minIndex != i) 
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}
int main()
{
    int arr[SIZE];
    cout << "Enter 8 numbers: ";
    for (int i = 0; i < SIZE; i++) 
    {
        cin >> arr[i];
    }

    selectionSort(arr, SIZE);

    cout << "Sorted: [ ";
    for (int i = 0; i < SIZE; i++) 
    {
        cout << arr[i] << " ";
    }
    cout<<" ]";
    cout << endl;

    int value;
    cout << "Enter the number you want to search for: ";
    cin >> value;
    int result = binary_search(arr,SIZE,value);
    if (result != -1) 
    {
        cout <<arr[result]<< " found at index: " << result << endl;
    } else 
    {
        cout << "Element not found in the array." << endl;
    }
}