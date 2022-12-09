// # Merge Sort
// # Time Complexity:
//       O(nlogn) -> Worst case
//       O(nlogn) -> Avg Case
#include <iostream>
using namespace std;

// # Global
int *a, *b;

// # Merge
void Merge(int lb, int mid, int ub)
{
    int i, j, k;
    i = lb;
    j = mid + 1;
    k = lb;
    while (i <= mid && j < ub)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= ub)
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }
}

// # Merge Sort
void Merge_Sort(int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        Merge_Sort(lb, mid);
        Merge_Sort(mid + 1, ub);
        Merge(lb, mid, ub);
    }
}

// # Main Function
int main()
{
    int lb, ub, n, i;
    cout << "\n# Merge Sort #\n";
    cout << "\n# Enter array size: ";
    cin >> n;
    a = new (nothrow) int[n];
    b = new (nothrow) int[n];
    lb = 0, ub = n - 1;
    cout << "\n# Enter array: " << endl;
    for (i = 0; i < n; i++)
        cin >> a[i];
    cout << "\n# Given array: " << endl;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";

    // # Merge Sort
    Merge_Sort(lb, ub);
    for (i = lb; i <= ub; i++)
        a[i] = b[i];
    delete[] b;

    cout << "\n\n# Sorted array: " << endl;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n\n";
    return 0;
}