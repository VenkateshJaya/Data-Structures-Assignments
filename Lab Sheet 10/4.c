#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int n;

int isheap(int arr[], int p){
    if( (n%2==0 && p>(n-2)/2) || (n%2==1 && p>(n-1)/2) ) return 1;
    if(arr[p] > arr[2*p+1] || arr[p] > arr[2*p+2]) return 0;
    if(isheap(arr, 2*p+1)) return 0;
    if(isheap(arr, 2*p+2)) return 0;

    return 1;
}

int main(){
    scanf("%d", &n);
    int arr[n]; for(int i=0; i<n; i++) scanf("%d", arr+i); 

    int ans = isheap(arr, 0);

    printf("\nAns: %d\n", ans);

    return 0;
}