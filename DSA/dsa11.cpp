#include <iostream>
#include <iomanip>
using namespace std;
struct tnode
{
    int data;
    tnode *left = NULL, *right = NULL;
};
class tree
{
public:
    tnode *root = NULL;
    void create();
    void search();
    void display_ascend();
    void inorder(tnode *q);

    tnode *deletenode(tnode *root, int key)
    {
        tnode *temp;
        if (root == NULL)
        {
            cout << "NO key exists" << endl;
            return NULL;
        }
        else if (key < root->data)
        {
            root->left = deletenode(root->left, key);
        }
        else if (root->data < key)
        {
            root->right = deletenode(root->right, key);
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                temp = root;
                root = NULL;
                delete temp;
            }
            else if (root->right == NULL)
            {
                temp = root;
                root = root->left;
                temp->left = NULL;
                delete temp;
            }
            else if (root->left == NULL)
            {
                temp = root;
                root = root->right;
                temp->left = NULL;
                delete temp;
            }
            else
            {
                temp = root;
                temp = temp->right;
                while (temp->left != NULL)
                {
                    temp = temp->left;
                }
                root->data = temp->data;
                root->right = deletenode(root->right, temp->data);
            }
            return root;
        }
    }
};

void tree::create()
{
    tnode *nn = new tnode;
    tnode *cn, *parent;
    cn = root;
    cout << "enter data in tree:" << endl;
    cin >> nn->data;
    if (cn == NULL)
    {
        root = nn;
    }
    else
    {
        while (cn != NULL)
        {
            parent = cn;
            if (cn->data > nn->data)
            {
                cn = cn->left;
            }
            else
            {
                cn = cn->right;
            }
        }
        if (parent->data > nn->data)
        {
            parent->left = nn;
        }
        else
        {
            parent->right = nn;
        }
    }
}
void tree::display_ascend()
{
    tnode *cn = root;
    if (cn == NULL)
    {
        cout << "binary tree is not in existance" << endl;
    }
    else
    {
        inorder(cn);
    }
    cout << endl;
}
void tree::inorder(tnode *root)
{
    tnode *cn = root;
    if (cn != NULL)
    {
        inorder(cn->left);
        cout << cn->data << " ";
        inorder(cn->right);
    }
}
void tree::search()
{
    tnode *cn = root;
    int m;
    cout << "enter data to search:" << endl;
    cin >> m;
    while (cn != NULL)
    {
        if (cn->data == m)
        {
            cout << "record found" << endl;
            break;
        }
        else if (cn->left != NULL || cn->right != NULL)
        {
            if (cn->data > m)
            {
                cn = cn->left;
            }
            else
            {
                cn = cn->right;
            }
        }
        else
        {
            cn = NULL;
        }
    }
    if (cn == NULL)
    {
        cout << "record not found" << endl;
    }
}

int main()
{
    tree t;
    int choice, key, ch;
    while (1)
    {
        cout << endl
             << "menu" << endl
             << "1)insert" << endl
             << "2)search" << endl
             << "3)display" << endl
             << "4)delete node" << endl
             << "5)exit" << endl;
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            do
            {
                t.create();
                cout << "want to add more:1)yes" << endl;
                cin >> ch;
            } while (ch == 1);
            break;
        case 2:
            t.search();
            break;
        case 3:
            t.display_ascend();
            break;
        case 4:
            cout << "enter the key to delete:" << endl;
            cin >> key;
            t.deletenode(t.root, key);
            break;
        case 5:
            return 0;
            break;
        default:
            cout << "wrong choice" << endl;
            break;
        }
    }
    return 0;
}