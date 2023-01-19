#include <iostream>
#include <iomanip>
using namespace std;

struct node
{
    int data;
    node *next;
};
class sll
{
public:
    node *header = NULL;
    void insert();
    void insertbeg();
    void insertend();
    void insertposition();
    void remove();
    void deletebeg();
    void deleteend();
    void deleteposition();
    void print();
    void search();
};

void sll::insert()
{
    int choice;
    cout << "enter choice" << endl
         << "1)begining" << endl
         << "2)end" << endl
         << "3)position" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        insertbeg();
        break;
    case 2:
        insertend();
        break;
    case 3:
        insertposition();
        break;
    default:
        cout << "wrong choice!!" << endl;
    }
}
void sll::insertbeg()
{
    node *nn;
    nn = new node;
    cout << "enter the data part of node:" << endl;
    cin >> nn->data;
    nn->next = header;
    header = nn;
}

void sll::insertend()
{
    node *nn;
    nn = new node;
    cout << "enter the data part of node:" << endl;
    cin >> nn->data;
    nn->next = NULL;
    if (header == NULL)
    {
        header = nn;
    }
    else
    {
        node *cn;
        cn = header;
        while (cn->next != NULL)
        {
            cn = cn->next;
        }
        cn->next = nn;
    }
}

void sll::insertposition()
{
    node *cn;
    cn = header;
    int n;
    cout << "enter the position:" << endl;
    cin >> n;
    if (n == 1)
    {
        insertbeg();
    }
    else if (header != NULL)
    {

        int count = 1;
        while (cn->next != NULL)
        {

            count++;
            cn = cn->next;
        }

        if (n > count)
        {
            cout << "sorry the position is invalid,we will put your record in last in the list:" << endl;
            cout << "the limit is  only upto :" << count << endl;
            insertend();
        }
        else
        {
            node *nn;
            nn = new node;
            cn = header;
            for (int i = 0; i <= n - 3; i++)
            {
                cn = cn->next;
            }
            cout << "enter the data part of node:" << endl;
            cin >> nn->data;
            nn->next = cn->next;
            cn->next = nn;
        }
    }
    else
    {
        cout << "first enter the first node to access other positions:" << endl;
    }
}
void sll::remove()
{
    int choice;
    cout << "enter choice" << endl
         << "1)begining" << endl
         << "2)end" << endl
         << "3)position" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        deletebeg();
        break;
    case 2:
        deleteend();
        break;
    case 3:
        deleteposition();
        break;
    default:
        cout << "wrong choice!!" << endl;
    }
}
void sll::deletebeg()
{
    node *nn;
    nn = new node;
    nn = header;
    header = nn->next;
    delete nn;
    cout << "deleted succesfully!!" << endl;
}

void sll::deleteend()
{
    node *cn;
    cn = header;
    int count = 1;
    while (cn->next != NULL)
    {

        count++;
        cn = cn->next;
    }
    node *nn;
    nn = header;
    if (count > 1)
    {
        while (nn->next->next != NULL)
        {
            nn = nn->next;
        }
        delete nn->next;
        nn->next = NULL;
        cout << "deleted succesfully!!" << endl;
    }
    else
        deletebeg();
        
}

void sll::deleteposition()
{
    node *nn;
    nn=header;
    int count=1,m;
    while(nn->next!=NULL)
    {
        count++;
        nn=nn->next;
    }
    cout<<"only positions upto "<<count<<" are available:"<<endl; 
    cout<<"enter the node position to be deleted:"<<endl;
    cin>>m;
    if(m>count)
    {
        cout<<"you crossed the position limit,deletion cannot be done:"<<endl;
    }
    else if(m==1)
    {
        deletebeg();
    }
    else if(m<1)
    {
        cout<<"no position in exictance,deletion cannot be done:"<<endl;

    }
    else if(m==count)
    {
        deleteend();
    }
    else
    {
        nn=header;
        for(int i=0;i<m-2;i++)
        {
            nn=nn->next->next;
        }
        node *temp=nn->next;
        nn->next=nn->next->next;
        delete temp;
        cout<<"deleted succesfully!!"<<endl;
    }
}

void sll::print()
{
    if (header == NULL)
    {
        cout << "no link list in exictance:" << endl;
    }
    else
    {
        node *cn;
        cn = header;
        cout << "your nodee structure is:" << endl;
        while (cn != NULL)
        {
            cout << cn->data << "   ";
            cn = cn->next;
        }
        cout << endl;
    }
}

void sll::search()
{
    int p;
    cout<<"enter the data part of node to be searched:"<<endl;
            cin>>p;
    node *nn;
    nn=header;
    int count=1,m=0;
    while(nn->next!=NULL)
    {
        count++;
        nn=nn->next;
    }
    nn=header;
    while(nn->data!=p)
    {
        m++;
        nn=nn->next;
        if(m==count)
        {
            cout<<"no data found:"<<endl;
            break;
        }
    }
    if(m<count&&m>=0)
    {
        cout<<"in the list of "<<count<<" the node entered is present at "<<m+1<<endl;
    }
}

int main()
{
    sll obj;
    int choice;
    while (1)
    {
        cout << "enter choice" << endl
             << "1)insert" << endl
             << "2)delete" << endl
             << "3)print" << endl
             << "4)search" << endl
             << "5)exit" <<endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.insert();
            break;
        case 2:
            obj.remove();
            break;
        case 3:
            obj.print();
            break;
        case 4:
            obj.search();
            break;
        case 5:
            cout<< "!!thank you !!"<<endl;
            return 0;
            break;
        default:
            cout <<"wrong choice" << endl;
            break;
        }
    }
    return 0;
}