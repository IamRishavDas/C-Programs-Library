//n queens problem
#include<stdio.h>
#include<math.h>
int x[10],count;
void queen(int, int);
int place(int, int);
void print(int);
int main()
{
	int n;
	printf("\n enter the number of queens: ");
	scanf("%d",&n);
	queen(1,n);
	return 0;
}
void queen(int row, int n)
{
	int col;
	for(col=1;col<=n;col++)
	{
		if(place(row,col))
		{
			x[row]=col;
			if(row==n)
				print(n);
			else
				queen(row+1,n);
		}
	}
}
int place(int row, int col)
{
	int i;
	for(i=1;i<row;i++)
	{
		if((x[i]==col)||(abs(i-row)==abs(x[i]-col)))
			return 0;
	}
	return 1;
}
void print(int n)
{
	int i,j;
	printf("\n\n the solution -- %d: \n",++count);
	for(i=1;i<=n;i++)
		printf("\t %d",i);
	for(i=1;i<=n;i++)
	{
		printf("\n %d",i);
		for(j=1;j<=n;j++)
		{
			if(x[i]==j)
				printf("\t Q");
			else
				printf("\t -");
		}
	}
}
