// # Linear Search OR Sequential Search
// # Recursive Approach -> Using Recursion
#include <iostream>
using namespace std;

// # linear search
int linear(int *arr, int n, int i, int key)
{
    if (i == n)
        return n;
    if (arr[i] == key)
        return i;
    else
        return linear(arr, n, i+1, key);
}

// # Main
int main()
{
    int *arr, n, i, loc, key;
    cout << "\n--- Linear Search ---\n";
    cout << "\nEnter the size of array: ";
    cin >> n;
    arr = new int[n];
    cout << "\nEnter array: ";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    cout << "\nEnter element to be search: ";
    cin >> key;
    // # linear search -> location is index or position -> position = index + 1
    loc = linear(arr, n, 0, key);
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