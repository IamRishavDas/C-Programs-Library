#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *next;
}*top=NULL;
void push(int);
void pop();
void pup();
int main()
{
	int choice,data;
	while(1)
	{
		printf("\n press 1 for push");
		printf("\n press 2 for pop");
		printf("\n press 3 for pup");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	printf("\n entre the data: ");
					scanf("%d",&data);
					push(data);
					break;
			case 2:	pop();
					break;
			case 3:	pup();
					break;
			default:	printf("\n wrong choice!!");
		}
	}
}
void push(int data)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=data;
	temp->next=top;
	top=temp;
}
void pop()
{
	struct node *temp;
	if(top==NULL)
		printf("\n stack is empty!!");
	else
	{
		temp=top;
		top=temp->next;
		int item=temp->info;
		free(temp);
		printf("\n element %d has been deleted");
	}
	
}
void pup()
{
	struct node *q;
	if(top==NULL)
		printf("\n stack empty nothing to display!!");
	else
	{
		q=top;
		while(q!=NULL)
		{
			printf("  \n||%d||",q->info);
			q=q->next;
		}
		printf("\n||__||");
	}
}

