// # Binary Search
// # Recursive Approach -> Using Recursion
// # Condition -> Array should be sorted in ascending order for binary search
#include <iostream>
using namespace std;

// # Binary Search
int Binary(int *arr, int l, int r, int key)
{
    int mid = (l + r) / 2;
    if (l > r)
        return -1;
    if (key == arr[mid])
        return mid;
    else if (key > arr[mid])
        return Binary(arr, mid + 1, r, key);
    else
        return Binary(arr, l, mid - 1, key);
}

// # Main
int main()
{
    int *arr, n, i, loc, key;
    cout << "\n--- Binary Search ---\n";
    cout << "\nEnter the size of array: ";
    cin >> n;
    arr = new int[n];
    cout << "\nEnter array: ";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    cout << "\nEnter element to be search: ";
    cin >> key;
    // # Binary Search
    loc = Binary(arr, 0, n - 1, key);
    if (loc == -1)
    {
        cout << "\nElement not found..." << endl;
        cout << "\n";
    }
    else
    {
        cout << "\nElement found at Index = " << loc;
        cout << " OR Position = " << ++loc << endl;
        cout << "\n";
    }
    return 0;
}