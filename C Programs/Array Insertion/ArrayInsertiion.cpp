#include<stdio.h>
#define max 10
int main()
{
	int a[max],n,i;
	int pos,data;
	printf("\n enter the no of elements to enter in the array: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n enter data %d: ",i+1);
		scanf("%d",&a[i]);
	}
	printf("\n enter the position to enter in the array: ");
	scanf("%d",&pos);
	pos=pos-1;
	printf("\n enter the data to enter: ");
	scanf("%d",&data);
	for(i=n;i>=pos;i--)
		a[i+1]=a[i];
	a[pos]=data;
	printf("\n the updated array is: ");
	for(i=0;i<n+1;i++)
	{
		printf("\n data %d: %d",i+1,a[i]);
	}
	return 0;
}
