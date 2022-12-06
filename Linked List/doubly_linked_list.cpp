// # Doubly Linked List (DLL) Implementation
// # Operation: 1.Creation  2.Insertion   3.Deletion   4.Display   5.Traversal   6.Search   3.Reverse  8.Reverse_Display
#include <iostream>
#include <iomanip>
using namespace std;

// Node -> DLL
struct node
{
    int data;
    struct node *next;
    struct node *prev;
} * head, *newnode, *temp, *tail;

// Global variable
int cnt, flag = 0;

// Function declaration
void Create_DLL(void);
void Display_DLL(void);
void Rev_Display_DLL(void); // Just display in reverse order
void Reverse_DLL(void);     // Reverse all the nodes
void Search_Data(void);
void Insert_at_beg(void);
void Insert_at_end(void);
void Insert_at_pos(void);
void Delete_from_beg(void);
void Delete_from_end(void);
void Delete_from_pos(void);

// main function
int main()
{
    cout << "\n# Doubly Linked List #\n";
    int ch;
    while (1)
    {
        // Operations Menu
        cout << "\n# Operations Menu: " << endl;
        cout << "1.Create linked list" << endl;
        cout << "2.Display linked list" << endl;
        cout << "3.Reverse linked list" << endl;
        cout << "4.Reverse Display" << endl;
        cout << "5.Search Data" << endl;
        cout << "6.Insert at beginning" << endl;
        cout << "7.Insert at end" << endl;
        cout << "8.Insert at specific position" << endl;
        cout << "9.Delete from beginning" << endl;
        cout << "10.Delete from end" << endl;
        cout << "11.Delete from specific position" << endl;
        cout << "0.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            Create_DLL();
            flag = 1;
            break;
        case 2:
            Display_DLL();
            break;
        case 3:
            Reverse_DLL();
            flag = 3;
            break;
        case 4:
            Rev_Display_DLL();
            flag = 2;
            break;
        case 5:
            Search_Data();
            break;
        case 6:
            Insert_at_beg();
            break;
        case 7:
            Insert_at_end();
            break;
        case 8:
            Insert_at_pos();
            break;
        case 9:
            Delete_from_beg();
            break;
        case 10:
            Delete_from_end();
            break;
        case 11:
            Delete_from_pos();
            break;
        case 0:
            cout << "\n* You are exit!\n\n";
            goto end;
            exit(0);
            break;
        default:
            cout << "\n* Inavlid Choice!\n";
            break;
        }
    }
// Free the pointers
end:
{
    delete head;
    delete newnode;
    delete temp;
    delete tail;
}
    return 0;
}

// ** Function defination **

// # Creation
void Create_DLL()
{
    cout << "\n# Create Doubly Linked List: " << endl;
    head = NULL; // Pointer to the first node
    tail = NULL; // Pointer to the last node

    // Other variables
    int choice, i = 1;

    // while loop
    while (choice)
    {
        // Dynamic memory allocation using new operator
        newnode = new (nothrow) struct node;

        // Enter data in the node
        cout << "\nEnter the node-" << i << " data: ";
        cin >> newnode->data;

        // Set all pointers to 'null' -> NULL = 0
        newnode->next = NULL;
        newnode->prev = NULL;

        // linking nodes
        if (head == NULL) // executes at first time only
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

        // condition for continue
        cout << "Do you want to continue? (1.Yes 0.No) : ";
        cin >> choice;
        i++;
    }
}

// # Display
void Display_DLL()
{
    cnt = 0;
    {
        // For output purpose
        if (flag == 1)
            cout << "\n# Display Linked List: " << endl;
        else if (flag == 2)
            cout << "\n# Reverse Display: " << endl;
        else if (flag == 3)
            cout << "\n# Reverse Linked List: " << endl;
        else
            cout << "\n# Updated Linked List: " << endl;
    }
    temp = head;
    if (head == NULL)
    {
        cout << "* The list is empty!" << endl;
    }
    else
    {
        cout << "  Node\tData" << endl;
        while (temp != NULL)
        {
            cnt++;
            cout << "  " << left << setw(8) << cnt;
            cout << left << setw(10) << temp->data << endl;
            temp = temp->next;
        }

        // node count
        cout << "* Number of nodes: " << cnt << endl;
    }
}

// # Reverse Display
void Rev_Display_DLL()
{
    int count = 0;
    cout << "\n# Reverse Display: " << endl;
    if (head == NULL)
    {
        cout << "* The list is empty!" << endl;
    }
    else
    {
        temp = tail;
        cout << "  Node\tData" << endl;
        while (temp != NULL)
        {
            count++;
            cout << "  " << left << setw(8) << count;
            cout << left << setw(10) << temp->data << endl;
            temp = temp->prev;
        }

        // node count
        cout << "* Number of nodes: " << count << endl
             << endl;
    }
}

