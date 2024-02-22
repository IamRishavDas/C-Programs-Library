#include<stdio.h>
int main()
{
	int a[10],n,i;
	printf("\n enter the no of elements: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n enter data %d: ",i+1);
		scanf("%d",&a[i]);
	}
	int max, min;
	max=a[0];
	min=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
		if(a[i]<min)
			min=a[i];
	}
	printf("\n maximum= %d \n minimum= %d",max,min);
	return 0;
}
