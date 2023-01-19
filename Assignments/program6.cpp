// # Assignment-6
// # Height Balanced Tree -> AVL Tree
#include <iostream>
using namespace std;

// # Node
struct Node
{
  int key;
  struct Node *left;
  struct Node *right;
  int height;
};

// # Global
int f = 1;

// # getHeight
int getHeight(struct Node *n)
{
  if (n == NULL)
    return 0;
  return n->height;
}

// # Creation
struct Node *createNode(int key)
{
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return node;
}

// # Max
int max(int a, int b)
{
  return (a > b) ? a : b;
}

// # Balance Factor
int getBalanceFactor(struct Node *n)
{
  if (n == NULL)
  {
    return 0;
  }
  return getHeight(n->left) - getHeight(n->right);
}

// # Right Rotate
struct Node *rightRotate(struct Node *y)
{
  struct Node *x = y->left;
  struct Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
  y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

  return x;
}

// # Left Rotate
struct Node *leftRotate(struct Node *x)
{
  struct Node *y = x->right;
  struct Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
  y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

  return y;
}

// # Insertion
struct Node *insert(struct Node *node, int key)
{
  if (node == NULL)
    return createNode(key);

  if (key < node->key)
    node->left = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);

  node->height = 1 + max(getHeight(node->left), getHeight(node->right));
  int bf = getBalanceFactor(node);

  // Left Left Case -> (LL)
  if (bf > 1 && key < node->left->key)
  {
    return rightRotate(node);
  }
  // Right Right Case -> (RR)
  if (bf < -1 && key > node->right->key)
  {
    return leftRotate(node); 
  }
  // Left Right Case -> (LR)
  if (bf > 1 && key > node->left->key)
  {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }
  // Right Left Case -> (RL)
  if (bf < -1 && key < node->right->key)
  {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }
  return node;
}

// # Inorder
void Inorder(struct Node *root)
{
  if (root != NULL)
  {
    Inorder(root->left);
    printf("%d ", root->key);
    Inorder(root->right);
  }
}

// # Search
struct Node *Search(struct Node *root, int key)
{
  if (root == NULL)
  {
    f = 0;
    return NULL;
  }
  if (key == root->key)
  {
    f = 1;
    return root;
  }
  else if (key < root->key)
  {
    return Search(root->left, key);
  }
  else
  {
    return Search(root->right, key);
  }
}

// # Main
int main()
{

  // # Construct AVL
  cout << "\n\n# Height Balanced Tree -> AVL #\n";
  struct Node *root = NULL;
  root = insert(root, 1);
  root = insert(root, 2);
  root = insert(root, 3);
  root = insert(root, 4);
  root = insert(root, 8);
  root = insert(root, 7);
  root = insert(root, 6);
  root = insert(root, 5);
  root = insert(root, 11);
  root = insert(root, 10);
  root = insert(root, 12);

  while (1)
  {
    cout << "\n# Menu:" << endl;
    cout << "1.Insertion \n2.Search \n3.Inorder \n4.Display \n5.Exit" << endl;
    cout << "Enter your chooice...";
    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
      cout << "\n# Insertion: " << endl;
      int key;
      cout << "  Enter element to be Inserted: ";
      cin >> key;
      struct Node *n = Search(root, key);
      if (f == 1)
      {
        cout << "  " << key << " is already present in AVL..!" << endl;
      }
      else
      {
        root = insert(root, key);
        cout << "  " << key << " is inserted successfully..!" << endl;
      }
    }
    break;

    case 2:
      cout << "\n# Search: " << endl;
      {
        int key;
        cout << "  Enter element to be searched: ";
        cin >> key;
        struct Node *n = Search(root, key);
        if (n != NULL)
          cout << "  Found: " << n->key << endl;
        else
          cout << "  Element not found..!" << endl;
      }
      break;

    case 3:
      cout << "\n# Inorder: ";
      Inorder(root);
      cout << endl;
      break;

    case 4:
      cout << "\n # Display: ";
      cout << "\n  Inorder: ";
      Inorder(root);
      cout << endl;
      break;

    case 5:
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