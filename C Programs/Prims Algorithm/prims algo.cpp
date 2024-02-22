//prims algorithm
#include<stdio.h>
#define max 10
#define inf 9999
int graph[max][max];
int vi[max]={0};
void prims_algo(int);
int main()
{
	int n,e,i,j,u,v,w;
	printf("\n enter the number of vertices: ");
	scanf("%d",&n);
	printf("\n enter the number of edges: ");
	scanf("%d",&e);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			graph[i][j]=inf;	
		}	
	}	
	printf("\n enter the source vertex destination vertex and the weight of the edge: \n");
	for(i=1;i<=e;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		graph[u][v]=graph[v][u]=w;
	}
	printf("\n the minimum distances are: \n");
	prims_algo(n);
	return 0;
}
void prims_algo(int n)
{
	int k=1;
	int c=0;
	int min,i,j,u,v;
	vi[1]=1;
	while(k<n)
	{
		min=inf;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(graph[i][j]<inf && vi[i]==1)
				{
					u=i;
					v=j;
					min=graph[i][j];
				}
			}
		}
		if(vi[v]==0)
		{
			printf("\n %d	:	%d		:	%d",u,v,graph[u][v]);
			vi[v]=1;
			c=c+min;
		}
		graph[u][v]=graph[v][u]=inf;
		k++;
	}
	printf("\n the minimal spanning cost is: %d",c);
}
