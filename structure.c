#include<stdio.h>
#define max 20
typedef struct student{
char name[max];
int roll;
int sem;
char sec;
}student;

int main()
{
    int a;
    student s1;
    printf("Enter name roll no, sem and sec of student 1:\n");
    gets(s1.name);
    scanf("%d %d",&s1.roll,&s1.sem);
    scanf(" %c",&s1.sec);

    printf("\nDetails of student 1:\n");
    printf("Name: ");
    puts(s1.name);
    printf("Roll No.: %d\nSem.: %d\nSec.: %c\n",s1.roll,s1.sem,s1.sec);

    student s2;
    printf("\nEnter name roll no, sem and sec of student 2:\n");
    gets(s2.name);
    scanf("%d %d",&s2.roll,&s2.sem);
    scanf(" %c",&s2.sec);

    printf("\nDetails of student 2:\n");
    printf("Name: ");
    puts(s2.name);
    printf("Roll No.: %d\nSem.: %d\nSec.: %c\n",s2.roll,s2.sem,s2.sec);

return 0;
}
