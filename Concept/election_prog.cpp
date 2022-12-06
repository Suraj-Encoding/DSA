// # Election Program
#include <iostream>
using namespace std;

// Function declaration
int election(int T);
int duplication(int N);

// Global array
int *arr, *un;

// Global Variables
int i, j, M;

// main function
int main()
{
    int T, count, i;
    cout << "\n# Sport Election #" << endl;
    cout << "# Candidates: ";
    cout << "\n 1.JANI\n 2.RAMYA" << endl;
    cout << "# Number of test cases: ";
    cin >> T;
    for (i = 0; i < T; i++)
    {
        cout << "\n* Test Case-" << (i + 1) << ":" << endl;
        count = election(T);
        cout << "# Winner:  ";
        if (count >= M)
            cout << "JANI!\n"
                 << endl;
        else
            cout << "RAMYA!\n"
                 << endl;
    }
    return 0;
}

int election(int T)
{
    int N, k;
    // Input people and min_votes
    cout << "Number of people: ";
    cin >> N;
    cout << "Minimum unique votes: ";
    cin >> M;

    // Dynamic memory allocation
    arr = new (nothrow) int[N];
    un = new (nothrow) int[N];

    // Enter votes as integer value
    cout << "\nEnter Voting Integers: " << endl;
    for (i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    // Display Integers
    cout << "\n* Voting Integers: " << endl;
    for (i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

    // Call duplication function
    k = duplication(N);

    // Display unique votes
    cout << "\n\n* Unique Votes: " << endl;
    for (i = 0; i < k; i++)
    {
        cout << un[i] << " ";
    }
    cout << "\n\n* Number of unique votes: " << k << endl;
    cout << endl;
    return k;
}

int duplication(int N)
{
    int key, flag, count, k;
    count = 0;
    for (i = 0; i < N; i++)
    {
        key = arr[i];
        flag = 0;
        k = 0;
        for (j = i; j < N; j++)
        {
            if (key == arr[j])
                flag = 1;
        }

        if (flag == 1 && i > 0)
        {
            for (int l = 0; l < i; l++)
            {
                if (key == arr[l])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                un[count] = key;
                count++;
            }
        }
        else
        {
            un[count] = key;
            count++;
        }
    }
    return count;
}
