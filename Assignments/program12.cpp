// # Assignment-12
// # Quick Sort
#include <iostream>
using namespace std;

// # Employee Structure
struct Employee
{
    string name;
    long int salary;
};

// # Swaping
void Swap(int x, int y, Employee *em)
{
    long int sal;
    string str;
    // Swaping Salary
    sal = em[x].salary;
    em[x].salary = em[y].salary;
    em[y].salary = sal;
    // Swaping Names
    str = em[x].name;
    em[x].name = em[y].name;
    em[y].name = str;
}

// # Partition -> Backbone of Quick Sort
int partition(Employee *em, int lb, int ub)
{
    int pivot, start, end;
    pivot = em[lb].salary;
    start = lb;
    end = ub;
    while (start < end)
    {
        while (em[start].salary <= pivot)
            start++;
        while (em[end].salary > pivot)
            end--;
        if (start < end)
            Swap(start, end, em);
    }
    Swap(lb, end, em);
    return end;
}

// # Quick Sort
Employee *Quick_Sort(Employee *em, int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(em, lb, ub);
        Quick_Sort(em, lb, loc - 1);
        Quick_Sort(em, loc + 1, ub);
    }
    return em;
}

// # Display Data
void display(Employee *em, int n)
{
    cout << "----------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            cout << "SR.No \tName \tSalary" << endl;
            cout << "----------------------------" << endl;
        }
        cout << (i + 1) << "\t" << em[i].name << "\t" << em[i].salary << endl;
    }
    cout << "----------------------------" << endl;
}

// # Main Function
int main()
{
    Employee *em;
    int lb, ub, n, i;
    cout << "\n# Quick Sort #\n";
    cout << "\n# Enter number of employee: ";
    cin >> n;
    em = new Employee[n];
    lb = 0, ub = n - 1;

    // # Insert Data
    cout << "\n# Enter Employee Data: " << endl;
    for (i = 0; i < n; i++)
    {
        cout << "\n# Employee-" << (i + 1) << " :" << endl;
        cout << "Enter name: ";
        cin >> em[i].name;
        cout << "Enter salary: ";
        cin >> em[i].salary;
    }

    // # Display
    cout << "\n# Employee Data: " << endl;
    display(em, n);

    // # Quick Sort
    em = Quick_Sort(em, lb, ub);

    // # Sorted
    cout << "\n\n# Sorted Employee Data: \n";
    display(em, n);

    // # Top 5
    int f = 1;
    cout << "\n\n# Top 5 Employee: \n";
    cout << "----------------------------" << endl;
    for (i = n - 5; i < n; i++)
    {
        if (f)
        {
            cout << "SR.No \tName \tSalary" << endl;
            cout << "----------------------------" << endl;
            f = 0;
        }
        if (n < 5 && i < 0)
        {
        }
        else
        {
            cout << (i + 1) << "\t" << em[i].name << "\t" << em[i].salary << endl;
        }
    }
    cout << "----------------------------" << endl;
    cout << "\n\n";
    return 0;
}