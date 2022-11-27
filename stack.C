#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
}*newnode,*top=0,*temp;

void display()
{
    temp=top;
    if(temp==0)
    {
        printf("Stack Underflow.\n");
    }
    else
    {
        printf("\nStack:\n");
        while(temp!=0)
        {
        printf("%d\n",temp->data);
        temp=temp->next;
        }
    }
}
void push()
{
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter Elements: ");
    scanf("%d",&newnode->data);
    newnode->next=top;
    top=newnode;
    display();
}
void pop()
{
    temp=top;
    if(temp==0) printf("Stack Underflow.\n");
    else
    {
        top=temp->next;
        free(temp);
        printf("\nElement Popped.");
        display();
    }
}
 void peek()
 {
     if(top==0) printf("Stack Underflow.");
     else printf("\nElement on top: %d",top->data);
 }
int main()
{
    int ch;
 do
    {
    printf("\nEnter the operation you want to perform.\nPress '1' to push element.\nPress '2' to pop element.\nPress '3' to display stack.\nPress '4' to display top element.\nPress '5' to Exit\n>");
    scanf("%d",&ch);
    switch(ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(0);
        default:
            printf("Enter valid choice.");
        }
    }
 while(ch!=5);
}
