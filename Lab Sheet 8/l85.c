#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int cmpfunc(const void *a , const void *b){
	return *(int*)a-*(int*)b;
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	int ans =0;
	for(int i=0; i < n ; ++i){
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(int),cmpfunc);
	int start = 0;
	int sum = 0;
	int exp;
	if(n%2!=0){
		start=1;
		sum+= pow(10,(n-1)/2)*a[0];
		exp = ((n-1)/2) -1;
	}
	else exp = n/2 -1;

	for(int i=start; i < n ; i+=2){
		sum+= pow(10,exp)*(a[i]+a[i+1]);
		exp--;
	}
	printf("%d\n",sum );
	
}
