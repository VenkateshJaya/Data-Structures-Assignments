#include<stdio.h>
#include<stdlib.h>
int minheapsize = 0;
int maxheapsize = 0;
int minheap[1<<20] = {};
int maxheap[1<<20] = {};

void swap(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


void maxheapifyutil(int a[],int i ,int n){
	int max_idx = i;
	if(2*i<=n && a[i]<a[2*i]) max_idx = 2*i;
	if(2*i+1<=n && a[2*i+1]> a[max_idx])max_idx = 2*i+1;
	if(max_idx!=i){
		swap(&a[i],&a[max_idx]);
		maxheapifyutil(a,max_idx,n);
	}
}

void maxheapify(int a[],int n){
	for(int i=n/2 ; i>=1 ; --i){
		maxheapifyutil(a,i,n);
	}
}

void minheapifyutil(int a[],int i ,int n){
	int min_idx = i;
	if(2*i<=n && a[i]>a[2*i]) min_idx = 2*i;
	if(2*i+1<=n && a[2*i+1] < a[min_idx])min_idx = 2*i+1;
	if(min_idx!=i){
		swap(&a[i],&a[min_idx]);
		minheapifyutil(a,min_idx,n);
	}
}

void minheapify(int a[],int n){
	for(int i=n/2 ; i>=1 ; --i){
		minheapifyutil(a,i,n);
	}
}

void insertminheap(int num){
	minheap[++minheapsize] = num;
	minheapify(minheap,minheapsize); 
}

void insertmaxheap(int num){
	maxheap[++maxheapsize] = num;
	maxheapify(maxheap,maxheapsize); 
}

float findnextmedian(int a[],int i , int m){
	int e = a[i];
	float median = -1;
	if(maxheapsize==minheapsize){
		if(e <= m ){ insertmaxheap(e);median = maxheap[1];}
		else {insertminheap(e);median = minheap[1];}
	}
	else if(maxheapsize> minheapsize){
		if(e>=m) insertminheap(e);
		else{
			insertminheap(maxheap[1]);
			maxheap[1] = e;
			maxheapify(maxheap,maxheapsize);
		}
		median = (minheap[1] + maxheap[1])/2.0;
	}
	else{
		if(e<=m) insertmaxheap(e);
		else{
			insertmaxheap(minheap[1]);
			minheap[1] = e;
			minheapify(minheap,minheapsize);
		}
		median = (minheap[1] + maxheap[1])/2.0;
	}
	return median;
}


int main(){
	int n;
	scanf("%d" , &n);
	int a[n+1];
	for (int i = 1; i <= n; ++i){
		scanf("%d",&a[i]);
	}
	float median=0;

	for(int i=1 ; i <= n ; ++i){
		median = findnextmedian(a,i,median);
		printf("%0.1f ", median);
	}
	printf("\n");
}