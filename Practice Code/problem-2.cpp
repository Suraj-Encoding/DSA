// # Problem-2 -> Reverse doubly linked list
#include <iostream>
using namespace std;

// Node
struct node
{
    int data;
    struct node *next;
    struct node *prev;
} * head, *newnode, *temp, *tail;

// Function declaration
void Create_DLL(void);
void Display_DLL(void);
void Reverse_DLL(void);

// main function
int main()
{

    int t, i;
    cin >> t;
    for (i = 1; i <= t; i++)
    {
        Create_DLL();
        Reverse_DLL();
        Display_DLL();
        head = tail = temp = NULL;
        cout << endl;
    }
    return 0;
}

// # Creation
void Create_DLL()
{
    int n;
    cin >> n;
    while (n)
    {
        newnode = new struct node;
        cin >> newnode->data;

        newnode->next = NULL;
        newnode->prev = NULL;

        if (head == NULL)
        {
            head = temp = tail = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
            tail = newnode;
        }
        n--;
    }
}

// # Display
void Display_DLL()
{
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// # Reverse
void Reverse_DLL()
{
    struct node *current, *nextnode;
    current = head;
    if (head == NULL)
    {
        cout << "empty" << endl;
    }
    else
    {
        while (current != NULL)
        {
            nextnode = current->next;
            current->next = current->prev;
            current->prev = nextnode;
            current = nextnode;
        }
        {
            current = head;
            head = tail;
            tail = current;
        }
    }
}
