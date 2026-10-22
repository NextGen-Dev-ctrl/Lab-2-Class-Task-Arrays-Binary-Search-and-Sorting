// Bubble sort with a pass counter
#include <iostream>
using namespace std;
int bubbleSort(int arr[], int size) 
{
    int passes = 0;
    bool swapped;

    for (int i = 0; i < size - 1; i++) 
    {
        passes++; 
        swapped = false;

        for (int j = 0; j < size - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped) 
        {
            break;
        }
    }
    return passes;
}

void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() 
{
    int arr1[] = {9, 7, 5, 3, 1};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int passes1 = bubbleSort(arr1, size1);

    cout << "Array 1 sorted: ";
    printArray(arr1, size1);
    cout << "\nPasses: " << passes1 << "\n\n";

    int arr2[] = {1, 2, 3, 4, 5};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int passes2 = bubbleSort(arr2, size2);

    cout << "Array 2 sorted: ";
    printArray(arr2, size2);
    cout << "\nPasses: " << passes2 << "\n";

    return 0;
}
