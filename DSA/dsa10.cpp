#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next,*prev;
};
class DLL{

    struct node *head,*tail,*temp,*new_node;

public :
    DLL(){
        head=0;
        tail=0;
    }
    void create_node(){
        
        new_node= new struct node;
        cout<<"Enter the data : ";
        cin>>new_node->data;
        new_node->next=0;
        new_node->prev=0;
    }

    void create_list(){
        int choice=1;
        
        while(choice==1){
            create_node();
            if(head==0){
                head=tail=new_node;
            }else{
                new_node->prev=tail;
                tail->next=new_node;
                tail=new_node;
            }
            cout<<"Do you want to add (1-Yes   2-No) : ";
            cin>>choice;
        }
    }
    
    void display(){
       
        temp=head;
        while(temp != 0){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    void insert_at_begining(){
        create_node();
        head->prev=new_node;
        new_node->next=head;
        head=new_node;
    }
    void insert_at_end(){
        create_node();
        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
    }
    void insert_after_data(int x){
        int flag=0;
        temp=head;
        while(temp != 0){
            if(x== temp->data){
                flag=1;
                break;
            }
            temp=temp->next;
        }
        if(flag==1){
            create_node();
            if(tail->data == x){
                insert_at_end();
            }else{
                new_node->prev=temp;
                new_node->next=temp->next;
                temp->next->prev=new_node;
                temp->next=new_node;
            }
        }else{
            cout<<"Data not present"<<endl;
        }
    }
    void insert_before_data(int x){
        int flag=0;
        temp=head;
        while(temp != 0){
            if(x== temp->data){
                flag=1;
                break;
            }
            temp=temp->next;
        }
        if(flag==1){
            create_node();
            if(head->data==x){
                insert_at_begining();
            }else{
                new_node->next=temp;
                new_node->prev=temp->prev;
                temp->prev->next=new_node;
                temp->prev=new_node;
            }
        }else{
            cout<<"Data not present"<<endl;
        }
    }
    void delete_At_begining(){
        head=temp;
        head=head->next;
        head->prev=0;
        delete temp;
        cout<<"Entered Data deleted successfully"<<endl;
    }
    void delete_at_end(){
        tail=temp;
        tail=tail->prev;
        tail->next=0;
        delete temp;
        cout<<"Entered Data deleted successfully"<<endl;
    }
    void delete_data(int x){
        int flag;
        temp=head;
        while(temp != 0){
            if(x== temp->data){
                flag=1;
                break;
            }
            temp=temp->next;
        }
        if(flag==1){
            if(temp==head){
                delete_At_begining();
            }else if(temp==tail){
                delete_at_end();
                cout<<"Entered Data deleted successfully"<<endl;
            }else{
                temp->next->prev=temp->prev;
                temp->prev->next=temp->next;
                delete temp;
                cout<<"Entered Data deleted successfully"<<endl;
            }
        }else{
            cout<<"Data not present"<<endl;
        }
    }
    void even_list(){
        struct node *even , *temp2;
        even=0;
        temp=head;

        while(temp != 0){
            if(temp->data % 2 == 0){
                if(even == 0){
                    new_node=new struct node;
                    new_node->data= temp->data;
                    new_node->next=0;
                    new_node->prev=0;
                    even=new_node;
                    temp2=even;
                }else{
                    new_node=new struct node;
                    new_node->data= temp->data;
                    new_node->next=0;
                    new_node->prev=0;
                    temp2->next=new_node;
                    new_node->prev=temp2;
                    temp2=temp2->next;
                }
            }
            temp=temp->next;
        }

        temp2=even;
        while(temp2 != 0){
            cout<<temp2->data<<" ";
            temp2=temp2->next;
        }
        cout<<endl;
    }
    

};
int main(){
    int data , choice=1;
    DLL number;
    while(choice == 1){
        int menu;
        cout<<"--> 1.Create Doubly linked list"<<endl;
        cout<<"--> 2.Display whole linked list"<<endl;
        cout<<"--> 3.Insert at begining"<<endl;
        cout<<"--> 4.Insert at end"<<endl;
        cout<<"--> 5.Insert after Data"<<endl;
        cout<<"--> 6.Insert before Data"<<endl;
        cout<<"--> 7.Delete Data"<<endl;
        cout<<"--> 8.Splitting into Even "<<endl;
        cout<<"Enter choice : ";
        cin>>menu;
        switch(menu){
            case 1:
                number.create_list();
                break;
            case 2:
                number.display();
                break;
            case 3:
                number.insert_at_begining();
                break;
            case 4:
                number.insert_at_end();
                break;
            case 5:
                cout<<"Enter number in linked list : ";
                cin>>data;
                number.insert_after_data(data);
                break;
            case 6:
                cout<<"Enter number in linked list : ";
                cin>>data;
                number.insert_before_data(data);
                break;
            case 7:
                cout<<"Enter the number you want to delete : ";
                cin>>data;
                number.delete_data(data);
                break;
            case 8:
                number.even_list();
                break;
            default:
                cout<<"Enter valid option"<<endl;
                break;
        }
        cout<<endl<<"DO YOU WANT to go in MENU ??? (1 - for yes  2 - no) : ";
        cin>>choice;
    }
    cout<<"Thank You"<<endl;

    return 0;
}
