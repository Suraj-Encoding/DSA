// # Singly Linked List (SLL) Implementation
// # Operations : 1.Creation  2.Insertion  3.Deletion  4.Display  5.Traversal  6.Reverse  7.Search   8.Getlength / Node_count

#include <iostream>
#include <iomanip> // For setw()
using namespace std;

// Node -> SLL
struct node
{
    int data;
    struct node *next;
} * head, *newnode, *temp;

// Functions declaration
void Insert_at_beg(int *);
void Insert_at_end(int *);
void Insert_at_pos(int *);
void Delete_from_beg(int *);
void Delete_from_end(int *);
void Delete_from_pos(int *);
void Create_linked_list(int *);
void Display_linked_list(int, int);
void Node_count(int);
int getlength(void);
void Search_Data(int);
void Reverse_linked_list(void);

// main function
int main()
{
    // Label
    cout << "\n# Singly Linked List # " << endl;

    head = NULL; // OR head=0 as NULL -> 0

    // Other variables
    int ch, pass = 0, len, count = 0, i = 1;

    // Menu driven
    do
    {
        // Operations Menu
        cout << "\n# Operations Menu: " << endl;
        cout << "1.Create linked list" << endl;
        cout << "2.Display linked list" << endl;
        cout << "3.Display node count" << endl;
        cout << "4.Insert at beginning" << endl;
        cout << "5.Insert at end" << endl;
        cout << "6.Insert at specific position" << endl;
        cout << "7.Delete from beginning" << endl;
        cout << "8.Delete from end" << endl;
        cout << "9.Delete from specific position" << endl;
        cout << "10.Length of linked list" << endl;
        cout << "11.Search Data" << endl;
        cout << "12.Reverse linked list" << endl;
        cout << "0.Exit" << endl;

        // Enter your choice
        cout << "Enter your choice: ";
        cin >> ch;

        // switch case
        switch (ch)
        {

        case 1:
            Create_linked_list(&count);
            pass = ch;
            break;

        case 2:
            if (pass == 0)
                pass = ch;
            Display_linked_list(count, pass);
            break;

        case 3:
            Node_count(count);
            pass = ch;
            break;

        case 4:
            Insert_at_beg(&count);
            pass = ch;
            break;

        case 5:
            Insert_at_end(&count);
            pass = ch;
            break;

        case 6:
            Insert_at_pos(&count);
            pass = ch;
            break;

        case 7:
            Delete_from_beg(&count);
            pass = ch;
            break;

        case 8:
            Delete_from_end(&count);
            pass = ch;
            break;

        case 9:
            Delete_from_pos(&count);
            pass = ch;
            break;

        case 10:
            len = getlength();
            cout << "\n* Length of linked list =  " << len << endl;
            if (len == 0)
                cout << "* The list is empty!" << endl;
            break;

        case 11:
            Search_Data(count);
            break;

        case 12:
            Reverse_linked_list();
            pass = ch;
            break;

        case 0:
            goto end;
            break;

        default:
            cout << "Incorrect Choice!" << endl;
            break;
        }
    } while (1);

end:
    cout << "\n* You are exit!\n"
         << endl;
    return 0;
}

// ** Functions Defination **

// # Insertion
void Insert_at_beg(int *count)
{
    newnode = new (nothrow) struct node;
    cout << "\n* Insert node at the beginning: " << endl;
    cout << "Enter the newnode data: ";
    cin >> newnode->data;
    newnode->next = head;
    head = newnode;
    (*count)++;
    cout << "Node Inserted successfully.." << endl;
}

void Insert_at_end(int *count)
{
    newnode = new (nothrow) struct node;
    cout << "\n* Insert node at the end: " << endl;
    cout << "Enter the newnode data: ";
    cin >> newnode->data;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (head == temp)
        head = newnode;
    else
        temp->next = newnode;
    newnode->next = NULL;
    (*count)++;
    cout << "Node Inserted successfully.." << endl;
}

// ** Generalised Insertion **
void Insert_at_pos(int *count)
{
    int pos, i = 1;
    newnode = new (nothrow) struct node;
    cout << "\n* Insert node at specific position: " << endl;
    cout << "Enter the position: ";
    cin >> pos;
    if (pos < 1 || pos >= (*count + 1))
    {
        cout << "Invalid position!" << endl;
    }
    else
    {
        cout << "Enter the newnode data: ";
        cin >> newnode->data;
        temp = head;
        if (head == NULL)
        {
            head = newnode;
            newnode->next = NULL;
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
                temp->next = newnode;
            }
            (*count)++;
            cout << "Node Inserted successfully.." << endl;
        }
    }
}

