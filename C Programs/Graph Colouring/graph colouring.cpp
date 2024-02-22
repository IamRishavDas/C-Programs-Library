//graph colouring problem
#include<stdio.h>
#define max 10
int graph[max][max];
int x[max];
int m,n;
int count;
void m_colouring(int);
void next_value(int);
int main()
{
	int e,i,j,u,v,k=1;
	printf("\n enter the number of vertices: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			graph[i][j]=0;
		}
	}
	printf("\n enter the number of edges: ");
	scanf("%d",&e);
	printf("\n enter source and destination \n");
	for(i=1;i<=e;i++)
	{
		scanf("%d %d",&u,&v);
		graph[u][v]=graph[v][u]=1;
	}
	printf("\n enter the number of colours: ");
	scanf("%d",&m);
	m_colouring(1);
	printf("\n total number of solutions are: %d",count);
	return 0;
}
void m_colouring(int k)
{
	int i;
	while(1)
	{
		next_value(k);
		if(x[k]==0)
			return;
		if(k==n)
		{
			printf("\n");
			for(i=1;i<=k;i++)
			{
				printf(" %d ",x[i]);
			}
			count++;
		}
		else
			m_colouring(k+1);
	}
}
void next_value(int k)
{
	int j;
	while(1)
	{
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0)
			return;
		for(j=1;j<=n;j++)
		{
			if((graph[j][k]!=0)&&(x[k]==x[j]))
				break;
		}
		if(j==n+1)
			return;
	}
}

