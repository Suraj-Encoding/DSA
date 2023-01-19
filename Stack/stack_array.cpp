// # Implement stack using array -> array = static memory allocation.
// # But still we use dynamic memory allocation in arrays.
// # Operations: 1.Push (Insertion)  2.Pop (Deletion)  3.Peek/Top (Print without deletion)  4.Display (Traversal + Print)   5.IsFull   6.IsEmpty
#include <iostream>
using namespace std;

// Global declaration
int N, top = -1, temp = 0;
int *stack;

// Functions declaration
void Push(void);
void Pop(void);
void Peek(void);
void Display(void);
void IsFull(void);
void IsEmpty(void);
void Top_value(void);

// main function
int main()
{
    int ch;
    cout << "\n# Stack Using Array #" << endl;
    cout << "\n# Create Stack: " << endl;
    cout << "Enter size of the stack: ";
    cin >> N;
    stack = new (nothrow) int[N];
    // do-while loop
    do
    {
        cout << "\n# Menu: " << endl;
        cout << "1.Push" << endl;
        cout << "2.Pop" << endl;
        cout << "3.Peek/Top" << endl;
        cout << "4.Display" << endl;
        cout << "5.IsFull" << endl;
        cout << "6.IsEmpty" << endl;
        cout << "7.Top Value" << endl;
        cout << "0.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        // Switch case
        switch (ch)
        {

        case 1:
            Push();
            break;

        case 2:
            Pop();
            break;

        case 3:
            Peek();
            break;

        case 4:
            Display();
            break;

        case 5:
            IsFull();
            break;

        case 6:
            IsEmpty();
            break;

        case 7:
            Top_value();
            break;

        case 0:
            goto end;
            break;

        default:
            cout << "\n* Invalid Choice!" << endl;
            break;
        }
    } while (1);
end:
    cout << "\n* You are exit!\n"
         << endl;
    return 0;
}

// ** Functions defination **

// # Push
void Push()
{
    int x, choice;
    cout << "\n# Push Data: \n"
         << endl;
    while (choice)
    {
        cout << "Enter the data: ";
        cin >> x;
        if (top == N - 1)
        {
            IsFull();
            choice = 0;
        }
        else
        {
            top++;
            stack[top] = x;
            cout << "* Data Push Successfully.." << endl;
            cout << "\nDo you want continue? (1.Yes 0.No): ";
            cin >> choice;
            cout << endl;
        }
    }
}

// # Pop
void Pop()
{
    cout << "\n# Pop Data: ";
    if (top == -1)
    {
        IsEmpty();
    }
    else
    {
        cout << "\n* Data Pop Successfully.." << endl;
        cout << "* Deleted item is: " << stack[top] << endl;
        stack[top] = 0;
        top--;
    }
}

// # Peek
void Peek()
{
    cout << "\n# Peek/Top Data: ";
    if (top == -1)
    {
        IsEmpty();
    }
    else
    {
        cout << "\n* The top most data of stack is: " << stack[top] << endl;
    }
}

// # Display
void Display()
{
    int i;
    cout << "\n# Display Stack: ";
    if (top == -1)
    {
        IsEmpty();
        cout<<"# Empty Stack # "<<endl;
        cout << "Index\tValue" << endl;
        for (i = (N-1); i >= 0; i--)
        {
            cout << " " << "-" << " \t "  << "-" << endl;
        }
       cout << " "<< top << " \t "  << "0" << endl;

    } 
    else
    {
        cout << "\nIndex\tValue" << endl;
        for (i = (N-1); i >= 0; i--)
        {
            if (stack[i] == 0)
                cout << " " << "-" << " \t "
                     << "-" << endl;
            else
                cout << " " << i << " \t " << stack[i] << endl;
        }
    }
}

// # IsFull
void IsFull()
{
    if (top == N - 1)
        cout << "\n* Overflow condition! -> Stack is full" << endl;
    else
        cout << "\n* Stack is not full" << endl;
}

// # IsEmpty
void IsEmpty()
{
    if (top == -1)
        cout << "\n* Underflow condition! -> Stack is empty" << endl;
    else
        cout << "\n* Stack is not empty" << endl;
}

// # Top Value
void Top_value()
{
    cout << "\n* top = " << top << endl;
}