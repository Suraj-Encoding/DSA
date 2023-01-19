// # Hashing
// # Hashtable Implementation
// # Hashing Technique: Division Method
// # Collision Resolution Technique: 1.Linear Probing  2.Quadratic Probing  3.Double Hashing
#include <iostream>
#include <iomanip>
using namespace std;

// # Hash
struct Hash
{
    int data;
    int index;
    int key;
};

// # Class
class Hashtable
{
private:
    int *arr;
    Hash *Table;
    int N;

public:
    // Functions
    void Insert(int col);
    void Search();
    void Display();
    // Collisions
    int Linear(int u);
    int Quadratic(int u);
    int Double(int u, int key);
    // Hashing
    int hashfunction(int key);
    // Constructor/Destructor
    Hashtable(int N);
    ~Hashtable();
};

// *** Function Definations ***

// # Constructor
Hashtable ::Hashtable(int N)
{
    this->N = N;
    arr = new int[N];
    Table = new Hash[N];
    for (int i = 0; i < N; i++)
        Table[i].data = Table[i].key = Table[i].index = -1;
}

// # Destructor
Hashtable ::~Hashtable()
{
    delete[] arr;
    delete[] Table;
}

// # Search
void Hashtable ::Search()
{
    int x, i;
    cout << "\n# Search: " << endl;
    cout << "Enter the element to be search: ";
    cin >> x;
    int index = hashfunction(x);
    int c = index;
    if (x == Table[index].data)
    {
        cout << "\nElement found at Index = " << Table[index].index;
        cout << " OR Position = " << ++Table[index].index << endl;
        cout << "\n";
    }
    else
    {
        while (Table[c].data != x)
        {
            c = (c + 1) % N;
            if (c == index)
            {
                cout << "\nElement not found...\n";
                break;
            }
            if (Table[c].data == x)
            {
                cout << "\nElement found at Index = " << Table[c].index;
                cout << " OR Position = " << ++Table[c].index << endl;
                cout << "\n";
            }
        }
    }
}

// # Insert
void Hashtable ::Insert(int col)
{
    int i;
    cout << "\n# Insert: \n";
    cout << "\n# Enter array: " << endl;
    cout << "  ";
    for (i = 0; i < N; i++)
        cin >> arr[i];
    for (i = 0; i < N; i++)
    {
        int index = hashfunction(arr[i]);
        // # Collision Resolution Techniques
        if (col == 1)
            index = Linear(index);
        else if (col == 2)
            index = Quadratic(index);
        else
            index = Double(index, arr[i]);
        Table[index].data = arr[i];
        Table[index].key = index;
        Table[index].index = i;
    }
}

// # Display
void Hashtable ::Display()
{
    cout << "\n# Display: \n\n";
    cout << "Key" << setw(7) << "Index" << setw(6) << "Data" << endl;
    cout << "-----------------\n";
    for (int i = 0; i < N; i++)
        cout << Table[i].key << setw(7) << Table[i].index << setw(6) << Table[i].data << endl;
}

// *** Hashing Technique ***

// # Hash Function -> Division Method
int Hashtable ::hashfunction(int key)
{
    return key % N;
}

// *** Collision Resolution Techniques ***

// # Linear Probing
int Hashtable ::Linear(int u)
{
    int i = 1, index = u;
    while (Table[index].key != -1 && i != N - 1)
    {
        index = (u + i) % N;
        i++;
    }
    return index;
}

// # Quadratic Probing
int Hashtable ::Quadratic(int u)
{
    int i = 1, index = u;
    while (Table[index].key != -1 && i != N - 1)
    {
        index = (u + i * i) % N;
        i++;
    }
    return index;
}

// # Double Hashing
int Hashtable ::Double(int u, int key)
{
    int i = 1, index = u;
    int v = hashfunction(key);
    while (Table[index].key != -1 && i != N - 1)
    {
        index = (u + v * i) % N;
        i++;
    }
    return index;
}

// # Main
int main()
{
    int size, ch;
    cout << "\n# Hashing #\n";
    cout << "\nEnter array size: ";
    cin >> size;
    Hashtable h(size);
    while (1)
    {
        cout << "\n# Hashing Menu:" << endl;
        cout << "1.Insert" << endl;
        cout << "2.Search" << endl;
        cout << "3.Display" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "\n\t1.Linear Probing" << endl;
            cout << "\t2.Quadratic Probing" << endl;
            cout << "\t3.Double Hashing" << endl;
            int col;
        label:
            cout << "\tEnter your choice: ";
            cin >> col;
            if (col <= 0 || col > 3)
            {
                cout << "\n\tEnter correct choice..\n\n";
                goto label;
            }
            h.Insert(col);
        }
        break;
        case 2:
            h.Search();
            break;
        case 3:
            h.Display();
            break;
        case 4:
            cout << "\nExit...\n";
            exit(0);
            break;
        default:
            cout << "\nInvalid Choice...\n";
            break;
        }
    }
    return 0;
}