#include<stdio.h>
//#include<conio.h>
#define max 50
int binary_search(int[],int, int,int);
int main()
{
	int a[max],i,n,found,element;
	printf("\nEnter the number of elements");
	scanf("%d",&n);
	printf("\nEnter the elements in ascending order");
	for(i=0;i<n;i++)
	{
		printf("\na[%d]",i);
		scanf("%d",&a[i]);
	}

	printf("\nEnter the elements to be searched");
	scanf("%d",&element);
	found = binary_search(a,0,n-1,element);
	if(found == (-1))
		printf("\nThe element is not found\n");
	else
		printf("\nThe element found at pos %d\n", found+1);
return 0;
}


int binary_search(int a[], int low, int high, int key)
{
	int mid;
	if(low>high)
		return -1;
	mid = (low+high)/2;
	if(a[mid] == key)
		return mid;
	else
		if(key> a[mid])
			binary_search(a,mid+1,high, key);
		else
			binary_search(a,low,mid-1,key);

}
