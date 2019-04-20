#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int n;

int main(){
    scanf("%d", &n);
    int arr[n]; for(int i=0; i<n; i++) scanf("%d", arr+i); 
    int ones = 0;
    int zeros = 0;
    int ans = 0;
    for(int l=1; l<=n; l++){
        for(int i=0; i<=n-l; i++){
            ones = zeros = 0;
            for(int j=i; j<i+l; j++){
                if(arr[j]==0) zeros++;
                if(arr[j]==1) ones++;
            }
            if(ones==zeros) ans++;
        }
    }

    printf("\nAns: %d\n", ans);

    return 0;
}