#include<stdio.h>
int main()
{
	int a[10],b[10],c[20],i,j,k,m,n;
	printf("\n enter the no of elements to enter in the first array: ");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		printf("\n enter data-%d: ",i+1);
		scanf("%d",&a[i]);
	}
	printf("\n enter the no of elements to enter in the second array: ");
	scanf("%d",&n);
	for(j=0;j<n;j++)
	{
		printf("\n enter data-%d: ",j+1);
		scanf("%d",&b[j]);
	}
	i=0;
	j=0;
	k=0;
	while((i<m) && (j<n))
	{
		if(a[i]<b[j])
		{
			c[k]=a[i++];
			k++;
		}
		else
			{
				c[k]=b[j++];
				k++;
			}
	}
	while(i<m)
	{
		c[k]=a[i++];
		k++;
	}
	while(j<n)
	{
		c[k]=b[j++];
		k++;
	}
	printf("\n the merged array is: ");
	for(k=0;k<m+n;k++)
		printf("\n data-%d: %d",k+1,c[k]);
	
}
