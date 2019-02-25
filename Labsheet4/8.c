#include<stdio.h>

int binSearch(int arr[],int key,int beg,int last)
{
	while(beg<=last)
	{
		int mid = (beg+last)/2;
		
		if(arr[mid]==key)
			return mid+1;
		
		else if(arr[beg]<arr[mid])		
		{
			if(key>=arr[beg]&&key<=arr[mid-1])		
			{
				last = mid-1;
				binSearch(arr,key,beg,last);
			}
			else		
			{
				beg = mid+1;
				binSearch(arr,key,beg,last);
			}
		}
		else
		{
			if(key>=arr[mid+1]&&key<=arr[last])		
			{
				beg = mid+1;
				binSearch(arr,key,beg,last);
			}
			else		
			{
				last = mid-1;
				binSearch(arr,key,beg,last);
			}
		}
	}
	return -1;
}

int main()
{
	int i,n,key;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	scanf("%d",&key);
	
	printf("%d",binSearch(arr,key,0,n-1));
}
