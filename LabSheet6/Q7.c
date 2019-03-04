#include<stdio.h>
int s,t,k,time,n;
void swap(int *p,int *q)
{
	int temp=*p;
	*p=*q;
	*q=temp;
}
void bubblesort(int a[],int b[])
{
	for(int j=0;j<n-1;j++)
		for(int i=0;i<n-i-1;i++)
			if(a[i]>a[i+1])
			{
				swap(&a[i],&a[i+1]);
				swap(&b[i],&b[i+1]);
			}
}

int maxtime(int dis,int cap)
{
	if(cap>=2*dis)
	{
		time=time+dis;
		return 1;
	}
	else if(cap==dis)
	{
		time=time+2*dis;
		return 1;
	}
	else if(cap<dis)
		return 0;
	else if(dis<cap && cap<2*dis)
	{
		time=time+3*dis - cap;
		return 1;
	}
}

int possible(int c[],int cap)
{
	int p=maxtime(c[0],cap);
	if(p==0)
		return 0;
	for(int i=1;i<k;i++)
	{
		p=maxtime(c[i]-c[i-1],cap);
		if(p==0)
			return 0;
	}
	p=maxtime(s-c[k-1],cap);
	if(p==0)
		return 0;
	if(time<=t)
		return 1;
	else
		return 0;
}

int main()
{
	scanf("%d%d%d%d",&n,&k,&s,&t);
	int a[n],b[n],c[k];
	for(int i=0;i<n;i++)
		scanf("%d%d",&a[i],&b[i]);
	for(int i=0;i<k;i++)
		scanf("%d",&c[i]);
	bubblesort(a,b);
	for(int i=0;i<n;i++)
	{
		time=0;
		if(possible(c,b[i]))
		{
			printf("%d\n",a[i]);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
