// # Duplication in an array
#include <iostream>
using namespace std;
int main()
{
    int n, i, j, key, k = 0, flag = -1, count;
    int un[10];
    // Enter size of array
    cout << "\nEnter size of array: ";
    cin >> n;
    // Dynamic memory allocation
    int *arr = new (nothrow) int[n];

    // Enter array elements
    cout << "Enter array: " << endl;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // display array
    cout << "Display array: " << endl;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Duplication
    for (i = 0; i < n; i++)
    {
        key = arr[i];
        count = 0;
        for (j = i; j < n; j++)
        {
            if (key == arr[j])
                count++;
        }
        if (flag == key)
        {
        }
        else
        {
            cout << "Repetition of " << key << " is: " << count << endl;
            flag = key;
            un[k] = key;
            k++;
        }
    }

    // Display unique elements of array
    cout << "Display unique array: " << endl;
    for (i = 0; i < k; i++)
    {
        cout << un[i] << " ";
    }
    cout << endl;

    // Free the memory using delete operator
    delete[] arr;

    return 0;
}