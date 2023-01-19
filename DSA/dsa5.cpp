#include <iostream>
using namespace std;

typedef struct node
{
public:
    int data;
    int l_th;
    int r_th;
    node *left, *right;
} node;
node *root, *dummy;
class TBT
{
public:
    TBT()
    {
        root = NULL;
        dummy = new node;
        dummy->left = dummy->right = NULL;
        dummy->l_th = dummy->r_th = 0;
    }
    void insert();
    void inOrder();
};
void TBT ::insert()
{
    node *nn;
    nn = new node;
    cout << "enter data : ";
    cin >> nn->data;
    nn->l_th = nn->r_th = 0;
    nn->left = nn->right = NULL;

    if (root == NULL)
    {
        root = nn;
        root->left = root->right = dummy;

        dummy->left = root;
        return;
    }
    else
    {
        node *t, *p;
        t = root;
        p = NULL;
        while (t != NULL)
        {
            p = t;
            if (nn->data < t->data)
            {
                if (t->l_th == 1)
                {
                    t = t->left;
                }
                else
                    t = NULL;
            }
            else
            {
                if (t->r_th == 1)
                {
                    t = t->right;
                }
                else
                    t = NULL;
            }
        }
        if (nn->data < p->data)
        {
            nn->left = p->left;
            nn->right = p;
            p->l_th = 1;
            p->left = nn;
        }
        else
        {
            nn->right = p->right;
            nn->left = p;
            p->right = nn;
            p->r_th = 1;
        }
        return;
    }
}
void TBT ::inOrder()
{
    node *t;
    t = root;
    while (1)
    {
        while (t->l_th == 1)
        {
            t = t->left;
        }
        cout << t->data << " ";
        while (t->r_th == 0)
        {
            if (t->right == dummy)
            {
                return;
            }
            else
            {
                t = t->right;
                cout << t->data << " ";
            }
        }
        t = t->right;
    }
}
int main()
{
    TBT t;
    int choice;

    do
    {
        cout << "********MENU************\n";
        cout << "1.create\n";
        cout << "2.display assend\n";
        cout << "************************\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            t.insert();
            break;
        case 2:
            cout << "Inorder Data";
            t.inOrder();
            break;
        default:
            cout << " wrong choice";
            break;
        }
        cout << "\n";
    } while (choice == 1 || choice == 2);
    return 0;
}
