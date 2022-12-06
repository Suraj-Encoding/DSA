// # Inorder Traversal
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// # Creation
struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// # Inorder
void Inorder(struct node *root)
{
    if (root != NULL)  
    {   
        // L Root R
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}

int main()
{
    // Constructing
    struct node *p = createNode(4); // p -> root node
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);

    // Finally The tree looks like this:
    //        4
    //       / \       //
    //      1   6
    //     / \        //
    //    5   2

    // # Inorder =  (L Root R) -> 5 1 2 4 6

    // Linking
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // Inorder
    cout << "# Inorder: ";
    Inorder(p);
    cout << "\n";
    return 0;
}
