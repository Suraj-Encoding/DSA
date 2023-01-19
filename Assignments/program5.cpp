// # Assignment-5
// # Threaded Binary Tree (TBT)
#include <iostream>
using namespace std;

// # Node
struct node
{
    int data;
    node *left, *right;
    int lbit, rbit;
};

// # Class
class TBT
{
private:
    node *root;
    node *head;
    node *temp;

public:
    // # Constructor
    TBT()
    {
        root = NULL;
        head = new struct node;
    }
    // # Create
    void Create()
    {
        int ch;
        do
        {
            cout << "\nEnter the data: ";
            temp = new struct node;
            cin >> temp->data;
            temp->left = NULL;
            temp->right = NULL;
            temp->lbit = 0;
            temp->rbit = 0;

            if (root == NULL)
            {
                root = temp;
                head->data = 999;
                head->left = root;
                head->right = head;
                head->lbit = 1;
                head->rbit = 1;
                root->left = head;
                root->right = head;
            }
            else
            {
                Insert(root, temp);
            }
            cout << "\nDo you want to Insert more nodes(0.No 1.Yes): ";
            cin >> ch;
        } while (ch);
    }
    // # Insert
    void Insert(struct node *root, struct node *temp)
    {
        if (temp->data < root->data)
        {
            if (root->left == NULL || root->lbit == 0)
            {
                temp->left = root->left;
                root->left = temp;
                temp->right = root;
                root->lbit = 1;
            }
            else
            {
                Insert(root->left, temp);
            }
        }
        if (temp->data > root->data)
        {
            if (root->right == NULL || root->rbit == 0)
            {
                temp->right = root->right;
                root->right = temp;
                temp->left = root;
                root->rbit = 1;
            }
            else
            {
                Insert(root->right, temp);
            }
        }
    }
    // # Inorder
    void Inorder()
    {
        struct node *t = head->left;
        do
        {
            while (t->lbit != 0)
            {
                t = t->left;
            }
            cout << t->data << " ";
            while (t->rbit == 0)
            {
                t = t->right;
                if (t == head)
                    return;
                cout << t->data << " ";
            }
            t = t->right;
        } while (t != head);
    }
};

// # Main Function
int main()
{
    cout << "\n# Threaded Binary Tree #\n";
    TBT t;
    cout << "\n# Creation: " << endl;
    t.Create();
    cout << "\n# Inorder: ";
    t.Inorder();
    cout << "\n\n";
    return 0;
}