// # Radix Sort OR Bucket Sort
#include <iostream>
using namespace std;
#define B 10
// B stands for Base -> for decimal numbers base is 10

// # Get Maximum Number
int getMax(int *arr, int n)
{
     int i, k;
     k = arr[0];
     for (i = 0; i < n; i++)
          if (arr[i] >= k)
               k = arr[i];
     return k;
}

// # Count Sort
void Count_Sort(int *arr, int n, int pos)
{
     int count[B] = {0};
     int *b = new int[n];
     int i;
     for (i = 0; i < n; i++)
          ++count[(arr[i] / pos) % 10];
     for (i = 1; i < B; i++)
          count[i] = count[i] + count[i - 1];
     for (i = n - 1; i >= 0; i--)
          b[--count[(arr[i] / pos) % 10]] = arr[i];
     for (i = 0; i < n; i++)
          arr[i] = b[i];
     delete[] b;
}

// # Radix Sort
void Radix_Sort(int *arr, int n)
{
     int max = getMax(arr, n);
     for (int pos = 1; max / pos > 0; pos = pos * 10)
          Count_Sort(arr, n, pos);
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
     int *arr, n, i;
     cout << "\n# Radix Sort #\n";
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

     // # Radix Sort
     Radix_Sort(arr, n);

     // # Sorted array
     cout << "\n\n# Sorted array: " << endl;
     display(arr, n);

     cout << "\n\n";
     return 0;
}

/*
               #---- NOTE ---#
      1. It is not comparison based sort
      2. We does not compare numbers here
      3. We compare digits here
      4. Data is to be sorted digit by digit according to there place values
      5. Decimal Number -> made up of 'Digits'  |  Binary Number -> made up of 'Bits'
      6. Two types of values are there:
           Face value  - Actual value
           Place value - Position of that digit in the number
      7. Example: consider one number ->  421
            Number -    4          2       1
            Face   -    4          2       1
            Place  -  Hundreds    Tens    Ones
                      (100's)    (10's)   (1's)
            Digit  -    MSD        -       LSD
     8. Decimal -> MSD/LSD  |  Binary -> MSB/LSB
     9. MSD - Most Significant Digit |  LSD - Least Significant Digit
    10. Sorting is from LSD to MSD
*/