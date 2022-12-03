#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node*next;
};
/*void createList(int n)
{
    struct Node *newNode, *temp;
    int data, i;

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));

    if(head == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }

    printf("Enter the data of node 1: ");
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;
    temp = head;

    for(i=2; i<=n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if(newNode == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }

        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        temp->next = newNode;
        temp = temp->next;
    }
}*/
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
void search(int val,struct Node *head)
{
    int index=0;
    while(head!=NULL)
    {
        if(val == head->data)
        {
            printf("the element %d is at position %d",val,index+1);
        }
        head = head->next;
        index++;
    }
}
void insert1(int val, struct Node **head)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->next = (*head);
    newNode->data = val;
    (*head) = newNode;
}
void insertn(int pos, int val, struct Node *head)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *a = head;
    newNode->data = val;
    while(--pos)
    {
        a=a->next;
    }
    newNode->next = a->next;
    a->next = newNode;
}
void deleten(int pos, struct Node *head)
{
    struct Node *a = head;
    struct Node *b = a->next;
    for(int i=0; i<pos-1; i++)
    {
        a = a->next;
        b = b->next;
    }
    a->next = b->next ;
    free(b);
}

int main()
{
    int num,x,val,pos;
    //while(flag==1)
    //{
    struct Node *head=NULL;
    struct Node *second=NULL;
    struct Node *third=NULL;
    struct Node *forth=NULL;

    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    forth=(struct Node*)malloc(sizeof(struct Node));

    printf("Enter 4 elements for List: ");
    scanf("%d",&head->data);
    head->next=second;
    scanf("%d",&second->data);
    second->next=third;
    scanf("%d",&third->data);
    third->next=forth;
    scanf("%d",&forth->data);
    forth->next=NULL;
    /*
    printf("Enter number of nodes required: ");
    scanf("%d",&n);
    createList(n);
    */
    while(x!=4)
    {
        printf("\nPress '1' to perform searching.\nPress '2' to perform Insertion.\nPress '3' to perform Deletion.\nPress '4' to exit.\n>");
        scanf("%d",&x);

        switch(x)
        {
            case 1:
            printf("\nEnter the element to search:");
            scanf("%d",&num);
            search(num,head);
            break;

            case 2:
            printf("\nEnter element to insert: ");
            scanf("%d",&val);
            printf("Enter the position to insert in: ");
            scanf("%d",&pos);
            if(pos==1)
            {
            printf("The list after insertion is: ");
            insert1(val, &head);
            printList(head);
            }
            else if (pos>5)
            {
                printf("Cannot insert at this position.");
            }
            else
            {
            printf("The list after insertion is: ");
            insertn(pos-1, val, head);
            printList(head);
            }
            break;

            case 3:
            printf("\nEnter position of element to delete: ");
            scanf("%d",&pos);
            if(pos==1)
            {
            struct Node *a = head ;
            head = a->next ;
            free(a);
            printf("The list after deletion is: ");
            printList(head);
            }
            else if (pos>4)
            {
                printf("Node is not present.");
            }
            else
            {
            deleten(pos-1, head);
            printf("The list after deletion is: ");
            printList(head);
            }
            break;

            case 4:
            exit(0);

            default:
            printf("Invalid Choice !");
        }
    }
    return 0;
}
