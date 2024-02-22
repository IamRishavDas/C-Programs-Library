#include<stdio.h>
#include<stdlib.h>
#define max 10
int isearch(int array[],int,int,int);
int main()
{
    int search;
    int array[max],n,i;
    printf("\n enter the no of elements you want to insert: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n enter data-%d: ",i+1);
        scanf("%d",&array[i]);
    }
    printf("\n enter the search element: ");
    scanf("%d",&search);
    int index;
    index=isearch(array,0,n-1,search);
    if(index==-1)
        printf("\n search unsuccessfull!!!");
    else
        printf("\n search successfull!!! \n element found in the position %d",index+1);
    return 0;
}
int isearch(int array[], int low, int high, int search)
{
    int pos;
    if(low<=high && search>=array[low] && search<=array[high])
    {
        //probing the positon 
        //with keeping uniform distribution in mind
        pos=low+(((double)(high-low)/(array[high]-array[low]))*(search-array[low]));
        //condition for target found
        if(array[pos]==search)
            return pos;
        else if(array[pos]>search)
             isearch(array,low,pos-1,search);
        else
             isearch(array,pos+1,high,search);
    }
    else
        return -1;
}
