// # Assignment-8
// # MST Implementation
// # Using Prim's Algorithm
// # Time Complexity -> O(v^2)
#include <iostream>
#include <vector>
using namespace std;
#define V 5 // Vertices

// # Minimum weight
int selectMinVertex(vector<int> &value, vector<bool> &setMST)
{
    int min = INT_MAX;
    int vertex;
    for (int i = 0; i < V; i++)
    {
        if (setMST[i] == false && value[i] < min)
        {
            vertex = i;
            min = value[i];
        }
    }
    return vertex;
}

// # Print MST
int printMST(int parent[], int graph[V][V])
{
    int wt = 0;
    cout << "  Edge  |  Weight\n";
    cout << "------------------\n";
    for (int i = 1; i < V; i++)
    {
        cout << "  " << parent[i] << " - " << i << "  |   " << graph[i][parent[i]] << " \n";
        wt = wt + graph[i][parent[i]];
    }
    return wt;
}

// # Prims Algorithm
void findMST(int graph[V][V])
{
    int parent[V];
    vector<int> value(V, INT_MAX);
    vector<bool> setMST(V, false);
    value[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < V - 1; i++)
    {
        int u = selectMinVertex(value, setMST);
        setMST[u] = true;
        for (int j = 0; j < V; j++)
        {
            if (graph[u][j] != 0 && setMST[j] == false && graph[u][j] < value[j])
            {
                value[j] = graph[u][j];
                parent[j] = u;
            }
        }
    }
    int wt = printMST(parent, graph);
    cout << "\n# Vertices = " << V << "\n\n# Edges = " << (V - 1) << "\n";
    cout << "\n# Minimum weight of ST: " << wt << endl;
}

// # Main Function
int main()
{
    // # Graph
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};
    cout << "\n# MST Implementation #" << endl;
    cout << "\n# MST:\n\n ";
    findMST(graph);
    cout << "\n";
    return 0;
}
