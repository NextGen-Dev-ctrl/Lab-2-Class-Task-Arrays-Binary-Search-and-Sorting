// selection Sort
#include <iostream>
using namespace std;
const int SIZE = 6;
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
    cout << "Enter 6 numbers: ";
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

    cout << "Smallest: " << arr[0] << endl;
    cout << "Largest: " << arr[SIZE - 1] << endl;

    return 0;
}


