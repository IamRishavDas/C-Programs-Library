#include<stdio.h>
int main()
{
	int a[10],n,i;
	int temp,j;
	printf("\n enter the no of data: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n enter data-%d: ",i+1);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	printf("\n the sorted array is: ");
	for(i=0;i<n;i++)
		printf("\n data-%d: %d",i+1,a[i]);
	return 0;
}
