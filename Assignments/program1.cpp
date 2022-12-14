// # Assignment-1
// # Hashtable Implementation

#include <iostream>
using namespace std;

struct Employee
{
    int id;
    string name;
    string col;
    int chain;
    int key;
};

class Hashtable
{

private:
    Employee Table[10];

public:
    void insertion();
    void deletion();
    void searching();
    void display();
    int hashfunction(int key);
    Hashtable();
    ~Hashtable();
};

void Hashtable ::deletion()
{
    int x, i;
    cout << "\n# Delete Data: " << endl;
    cout << "Enter Id to be deleted: ";
    cin >> x;
    for (i = 0; i < 10; i++)
    {
        if (x == Table[i].id)
        {

            cout << "Data is deleted successfully.." << endl;
            cout << "\n# Deleted Data:" << endl;
            cout << "Key\tId\tName\tCollision\tChain" << endl;
            cout << "" << Table[i].key << "\t" << Table[i].id << "\t" << Table[i].name << " \t" << Table[i].col << " \t\t" << Table[i].chain << endl;
            Table[i].id = 1;
            Table[i].key = 1;
            Table[i].name = "null";
            Table[i].col = "null";
            Table[i].chain = 1;
            break;
        }
    }
}

// Searching
void Hashtable ::searching()
{
    int iKey, j;
    cout << "\n# Search Data: " << endl;
    cout << "Enter the id to be searched:  ";
    cin >> iKey;

    for (j = 0; j < 10; j++)
    {
        if (iKey == Table[j].id)
        {
            cout << "Employee found at index: " << j << endl;
            goto display;
        }
    }

display:
    cout << "\n# Searched data is: " << endl;
    cout << "Key\tId\tName\tCollision\tChain" << endl;
    cout << "" << Table[j].key << "\t" << Table[j].id << "\t" << Table[j].name << " \t" << Table[j].col << " \t\t" << Table[j].chain << endl;
}

int Hashtable ::hashfunction(int key)
{
    return key % 10;
}

Hashtable ::Hashtable()
{
    for (int i = 0; i < 10; i++)
    {

        Table[i].id = 1;
        Table[i].key = 1;
        Table[i].name = "null";
        Table[i].col = "null";
        Table[i].chain = 1;
    }
    cout << "\nConstructor.." << endl;
}

Hashtable ::~Hashtable()
{
    cout << "\nDestroyed..\n"
         << endl;
}

void Hashtable ::insertion()
{
    int id, flag = 0;
    int i, choice;
    string name;
    cout << "\n# Insert Data: " << endl;
    for (i = 0; i < 10; i++)
    {
        cout << "\n# Insert Employee-" << (i + 1) << " Data: " << endl;
        cout << "Enter Employee Id: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin >> name;

        int index = hashfunction(id);
        int c = index;

        while (Table[index].key != 1 && flag != 10)
        {
            index = (index + 1) % 10;
            flag++;
        }

        if (flag != 0)
        {
            Table[index].col = "1";
            Table[index].chain = c;
        }
        Table[index].id = id;
        Table[index].name = name;
        Table[index].key = index;

        // continue condition
        cout << "* Do you want to continue? (1.Yes 0.No) : ";
        cin >> choice;
        if (choice == 0)
        {
            cout << "\n* Number of Employees are: " << (i + 1) << endl;
            break;
        }
    }
}

void Hashtable ::display()
{
    cout << "\n# Employee Data: \n"
         << endl;
    cout << "Key\tId\tName\tCollision\tChain " << endl;

    int j = 0;
    for (j = 0; j < 10; j++)
    {
        cout << "" << Table[j].key << "\t" << Table[j].id << "\t" << Table[j].name << " \t" << Table[j].col << " \t\t" << Table[j].chain << endl;
    }
}

int main()
{

    int ch;
    Hashtable h;
    do
    {
        cout << endl;
        cout << "# Hashing Menu:" << endl;
        cout << "1.Insert Data" << endl;
        cout << "2.Delete Data" << endl;
        cout << "3.Search Data" << endl;
        cout << "4.Display Data" << endl;
        cout << "0.Exit" << endl;

        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            h.insertion();
            break;

        case 2:
            h.deletion();
            break;

        case 3:
            h.searching();
            break;

        case 4:
            h.display();
            break;

        case 0:
            goto end;
            break;

        default:
            cout << "Incorrect Choice!" << endl;
        }

    } while (1);

end:
    cout << "* You are exit!" << endl;
    return 0;
}