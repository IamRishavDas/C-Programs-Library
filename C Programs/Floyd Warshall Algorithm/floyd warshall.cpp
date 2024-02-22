//floyd warshall algorithm
#include<stdio.h>
#define max 10
#define inf 9999
int a[max][max];
void floyd(int);
int main()
{
	int n,i,j,e,u,v,w;
	printf("\n enter the number of vertices: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j)
				a[i][j]=0;
			else
				a[i][j]=inf;
		}
	}
	printf("\n enter the number of edges: ");
	scanf("%d",&e);
	printf("\n enter the source destnation vertiex and the weight of the edge \n");
	for(i=1;i<=e;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		a[u][v]=w;
	}
	floyd(n);
	return 0;
}
void floyd(int n)
{
	int k,i,j;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[i][k]+a[k][j]<a[i][j])
					a[i][j]=a[i][k]+a[k][j];
			}
		}
	}
	printf("\n the solution matrix is: \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf(" %d ",a[i][j]);
		}
		printf("\n");
	}
}
