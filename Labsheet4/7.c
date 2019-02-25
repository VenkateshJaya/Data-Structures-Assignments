#include<stdio.h>

int arr[100000];
int a,b;

void bubblesort(int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j+1]<arr[j])
			{
				a = j;
				b = j+1;
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
				return;
			}
		}
}

int binSearch(int k,int beg,int last)
{
	while(beg<=last)
	{
		int mid = (beg+last)/2;
		if(arr[mid]==k)
		{
			if(mid==a)
				return b+1;
			else if(mid==b)
				return a+1;
			else
				return mid+1;		
		}
		else if(k<arr[mid])
		{
			last = mid-1;
			binSearch(k,beg,last);
		}
		else
		{
			beg = mid+1;
			binSearch(k,beg,last);
		}
	}
	return -1;
}

int main()
{
	int i,n,k;
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	scanf("%d",&k);
	
	bubblesort(n);
	
	printf("%d",binSearch(k,0,n-1));
}
