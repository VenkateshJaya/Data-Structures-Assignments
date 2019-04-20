#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n,k; scanf("%d %d", &n, &k);
    int arr[n]; for(int i=0; i<n; i++) scanf("%d", arr+i);
    int ans = 0;

    while(k--){
        int maxi = 0;
        int max = 0;
        for(int i=0; i<n; i++){
            if(arr[i] > max){
                maxi = i;
                max = arr[i];
            }
        }
        ans += max;
        arr[maxi] = max/2;
    }

    printf("\nAns: %d\n", ans);

    return 0;
}