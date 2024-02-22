//binary search
#include<stdio.h>
#define max 10
int a[max];
int binarysearch(int,int,int);
int main()
{
	int n,i;
	int s,t;
	printf("\n enter the no of elements to enter in the array: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n element-%d: ",i+1);
		scanf("%d",&a[i]);
	}
	printf("\n enter the element which you want to search from the following array: ");
	scanf("%d",&s);
	t=binarysearch(0,n-1,s);
	if(t<0)
		printf("\n search unsuccessful");
	else
		printf("\n the element is in the %d position",t+1);
	return 0;
}
int binarysearch(int low, int high, int search)
{
	int mid;
	if(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==search)
			return mid;
		else if(a[mid]>search)
			binarysearch(0,mid-1,search);
		else
			binarysearch(mid+1,high,search);
	}
	else
		return -1;
}
