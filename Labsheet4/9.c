#include<stdio.h>

void binSearch(int arr[],int key,int beg,int last)
{
	while(beg<=last)
	{
		int mid = (beg+last)/2;
		
		if(arr[mid]==key)
		{
			printf("Naruto %d",mid+1);
			exit(1);
		}
		if(key<arr[mid])
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
	printf("Sasuke %d",beg+1);
	exit(1);
}

int main()
{
	int i,n,key;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
		
	scanf("%d",&key);	
	
	binSearch(arr,key,0,n-1);	
}
