//find the maximum from each row and colum from a matrix and also the maximum from the whole matrix
#include<stdio.h>
#define max 10
int mat[max][max];
int max_of_each_row(int,int);
int max_of_each_col(int,int);
void print(int[],int);
void maximum_in_mat(int,int);
int main()
{
    int m,n,i,j;
    printf("\n enter the number of row: ");
    scanf("%d",&m);
    printf("\n enter the number of column: ");
    scanf("%d",&n);
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            printf("\n enter data-[%d][%d]: ",i,j);
            scanf("%d",&mat[i][j]);
        }
    printf("\n the matrix is: \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\t %d \t",mat[i][j]);
        }
        printf("\n");
    }

    max_of_each_row(m,n);
    max_of_each_col(m,n);
    maximum_in_mat(m,n);

    return 0;
}

int max_of_each_row(int m, int n)
{
    int maximum=0;
    int result_row[m];
    int i=0,j;
    while(i<m)
    {
        for(j=0;j<n;j++)
        {
            if(mat[i][j]>maximum)
                maximum=mat[i][j];
        }
        result_row[i]=maximum;
        maximum=0;
        i++;
    }
    printf("\n the maximum elements for every row is: ");
    print(result_row,m);
}
int max_of_each_col(int m, int n)
{
    int maximum=0;
    int result_col[n];
    int j=0,i;
    while(j<n)
    {
        for(i=0;i<m;i++)
        {
            if(mat[i][j]>maximum)
                maximum=mat[i][j];
        }
        result_col[j]=maximum;
        maximum=0;
        j++;
    }

    printf("\n the maximum elements form each coloumn is: ");
    print(result_col,n);
}
void maximum_in_mat(int m, int n)
{
    int maximum=0;
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(mat[i][j]>maximum)
                maximum=mat[i][j];
        }
    }
    printf("\n the maximum element form the whole array is: %d",maximum);
}
void print(int array[], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf(" %d ",array[i]);
}
