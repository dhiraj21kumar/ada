#include<stdio.h>
#include<sys/time.h>
#include<time.h>
#include<sys/resource.h>
int n,a[50];
main()
{
         struct timeval  tv1, tv2;
         struct rusage r_usage;
          int i;
          printf("\n\t\t\t MERGE SORT \n");
	printf("\n Enter the size of the array:");
	scanf("%d",&n);
	printf("\n Enter the array elements \n");
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
              gettimeofday(&tv1, NULL);
          	divide(1,n);
             gettimeofday(&tv2, NULL);
         printf("Time of merge sort=%f microseconds",(double)(tv2.tv_usec-tv1.tv_usec));//in microseconds
          //printf ("Time = %f seconds\n", (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +  (double) (tv2.tv_sec - tv1.tv_sec));
        	printf("\n Sorted elements of the array \n");
	for(i=1;i<=n;i++)
		printf("%d\t",a[i]);
         getrusage(RUSAGE_SELF,&r_usage);
         printf("Memory usage: %ld kilobytes\n",r_usage.ru_maxrss);
}

divide(int low,int high)
{
	int mid;
	if(low < high)
	{
		mid=(low+high)/2;
		divide(low,mid);
		divide(mid+1,high);
		mergesort(low,mid,high);
	}
}

mergesort(int low,int mid,int high)
{
	int i,h,j,k,b[50];
	i=h=low;
	j=mid+1;
	while(h<=mid && j<= high)
	{
		if(a[h]<=a[j])
		{
			b[i]=a[h];
			h=h+1;
		}
		else
		{
			b[i]=a[j];
			j=j+1;
		}
		i=i+1;
	}
	if(h>mid)
		for(k=j;k<=high;k++)
		{
			b[i]=a[k];
			i=i+1;
		}
	else
		for(k=h;k<=mid;k++)
		{
			b[i]=a[k];
			i=i+1;
		}
	for(k=low;k<=high;k++)	a[k]=b[k];
}
