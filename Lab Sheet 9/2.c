#include <stdio.h>
#include<string.h>
#define N 9999999

int A[N],B[N];

int main(){ 
        int n, m ,ms;
        scanf("%d%d%d", &n, &m, &ms);
        for(int i = 0; i < n; i++){
            scanf("%d",A+i);
        }
        for(int i = 0; i < m; i++){
           scanf("%d",B+i);
        }

        int sum = 0;
        int x = 0, y = 0;

        while (x < n && sum + A[x] <= ms) {
            sum += A[x++];
        }

        int count = x;

        while (y < m && x >= 0) {
            sum += B[y++];
            while (sum > ms && x > 0) {
                sum -= A[--x];
            }

            if (sum <= ms && count < x + y) {
                count = x + y;
            }
        }

        printf("%d\n",count);
    return 0;
}