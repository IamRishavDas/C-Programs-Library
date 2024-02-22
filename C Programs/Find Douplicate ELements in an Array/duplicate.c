//time complexity is order of O(n^2)
#include<stdio.h>
int main()
{
    int array[10],n,i;
    printf("\n enter the number of elements: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n enter data-%d: ",i+1);
        scanf("%d",&array[i]);
    }

    int j;
    int flag=0;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(array[i]==array[j])
            {
                printf("\n there is a duplicate element in the array");
                printf("\n the element is: %d \n",array[i]);
                flag=1;
            }
        }
    }
    if(flag==0)
        printf("\n no duplicate element");

    return 0;

}