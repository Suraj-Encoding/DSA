#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;
struct node
{
    int data;
    node *next;
};
class graph
{
public:
    int m[10][10], n = 1;
    node *h[10];
    graph(int p)
    {
        n = p;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                m[i][j] = 0;
        }
    }
    void insertmat(int);
    void displaymat();
    void insertlist(int);
    void addedge(int x, int y);
    void displaylist();
    void bfsmat()
    {
        queue<int> p;
        int visited[n + 1], var, j, pre;
        cout << "Enter starting vertex:" << endl;
        cin >> var;
        for (int i = 0; i <= n; i++)
        {
            visited[i] = 0;
        }
        p.push(var);
        visited[var] = 1;
        while (!p.empty())
        {
            pre = p.front();
            cout << p.front() << " ";
            p.pop();
            for (j = 0; j < n; j++)
            {
                if (m[pre - 1][j] == 1 && visited[j + 1] != 1)
                {
                    p.push(j + 1);
                    visited[j + 1] = 1;
                }
            }
        }
    }
    void bfslist()
    {
        queue<int> p;
        node *cn;
        int visited[n + 1], var, j, pre;
        cout << "Enter starting vartex:" << endl;
        cin >> var;
        for (int i = 0; i <= n; i++)
        {
            visited[i] = 0;
        }
        p.push(var);
        visited[var] = 1;
        while (!p.empty())
        {
            pre = p.front();
            cout << p.front() << " ";
            p.pop();
            cn = h[pre];
            while (cn->next != NULL)
            {
                cn = cn->next;
                if (visited[cn->data] != 1)
                {
                    p.push(cn->data);
                    visited[cn->data] = 1;
                }
            }
        }
    }
};
void graph::addedge(int x, int y)
{
    node *nn, *cn;
    nn = new node;
    nn->data = y;
    nn->next = NULL;
    if (h[x] != NULL)
    {
        cn = h[x];
        while (cn->next != NULL)
        {
            cn = cn->next;
        }
        cn->next = nn;
    }
}
void graph::insertmat(int pair)
{
    cout << "enter the " << pair << " pairs of vertices:" << endl;
    int i, j, choice;
    do
    {

        cin >> i >> j;
        if (i <= n && j <= n)
        {
            m[i - 1][j - 1] = 1;
            m[j - 1][i - 1] = 1;
            pair--;
        }
        else
        {
            cout << "the pair of vertices contain a vertice beyond limit" << endl;
        }
    } while (pair);
    displaymat();
    int ch1;
    do
    {
        bfsmat();
        cout << endl
             << "want to search for other vertex:1)yes" << endl;
        cin >> ch1;
    } while (ch1 == 1);
}
void graph::displaymat()
{
    cout << endl
         << "the elements of graph in matrix form are as follow:" << endl;
    cout << "M|";
    for (int t = 0; t < n; t++)
    {
        cout << "\t" << t + 1 << "|";
    }
    cout << endl;
    for (int k = 0; k < n; k++)
    {
        cout << k + 1 << "|";
        for (int t = 0; t < n; t++)
        {
            cout << "\t" << m[k][t] << "|";
        }
        cout << endl;
    }
}
void graph::insertlist(int pair)
{
    int i, j, choice;
    for (int t = 0; t < 10; t++)
    {
        h[t] = new node;
        h[t]->data = t;
        h[t]->next = NULL;
    }
    cout << "enter the " << pair << " pairs of vertices:" << endl;
    do
    {
        cin >> i >> j;
        if (i <= n && j <= n && i != j)
        {
            addedge(i, j);
            addedge(j, i);
            pair--;
        }
        else if (i == j)
        {
            addedge(i, j);
            pair--;
        }
        else
        {
            cout << "the pair of vertices contain a vertice beyond limit" << endl;
        }
    } while (pair);
    displaylist();
    int ch1;
    do
    {
        bfslist();
        cout << endl
             << "want to search for other vertex:1)yes" << endl;
        cin >> ch1;
    } while (ch1 == 1);
}
void graph ::displaylist()
{
    cout << endl
         << "the elements of graph in list form are as follow:" << endl;
    cout << "v"
         << "-->edges" << endl;
    node *cn;
    for (int i = 1; i <= n; i++)
    {
        cn = h[i];
        do
        {
            cout << cn->data;
            if (cn->next != NULL)
                cout << "-->";
            cn = cn->next;
        } while (cn != NULL);
        cout << endl;
    }
}
int main()
{
    int i = 0, choice, v, pair;
    while (1)
    {
        cout << endl
             << "enter the number of vertex:" << endl;
        cin >> v;
        graph p(v);
        cout << "enter number of pairs:" << endl;
        cin >> pair;
        cout << endl
             << "1)insert in matrix" << endl
             << "2)insert in list" << endl
             << "3)exit" << endl;
        cout << "enter the choice:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            p.insertmat(pair);
            break;
        case 2:
            p.insertlist(pair);
            break;
        case 3:
            return 0;
            break;
        default:
            cout << "wrong choice" << endl;
            break;
        }
        cout << endl
             << "want to continue:1)yes" << endl;
        cin >> choice;
        if (choice != 1)
        {
            return 0;
        }
    }
    return 0;
}