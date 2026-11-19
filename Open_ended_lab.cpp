// Student Attendance Manager
#include <iostream>
using namespace std;
const int MAX = 100;
void display(int arr[], int n)
{
    cout << "Roll Numbers: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertNumber(int arr[], int &n, int value, int pos)
{
    if (n == MAX)
    {
        cout << "Array is full!" << endl;
        return;
    }

    if (pos < 1 || pos > n + 1)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    for (int i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = value;
    n++;

    cout << "Roll number inserted successfully." << endl;
    display(arr, n);
}

void deleteNumber(int arr[], int &n, int value)
{
    int index = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Roll number not found!" << endl;
        return;
    }

    for (int i = index; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    cout << "Roll number deleted successfully." << endl;
    display(arr, n);
}

void searchNumber(int arr[], int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            cout << "Roll number found at position " << i + 1 << endl;
            return;
        }
    }

    cout << "Roll number not found!" << endl;
}

void sortArray(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Array sorted successfully." << endl;
    display(arr, n);
}

void binarySearch(int arr[], int n, int value)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == value)
        {
            cout << "Roll number found at position "<< mid + 1 << endl;
            return;
        }
        else if (arr[mid] < value)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << "Roll number not found!" << endl;
}

int main()
{
    int arr[MAX];
    int n, choice, value, pos;

    cout << "Enter number of students: ";
    cin >> n;

    if (n < 0 || n > MAX)
    {
        cout << "Invalid array size!" << endl;
        return 0;
    }

    cout << "Enter roll numbers:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    display(arr, n);

    do
    {
        cout << "\n===== STUDENT ATTENDANCE MANAGER =====" << endl;
        cout << "1. Insert Roll Number" << endl;
        cout << "2. Delete Roll Number" << endl;
        cout << "3. Search Roll Number" << endl;
        cout << "4. Sort Array" << endl;
        cout << "5. Binary Search" << endl;
        cout << "6. Display Array" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "Enter roll number: ";
            cin >> value;

            cout << "Enter position: ";
            cin >> pos;

            insertNumber(arr, n, value, pos);
            break;

        case 2:
            cout << "Enter roll number to delete: ";
            cin >> value;

            deleteNumber(arr, n, value);
            break;

        case 3:
            cout << "Enter roll number to search: ";
            cin >> value;

            searchNumber(arr, n, value);
            break;

        case 4:
            sortArray(arr, n);
            break;

        case 5:
            cout << "Enter roll number for binary search: ";
            cin >> value;

            binarySearch(arr, n, value);
            break;

        case 6:
            display(arr, n);
            break;

        case 0:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}