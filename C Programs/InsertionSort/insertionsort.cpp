#include<stdio.h>
int main()
{
	int a[10],n,i;
	int key,j;
	printf("\n enter the no of element: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n enter data-%d: ",i+1);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		j=i;
		while(a[j-1]>a[j] && j>0)
		{
			temp=a[j-1];
			a[j-1]=a[j];
			a[j]=temp;
			j--;
		}
	}
	
	for(i=0;i<n;i++)
		printf("\n data-%d: %d",i+1,a[i]);
	return 0;
}
