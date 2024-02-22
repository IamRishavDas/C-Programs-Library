//duplicate elemnts in an array
//the minimum time complexity can be reduced to O(nlogn)
#include<stdio.h>
#define max 10
void array_sort(int [],int);
int duplicate(int [],int);
int main()
{
    int array[max],n,i;
    printf("\n enter the number of elements: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n enter data-%d: ",i+1);
        scanf("%d",&array[i]);
    }

    array_sort(array,n);
    duplicate(array,n);

    return 0;
    
}
void array_sort(int array[],int n)
{
    int i,j;
    int temp;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
        {
            if(array[i]<array[j])
            {
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
}
//time complexity is O(n)
int duplicate(int array[], int n)
{
    int i;
    int flag=0;
    for(i=0;i<n;i++)
    {
        if(array[i]==array[i+1])
            {
                printf("\n there is a duplicate element in the array");
                printf("\n the element is: %d",array[i]);
                flag=1;
            }
    }
    if(flag==0)
        printf("\n no duplicate element in the array");
}