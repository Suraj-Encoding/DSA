// # Problem-1 -> Sorted Insertion
#include <iostream>
using namespace std;

// Node
struct node
{
    int data;
    struct node *next;
    struct node *prev;
} * head, *newnode, *temp, *tail, *ptr;

// Function declaration
void Create_DLL(void);
void Display_DLL(void);
void Insert_DLL(void);

// main function
int main()
{

    int t, i;
    cin >> t;
    for (i = 1; i <= t; i++)
    {
        Create_DLL();
        Insert_DLL();
        Display_DLL();
        head = tail = temp = ptr = NULL;
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
        newnode = new (nothrow) struct node;
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

// # Insertion
void Insert_DLL()
{
    int data;
    cin >> data;
    newnode = new struct node;
    newnode->data = data;
    temp = head;
    while (temp != NULL)
    {
        if (data < temp->data)
        {
            ptr = temp->prev;
            break;
        }
        temp = temp->next;
    }

    // Main logic
    if (temp == head)
    {
        head = newnode;
        temp->prev = newnode;
        newnode->prev = NULL;
        newnode->next = temp;
    }
    else if (temp == NULL)
    {
        newnode->prev = tail;
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
    }
    else
    {
        temp->prev = newnode;
        newnode->prev = ptr;
        ptr->next = newnode;
        newnode->next = temp;
    }
}