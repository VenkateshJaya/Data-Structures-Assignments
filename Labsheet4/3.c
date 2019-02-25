#include<stdio.h>

int main()
{
	int arr[100];
	int i = 0;
	int x;
	while(scanf("%d",&x)==1)
		arr[i++] = x;
	
	int n = i;
	for(i=0;i<n;i+=2)
		if(arr[i]!=arr[i+1])
		{
			printf("%d",arr[i]);
			return;
		}					
}