// # Search
void Search_Data()
{
    int data, flag = 0, i;
    temp = head;
    cout << "\n# Search Data: " << endl;
    if (head == NULL)
    {
        cout << "* The list is empty!" << endl;
    }
    else
    {
        cout << "Enter data to be Searched: ";
        cin >> data;
        for (i = 0; temp != tail->next; i++)
        {
            if (data == temp->data)
            {
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        cout << "\n # Display Data: " << endl;
        if (flag == 0)
        {
            cout << "* Data not found!" << endl;
        }
        else
        {
            cout << "  Node\tData" << endl;
            cout << "  " << left << setw(8) << (i + 1);
            cout << left << setw(10) << data << endl;
            cout << "* Data found at node-" << (i + 1) << endl;
        }
    }
}

// # Reverse
void Reverse_DLL()
{
    struct node *current, *nextnode;
    current = head;
    cout << "\n# Reverse Linked List: " << endl;
    if (head == NULL)
    {
        cout << "* The list is empty! You can't reverse." << endl;
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
        cout << "* Linked list reversed successfully.." << endl;
    }
}

// # Insertion
void Insert_at_beg()
{
    newnode = new (nothrow) struct node;
    cout << "\n* Insert node at the beginning: " << endl;
    cout << "Enter the newnode data: ";
    cin >> newnode->data;
    newnode->prev = NULL; // always
    if (head == NULL)
    {
        newnode->next = NULL;
        head = tail = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    cnt++;
    cout << "Node Inserted successfully.." << endl;
}

void Insert_at_end()
{
    newnode = new (nothrow) struct node;
    cout << "\n* Insert node at the end: " << endl;
    cout << "Enter the newnode data: ";
    cin >> newnode->data;
    if (head == NULL)
        head = newnode;
    else
        tail->next = newnode;
    {
        newnode->next = NULL; // always
        newnode->prev = tail;
        tail = newnode;
        cnt++;
    }
    cout << "Node Inserted successfully.." << endl;
}

// ** Generalised Insertion **
void Insert_at_pos()
{
    int pos, i = 1;
    newnode = new (nothrow) struct node;
    cout << "\n* Insert node at specific position: " << endl;
    cout << "Enter the position: ";
    cin >> pos;
    if (pos < 1 || pos >= (cnt + 1))
    {
        cout << "Invalid position!" << endl;
    }
    else
    {
        cout << "Enter the newnode data: ";
        cin >> newnode->data;
        {
            temp = head;
            newnode->next = NULL;
            newnode->prev = NULL;
        }
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            while (i < (pos - 1))
            {
                temp = temp->next;
                i++;
            }
            if (pos == 1)
            {
                newnode->next = head;
                head->prev = newnode;
                head = newnode;
            }
            else if (pos == 2) // Exception
            {
                newnode->next = temp->next;
                temp->next = newnode;
            }
            else
            {
                newnode->next = temp->next;
                temp->next->prev = newnode;
                newnode->prev = temp;
                temp->next = newnode;
            }
            cnt++;
            cout << "Node Inserted successfully.." << endl;
        }
    }
}

// # Deletion
void Delete_from_beg()
{
    if (head == NULL)
    {
        cout << "\n* The list is empty!" << endl;
    }
    else
    {
        cout << "\n* Delete node from the beginning: " << endl;
        if (head->next == NULL)
            head = NULL;
        else
        {
            temp = head;
            head = head->next;
            head->prev = NULL;
        }
        delete temp;
        cnt--;
        cout << "Node deleted successfully.." << endl;
    }
}

void Delete_from_end()
{
    if (head == NULL)
    {
        cout << "\n* The list is empty!" << endl;
    }
    else
    {
        cout << "\n* Delete node from the end: " << endl;
        temp = tail;
        if (head == tail)
            head = NULL;
        else
        {
            tail->prev->next = NULL;
            tail = tail->prev;
        }
        delete temp;
        cnt--;
        cout << "Node deleted successfully.." << endl;
    }
}

// ** Generalised Deletion **
void Delete_from_pos()
{
    if (head == NULL)
    {
        cout << "\n* The list is empty!" << endl;
    }
    else
    {
        cout << "\n* Delete node from the specific position: " << endl;
        int pos, i = 1;
        cout << "Enter the position: ";
        cin >> pos;
        if (pos < 1 || pos > cnt)
        {
            cout << "Invalid position!" << endl;
        }
        else
        {
            temp = head;
            while (i < pos)
            {
                temp = temp->next;
                i++;
            }
            if (pos == 1)
            {
                head = head->next;
                head->prev = NULL;
                delete temp;
            }
            else if (pos == cnt)
            {
                temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete temp;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
            }
            cnt--;
            cout << "Node deleted successfully.." << endl;
        }
    }
}

// ** Done **