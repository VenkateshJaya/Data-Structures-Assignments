#include<stdio.h>
#include<stdlib.h>

int min(int a , int b){
	return a<=b?a:b;
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	int ans =0;
	for(int i=0; i < n ; ++i){
		scanf("%d",&a[i]);
	}
	for (int i = 0; i < n; ++i){
		int mini = a[i];
		for(int j=i ; j < n ; ++j){
			mini = min(mini,a[j]);
			ans+=mini;
		}
	}
	printf("%d\n",ans );
}
