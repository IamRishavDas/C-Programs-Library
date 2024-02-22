//matrix chain multiplication problem
//dynamic programming
#include<stdio.h>
#define max 10
#define inf 9999
int m[max][max],s[max][max];
void matrix_chain(int [], int );
void optimal_paren(int, int);
int main()
{
	int p[max];
	int n,i;
	printf("\n enter the number of arrays: ");
	scanf("%d",&n);
	printf("\n enter the dimensional array: \n");
	for(i=0;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	matrix_chain(p,n);
	printf("\n the minimum number of scalor multiplication required is: %d",m[1][n]);
	printf("\n the optimal parenthasis: \n");
	optimal_paren(1,n);
	
	return 0;
}
void matrix_chain(int p[], int n)
{
	int i,j,k,q,l;
	for(i=1;i<=n;i++)
		m[i][i]=0;
	for(l=2;l<=n;l++)
	{
		for(i=1;i<=n-l+1;i++)
		{
			j=i+l-1;
			m[i][j]=inf;
			for(k=i;k<j;k++)
			{
				q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
}
void optimal_paren(int i, int j)
{
	if(i==j)
		printf("A%d",i);
	else
	{
		printf("(");
		optimal_paren(i,s[i][j]);
		optimal_paren(s[i][j]+1,j);
		printf(")");
	}
}

