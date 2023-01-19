// # Assignment-1
// # Hashtable Implementation
#include <iostream>
#include <iomanip>
using namespace std;

// # Employee
struct Employee
{
    int id;
    string name;
    int key;
};

// # Class
class Hashtable
{
private:
    Employee *Table;
    int N;

public:
    void Insert();
    void Delete();
    void Search();
    void Display();
    int Search_Key(int x);
    int hashfunction(int key);
    Hashtable(int n);
    ~Hashtable();
};

// ** Function Definations **

// # Constructor
Hashtable ::Hashtable(int n)
{
    N = n;
    Table = new Employee[N];
    for (int i = 0; i < N; i++)
    {
        Table[i].id = -1;
        Table[i].key = -1;
        Table[i].name = "NULL";
    }
}

// # Destructor
Hashtable ::~Hashtable()
{
    for (int i = 0; i < N; i++)
    {

        Table[i].id = -1;
        Table[i].key = -1;
        Table[i].name = "NULL";
    }
}

// # Hash Function
int Hashtable ::hashfunction(int key)
{
    return key % N;
}

// # Delete
void Hashtable ::Delete()
{
    int x;
    cout << "\n# Delete Data: " << endl;
    cout << "Enter Id to be deleted: ";
    cin >> x;
    int index = Search_Key(x);
    if (index == 99)
        cout << "\nData not found...\n";
    else
    {
        cout << "Data is deleted successfully.." << endl;
        cout << "\n# Deleted Data:" << endl;
        cout << "key" << setw(10) << "Id" << setw(9) << "Name" << endl;
        cout << Table[index].key << setw(11) << Table[index].id << setw(11) << Table[index].name << endl;
        Table[index].id = -1;
        Table[index].key = -1;
        Table[index].name = "NULL";
    }
}

// # Search
void Hashtable ::Search()
{
    int x;
    cout << "\n# Search Data: " << endl;
    cout << "Enter the Id to be searched: ";
    cin >> x;
    int index = hashfunction(x);
    int c = index;
    if (x == Table[index].id)
    {
        cout << "Employee found at index " << index << endl;
        cout << "\n# Searched data is: " << endl;
        cout << "key" << setw(10) << "Id" << setw(9) << "Name" << endl;
        cout << Table[index].key << setw(11) << Table[index].id << setw(11) << Table[index].name << endl;
    }
    else
    {
        while (Table[c].id != x)
        {
            c = (c + 1) % N;
            if (c == index)
            {
                cout << "\nData not found...\n";
                break;
            }
            if (Table[c].id == x)
            {
                cout << "Employee found at index " << c << endl;
                cout << "\n# Searched data is: " << endl;
                cout << "key" << setw(10) << "Id" << setw(9) << "Name" << endl;
                cout << Table[c].key << setw(11) << Table[c].id << setw(11) << Table[c].name << endl;
            }
        }
    }
}

// # Search Key
int Hashtable ::Search_Key(int x)
{
    int index = hashfunction(x);
    int c = index;
    if (x == Table[index].id)
        return index;
    else
    {
        while (Table[c].id != x)
        {
            c = (c + 1) % N;
            if (c == index)
                return 99;
            if (Table[c].id == x)
                return c;
        }
    }
    return 99;
}

// # Insert
void Hashtable ::Insert()
{
    int id, flag = 0;
    int i, choice;
    string name;
    cout << "\n# Insert Data: " << endl;
    for (i = 0; i < N; i++)
    {
        cout << "\n# Insert Employee-" << (i + 1) << " Data: " << endl;
        cout << "Enter Employee Id: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin >> name;

        int index = hashfunction(id);

        while (Table[index].key != -1 && flag != N)
        {
            index = (index + 1) % N;
            flag++;
        }

        if (flag == N)
        {
            cout << "\n* Number of Employees are: " << N << endl;
            cout << "\n* Hashtable is Full..!\n";
            break;
        }

        Table[index].id = id;
        Table[index].name = name;
        Table[index].key = index;

        cout << "* Do you want to add more employee? (0.No 1.Yes) : ";
        cin >> choice;
        if (choice == 0)
        {
            cout << "\n* Number of Employees are: " << (i + 1) << endl;
            break;
        }
    }
    if (i == N)
    {
        cout << "\n* Number of Employees are: " << N << endl;
        cout << "\n* Hashtable is Full..!\n";
    }
}

// # Display
void Hashtable ::Display()
{
    cout << "\n# Hash Table: \n\n";
    cout << "key" << setw(10) << "Id" << setw(9) << "Name" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << Table[i].key << setw(11) << Table[i].id << setw(11) << Table[i].name << endl;
    }
}

// # Main Function
int main()
{
    int n, ch;
    cout << "\n# HashTable Implementation #\n";
    cout << "\nEnter number of Employees: ";
    cin >> n;
    Hashtable h(n);
    do
    {
        cout << "\n# Hashing Menu:" << endl;
        cout << "1.Insert Data" << endl;
        cout << "2.Delete Data" << endl;
        cout << "3.Search Data" << endl;
        cout << "4.Display Data" << endl;
        cout << "5.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            h.Insert();
            break;

        case 2:
            h.Delete();
            break;

        case 3:
            h.Search();
            break;

        case 4:
            h.Display();
            break;

        case 5:
            cout << "\nYou are exit!\n\n";
            exit(0);
            break;

        default:
            cout << "\nInvalid Choice!" << endl;
            break;
        }

    } while (1);
    return 0;
}