// # Assignment-4 -> Part-1
// # Implement stack using linked list
// # Operations: 1.Push  2.Pop  3.Peek  4.Display  5.IsEmpty  6.Node_count
#include <iostream>
using namespace std;

// # Functions Declaration
void Push(void);
void Pop(void);
void Peek(void);
void Display(void);
void node(void);
void IsEmpty(void);

// # Global variables
int cnt = 0;

// # Linked List
struct stack
{
    int data;
    struct stack *link;
} *top, *temp, *newnode;

// # Main Function
int main()
{
    int ch;
    top = NULL;
    cout << "\n# Stack Using Linked List #" << endl;
    do
    {
        cout << "\n# Menu: " << endl;
        cout << "1.Push" << endl;
        cout << "2.Pop" << endl;
        cout << "3.Peek" << endl;
        cout << "4.Display" << endl;
        cout << "5.IsEmpty" << endl;
        cout << "6.Stack Size" << endl;
        cout << "0.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
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
            IsEmpty();
            break;
        case 6:
            node();
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
    cout << "\n* You are exit!\n\n";
    return 0;
}

// ** Functions Definations **

// # Push
void Push()
{
    int choice = 1;
    cout << "\n# Push Data: \n"
         << endl;
    while (choice)
    {
        cnt++;
        newnode = new (nothrow) struct stack;
        cout << "Enter the node-" << cnt << " data: ";
        cin >> newnode->data;
        newnode->link = top;
        top = newnode;
        cout << "* Data Push Successfully.." << endl;
        cout << "\nDo you want continue? (1.Yes 0.No): ";
        cin >> choice;
        cout << endl;
    }
}

// # Pop
void Pop()
{
    cout << "\n# Pop Data: ";
    if (top == NULL)
    {
        IsEmpty();
    }
    else
    {
        cout << "\n* Data Pop Successfully.." << endl;
        temp = top;
        top = top->link;
        cout << "* Deleted item is: " << temp->data << endl;
        delete temp;
        cnt--;
    }
}

// # Peek
void Peek()
{
    cout << "\n# Peek Data: ";
    if (top == NULL)
    {
        IsEmpty();
    }
    else
    {
        cout << "\n* The top most data of stack is: " << top->data << endl;
    }
}

// # Display
void Display()
{
    int i;
    cout << "\n# Display Stack: ";
    if (top == NULL)
    {
        IsEmpty();
    }
    else
    {
        cout << "\nNode\tValue" << endl;
        temp = top;
        for (i = 1; i <= cnt; i++)
        {
            cout << " " << i << " \t " << temp->data << endl;
            temp = temp->link;
        }
    }
}

// # IsEmpty
void IsEmpty()
{
    if (top == NULL)
        cout << "\n* Stack is empty" << endl;
    else
        cout << "\n* Stack is not empty" << endl;
}

// # Stack Size
void node()
{
    if (top == NULL)
        cout << "\n* Stack is empty" << endl;
    else
        cout << "\n* Nodes in stack: " << cnt << endl;
}
