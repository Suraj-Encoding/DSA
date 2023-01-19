// # Assignment-9
// # Merge Sort
#include <iostream>
using namespace std;

// # Employee Structure
struct Employee
{
    string name;
    long int salary;
};

// # Merge
void Merge(Employee *em, int lb, int mid, int ub)
{
    int i, j, k;
    i = lb;
    j = mid + 1;
    k = lb;
    Employee b[10];
    while (i <= mid && j <= ub)
    {
        if (em[i].salary <= em[j].salary)
        {
            b[k].name = em[i].name;
            b[k].salary = em[i].salary;
            i++;
        }
        else
        {
            b[k].name = em[j].name;
            b[k].salary = em[j].salary;
            j++;
        }
        k++;
    }
    while (j <= ub)
    {
        b[k].name = em[j].name;
        b[k].salary = em[j].salary;
        j++;
        k++;
    }
    while (i <= mid)
    {
        b[k].name = em[i].name;
        b[k].salary = em[i].salary;
        i++;
        k++;
    }
    // # Copy b to arr
    for (k = lb; k <= ub; k++)
    {
        em[k].name = b[k].name;
        em[k].salary = b[k].salary;
    }
}

// # Merge Sort
void Merge_Sort(Employee *em, int lb, int ub)
{
    int mid;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;
        Merge_Sort(em, lb, mid);
        Merge_Sort(em, mid + 1, ub);
        Merge(em, lb, mid, ub);
    }
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
    cout << "\n# Merge Sort #\n";
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
    Merge_Sort(em, lb, ub);

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