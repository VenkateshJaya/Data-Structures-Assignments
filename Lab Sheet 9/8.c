#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int desc(const void *a, const void *b){
    return *((int*)b) - *((int*)a);
}

int main(){
    int k,w,n; scanf("%d %d %d", &k,&w,&n);
    int arr[n][2]; 
    for(int i=0; i<n; i++) scanf("%d", arr[i]);
    for(int i=0; i<n; i++) scanf("%d", arr[i]+1);

    qsort(arr, n, sizeof(arr[0]), desc);

    int max = 0;
    for(int j=0; j<k; j++){
        for(int i=0; i<n; i++){
            if(arr[i][1] <= w){
                w += arr[i][0];
                arr[i][1] = INT_MAX ;
                break;
            }
            // printf("%d %d\n", arr[i][0], arr[i][1]);
        }
    }

    printf("Ans: %d\n", w);
    return 0;
}