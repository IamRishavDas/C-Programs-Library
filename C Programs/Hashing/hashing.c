//hashing with linear probing
#include<stdio.h>
#include<stdlib.h>
#define max 10

struct record
{
	int key;
	int data;
	struct record *next;
}*hash=NULL;

int array[max];
int hash_function(int,int);
int insert(int,int);
void traverse();
void key_search(int,int);
void traverse_hash_map();
void del_array(int,int);
void del_record(int);
void collision(int,int);
void hash_table_update(int,int);


int main()
{
	int choice;
	int key_index;
	int data,value;
	int n,search,no_keys,i;
	
	printf("\n enter the value of n (considering the hash function 'key mod n' and the array size predefined max is 10): ");
	scanf("%d",&n);
	while(1)
	{
		printf("\n press 1 for insert an item in hash table");
		printf("\n press 2 for display the list");
		printf("\n press 3 for seacrh an data");
		printf("\n press 4 for traverse the hash map");
		printf("\n press 5 for delete any value from the list");
		printf("\n enter choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	printf("\n enter the no of keys: ");
					scanf("%d",&no_keys);
					for(i=0;i<no_keys;i++)
					{
						printf("\n enter data: ");
						scanf("%d",&data);
						key_index=hash_function(data,n);
						insert(key_index,data);
					}
					break;
			case 2:	traverse();
					break;
			case 3:	printf("\n enter the search element: ");
					scanf("%d",&search);
					key_search(search,n);
					break;
			case 4: traverse_hash_map();
					break;
			case 5:	printf("\n enter the value you want to delete: ");
					scanf("%d",&value);
					del_array(value,n);
					break;

			default:	printf("\n wrong choice!!!");
		}
	}
}

int hash_function(int data,int n)
{
	return (data%n);
}
int insert(int key_index, int data)
{
	if(array[key_index]!=0)
		{
			//for data collision
			collision(key_index,data);
		}
	//key insertion
	else
		{
			array[key_index]=data;
			hash_table_update(key_index,data);
		}

}
//collision resolving using linear probing
void collision(int key_index, int data)
{
	key_index++;
	if(array[key_index]==0)	
		array[key_index]=data;
	else
		collision(key_index,data);
	//update hash table
	hash_table_update(key_index,data);
}
void hash_table_update(int key_index,int data)
{
	//updating hash table
	struct record *temp;
	temp=(struct record*)malloc(sizeof(struct record));
	temp->data=data;
	temp->key=key_index;
	temp->next=NULL;
	if(hash==NULL)
		{
			hash=temp;
		}
	else
	{
		struct record *q;
		q=hash;
		while(q->next!=NULL)
			q=q->next;
		q->next=temp;
	}

}
void traverse()
{
	//traversing the array
	int i;
	for(i=0;i<max;i++)
	{
		if(array[i]!=0)
			printf("\n data-%d: %d",i,array[i]);
	}
	printf("\n");
}
void key_search(int search, int n)
{
	int key;
	int flag=0;
	key=hash_function(search,n);
	if(array[key]==search)
	{
		printf("\n search successfull \n element is in the %d positon",key);
		flag=1;
	}
	else
		printf("\n search unsuccessfull!!!");
	
}
void traverse_hash_map()
{
	//traverse hash map
	struct record *q;
	q=hash;
	if(q==NULL)
		printf("\n the hash table is not yet implemented");
	else
	{
		printf("\n the hash table is---------");
		while(q!=NULL)
		{
			printf("\n key : %d \t key index : %d",q->data,q->key);
			q=q->next;
		}
		printf("\n ");
	}
}
void del_array(int value,int n)
{
	int t=hash_function(value,n);
	if(array[t]==value)
	{
		printf("\n %d has been deleted",array[t]);
		array[t]=0;
		//delete the key record
		del_record(value);
	}
	else
	{
		printf("\n the element is not available in the list");
	}
}
void del_record(int value)
{
	//delete record from hash table
	struct record *temp;
	struct record *q;
	q=hash;
	while(q->next->data!=value)
		q=q->next;
	temp=q->next;
	q->next=temp->next;
	free(temp);	
	
}



