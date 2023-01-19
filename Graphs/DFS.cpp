// # DFS
// # Using Recursion -> Functions by default uses stack
#include <iostream>
using namespace std;

// # Global
int v[7] = {0, 0, 0, 0, 0, 0, 0};
int a[7][7] =
    {
        {0, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 0, 1, 1, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

// # DFS
void DFS(int i)
{
    cout << i << " ";
    v[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        // !v[j] -> v[j]==0
        if (a[i][j] == 1 && !v[j])
        {
            DFS(j);
        }
    }
}

int main()
{
    // # DFS Implementation
    cout << "\n# DFS Traversal #\n";
    int i = 4; // source node
    cout << "\n# Source Node: " << i << endl;
    cout << "\n# DFS Traversal: ";
    DFS(i);
    cout<<"\n\n";
    return 0;
}
