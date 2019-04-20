#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void* a , const void*b){
	return *(int*)a - *(int*)b;
}

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int a[n];
	for(int i = 0 ; i < n ; ++i){
		scanf("%d",&a[i]);
	}

	qsort(a,n,sizeof(int),cmpfunc);
	int ans=0;
	int start = 0;
	while(1){
		if(a[start]>=k) break;
		start++;
		a[start] = 2*a[start]+ a[start-1];
		ans++;
		qsort(a+start,n-start,sizeof(int),cmpfunc);
	}	
	printf("%d\n",ans );
}