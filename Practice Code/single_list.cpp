// # Employee database using linked list
#include <iostream>
#include <iomanip>
using namespace std;

struct node
{
    string name;
    long int salary;
    struct node *next;
} * head, *temp, *newnode;

void Create();
void Display(int);
void Sort();

int main()
{
    cout << "\n# Employee Database # \n";
    head = NULL;
    int ch, pass;
    while (1)
    {
        cout << "\n# Menu: \n1.Create \n2.Display \n3.Sort \n0.Exit " << endl;
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            Create();
            break;
        case 2:
            Display(pass);
            break;
        case 3:
            Sort();
            pass = ch;
            break;
        case 0:
            cout << "\n* You are exit!\n"
                 << endl;
            exit(0);
            break;
        default:
            cout << "\n* Invalid choice!" << endl;
            break;
        }
    }
    return 0;
}

void Create()
{

    cout << "\n# Create Linked List: " << endl;
    int choice, i = 1;
    while (choice)
    {
        newnode = new (nothrow) struct node;
        cout << "\n# Enter the Employee-" << i << " data: " << endl;
        cout << "Enter name: ";
        cin >> newnode->name;
        cout << "Enter salary: ";
        cin >> newnode->salary;
        newnode->next = NULL;

        // linking nodes
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        // condition for continue
        cout << "Do you want to continue? (1.Yes 0.No) : ";
        cin >> choice;
        i++;
    }
}

void Display(int ch)
{
    if (ch == 3)
        cout << "\n# Sorted Linked List: " << endl;
    else
        cout << "\n# Display Linked List: " << endl;
    if (head == NULL)
    {
        cout << "* The list is empty!" << endl;
    }
    else
    {
        int i = 1;
        temp = head;
        cout << "Node\tSalary\t  Name" << endl;
        while (temp != NULL)
        {
            cout << left << setw(9) << i;
            cout << left << setw(9) << temp->salary;
            cout << left << setw(10) << temp->name << endl;
            temp = temp->next;
            i++;
        }
        if (ch != 3)
            cout << "\n* Number of nodes =  " << (i - 1) << endl;
        cout << endl;
    }
}

void Sort()
{
    cout << "\n# Sort Linked List: " << endl;
    struct node *current = head, *index = NULL;
    int temp;
    string name;
    if (head == NULL)
    {
        cout << "* The list is empty!" << endl;
    }
    else
    {
        while (current != NULL)
        {
            index = current->next;
            while (index != NULL)
            {
                if (current->salary < index->salary)
                {
                    // swap salary
                    temp = index->salary;
                    index->salary = current->salary;
                    current->salary = temp;
                    // swap name
                    name = index->name;
                    index->name = current->name;
                    current->name = name;
                }
                index = index->next;
            }
            current = current->next;
        }
        cout << "* list is sorted" << endl;
    }
}

// ** Done **