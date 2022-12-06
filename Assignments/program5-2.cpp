// # Assignment-5 -> Part-2
// # Implement Queue using linked list
#include <iostream>
using namespace std;

typedef struct Node
{
  int data;
  Node *next;
} node;

class queue
{
private:
  node *front;
  node *rear;

public:
  queue()
  {
    front = rear = NULL;
  }
  void enqueue(int a);
  void dequeue();
  void display();
  void peek();
};

void queue::enqueue(int a)
{
  node *newnode = new node;
  newnode->data = a;
  newnode->next = NULL;
  if (rear != NULL)
  {
    rear->next = newnode;
    rear = newnode;
  }
  else
  {
    front = rear = newnode;
  }
  cout << "* Data enqueue successfully.." << endl;
}

void queue::dequeue()
{
  if (front != NULL)
  {
    node *temp = front;
    front = front->next;
    delete temp;
    cout << "* Data dequeue successfully.." << endl;
  }
  else
  {
    cout << "* Queue is empty!\n";
  }
}

void queue::peek()
{
  if (front != NULL)
  {
    cout << "\n# Front element is: " << front->data << "\n\n";
  }
  else
  {
    cout << "* Queue is empty!\n";
  }
}

void queue::display()
{
  if (front == NULL || rear == NULL)
  {
    cout << "* Queue is empty!\n";
    return;
  }
  node *temp = front;
  while (temp != NULL)
  {
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout << "NULL\n";
}

int main()
{
  queue q;
  int ch, data;
  cout << "\n # Queue Using Linked List # \n";
  while (1)
  {
    cout << "\n# Menu: \n1.Enqueue \n2.Dequeue \n3.Display \n4.Peek \n0.Exit" << endl;
    cout << "Enter your choice: ";
    cin >> ch;
    switch (ch)
    {
    case 1:
      cout << "\n# Enqueue: " << endl;
      cout << "* Enter Data: ";
      cin >> data;
      q.enqueue(data);
      break;

    case 2:
      cout << "\n# Dequeue: " << endl;
      q.dequeue();
      break;

    case 3:
      cout << "\n# Display: " << endl;
      q.display();
      break;

    case 4:
      cout << "\n# Peek: " << endl;
      q.peek();
      break;

    case 0:
      cout << "\n* You are exit\n\n";
      exit(0);
      break;

    default:
      cout << "\n* Invalid Choice\n";
      break;
    }
  }
  return 0;
}