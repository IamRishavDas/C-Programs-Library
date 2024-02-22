#include<stdio.h>
#include<stdlib.h>
#define max 5
int queue[max];
int front=-1;
int rear=-1;
void add();
void del();
void display();
int main()
{
	int choice;
	while(1)
	{
		printf("\n press 1 for insertion");
		printf("\n press 2 for deletion");
		printf("\n press 3 for display");
		printf("\n press 4 for exit");
		printf("\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	add();
				break;
			case 2:	del();
				break;
			case 3:	display();
				break;
			case 4:	exit(0);
			default:printf("\n you have enterd a wrong choice");
		}
	}
return 0;
}
void add()
{
	int item;
	if(rear==max-1)
		printf("\n the linear queue is full ");
	else
	{
		if(front==-1)
			{
				front=0;
				rear=0;
			}
		else
			rear=rear+1;
		printf("\n enter the element: ");
		scanf("%d",&item);
		queue[rear]=item;
	}
}
void del()
{
	if(front==-1)
		printf("\n underflow condition");
	else
	{
		printf("\n the element %d is deleted",queue[front]);
		front=front+1;
	}
}
void display()
{
	int i;
	for(i=front;i<=rear;i++)
		printf("\n element= %d",queue[i]);
}
