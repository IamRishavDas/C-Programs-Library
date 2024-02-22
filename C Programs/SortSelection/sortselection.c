#include<stdio.h>
#include<stdlib.h>
#define n 4
int array[n];
void printarray()
{
    int i;
    for(i=0;i<n;i++)
        printf("\n data-%d: %d",i+1,array[i]);
}
void bubblesort()
{
    int i,j;
    int temp;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
        {
            if(array[j]>array[j+1])
            {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    printarray();
}
void selectionsort()
{
    int i,j;
    int temp;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
        {
            if(array[i]>array[j])
            {
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    printarray();
}
void insertionsort()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        j=i;
        while(array[j-1]>array[j] && j>0)
        {
            int temp=array[j-1];
            array[j-1]=array[j];
            array[j]=temp;
            j--;
        }
    }
    printarray();
}
void enterarray()
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\n enter data-%d: ",i+1);
        scanf("%d",&array[i]);
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("\n press 1 for insert in arary");
        printf("\n press 2 for bubble sort");
        printf("\n press 3 for selection sort");
        printf("\n press 4 for insertion sort");
        printf("\n press 5 for exit");
        printf("\n enter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: enterarray();
                    break;
            case 2: bubblesort();
                    break;
            case 3: selectionsort();
                    break;
            case 4: insertionsort();
                    break;
            case 5: exit(0);
            default:    printf("\n wrong choice!!!");
        }
    }
    return 0;
}