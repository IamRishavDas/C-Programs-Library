//incomplete***

#include<stdio.h>
int countingsort(int array[],int n,int place)
{
    int output[n+1];
    int max=(array[0]/place)%10;
    int i;
    for(i=0;i<n;i++)
    {
        if(((array[i]/place)%10)>max)
            max=array[i];
    }
    int count[max+1];
    for(i=1;i<max;i++)
    {
        count[i]=0;
    }
    //calculate the count of elements
    for(i=0;i<n;i++)
    {
        count[(array[i]/place)%10]++;
    }
    //cumulative count
    for(i=0;i<10;i++)
        count[i]+=count[i-1];
    
    //place the elements in sorted order
    for(i=n-1;i>=0;i--)
    {
        output[count[(array[i]/place)%10]-1]=array[i];
        count[(array[i]/place)%10]--;
    }

    for(i=0;i<n;i++)
        array[i]=output[i];
}
int get_max(int array[],int n)
{
    int max;
    max=array[0];
    int i;
    for(i=0;i<n;i++)
    {
        if(array[i]>max)
            max=array[i];
    }
}
int radixsort(int array[], int n)
{
    int max;
    max=get_max(array,n);
    int place;
    for(place=1;max/place>0;place*=10)
    {
        countingsort(array,n,place);
    }
}
int printarray(int array[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\n data-%d: %d",i+1,array[i]);
    }
}
#define max 10
int main()
{
    int array[max],n,i;
    printf("\n enter the no of elemnets to enter in the array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n enter data-%d: ",i+1);
        scanf("%d",&array[i]);
    }
    radixsort(array,n);
    printarray(array,n);
    return 0;
}