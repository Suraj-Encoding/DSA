// # BFS
#include <iostream>
using namespace std;

// # Global
int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int a[7][7] =
    {
        {0, 1, 1, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0}};

// # Queue
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int IsEmpty(struct queue *q)
{
    if (q->r == q->f)
        return 1;
    else
        return 0;
}

int IsFull(struct queue *q)
{
    if (q->r == q->size - 1)
        return 1;
    else
        return 0;
}

void Enqueue(struct queue *q, int val)
{
    if (IsFull(q))
    {
        cout << "\nThe Queue is full" << endl;
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int Dequeue(struct queue *q)
{
    int a = -1;
    if (IsEmpty(q))
    {
        cout << "The Queue is empty!" << endl;
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

// # BFS
void BFS(struct queue *q, int i)
{
    cout << i << " ";
    visited[i] = 1;
    Enqueue(q, i); // Enqueue i for exploration
    while (!IsEmpty(q))
    {
        int node = Dequeue(q);
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                cout << j << " ";
                visited[j] = 1;
                Enqueue(q, j);
            }
        }
    }
}

// # Main
int main()
{
    // # Queue Initialisation
    struct queue q;
    q.size = 50;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // # BFS Implementation
    cout << "\n# BFS Traversal #\n";
    int i = 0; // source node
    cout << "\n# Source Node: " << i << endl;
    cout << "\n# BFS Traversal: ";
    BFS(&q, i);
    cout << "\n\n";
    return 0;
}
