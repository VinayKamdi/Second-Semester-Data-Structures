#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *hash[10]={NULL},*c;

void insert()
{
    int i,key;
    printf("\nEnter value to Insert: ");
    scanf("%d",&key);
    i=key%10;

    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=key;
    newnode->next = NULL;

    if(hash[i] == NULL) hash[i] = newnode;
    else
    {
        c=hash[i];
        newnode->next=c;
        hash[i]=newnode;
    }
    printf("Inserted Successfully.\n");
}
void search()
{
    int key,index;
    printf("\nEnter element to search: ");
    scanf("%d",&key);
    index=key%10;
    if(hash[index] == NULL) printf("\nElement not found.\n");
    else
    {
        for(c=hash[index];c!=NULL;c=c->next)
        {
            if(c->data == key)
                {
                    printf("%d found at index %d.\n",key, index);
                    break;
                }
        }
        if(c==NULL)
            printf("\nElement not found\n");
    }
}
void display()
{
    int i;
    for(i=0;i<10;i++)
    {
        printf("\nindex %d : ",i);
        if(hash[i] == NULL)
        {
        printf("No Element.");
        }
        else
        {
            for(c=hash[i];c!=NULL;c=c->next)
            printf("%d | ",c->data);
        }
        printf("\n");
    }
}
int main()
{
    int opt,key,i;
    while(1)
    {
        printf("\nEnter the operation you want to perform:\nPress '1' to Insert.\nPress '2' to Display Hash Table.\nPress '3' to Search element.\nPress '4' to Exit\n>");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:exit(0);
        }
    }
}
