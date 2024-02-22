#include<stdio.h>
#include<stdlib.h>
int top=-1;
#define max 5
int stack[max];
void push();
void pop();
void pup();
void main()
{
	int choice;
	while(1)
	{
		printf("\npress 1 for insert a elemnt in the stack");
		printf("\npress 2 for delete an element");
		printf("\npress 3 for display the stack elements");
		printf("\npress 4 for exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	push();
				break;
			case 2:	pop();
				break;
			case 3:	pup();
				break;
			case 4:	exit(0);
			default:printf("\n you have entered a wrong choice");
		}
	}
}
void push()
{
	int element;
	if(top==max-1)
		printf("\n stack overflow");
	else
	{
		printf("\n enter the element to insert: ");
		scanf("%d",&element);
		top=top+1;
		stack[top]=element;
	}
		
}
void pop()
{
	if(top==-1)
		printf("\n stack underflow");
	else
	{
		printf("\n the %d element is deleted",stack[top]);
		top=top-1;
	}
}
void pup()
{
	int i;
	if(top==-1)
		printf("\n underflow condition");
	else
	{
		for(i=0;i<=top;i++)
			printf("\n element= %d",stack[i]);
	}
	printf("\n");
}
