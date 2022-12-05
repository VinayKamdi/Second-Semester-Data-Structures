#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int id1=1000;
struct movie_details
{
	char name[25];
	char phoneno[15];
	int seatnum;
	int id;
};

int movieselect(void)
{
	int i;
	system("cls");
	printf("\t\t\tMovie Name\n");
	printf("\t\t\t-------------------------------------\n");
	printf("\t\t\t1.American Psycho starring Christian (brucewayne) Bale\n\n");
	printf("\t\t\t2.Fight Club starring Brad (chad) Pitt\n\n");
	printf("\t\t\t3.Drive starring Ryan (literally me) Gosling\n\n\t\t\tAction> ");
	scanf("%d",&i);
	system("cls");
	return i;
}

struct movie_details person[300];
void details(int count)
{
	char pass[10],pak[10]="asd";
	printf("\n\t\tEnter the password to see details: ");
	scanf("%s",&pass);
	if (strcmp(pass,pak)==0)
	{
		system("cls");
		for (int i=0;i<count;i++)
		{
			printf("\t\tSeat No: %d is booked by %s, booking id is %d\n",person[i].seatnum, person[i].name, person[i].id);
		}
	}
	else
		printf("Entered password is wrong.\n");
		system("PAUSE");
		system("cls");
}

struct movie_details person[300];
void reserveticket(int *array,int price,int selection, int count)
{
	int i,j;

	printf("\t\t\tPlease enter your name: ");
	scanf(" %19[^\n]%*[^\n]",&person[count].name);
	printf("\t\t\tPlease enter your phone number: ");
	scanf("%u",&person[count].phoneno);

	printf("\n                                SCREEN\n\n\n");
	for (i=1;i<=100;i++)
	{
		if (array[i]==0)
			printf("%d\t",i);
		else
			printf("*\t",i);
		if(i%10==0)
			printf("\n\n");
	}
	printf("\t\t\tPlease select seat number you want? ");
	scanf("%d",&j);
	z:if (j>100 || j<1)
	{
		printf("Seat No. %d is unavailable in this theater\n",j);
		printf("Please re-enter seat number: ");
		scanf("%d",&j);
		goto z;
	}
	if (array[j]==1)
	{
		printf("Sorry, this seat is already booked! Please choose another seat: ");
		scanf("%d",&j);
		goto z;
	}
	else
	{
		id1=id1+1;
		array[j]=1;
		person[count].seatnum=j;
		if (selection==1)
			show1(j,person[count].name,id1,price,count);
		else if (selection==2)
			show2(j,person[count].name,id1,price,count);
		else
			show3(j,person[count].name,id1,price,count);
	}
}

struct movie_details person[300];
void show1(int choice,char name[10],int id1,int price,int count)
{
    
	system("cls");
	printf("\n\n");
    printf("\t============================================================\n");
    printf("\t Booking ID : %d \t\t\tShow Name : American Psycho\n",id1);
    printf("\t Customer  : %s\n",name);
    printf("\t\t\t                              Date      : 22-08-2022\n");
    printf("\t                                              Time      : 07:00pm\n");
    printf("\t                                              Hall      : 02\n");
    printf("\t                                              Seats No. : %d  \n",choice);
    printf("\t                                              Price     : %d  \n\n",price);
	printf("\t============================================================\n");
	person[count].id=id1;
    printf("\tThank You For Booking a Ticket\n");
	system("PAUSE");
	system("cls");
    return;
}

struct movie_details person[300];
void show2(int choice,char name[10],int id1,int price,int count)
{
    
	system("cls");
	printf("\n\n");
       
    printf("\t============================================================\n");
    printf("\t Booking ID : %d \t\t\tShow Name : Fight Club\n",id1);
    printf("\t Customer  : %s\n",name);
    printf("\t\t\t                                Date      : 22-08-2022\n");
    printf("\t\t\t                                Time      : 09:00pm\n");
    printf("\t\t\t                                Hall      : 03\n");
    printf("\t\t\t                                Seat No.  : %d  \n",choice);
    printf("\t\t\t                                Price     : %d  \n\n",price);
	printf("\t============================================================\n");
    person[count].id=id1;
    printf("\tThank You For Booking a Ticket\n");
	system("PAUSE");
	system("cls");
    return;
}

struct movie_details person[300];
void show3(int choice,char name[10],int id1,int price,int count)
{ 
	
	system("cls");
	printf("\n\n");

    printf("\t============================================================\n");
    printf("\t Booking ID : %d \t\t\tShow Name : Drive\n",id1);
    printf("\t Customer  : %s\n",name);
    printf("\t\t\t                              Date      : 22-08-2022\n");
    printf("\t                                              Time      : 12:00am\n");
    printf("\t                                              Hall      : 04\n");
    printf("\t                                              seats No. : %d  \n",choice);
    printf("\t                                              price . : %d  \n\n",price);
	printf("\t============================================================\n");
    person[count].id=id1;
    printf("\tThank You For Booking a Ticket\n");
	system("PAUSE");
	system("cls");
    return;
}

struct movie_details person[300];
void cancelticket(int *array)
{
    int Cseat,i,stop;
	printf("Please enter ID number of ticket: ");
	scanf("%d",&Cseat);
	for (i=0;i<300;i++)
	{
		if(Cseat==person[i].id)
		{
			stop=5;
			system("cls");
			printf("L chosen.\nYour ticket for seat no. %d is cancelled successfully.",person[i].seatnum);
			array[person[i].seatnum]=0;
			i=300;
		}
	}
	  if (stop!=5)
	  		printf("Ticket ID number is incorrect please enter right one to cancel ticket: \n");
}

int main()
{
	int **seatnum, choice, price=500, selection, i,x, count = 0;
	char pass[10],pak[10]="asd";

	seatnum=(int **)calloc(101,sizeof(int *));

	for (i=0;i<3;i++)
		*(seatnum+i)=(int *)calloc(101,sizeof(int ));
	
while(x!=3)
	{
		system("cls");
		printf("\t###### Welcome To Monarch Theatre, Gotham City ######\n");
		printf("\t-----------------------------------------------------\n");
        c:
		printf("\n\t\t\tWhat can we help you with?\n\n");
        printf("\t\t\t1- To purchase ticket.\n");
        printf("\t\t\t2- To cancel the seat.\n");
		printf("\t\t\t3- To view reserved tickets.\n");
        printf("\t\t\t4- Exit System.\n\n\t\t\tAction> ");
        scanf("%d",&choice);
        switch(choice)
		{
        case 1:
            printf("\n\tEnter the password to book the ticket: ");
            scanf("%s",&pass);
            if (strcmp(pass,pak)==0)
			{
                selection=movieselect();
                reserveticket(seatnum[selection-1],price,selection,count);
                count++;
            }
            else
                printf("\t\t\tWrong Password!\n");
                goto c;
            break;

        case 2:
            printf("\n\tEnter the password to cancel the seat: ");
            scanf("%s",&pass);
            if (strcmp(pass,pak)==0)
			{
                selection=movieselect();
                cancelticket(seatnum[selection-1]);
            }
            else
                printf("\t\t\tWrong Password!\n");
            	goto c;
            break;

		case 3:
			details(count);
        	goto c;
			break;
			
		case 4:
        	exit(0);

        default:
			printf("\t\t\tEnter Valid Choice.\n");
			break;
		}
	}
}