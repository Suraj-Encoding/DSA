// # Singly link list Implementation
#include <stdio.h>
#include <stdlib.h>
int main()
{   
    // Node 
    struct node
    {
        int data;
        struct node *next;  
    };

    // Pointers
    struct node *head, *newnode, *temp;
    head=0;  // 0 -> Null

    // Other variables
    int choice,count=0;
    
    // while loop
    while(choice){
    // Dynamic memory allocation -> using malloc function
    // creating new node 
    newnode = (struct node*) malloc(sizeof(struct node));
    // Dynamic memory allocation in c++ -> using new operator 
    // newnode = new(nothrow) struct node;  
    printf("\nEnter the data: ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    
    // linking nodes
    if(head==0)
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
    
    // condition for continue
    printf("Do you want to continue? (1.Yes 0.No) : ");
    scanf("%d",&choice);
 }
    
    // Display data
    printf("\n# Linked list is: ");
    temp=head;
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp = temp->next;
        count++;
    }

    // Display count of nodes
    printf("\nNumber of nodes are: %d\n",count);
    return 0;
}