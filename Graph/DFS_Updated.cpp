// # DFS
// # Using Recursion -> Functions by default uses stack
#include <iostream>
using namespace std;
#define N 10

// # Global
int *v;
int a[N][N];

// # DFS
void DFS(int i)
{
    cout << i << " ";
    v[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (a[i][j] == 1 && !v[j])
        {
            DFS(j);
        }
    }
}

// # Main
int main()
{
    // # DFS Implementation
    int n, j;
    int i; // Source Node
    cout << "\n# DFS Traversal #\n";
    cout << "\n# Enter number of nodes in graph: ";
    cin >> n;
    v = new int[n];
    for (i = 0; i < n; i++)
        v[i] = 0;
    cout << "\n# Enter adjacency matrix: " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "\n# Enter source node: ";
    cin >> i;
    cout << "\n# Source Node: " << i << endl;
    cout << "\n# DFS Traversal: ";
    DFS(i);
    cout << "\n\n";
    return 0;
}
