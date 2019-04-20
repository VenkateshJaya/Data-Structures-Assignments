#include <stdio.h>
#include <stdlib.h>
int n,m,minCost=123456;
int p[20][20]={{0}},arr[20][20]={{0}};
void calcCost(int s,int d,int k,int cost)
{
	if(k<0&&s==d)
	{
		if(cost<minCost)
		{
			minCost = cost;
		}
	}
	else if(k>=0)
	{
		for (int i = 0; i <n; ++i)
		{
			if(arr[s][i]==1)
			{
				calcCost(i,d,k-1,cost+p[s][i]);	
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d %d",&n,&m);
	for (int i = 0; i < m; ++i)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		arr[x][y] =1;
		p[x][y] = z;
	}
	int t;
	scanf("%d",&t);
	for (int i = 0; i <t; ++i)
	{
		int s,d,k;
		scanf("%d %d %d",&s,&d,&k);
		calcCost(s,d,k,0);
		printf("%d\n",minCost );
		minCost =123456;
	}
	return 0;
}