// # Deletion
void Delete_from_beg(int *count)
{
    if (head == NULL)
    {
        cout << "\n* The list is empty!" << endl;
    }
    else
    {
        cout << "\n* Delete node from the beginning: " << endl;
        temp = head;
        if (head->next == NULL)
            head = NULL;
        else
            head = head->next;
        delete temp;
        (*count)--;
        cout << "Node deleted successfully.." << endl;
    }
}

void Delete_from_end(int *count)
{
    if (head == NULL)
    {
        cout << "\n* The list is empty!" << endl;
    }
    else
    {
        cout << "\n* Delete node from the end: " << endl;
        struct node *prevnode;
        temp = head;
        while (temp->next != NULL)
        {
            prevnode = temp;
            temp = temp->next;
        }
        if (temp == head)
            head = NULL;
        else
            prevnode->next = NULL;
        delete temp;
        (*count)--;
        cout << "Node deleted successfully.." << endl;
    }
}

// ** Generalised Deletion **
void Delete_from_pos(int *count)
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
        if (pos < 1 || pos > *count)
        {
            cout << "Invalid position!" << endl;
        }
        else
        {
            struct node *nextnode;
            temp = head;
            while (i < (pos - 1))
            {
                temp = temp->next;
                i++;
            }
            if (temp == head)
            {
                head = NULL;
                delete temp;
            }
            else
            {
                nextnode = temp->next;
                temp->next = nextnode->next;
                delete nextnode;
            }
            (*count)--;
            cout << "Node deleted successfully.." << endl;
        }
    }
}

// # Display
void Display_linked_list(int count, int ch)
{
    if (head == NULL)
    {
        cout << "\n# Display Linked List: " << endl;
        cout << "* The list is empty!" << endl;
    }
    else
    {
        if (ch <= 3)
            cout << "\n# Display Linked List: " << endl;
        else if (ch == 12)
            cout << "\n# Reversed Linked List: " << endl;
        else
            cout << "\n# Updated Linked List: " << endl;
        temp = head;
        int i = 1;
        cout << "  Node\tData" << endl;
        while (temp != NULL)
        {
            cout << "  " << left << setw(8) << i;
            cout << left << setw(10) << temp->data << endl;
            temp = temp->next;
            i++;
        }
        cout << "* Number of nodes =  " << count << endl;
        cout << endl;
    }
}

// # Creation
void Create_linked_list(int *cnt)
{

    cout << "\n# Create Linked List: " << endl;

    // Other variables
    int choice, count = 0, i = 1;

    // while loop
    while (choice)
    {
        newnode = new (nothrow) struct node;
        cout << "\nEnter the node-" << i << " data: ";
        cin >> newnode->data;
        newnode->next = NULL;

        // linking nodes
        if (head == NULL) // executes at first time only
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

    // Display data
    cout << "\n# Display Linked List: " << endl;
    temp = head;
    cout << "  Node\tData" << endl;
    while (temp != NULL)
    {
        count++;
        cout << "  " << left << setw(8) << count;
        cout << left << setw(10) << temp->data << endl;
        temp = temp->next;
    }

    // Display count of nodes
    cout << "* Number of nodes in the linked list are: " << count << endl;

    *cnt = count;
}

// # Node_count
void Node_count(int count)
{
    cout << "\n# Node Count: " << endl;
    if (head == NULL)
    {
        cout << "* The list is empty!" << endl;
        cout << "* Number of nodes = " << count << endl;
    }
    else
    {
        cout << "* Number of nodes = " << count << endl;
    }
}

// # Linked list length
int getlength()
{
    int count = 0;
    temp = head;
    if (head == NULL)
        return count;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// # Search
void Search_Data(int count)
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
        for (i = 0; i < count; i++)
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

// # Reverse linked list
void Reverse_linked_list()
{
    struct node *prevnode, *currentnode, *nextnode;
    prevnode = NULL;
    currentnode = nextnode = head;
    if (head == NULL)
    {
        cout << "\n* The list is empty! You can't reverse." << endl;
    }
    else
    {
        while (nextnode != NULL)
        {
            nextnode = nextnode->next;
            currentnode->next = prevnode;
            prevnode = currentnode;
            currentnode = nextnode;
        }
        head = prevnode;
        cout << "\n* Linked list reversed successfully.." << endl;
    }
}

// ** Done **