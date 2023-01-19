// # Binary Tree Implementation
// # Using Recursion
// # Creation
#include <iostream>
using namespace std;

// # Node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// # Creation
struct node *Create()
{
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    // ** malloc returns void pointer so we have to typecast it to struct node **
    cout << "\n* Enter Data (-1 for no node): ";
    cin >> x;
    // ** Base Condition **
    if (x == -1)
        return NULL;
    // ** Recrsive Condition **
    newnode->data = x;
    cout << "\n* Enter left child of " << x << ": " << endl;
    newnode->left = Create();
    cout << "\n* Enter right child of " << x << ": " << endl;
    newnode->right = Create();
    return newnode;
}

// # Main
int main()
{
    cout << "\n# Binary Tree Implementation #\n";
    struct node *root;
    root = NULL;
    root = Create();
    cout << "\n# Tree is created successfully..." << endl;
    return 0;
}

/*
       # Note:
         ** We can also typedef structure -> we can use 'node' instead of 'struct node' **
         ** For dynamic memory allocation -> use malloc or new **
*/