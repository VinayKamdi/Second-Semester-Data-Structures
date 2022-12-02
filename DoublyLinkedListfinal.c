#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node* prev;
    int data;
    struct Node* next;
}*head,*last;

void createlist(int n)
{
    struct Node* newnode;
    int i,data;
    if(n>=1)
    {
        head=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter element 1 for list: ");
        scanf("%d",&head->data);
        head->prev=NULL;
        last=head;
        for(i=2;i<=n;i++)
        {
            newnode=(struct Node*)malloc(sizeof(struct Node));
            newnode->prev=last;
            newnode->next=NULL;
            printf("Enter element %d for list: ",i);
            scanf("%d",&newnode->data);
            last->next=newnode;
            last=newnode;
        }
    }
}
void displayfromstart()
{
    int n=1;
    struct Node* tem;
    if (head==NULL) printf("\nList is empty.");
    else
    {
        tem=head;
        printf("\nLinked List: ");
        do
        {
            printf("%d ",tem->data);
            n++;
            tem=tem->next;
        }
        while(tem!=NULL);
        printf("\n");
    }
}
void displayfromlast()
{
    int n=1;
    struct Node* tem;
    if (head==NULL) printf("\nList is empty.");
    else
    {
        tem=last;
        printf("\nLinked List: ");
        do
        {
            printf("%d ",tem->data);
            n++;
            tem=tem->prev;
        }
        while(tem!=NULL);
        printf("\n");
    }
}
void insertfromstart()
{
    struct Node *newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));

    if (head==NULL) printf("\nList is empty.");

    else
    {
        newnode==(struct Node*)malloc(sizeof(struct Node));
        printf("Element to insert at start: ");
        scanf("%d",&newnode->data);
        newnode->next=head;
        newnode->prev=NULL;
        head->prev=newnode;
        head=newnode;
        printf("\nInserted Successfully.");
    }
}
void insertfromlast()
{
    struct Node *newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    if (head==NULL) printf("\nList is empty.");
    else
    {
        newnode==(struct Node*)malloc(sizeof(struct Node));
        printf("Element to insert at last: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=last;
        last->next=newnode;
        last=newnode;
        printf("\nInserted Successfully.");
    }
}
void insert(int n)
{
    struct Node *newnode;
    struct Node *tem;
    if (head==NULL) printf("\nList is empty.");
    else
    {
        tem=head;
        for(int i=1;i<n && tem!=NULL;i++) tem=tem->next;
        if(n==1 || n==0) insertfromstart();

        else if(tem==last) insertfromlast();

        else if(tem!=NULL)
        {
            newnode=(struct Node*)malloc(sizeof(struct Node));
            printf("Enter Element to insert: ");
            scanf("%d",&newnode->data);
            newnode->prev=tem;
            newnode->next=tem->next;
            tem->next->prev=newnode;
            tem->next=newnode;
            printf("\nInserted Successfully.");
        }
    }
}
void deletefromstart()
{
    struct Node *todelete;
    if (head==NULL) printf("\nList is empty.");
    else
    {
        todelete=head;
        head=head->next;
        head->prev=NULL;
        free(todelete);
        printf("\nSuccessfully Deleted.");
    }
}
void deletefromend()
{
    struct Node *todelete;
    if (head==NULL) printf("\nList is empty.");
    else
    {
        todelete=last;
        last=last->prev;
        last->next=NULL;
        free(todelete);
        printf("\nSuccessfully Deleted.");
    }
}
void delete(int n)
{
    struct Node *tem;
    tem=head;
    for(int i=0;i<n-1 &&tem!=NULL;i++)
    tem=tem->next;

    if(tem==head) deletefromstart();

    else if(tem==last) deletefromend();

    else
    {
        tem->prev->next=tem->next;
        tem->next->prev=tem->prev;
        free(tem);
        printf("\nThe position %d is Deleted.",n);
    }
}
int main()
{
    int n,choice,tem;
    printf("Enter the size for list: ");
    scanf("%d",&n);
    createlist(n);
    do{
        printf("\nEnter the operation you want to perform:\nPress '1' to display list from start.\nPress '2' to display list from end.\nPress '3' to perform Insertion.\nPress '4' to perform Deletion.\nPress '5' to Exit.\n>");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            displayfromstart();
            break;
        case 2:
            displayfromlast();
            break;
        case 3:
            printf("\nEnter the position for element to insert: ");
            scanf("%d",&tem);
            insert(tem);
            displayfromstart();
            break;
        case 4:
            printf("\nEnter the position of element to delete: ");
            scanf("%d",&tem);
            delete(tem);
            displayfromstart();
            break;
        case 5:
            exit(0);
        default:
            printf("Wrong Button Pressed.");
            break;
        }
    }
    while(choice!=5);
    return 0;
}