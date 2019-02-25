#include<stdio.h>

void swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int i,n,s;
	printf("enter n and budget : ");
	scanf("%d%d",&n,&s);
	int arr[n+1];
	
	for(i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	
	for(i=1;i<n;i++)
	{
		int j;
		for(j=i+1;j<=n;j++)
			if(arr[j]<arr[i])
				swap(&arr[i],&arr[j]);
		
	}
	
	int min = 0,k = 1,count=0;
	
	for(k=0;k<=n;k++)
	{
		int sum = 0;
		for(i=1;i<=k;i++) 
			sum+=arr[i]+k*i;
		if(sum>=min&&sum<=s)
		{
			min = sum;
			count = k;
		}		
	}
	printf("%d %d",count,min);
}
