// # Array Program
#include <iostream>
using namespace std;

// Global declaration
int *arr, *arr1, *arr2;
int M, N, i, j;

// Function declaration
void solution(void);
void sort(void);

// main function
int main()
{
    int T, k;
    cout << "\n# Array Problem # \n"
         << endl;
    cout << "# Number of test cases: ";
    cin >> T;
    for (k = 0; k < T; k++)
    {
        cout << "\nTest Case-" << (k + 1) << ": " << endl;
        solution();
    }
    return 0;
}

// ** Function defination **

// # complete logic
void solution()
{
    // Variables
    int sum1 = 0, sum2 = 0, diff = 0;

    // Enter values
    cout << "Enter size of array: ";
    cin >> N;
    cout << "Enter size of sub-array: ";
    cin >> M;

    // Dynamic memory allocation
    arr = new (nothrow) int[N];
    arr1 = new (nothrow) int[M];
    arr2 = new (nothrow) int[N - M];

    // Enter array
    cout << "\n# Enter array: ";
    for (i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    // sort the given array
    sort();

    // Make two groups
    for (i = 0; i < M; i++)
    {
        arr1[i] = arr[i];
        sum1 += arr1[i];
    }
    j = 0;
    for (i = M; i < N; i++)
    {
        arr2[j] = arr[i];
        sum2 += arr2[j];
        j++;
    }

    // // free actual array
    // delete[] arr;

    // Display all data
    cout << "\n# Group-1 = {";
    for (i = 0; i < M; i++)
    {
        if (i == M - 1)
            cout << arr1[i];
        else
            cout << arr1[i] << ",";
    }
    cout << "}";
    cout << "\n\n# Group-2 = {";
    for (i = 0; i < (N - M); i++)
    {
        if (i == N - M - 1)
            cout << arr2[i];
        else
            cout << arr2[i] << ",";
    }
    cout << "}";
    cout << "\n\n* Group-1 sum is: " << sum1 << endl;
    cout << "\n* Group-2 sum is: " << sum2 << endl;
    diff = sum2 - sum1;
    cout << "\n# Maximum difference: " << diff << endl;
}

// # Sort Array
void sort()
{
    int temp, flag;
    for (i = 0; i < (N - 1); i++)
    {
        flag = 0;
        for (j = 0; j < (N - 1 - i); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}