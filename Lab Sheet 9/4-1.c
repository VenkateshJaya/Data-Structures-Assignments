#include<stdio.h>
#include<stdlib.h>

int isp(int num){
    for(int i=2; i<num; i++) if(num%i==0) return 0;
    return 1;
}

int main(){
    int n; scanf("%d", &n);
    int petrol[n]; 
    int dist[n];
    for(int i=0; i<n; i++) scanf("%d %d", petrol+i, dist + i);
   for(int i=0; i<n; i++){
        int p = 0;
        p += petrol[i];
        if(p<dist[i]) continue;

        for(int b=i+1; ;b=(b+1)%n){
            if(b==i){
                printf("Ans: %d\n", i);
                return 0;
            }
            p += petrol[b];
            if(p < dist[b]) break;
        }
    }
    return 0;
}