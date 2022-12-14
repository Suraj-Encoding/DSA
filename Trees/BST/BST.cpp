// # Binary Search Tree (BST)
// # Operations: 1.Creation  2.Insertion  3.Deletion  4.Search  5.IsBST
//               6.Traversal -> (Inorder,Preorder,Postorder)
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
struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// **** Traversal ****

// # Inorder
void Inorder(struct node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}

// # Preorder
void Preorder(struct node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

// # Postorder
void Postorder(struct node *root)
{
    if (root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }
}

// # IsBST
int IsBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!IsBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return IsBST(root->right);
    }
    else
    {
        return 1;
    }
}

// # Search
struct node *Search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return Search(root->left, key);
    }
    else
    {
        return Search(root->right, key);
    }
}

// # Insert
void Insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            cout << "  Cannot Insert " << key << ", already in BST" << endl;
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *newnode = createNode(key);
    if (key < prev->data)
    {
        prev->left = newnode;
    }
    else
    {
        prev->right = newnode;
    }
    cout << "  Data Inserted successfully..!" << endl;
}

// # Inoder_Predecessor
struct node *Inorder_Predecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
        root = root->right;
    return root;
}

// # Delete
struct node *Delete(struct node *root, int key)
{
    struct node *ipre;
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
    {
        delete root;
        return NULL;
    }
    // Search for the node to be deleted
    if (key < root->data)
        root->left = Delete(root->left, key);
    else if (key > root->data)
        root->right = Delete(root->right, key);
    // Deletion strategy when the node is found
    else
    {
        ipre = Inorder_Predecessor(root);
        root->data = ipre->data;
        root->left = Delete(root->left, ipre->data);
    }
    return root;
}

// # Main Function
int main()
{
    // # Construct BST
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    // # Binary Search Tree (BST)
    //            5
    //           / \
    //          3   6
    //         / \
    //        1   4

    // # Linking nodes
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // # BST Program
    cout << "\n\n# Binary search Tree #\n";
    while (1)
    {
        cout << "\n# Menu:" << endl;
        cout << "1.Insertion \n2.Deletion \n3.Search \n4.IsBST \n5.Traversal \n6.Exit" << endl;
        cout << "Enter your chooice...";
        int ch;
        cin >> ch;
        switch (ch)
        {

        case 1:
            cout << "\n# Insertion: " << endl;
            {
                int key;
                cout << "  Enter element to be Inserted: ";
                cin >> key;
                Insert(p, key);
            }
            break;

        case 2:
            cout << "\n# Deletion: " << endl;
            {
                int key;
                cout << "  Enter element to be deleted: ";
                cin >> key;
                // Check presence of key in BST
                struct node *n = Search(p, key);
                if (n == NULL)
                {
                    cout << "  Element not found..!" << endl;
                }
                else
                {
                    cout << "\n  Inorder: ";
                    Inorder(p);
                    Delete(p, key);
                    cout << "\n  " << key << " is deleted successfully..." << endl;
                    cout << "  |Root node: " << p->data;
                    cout << "| -> Inorder: ";
                    Inorder(p);
                }
            }
            break;

        case 3:
            cout << "\n# Search: " << endl;
            {
                int key;
                cout << "  Enter element to be searched: ";
                cin >> key;
                struct node *n = Search(p, key);
                if (n != NULL)
                    cout << "  Found: " << n->data << endl;
                else
                    cout << "  Element not found..!" << endl;
            }
            break;

        case 4:
            cout << "\n# IsBST: " << endl;
            {
                int x = IsBST(p);
                if (x)
                    cout << "  Given tree is a BST..!" << endl;
                else
                    cout << "  Given tree is not a BST..!" << endl;
            }
            break;

        case 5:
            cout << "\n# Traversal: ";
            cout << "\n  Inorder: ";
            Inorder(p);
            cout << "\n  Preorder: ";
            Preorder(p);
            cout << "\n  Postorder: ";
            Postorder(p);
            cout << endl;
            break;

        case 6:
            cout << "\n* You are exit!\n\n";
            exit(0);
            break;

        default:
            cout << "\n* Inavlid Choice!\n";
            break;
        }
    }
    return 0;
}