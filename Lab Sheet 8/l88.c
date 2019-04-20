#include<stdio.h>
#include<stdlib.h>

int m[50][50];

int check(int i , int j , int a , int b){
	int ones = 0;
	for(int r = i ; r<=a ; ++r){
		for(int c = j ; c <=b ; ++c ){
			if(m[r][c]==1)ones++;
		}
	}

	if(ones==1){
		printf("%d %d %d %d\n",i,j,a,b );
		return 1;
	}
	return 0;
}

int main(){

	int n;
	scanf("%d",&n);
	
	for(int i=0; i < n ; ++i){
		for(int j = 0 ; j < n ; ++j){
			scanf("%d",&m[i][j]);
		}
	}

	int ans = 0;
	for(int i=0 ; i < n ; ++i){
		for(int j=0 ; j < n ; ++j){
			for(int a= i; a<n ; ++a){
				for(int b =j ; b<n ; ++b){
					ans+= check(i,j,a,b);
				}
			}
		}

	}
	printf("%d\n", ans);
}