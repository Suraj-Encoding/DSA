// # Preorder Traversal
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

// # Preorder
void Preorder(struct node *root)
{
    if (root != NULL)
    {   
        // Root L R
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
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

    // # Preorder = (Root L R) -> 4 1 5 2 6

    // Linking
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // Preorder
    cout << "# Preorder: ";
    Preorder(p);
    cout << "\n";
    return 0;
}
