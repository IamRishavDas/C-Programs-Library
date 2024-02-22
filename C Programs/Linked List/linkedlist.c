#include<stdio.h>
#include<stdlib.h>
struct node
	{
		int info;
		struct node *link;
	}*start=NULL;
void append(int);
void add_begin(int);
void add_after_node(int,int);
//void add_after_value(int,int);
void del_begin();
void del_node(int);
void del_value(int);
void del_last();
void search(int);
void reverse();
void display();
void end();
void max_min();
int main()
{
	int n,i,data,pos,value;
	int choice;
	while(1)
	{
		printf("\n ************************************************************");
		printf("\n ************************************************************");
		printf("\n ** <1> to add a new node to list			     **");
		printf("\n ** <2> to add a new node at the begining of the list	     **");
		printf("\n ** <3> to add a new node after a gievn node of the list   **");
		//printf("\n ** <4> to add a new node after a gievn value of the list**");
		printf("\n ** <5> to delete a node from the begining of the list     **");
		printf("\n ** <6> to delete a given node in the list		     **");
		printf("\n ** <7> to delete a given value in the list		     **");
		printf("\n ** <8> to delete the last node in the list		     **");
		printf("\n ** <9> to reverse the list				     **");
		printf("\n ** <10> to search for a particular value in the list      **");
		printf("\n ** <11> to display the list				     **");
		printf("\n ** <12> to end operation				     **");
		printf("\n ** <13> to exit without freeing the memory		     **");
		printf("\n ** <14> to find maximum and minimum element from the linked list **");
		printf("\n ************************************************************");
		printf("\n ************************************************************");
		printf("\n enter choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\n Enter the number of node: ");
				scanf("%d",&n);
				for(i=0;i<n;i++)
					{
						printf("\n value= ");
						scanf("%d",&data);
						append(data);
					}
				break;
			case 2:	printf("\n Enter the data: ");
				scanf("%d",&data);
				add_begin(data);
				break;
			case 3:	printf("\n enter the position after which to insert a node: ");
				scanf("%d",&pos);
				printf("\n Enter data: ");
				scanf("%d",&data);
				add_after_node(pos,data);
				break;
		/*	case 4:	printf("\n enter the value after which to insert a node: ");
				scanf("%d",&value);
				printf("\n Enter data: ");
				scanf("%d",&data);
				add_after_value(value,data);
				break;			*/
			case 5:	del_begin();
				break;
			case 6: printf("\n enter the position of the node to delete: ");
				scanf("%d",&pos);
				del_node(pos);
				break;
			case 7:	printf("\n enter the value to delete: ");
				scanf("%d",&data);
				del_value(data);
				break;
			case 8:	del_last();
				break;
			case 9:	reverse();
				break;
			case 10: printf("\n enter the value to search: ");
				 scanf("%d",&data);
				 search(data);
				 break;
			case 11: display();
				 break;
			case 12: end();
				 break;
			case 13: exit(0);
			case 14: max_min();
				 break;
			default: printf("\n invalid choice !!!");
				 printf("\n ");
		}
	}
	
	return 0;
}
void append(int data)
{
	struct node *temp, *q;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=data;
	temp->link=NULL;
		if(start==NULL)
			start=temp;
		else
		{
			q=start;
				while(q->link!=NULL)
				q=q->link;
			q->link=temp;
		}
}
void add_begin(int data)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=data;
	temp->link=start;
	start=temp;
}
void add_after_node(int pos, int data)
{
	struct node *temp, *q;
	q=start;
	int i;
	for(i=0;i<pos-1;i++)
	{
		q=q->link;
		if(q==NULL)
			{printf("\n position does not exist");}
	
	}
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=data;
	temp->link=q->link;
	q->link=temp;
}
void del_begin()
{
	struct node *temp;
	temp=start;
	start=start->link;
	free(temp);
}
void del_node(int pos)
{
	struct node *temp,*q;
	q=start;
	while((pos-1)>1 && (q!=NULL))
	{
		q=q->link;
		pos=pos-1;
	}	
	if(q==NULL)
		{printf("\n position does not exist in the linked list");}
	else
	{
		temp=q->link;
		q->link=temp->link;
		free(temp);
	}
}
void del_value(int data)
{
	struct node *q, *temp;
	if(start->info==data)
		{
			del_begin();
		}
	q=start;
	while((q->link!=NULL)&&(q->link->info!=data))
		q=q->link;
	if(q->link!=NULL)
	{
		temp=q->link;
		q->link=temp->link;
		free(temp);
	}
	else
		printf("\n value is not found in the list");
	
}
void del_last()
{
	struct node *temp, *q;
	q=start;
	while(q->link->link!=NULL)
	{
		q=q->link;
	}
	temp=q->link;
	q->link=NULL;
	free(temp);
}
void reverse()
{
	struct node *q, *prev=NULL, *sprev=NULL;
	q=start;
	while(q!=NULL)
	{
		sprev=prev;
		prev=q;
		q=q->link;
		prev->link=sprev;
	}
	start->link=NULL;	
	start=prev;
	
}
void end()
{
	while(start!=NULL)
		del_begin();
}
void search(int data)
{
	struct node *q;
	q=start;
	int count=0;
	int flag=0;
	while(q!=NULL)
	{
		count++;
		if(q->info==data)
			{
			printf("\n data %d is found in the position %d",data,count);
			flag=1;
			}
		q=q->link;
	}
	if(flag==0)
		printf("\n data not found");
}
void display()
{
	struct node *q;
	int count=0;
	q=start;
	if(start==NULL)
		printf("\n nothing to display in the list");
	else
	{
		while(q!=NULL)
		{
			printf("\n data%d= %d",++count,q->info);
			q=q->link;
		}	
	}
}
void max_min()
{
	int max,min;
	struct node *q;
	max=start->info;
	min=start->info;
	q=start;
	while(q!=NULL)
		{
			q=q->link;
			if(q->info > max)
				max=q->info;
		}
	q=start;
	while(q!=NULL)
		{
			q=q->link;
			if(q->info < min)
				min=q->info;
		}
	printf("\n maximum= %d \n minimum= %d",max,min);
}

