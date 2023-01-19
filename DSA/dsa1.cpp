#include <iostream>
#include <iomanip>
using namespace std;
class hashrecord
{
private:
    int id;
    string name;
    int key;

public:
    hashrecord()
    {
        id = -1;
        name = "";
        key = -1;
    }
    friend class hashtable;
};
class hashtable
{
private:
    int size;
    hashrecord *table;

public:
    hashtable(int p)
    {
        size = p;
        table = new hashrecord[size];
    }
    int hashfunc(int p)
    {
        return (p % size);
    }
    void insertdata(int id, string name)
    {
        int index = hashfunc(id);
        int c = index;
        if (table[c].key == -1)
        {
            table[c].key = index;
            table[c].id = id;
            table[c].name = name;
        }
        else
        {
            while (table[c].key != -1)
            {
                c = (c + 1) % size;
                if (table[c].key == -1)
                {
                    table[c].key = c;
                    table[c].id = id;
                    table[c].name = name;
                    return;
                }
                if (c == index)
                {
                    cout << "sorry hash is full:" << endl;
                    return;
                }
            }
        }
    }
    int search(int id)
    {
        int index = hashfunc(id);
        int c = index;
        if (table[c].id == id)
        {
            cout << "record found" << endl;
            cout << "name of the employee:" << table[c].name << endl;
            return index;
        }
        else
        {
            while (table[c].id != id)
            {
                c = (c + 1) % size;
                if (c == index)
                {
                    cout << "no record found:" << endl;
                    return -99;
                }
                if (table[c].id == id)
                {
                    cout << "record found" << endl;
                    cout << "name of the employee:" << table[c].name << endl;
                    return c;
                }
            }
        }
    }
    void remove(int id)
    {
        int data = search(id);
        if (data == -99)
        {
            cout << "no data for given id :" << endl
                 << "deletion cannot be done:" << endl;
        }
        else
        {
            table[data].id = -1;
            table[data].key = -1;
            table[data].name = "";
            cout << "deletion occured succesfully!!" << endl;
        }
    }
    void update(int id)
    {
        int data = search(id);
        if (data == -99)
        {
            cout << "no data for given id :" << endl
                 << "updation cannot be done:" << endl;
        }
        else
        {
            cout << "enter name (you cannot update id or key):" << endl;
            cin >> table[data].name;
            cout << "updation occured succesfully!!" << endl;
        }
    }
    void print(int id)
    {
        int data = search(id);
        if (data == -99)
        {
            cout << "no data for given id :" << endl
                 << "printing cannot be done:" << endl;
        }
        else
        {
            cout << table[data].name << endl;
            cout << table[data].id << endl;
            cout << table[data].key << endl;
        }
    }
};
int main()
{
    int n, choice, emp, b;
    string name1;
    cout << "enter the number of employee:" << endl;
    cin >> n;
    hashtable h(n);
    while (1)
    {
        cout << "enter a choice" << endl
             << "1)insert" << endl
             << "2)search" << endl
             << "3)delete" << endl
             << "4)update" << endl
             << "5)print by id" << endl
             << "6)exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter id:" << endl;
            cin >> emp;
            cout << "enter name:" << endl;
            cin >> name1;
            h.insertdata(emp, name1);
            break;
        case 2:
            cout << "enter id:" << endl;
            cin >> emp;
            b = h.search(emp);
            break;
        case 3:
            cout << "enter id:" << endl;
            cin >> emp;
            h.remove(emp);
            break;
        case 4:
            cout << "enter id:" << endl;
            cin >> emp;
            h.update(emp);
            break;
        case 5:
            cout << "enter id:" << endl;
            cin >> emp;
            h.print(emp);
            break;
        case 6:
            return 0;
            break;
        default:
            cout << "wrong choice:" << endl;
            break;
        }
    }
    return 0;
}
