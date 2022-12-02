#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int salary;
	char name[20];
	int id;
	struct node *right;
	struct node *left;
}*root=NULL,*newnode,*temp1,*temp2;

void insert()
{
    newnode=(struct node*)malloc(sizeof(struct node));
	newnode->right=NULL;
	newnode->left=NULL;

	printf("ID: ");
	scanf("%d",&newnode->id);
    printf("Name: ");
    scanf("%s",&newnode->name);
	printf("Salary: ");
	scanf("%d",&newnode->salary);

	if(root==NULL)
	root=newnode;
	else
	insertn(root,newnode);
}

void insertn(struct node *root,struct node *newnode)
{
    if(newnode->salary>root->salary)
    {
        if(root->right==NULL)
        root->right=newnode;
        else
        insertn(root->right,newnode);
    }
    else if(newnode->salary<root->salary)
    {
        if(root->left==NULL)
        root->left=newnode;
        else
        insertn(root->left,newnode);
    }
}
int total(struct node * temp1)
{
    int sum=0;
    if(temp1!=NULL)
    {
        sum=(temp1->salary)+total(temp1->left)+total(temp1->right);
        return sum;
    }
}
void max_min()
{
    temp1=temp2=root;
    while(temp1!=NULL && temp1->right!=NULL)
    {
        temp1=temp1->right;
    }
    while(temp2!=NULL && temp2->left!=NULL)
    {
        temp2=temp2->left;
    }
    printf("Maximum salary: %d\nID: %d\nName: %s\n\nMinimum salary: %d\nID: %d\nName: %s\n",temp1->salary,temp1->id,temp1->name,temp2->salary,temp2->id,temp2->name);
}
void display(struct node * temp1)
{
    if(temp1!=NULL)
    {
        display(temp1->left);
        printf("\nID: %d\n",temp1->id);
        printf("Name: %s\n",temp1->name);
        printf("Salary: %d\n",temp1->salary);
        display(temp1->right);
        
    }
}
void displayrange(struct node * temp1)
{
    
    int n1,n2;
    printf("Salary Range 1: ");
    scanf("%d",&n1);
     printf("Salary Range 2: ");
    scanf("%d",&n2);
    if(temp1!=NULL)
    {
        if(temp1->salary>=n1 && temp1->salary<=n2)
        {
            printf("%d",temp1->salary);
        }
        display(temp1->right);
    }  
}
	
int main()
{
    int x,sum;
    while(1)
    {
    printf("\nPress '1' to insert.\nPress '2' to display the names of employees with min. and max. salary.\nPress '3' for total monthly expenses.\nPress '4' to display the names of employees acc. to salary\nPress '5' to display the names of employees acc. to salary in specific range.\nPress '6' to exit.\n>");
    scanf("%d",&x);
    switch(x)
    {
        case 1:
        insert();
        printf("Node Added.\n");
        break;

        case 2:
        max_min();
        break;

        case 3:
        sum=total(root);
        printf("%d\n",sum);
        break;

        case 4:
        display(root);
        break;

        case 5:
        displayrange(root);
        break;

        case 6:
        exit(0);
        break;
    }  
    }
}