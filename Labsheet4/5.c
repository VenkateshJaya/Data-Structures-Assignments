#include<stdio.h>
#include<limits.h>

int main()
{
	int i,n,m;
	scanf("%d%d",&n,&m);
	
	int arr[n];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	int count = 0,sum;	
	for(i=0;i<INT_MAX;i++)
	{
		sum = 0;
		count++;
		int j;
		for(j=0;j<n;j++)
			sum+=count/arr[j];
			
		if(sum>=m)
		{
			printf("%d",count);
			return;
		}
	}
}
