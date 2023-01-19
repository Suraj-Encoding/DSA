#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    int height;
    node *left;
    node *right;
} node;
node *root = NULL;
class tree
{
public:
    int getheight(node *n)
    {
        if (n == NULL)
            return 0;
        return n->height;
    }
    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
    node *createnode(int data)
    {
        node *nn = new node;
        nn->data = data;
        nn->left = NULL;
        nn->right = NULL;
        nn->height = 1;
        return nn;
    }
    int getbalancefactor(node *n)
    {
        if (n == NULL)
            return 0;
        return (getheight(n->left) - getheight(n->right));
    }
    node *rightrotate(node *y)
    {
        node *x = y->left;
        node *t2 = x->right;

        x->right = y;
        y->left = t2;
        y->height = max(getheight(y->right), getheight(y->left));
        x->height = max(getheight(x->right), getheight(x->left));
        return x;
    }

    node *leftrotate(node *x)
    {
        node *y = x->right;
        node *t2 = y->left;

        y->left = x;
        x->right = t2;
        y->height = max(getheight(y->right), getheight(y->left));
        x->height = max(getheight(x->right), getheight(x->left));
        return y;
    }

    node *create(node *node, int data)
    {
        if (node == NULL)
            return createnode(data);
        if (data < node->data)
            node->left = create(node->left, data);
        else if (data > node->data)
            node->right = create(node->right, data);
        else // Equal keys not allowed
            return node;
        int bf = getbalancefactor(node);
        if (bf > 1 && data < node->left->data)
            return rightrotate(node);

        // Right Right Case
        if (bf < -1 && data > node->right->data)
            return leftrotate(node);
        // Left Right Case
        if (bf > 1 && data > node->left->data)
        {
            node->left = leftrotate(node->left);
            return rightrotate(node);
        }

        // Right Left Case
        if (bf < -1 && data < node->right->data)
        {
            node->right = rightrotate(node->right);
            return leftrotate(node);
        }
        return node;
    }
    void inorder(node *root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void display()
    {
        int ch;
        node *temp = root;
        
            cout << "DISPLAYING ELEMENTS IN ASCENDING ORDER(inorder traversal):";
            inorder(temp);

    }
    void search()
    {
        int d;
        cout << "ENTER DATA TO BE SEARCHED:";
        cin >> d;
        node *temp = root, *parent;
        while (temp != NULL)
        {
            if (temp->data == d)
            {
                break;
            }
            else
            {
                parent = temp;
                if (d < temp->data)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
        if (temp == NULL)
        {
            cout << "ELEMENT NOT FOUND\n";
        }
        else
        {
            cout << "ELEMENT FOUND\n";
        }
    }
};
int main()
{
    int ch, data;
    tree t;
    while (1)
    {
        cout << "\nENTER:\n1.CREATE\n2.DISPLAY\n3.SEARCH\n4.EXIT\nCHOICE:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "ENTER NODE VALUE:";
            cin >> data;
            root = t.create(root, data);
            break;
        case 2:
            t.display();
            break;
        case 3:
            t.search();
            break;
        case 4:
            return 0;
        default:
            cout << "INVALID INPUT!!!!";
            break;
        }
    }
}