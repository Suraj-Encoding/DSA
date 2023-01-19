#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
class sll
{
public:
    node *header = NULL;
    void insertend();
    void deleteend();
    void deletebeg();
    void print();
    friend void stack(sll);
    friend void queue(sll);
};
void sll::insertend()
{
    node *nn;
    nn = new node;
    cout << "enter data:" << endl;
    cin >> nn->data;
    nn->next = NULL;
    if (header == NULL)
    {
        header = nn;
    }
    else
    {
        node *cn;
        cn = header;
        while (cn->next != NULL)
        {
            cn = cn->next;
        }
        cn->next = nn;
    }
}

void sll::deletebeg()
{
    node *cn;
    cn = header;
    header = cn->next;
    delete cn;
    cout << "deleted succesfully" << endl;
}

void sll::deleteend()
{
    node *cn, *nn;
    cn = header;
    int count = 1;
    while (cn->next != NULL)
    {
        count++;
        nn = cn;
        cn = cn->next;
    }
    if (count > 1)
    {
        delete cn;
        nn->next = NULL;
        cout << "deleted succesfully" << endl;
    }
    else
    {
        delete cn;
        delete nn;
        cout << "deleted succesfully" << endl;
    }
}

void sll::print()
{
    node *cn;
    cn = header;
    if (header == NULL)
    {
        cout << "no element present" << endl;
    }
    else
    {
        cout << "the elements are" << endl;
        do
        {
            cout << cn->data << endl;
            cn = cn->next;
        } while (cn != NULL);
    }
}
void stack(sll b)
{
    while (1)
    {
        int d;
        cout << "1)push"
             << "2)pop"
             << "3)print"
             << "4)exit" << endl;
        cin >> d;

        switch (d)
        {
        case 1:
            b.insertend();
            break;
        case 2:
            b.deleteend();
            break;
        case 3:
            b.print();
            break;
        case 4:
            return;
            break;
        default:
            cout << "wrong choice" << endl;
            break;
        }
    }
}
void queue(sll c)
{
    while (1)
    {
        int d;
        cout << "1)insert"
             << "2)remove"
             << "3)print"
             << "4)exit" << endl;

        cin >> d;

        switch (d)
        {
        case 1:
            c.insertend();
            break;
        case 2:
            c.deletebeg();
            break;
        case 3:
            c.print();
            break;
        case 4:
            return;
            break;
        default:
            cout << "wrong choice" << endl;
            break;
        }
    }
}

int main()
{
    int choice, q = 1;
    sll b, c;
    while (1)
    {
        cout << "Menu" << endl;
        cout << "1)stack " << endl
             << "2)queue" << endl
             << "3)end" << endl;
        cout << "enter your choice:" << endl;
        cin >> choice;

        if (choice == 1)
        {
            stack(b);
        }
        else if (choice == 2)
        {
            queue(c);
        }
        else if (choice == 3)
        {
            return 0;
        }
        else
        {
            cout << "wrong input" << endl;
        }
    }
    return 0;
}