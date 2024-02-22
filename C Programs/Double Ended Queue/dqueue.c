#include<stdio.h>
#include<stdlib.h>
#define max 5
int dqueue[max];
int front=-1;
int rear=-1;
void insert();
void del();
void display();
void insert_at_front();
void delete_at_rear();
void input_restricted();
void output_restricted();
void main()
{
	int choice;
	while(1)
	{
		printf("\n press 1 for input restricted dqueue");
		printf("\n press 2 for output restricted dqueue\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: input_restricted();
				break;
			case 2:	output_restricted();
				break;
			default: printf("\n you have entered a wrong choice");
		}
	}
}
void input_restricted()
{
	int c1;
	while(1)
	{
		printf("\n press '1' for insert an element in the rear side");
		printf("\n press '2' for delete an element from front side");
		printf("\n press '3' for delete an element from the rear side");
		printf("\n press '4' for display the queue");
		printf("\n press '5' for exit\n");
		scanf("%d",&c1);
		switch(c1)
			{
				case 1:	insert();
						break;
				case 2:	del();
						break;
				case 3:	delete_at_rear();
						break;
				case 4:	display();
						break;
				case 5:	exit(0);
				default:	printf("\n you have entered a worng choice");
			}
	}
}
void output_restricted()
{
	int c2;
	while(1)
	{
		printf("\n press 1 for insert an element in the rear side");
		printf("\n press 2 for delete an element from front side");
		printf("\n press 3 for insert an element at front side");
		printf("\n press 4 for display the queue");
		printf("\n press 5 for exit\n");
		scanf("%d",&c2);
		switch(c2)
			{
				case 1:	insert();
						break;
				case 2:	del();
						break;
				case 3:	insert_at_front();
						break;
				case 4:	display();
						break;
				case 5:	exit(0);
				default:	printf("\n you have entered a worng choice");
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
		dqueue[rear]=element;
	}
}
void del()
{
	if(front==-1)
		printf("\n underflow condition");
	else
	{
		printf("\n the element %d is deleted",dqueue[front]);
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
			printf("\n element= %d",dqueue[i]);
	}
	else
	{
		
		for(i=front;i<=max-1;i++)
			printf("\n element= %d",dqueue[i]);
		
		for(i=0;i<=rear;i++)
			printf("\n element= %d",dqueue[i]);
	}
}
void delete_at_rear()
{
	if(front==-1)
		printf("\n unnderflow, nothing to delete");
	else
	{
		printf("\n the element deleted from rear side is %d",dqueue[rear]);
		if(front==rear)
			{
				front==-1;
				rear==-1;
			}
		else if(rear==0)
			{
				rear=max-1;
			}
		else
			rear=rear-1;
	}
}
void insert_at_front()
{
	int element;
	if((front==rear+1)||(front==0 && rear==max-1))
		printf("\n overflow condition, no space in queue");
	else
	{
		if(front==-1)
			{
				front=0;
				rear=0;
			}
		else if(front==0)
			{
				front=max-1;
			}
		else
			front=front-1;
		printf("\n enter the element to insert: ");
		scanf("%d",&element);
		dqueue[front]=element;
	}
}
