// # Shell Sort
#include <iostream>
#include <algorithm>
using namespace std;

// # Shell sort
void Shell_Sort(int *arr, int n)
{
    int i, j, gap;
    for (gap = n / 2; gap >= 1; gap = gap / 2)
    {
        for (j = gap; j < n; j++)
        {
            for (i = j - gap; i >= 0; i = i - gap)
            {
                if (arr[i] > arr[i + gap])
                    swap(arr[i], arr[i + gap]);
                else
                    break;
            }
        }
    }
}

// # Display Array
void display(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n\n";
}

// # Main Function
int main()
{
    int *arr, n, i;
    cout << "\n# Shell Sort #\n";
    cout << "\n# Enter array size: ";
    cin >> n;
    arr = new int[n];

    // # Enter array
    cout << "\n# Enter array: " << endl;
    for (i = 0; i < n; i++)
        cin >> arr[i];

    // # Given array
    cout << "\n# Given array: " << endl;
    display(arr, n);

    // # Shell Sort
    Shell_Sort(arr, n);

    // # Sorted array
    cout << "# Sorted array: " << endl;
    display(arr, n);

    return 0;
}