//modified prims algorithm
#include<stdio.h>
#define max 10
#define inf 9999
int graph[max][max];
int vi[max]={0};
int main()
{
	int m,n,i,j,u,v,w,e,c=0,k=1,min;
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
	printf("\n enter the source vertex destination vertex and weight: \n");
	for(i=1;i<=e;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		graph[u][v]=graph[v][u]=w;	
	}
	vi[1]=1;
	while(k<n)
	{
		
		for(i=1;i<=n;i++)
		{
			min=inf;
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
	
	return 0;	
}
