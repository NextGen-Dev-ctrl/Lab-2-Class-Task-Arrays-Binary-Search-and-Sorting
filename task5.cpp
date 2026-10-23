// Insertion sort with a shift counter
#include <iostream>
using namespace std;
int insertionSort(int arr[], int size) 
{
    int shifts = 0; 
    
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            shifts++; 
            j--;
        }
        arr[j + 1] = key;
    }
    
    return shifts;
}

int main() {
    int arr[] = {23, 11, 45, 8, 30};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int totalShifts = insertionSort(arr, size);
    
    cout << "Sorted: ";
    for (int i = 0; i < size; i++) 
    {
        std::cout << arr[i] << " ";
    }
    cout << std::endl;
    
    cout << "Shifts: " << totalShifts << std::endl;
    
    return 0;
}
