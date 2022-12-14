// # Assignment-8
// # Prim's Algorithm
// # MST Implementation
#include <iostream>
using namespace std;
#define V 5 // Vertices

// # Minimum weight
int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
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
void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1; // First node is always root of MST

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
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
    primMST(graph);
    cout << "\n";
    return 0;
}
