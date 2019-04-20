#include<stdio.h>
#include<stdlib.h>

int minheapsize =0;
int minheap[1<<20] = {};

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
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



int main(){
    int n;
    scanf("%d",&n);
    int a[n+1];
    for(int i=1 ; i <= n ; ++i){
        scanf("%d",&a[i]);
    }
    int sum=0;
    int diff = 0;

    for(int i=1;i <= n ;++i){
        if(minheapsize!=0 && minheap[1]< a[i]){
            diff = a[i] - minheap[1];
            sum+= diff;
            minheap[1] = a[i];
            minheapify(minheap,minheapsize);
        }
        insertminheap(a[i]);
    }
    printf("%d\n",sum );
}