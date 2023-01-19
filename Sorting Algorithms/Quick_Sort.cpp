// # Quick Sort
#include <iostream>
using namespace std;

// # Swaping
void Swap(int &x, int &y)
{
    int t;
    t = x;
    x = y;
    y = t;
}

// # Partition -> Backbone of Quick Sort
int partition(int *arr, int lb, int ub)
{
    int pivot, start, end;
    pivot = arr[lb];
    start = lb;
    end = ub;
    while (start < end)
    {
        while (arr[start] <= pivot)
            start++;
        while (arr[end] > pivot)
            end--;
        if (start < end)
            Swap(arr[start], arr[end]);
    }
    Swap(arr[lb], arr[end]);
    return end;
}

// # Quick Sort
void Quick_Sort(int *arr, int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(arr, lb, ub);
        Quick_Sort(arr, lb, loc - 1);
        Quick_Sort(arr, loc + 1, ub);
    }
}

// # Main Function
int main()
{
    int *arr;
    int lb, ub, n, i;
    cout << "\n# Quick Sort #\n";
    cout << "\n# Enter array size: ";
    cin >> n;
    arr = new  int[n];
    lb = 0, ub = n - 1;

    // # Enter array
    cout << "\n# Enter array: " << endl;
    for (i = 0; i < n; i++)
        cin >> arr[i];

    // # Given array
    cout << "\n# Given array: " << endl;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";

    // # Quick sort
    Quick_Sort(arr, lb, ub);
    
    // # Sorted array
    cout << "\n\n# Sorted array: " << endl;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n\n";
    return 0;
}