#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int info;
	struct node *link;
}*last=NULL;
void create_node(int);
void add_begin(int);
void add_at_pos(int,int);
void del_first_node();
void del_last_node();
void del_value(int);
void del_pos(int);
void display();
int main()
{
	int choice,n;
	int pos;
	int i,data;
	while(1)
	{
		printf("\n press 1 for insert node in circular linked list");
		printf("\n press 2 for insert a node at the begin of the list");
		printf("\n press 3 for insert a node at a given position");
		printf("\n press 4 for delete the first node");
		printf("\n press 5 for delete the last node");
		printf("\n press 6 for delete a particular value from the list");
		printf("\n press 7 for delete a node in particular position");
		printf("\n press 8 for display");
		printf("\n enter choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	printf("\n enter the no of elements: ");
					scanf("%d",&n);
					for(i=0;i<n;i++)
					{
						printf("\n enter the data %d: ",i+1);
						scanf("%d",&data);
						create_node(data);
					}
					break;
			case 2:	printf("\n enter the data: ");
					scanf("%d",&data);
					add_begin(data);
					break;
			case 3:	printf("\n enter the positon: ");
					scanf("%d",&pos);
					printf("\n enter the data: ");
					scanf("%d",&data);
					add_at_pos(pos,data);
					break;
			case 4:	del_first_node();
					break;
			case 5:	del_last_node();
					break;
			case 6:	printf("\n enter the value: ");
					scanf("%d",&data);
					del_value(data);
					break;
			case 7:	printf("\n enter node index: ");
					scanf("%d",&pos);
					del_pos(pos);
					break;
			case 8: display();
					break;
			default:	printf("\n wrong choice!!");
		}
	}
}
void create_node(int data)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=data;
	if(last==NULL)
	{
		last=temp;
		last->link=temp;
	}
	else
	{
		temp->link=last->link;
		last->link=temp;
		last=temp;
	}
}
void add_begin(int data)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=data;
	temp->link=last->link;
	last->link=temp;
}
void add_at_pos(int pos, int data)
{
	struct node *temp,*q;
	int flag=0;
	q=last->link;
	int i;
	for(i=0;i<pos-1;i++)
	{
		q=q->link;
		if(q==last->link)
			{
				puts("position not exist");
				flag=1;
			}
	}
	if(flag==0)
		{
			temp=(struct node*)malloc(sizeof(struct node));
			temp->info=data;
			temp->link=q->link;
			q->link=temp;
				if(q==last)
					last=temp;
		}
}
void del_first_node()
{
	struct node *temp;
	temp=last->link;
	last->link=temp->link;
	free(temp);
}
void del_last_node()
{
	struct node *temp;
	temp=last;
	struct node *q;
	q=last->link;
	while(q!=last)	
		q=q->link;
	q->link=last->link;
	last=q;
	free(temp);
}
void del_pos(int pos)
{
	struct node *temp;
	struct node *q;
	int i;
	q=last->link;
	int flag=0;
	for(i=0;i<pos-1;++i)
	{
		q=q->link;
		if(q==last->link)
			{
				puts("position not exist");
				flag=1;
			}
	}
	if(flag==0)
		{
			temp=q->link;
			q->link=temp->link;
			free(temp);
		}
}
void del_value(int data)
{
	struct node *q, *temp;
	if(last->link==last && last->info==data)
	{
		temp=last;
		free(temp);
		last=NULL;
	}
	q=last->link;
	if(q->info==data)
		del_first_node();
	while(q->link!=last)
		{
			if(q->link->info==data)
				{
					temp=q->link;
					q->link=temp->link;
					free(temp);
				}
				q=q->link;
		}
	if(q->link->info==data)
		del_last_node();	
	
}
void display()
{
	struct node *q;
	q=last->link;
	if(last==NULL)
		puts("empty list!!");
	else
	{
		while(q!=last)
			{
				printf("\n data: %d",q->info);
				q=q->link;
			}
			printf("\n data: %d",last->info);
	}
}
