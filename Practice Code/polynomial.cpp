// # Polynomial Addition
#include <iostream>
using namespace std;

struct node
{
    int coe;
    int expo;
    struct node *next;
};

struct node *Create(struct node *head)
{
    int term, i;
    int coe, expo;
    cout << "Enter noumber of terms: ";
    cin >> term;
    for (i = 0; i < term; i++)
    {
        cout << "# Term-" << (i + 1) << endl;
        cout << "Coe: ";
        cin >> coe;
        cout << "Expo: ";
        cin >> expo;

        head = Insert(head, coe, expo);
    }
    return head;
}

struct node *Insert(struct node *head, int coe, int expo)
{
    struct node *temp;
    struct node *ptr = new (nothrow) struct node;
    ptr->coe = coe;
    ptr->expo = expo;
    ptr->next = NULL;
}

int main()
{
    struct node *head1, *head2;
    head1 = head2 = NULL;
    cout << "Enter the first polynomial: " << endl;
    head1 = Create(head1);
    cout << "Enter the second polynomial: " << endl;
    head2 = Create(head2);
    // polyadd(head1, head2);
    return 0;
}