#include<stdio.h>
#include<math.h>
#include<limits.h>

int main()
{
	int n,k,v;
	scanf("%d%d",&n,&k);
	
	for(v=0;v<INT_MAX;v++)
	{
		int sum = 0;
		int div = v;
		while(div!=0)
		{
			sum+=div;
			if(sum>=n)
			{
				printf("%d",v);
				return;
			}
			div/=k;
		}
	}
}
