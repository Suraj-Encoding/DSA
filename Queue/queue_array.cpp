// # Queue using arrays
// # Operations:
//   1.Enqueue (Insertion)  2.Dequeue (Deletion)   3.Front/Head   4.Rear/Tail  -> [Print without deletion]
//   5.IsFull  6.IsEmpty    7.Display ( Traverse + Print )
#include <iostream>
using namespace std;

// Global declaration
int N, front = -1, rear = -1;
int *queue;

// Functions declaration
void Enqueue(void);
void Dequeue(void);
void Display(void);
void Front(void);
void Rear(void);
void IsFull(void);
void IsEmpty(void);
void Position(void);

// main function
int main()
{
    int ch;
    cout << "\n# Queue Using Array #" << endl;
    cout << "\n# Create Queue: " << endl;
    cout << "Enter size of the queue: ";
    cin >> N;
    queue = new (nothrow) int[N];
    cout << "* Queue created successfully.." << endl;
    // do-while loop
    do
    {
        cout << "\n# Menu: " << endl;
        cout << "1.Enqueue" << endl;
        cout << "2.Dequeue" << endl;
        cout << "3.Display" << endl;
        cout << "4.Front_Data" << endl;
        cout << "5.Rear_Data" << endl;
        cout << "6.IsFull" << endl;
        cout << "7.IsEmpty" << endl;
        cout << "8.Position" << endl;
        cout << "0.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        // Switch case
        switch (ch)
        {

        case 1:
            Enqueue();
            break;

        case 2:
            Dequeue();
            break;

        case 3:
            Display();
            break;

        case 4:
            Front();
            break;

        case 5:
            Rear();
            break;

        case 6:
            IsFull();
            break;

        case 7:
            IsEmpty();
            break;

        case 8:
            Position();
            break;

        case 0:
            goto end;
            break;

        default:
            cout << "\n* Invalid Choice!" << endl;
            break;
        }
    } while (1);
end:
    cout << "\n* You are exit!\n"
         << endl;
    return 0;
}

// ** Functions defination **

// # Enqueue
void Enqueue()
{
    int x, choice;
    cout << "\n# Enqueue Data: \n"
         << endl;
    while (choice)
    {
        cout << "Enter the data: ";
        cin >> x;
        if (rear == N - 1)
        {
            IsFull();
            choice = 0;
        }
        else
        {
            if (front == -1)
            {
                front++;
            }
            rear++;
            queue[rear] = x;
            cout << "* Data Enqueue Successfully.." << endl;
            cout << "\nDo you want continue? (1.Yes 0.No): ";
            cin >> choice;
            cout << endl;
        }
    }
}

// # Dequeue
void Dequeue()
{
    cout << "\n# Dequeue Data: ";
    if (rear == -1)
    {
        IsEmpty();
    }
    else
    {
        cout << "\n* Data Dequeue Successfully.." << endl;
        cout << "* Deleted item is: " << queue[front] << endl;
        queue[front] = 0;
        front++;
    }
}

// # Front
void Front()
{
    cout << "\n# Front Data: ";
    if (rear == -1)
    {
        IsEmpty();
    }
    else
    {
        cout << "\n* The front data of queue is: " << queue[front] << endl;
    }
}

// # Rear
void Rear()
{
    cout << "\n# Rear Data: ";
    if (rear == -1)
    {
        IsEmpty();
    }
    else
    {
        cout << "\n* The rear data of queue is: " << queue[rear] << endl;
    }
}

// # Display
void Display()
{
    int i;
    cout << "\n# Display queue: ";
    if (rear == -1)
    {
        IsEmpty();
        cout << "# Empty queue # " << endl;
        cout << "  Index : ";
        for (i = 0; i < N; i++)
        {
            if (i == 0)
                cout << "-1 ";
            cout << "- ";
        }
        cout << endl;
        cout << "  Value : ";
        for (i = 0; i < N; i++)
        {
            if (i == 0)
                cout << " 0 ";   
            cout << "- ";
        }
        cout << endl;
    }
    else
    {
        cout << endl;
        cout << "  Index : ";
        for (i = 0; i < N; i++)
        {
            if (queue[i] == 0)
            {
                cout << "- ";
            }
            else
            {
                cout << i << " ";
            }
        }
        cout << endl;
        cout << "  Value : ";
        for (i = 0; i < N; i++)
        {
            if (queue[i] == 0)
            {
                cout << "- ";
            }
            else
            {
                cout << queue[i] << " ";
            }
        }
        cout << endl;
    }
}

// # IsFull
void IsFull()
{
    if (rear == N - 1)
        cout << "\n* Overflow condition! -> Queue is full" << endl;
    else
        cout << "\n* Queue is not full" << endl;
}

// # IsEmpty
void IsEmpty()
{
    if (rear == -1)
        cout << "\n* Underflow condition! -> Queue is empty" << endl;
    else
        cout << "\n* Queue is not empty" << endl;
}

// # Position
void Position()
{   
    cout<<"\n# Position: "<<endl;
    cout << "* Front = " << front << endl;
    cout << "* Rear = " << rear << endl;
}
