//fractioanl knapsack
//greedy technique
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int p,w;
	float r,x;
}k[10],t; 
int main()
{
	int n,m,i,j,c=0;
	struct node temp;
	printf("\n enter the number of items: ");
	scanf("%d",&n);
	printf("\n enter the capacity of the knapsack: ");
	scanf("%d",&m);
	for(i=0;i<n;i++)
	{
		printf("\n enter profit and weight for %d product: ",i+1);
		scanf("%d %d",&k[i].p,&k[i].w);
		k[i].x=0;
		k[i].r=(float)k[i].p/k[i].w;
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(k[i].r<k[j].r)
			{
				temp=k[i];
				k[i]=k[j];
				k[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(m>k[i].w)
		{
			k[i].x=1;
			c=c+k[i].p*k[i].x;
			m=m-k[i].w;
			
		}
		else
		{
			k[i].x=(float)m/k[i].w;
			c=c+k[i].p*k[i].x;
			m=0;
			break;
		}
	}
	printf("\n the solution vector is: \n");
	for(i=0;i<n;i++)
	{
		printf("\t %f",k[i].x);
	}
	printf("\n the maximum cost can be obtained is: %d",c);
	return 0;
}
