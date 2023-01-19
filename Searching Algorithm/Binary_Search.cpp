// # Binary Search
// # Iterative Approach -> Using Iteration
// # Condition -> Array should be sorted in ascending order for binary search
#include <iostream>
using namespace std;

// # Binary Search
int Binary(int *arr, int n, int key)
{
    int l, r, mid;
    l = 0, r = n - 1;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (key == arr[mid])
            return mid;
        else if (key > arr[mid])
            l = mid + 1;
        else
            r = mid - 1;
    }
    return n;
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
    loc = Binary(arr, n, key);
    if (loc == n)
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