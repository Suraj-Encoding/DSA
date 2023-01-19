// # Merge Sort
#include <iostream>
using namespace std;

// # Merge
void Merge(int *arr, int lb, int mid, int ub)
{
    int i, j, k;
    i = lb;
    j = mid + 1;
    k = lb;
    int b[10];
    while (i <= mid && j <= ub)
    {
        if (arr[i] <= arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    while (j <= ub)
    {
        b[k] = arr[j];
        j++;
        k++;
    }
    while (i <= mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }
    // # Copy b to arr
    for (k = lb; k <= ub; k++)
        arr[k] = b[k];
}

// # Merge Sort
void Merge_Sort(int *arr, int lb, int ub)
{
    int mid;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;
        Merge_Sort(arr, lb, mid);
        Merge_Sort(arr, mid + 1, ub);
        Merge(arr, lb, mid, ub);
    }
}

// # Display Array
void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// # Main Function
int main()
{
    int *arr;
    int lb, ub, n, i;
    cout << "\n# Merge Sort #\n";
    cout << "\n# Enter array size: ";
    cin >> n;
    arr = new int[n];
    lb = 0, ub = n - 1;

    // # Enter array
    cout << "\n# Enter array: " << endl;
    for (i = 0; i < n; i++)
        cin >> arr[i];

    // # Given array
    cout << "\n# Given array: " << endl;
    display(arr, n);

    // # Merge Sort
    Merge_Sort(arr, lb, ub);

    // # Sorted array
    cout << "\n\n# Sorted array: " << endl;
    display(arr, n);

    cout << "\n\n";
    return 0;
}