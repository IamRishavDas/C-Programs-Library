//linear search
#include<stdio.h>
int main()
{
	int a[10],n,i;
	int flag=0;
	int data;
	printf("\n enter the no of elements: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n enter data-%d: ",i+1);
		scanf("%d",&a[i]);
	}
	printf("\n enter the data you want to search from the list: ");
	scanf("%d",&data);
	for(i=0;i<n;i++)
	{
		if(a[i]==data)
		{
		flag=1;
		printf("\n the data %d is found in the list in %d positon",data,i+1);
		}
	}
	if(flag==0)
		printf("\n data is not in the list");
}
