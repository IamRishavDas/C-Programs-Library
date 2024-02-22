#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int info;
	struct node *prev;
	struct node *next;
}*start=NULL;
void append(int);
void add_begin(int);
void add_at_pos(int,int);
void del_first_node();
void del_last_node();
void del_pos(int);
void del_value(int);
void display();
void display();
int main()
{
	int i,data,choice,pos,n;
	while(1)
	{
		printf("\n press 1 for insert elements in the list: ");
		printf("\n press 2 for insert at the begin of the list: ");
		printf("\n press 3 for insert node at a given position: ");
		printf("\n press 4 for delete the first node:");
		printf("\n press 5 for delete the last node:");
		printf("\n press 6 for delete any value in the list:");
		printf("\n press 7 for delete any given position: ");
		printf("\n press 8 for display the list");
		printf("\n enter choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	printf("\n enter the no of nodes: ");
					scanf("%d",&n);
					for(i=0;i<n;i++)
					{
						printf("\n enter data %d: ",i+1);
						scanf("%d",&data);
						append(data);
					}
					break;
			case 2:	printf("\n enter the data: ");
					scanf("%d",&data);
					add_begin(data);
					break;
			case 3:	printf("\n enter the position: ");
					scanf("%d",&pos);
					printf("\n enter the data: ");
					scanf("%d",&data);
					add_at_pos(pos,data);
					break;
			case 4:	del_first_node();
					break;
			case 5:	del_last_node();
					break;
			case 6:	printf("\n enter the data to delete: ");
					scanf("%d",&data);
					del_value(data);
					break;
			case 7:	printf("\n enter the position to delete: ");
					scanf("%d",&pos);
					del_pos(pos);
					break;
			case 8:	display();
					break;
			default:	printf("\n invalid choice!!");
		}
	}
}
void append(int data)
{
	struct node *temp;
	struct node *q;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=data;
	temp->next=NULL;
	if(start==NULL)
		{
			temp->prev=NULL;
			start=temp;
		}
	else
	{
		q=start;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		q->next=temp;
		temp->prev=q;
	}
}
void add_begin(int data)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=data;
	temp->prev=NULL;
	temp->next=start;
	start->prev=temp;
	start=temp;
}
void add_at_pos(int pos, int data)
{
	struct node *temp,*q;
	int i;
	int flag=0;
	q=start;
	for(i=0;i<pos-1;i++)
	{
		q=q->next;
		if(q==NULL)
		{
			puts("positon not exist!!");
			flag=1;
		}
	}
	if(flag==0)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->info=data;
		temp->next=q->next;
		q->next=temp;
		temp->prev=q;
	}
}
void del_first_node()
{
	struct node *temp;
	temp=start;
	start=start->next;
	start->prev=NULL;
	free(temp);
}
void del_last_node()
{
	struct node *temp, *q;
	q=start;
	while(q->next->next!=NULL)
		q=q->next;
	temp=q->next;
	q->next=NULL;
	free(temp);
}
void del_pos(int pos)
{
	struct node *q;
	struct node *temp;
	int i, flag=0;
	q=start;
	for(i=1;i<pos-1;i++)
	{
		q=q->next;
		if(q==NULL)
		{
			puts("invalid position!!");
			flag=1;
		}
	}
	if(flag==0)
	{
		temp=q->next;
		q->next=temp->next;
		temp->next->prev=q;
		free(temp);
	}
}
void del_value(int data)
{
	struct node *temp, *q;
	if(start==NULL)
		puts("list is empty!!");
	if(start->info==data && start->next==start->prev==NULL)
	{
		temp=start;
		free(temp);
		start=NULL;
	}
	if(start->info==data)
		{
			del_first_node();
		}
	q=start;
	while(q->next->next!=NULL)
	{
		if(q->next->info==data)
		{
			temp=q->next;
			q->next=temp->next;
			temp->next->prev=q;
			free(temp);	
		}	
		q=q->next;
	}
	if(q->next->info==data)
		{
			del_last_node();
		}	
}
void display()
{
	struct node *q;
	if(start==NULL)
		puts("list is empty!!");
	else
	{
	q=start;
	while(q!=NULL)
		{
			printf("\n data= %d",q->info);
			q=q->next;
		}	
	}
}




