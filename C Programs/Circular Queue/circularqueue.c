#include<stdio.h>
#include<stdlib.h>
#define max 5
int cq[max];
int front=-1;
int rear=-1;
void insert();
void del();
void display();
void main()
{
	int choice;
	while(1)
	{	
		printf("\n press 1 for insert");
		printf("\n press 2 for delete");
		printf("\n press 3 for display");
		printf("\n press 4 for exit the program");
		printf("\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	insert();
				break;
			case 2:	del();
				break;
			case 3:	display();
				break;
			case 4:	exit(0);
			default:printf("\n you have entered a worng choice");
		}
	}
	
}
void insert()
{
	int element;
	if((front==rear+1)||(front==0 && rear==max-1))
		printf("\n overflow condition");
	else
	{
		if(front==-1)
			{
			front=0;
			rear=0;
			}
		else if(rear==max-1)
			rear=0;
		else
			rear=rear+1;
		printf("\n enter the element: ");
		scanf("%d",&element);
		cq[rear]=element;
	}
}
void del()
{
	if(front==-1)
		printf("\n underflow condition");
	else
	{
		printf("\n the element %d is deleted",cq[front]);
		if(front==rear)
			{
				front=-1;
				rear=-1;
			}
		else if(front==max-1)
			front=0;
		else
			front=front+1;
	}
}
void display()
{
	int i;
	if(front<rear)
	{
		for(i=front;i<=rear;i++)
			printf("\n element= %d",cq[i]);
	}
	else
	{
		
		for(i=front;i<=max-1;i++)
			printf("\n element= %d",cq[i]);
		
		for(i=0;i<=rear;i++)
			printf("\n element= %d",cq[i]);
	}
}
