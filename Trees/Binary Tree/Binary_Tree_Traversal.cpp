// # Binary Tree Traversal
// # Using Recursive Approach
// # 1.Creation  2.Traversal
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

// ** Binary Tree traversal **

// # Preorder
void Preorder(struct node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

// # Inorder
void Inorder(struct node *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

// # Postorder
void Postorder(struct node *root)
{
    if (root == NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

// # Main
int main()
{
    cout << "\n# Binary Tree Implementation #\n";
    struct node *root;
    root = NULL;
    cout << "\n# Creation #\n";
    root = Create();
    cout << "\n# Tree is created successfully..." << endl;

    cout << "\n# Traversal #\n";
    cout << "\n# Preorder: ";
    Preorder(root);

    cout << "\n# Inorder: ";
    Inorder(root);

    cout << "\n# Postorder: ";
    Postorder(root);

    cout << "\n\n# Tree is traversed successfully..." << endl;
    cout << "\n\n";
    return 0;
}
