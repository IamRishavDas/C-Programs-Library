#include<stdio.h>
#include<stdlib.h>
#define max 10
void quicksort(int arr[],int l,int u)
{
    int p;
    if(l<u)
    {
        p=partition(arr,l,u);
        quicksort(arr,l,p-1);
        quicksort(arr,p+1,u);
    }
}
void partition(int arr[],int l, int u)
{
    int j;
    int pivot=arr[u];
    int i=l-u;
    for(j=l;j<u;j++)
    {
        if(arr[j]<pivot)
        {
            i=i+1;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[u]);
    return (i+1);
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int arr[max],n,i;
    printf("\n enter the number of elements to enter in the array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n element-%d: ",i+1);
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);

    printf("\n after sorting the array-----");
    for(i=0;i<n;i++)
    {
        printf("element-%d: %d",i+1,arr[i]);
    }
    return 0;
}
