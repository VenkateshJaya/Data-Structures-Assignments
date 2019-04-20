#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define N 100

int arr[N];
int k;
char query[10];

int finddiff(){
    if(k==0) return -1;
    int min = INT_MAX;
    int max = 0;
    int res = 0;
    for(int i=0; i<k; i++){
        if(arr[i]>max) max = arr[i];
        if(arr[i]<min) min = arr[i];
    }
    res = max-min;
    
    for(int i=0; i<k; i++){
        if(arr[i]==max){ 
            for(int j=i; j<k-1; j++) arr[j] = arr[j+1];
            k--;
            break;
        }
    }
    if(max==min) return res;
    for(int i=0; i<k; i++){
        if(arr[i]==min){ 
            for(int j=i; j<k-1; j++) arr[j] = arr[j+1];
            k--;
            break;
        }
    }
    return res;
}
int findhigh(){
    if(k==0) return -1;
    int max = 0, c = 0;
    for(int i=0; i<k; i++) if(arr[i]>max) max = arr[i];
    for(int i=0; i<k; i++) if(arr[i]==max) c++;
    return c;
}
int findlow(){
    if(k==0) return -1;
    int min = INT_MAX, c = 0;
    for(int i=0; i<k; i++) if(arr[i]<min) min = arr[i];
    for(int i=0; i<k; i++) if(arr[i]==min) c++;
    return c;
}

int main(){
    int q; scanf("%d", &q);
    while(q--){
        scanf("%s", query);
        if(strcmp(query, "Push")==0){
            int x; scanf("%d", &x);
            arr[k++] = x;
        }else if(strcmp(query, "Diff")==0) printf("diff: %d\n", finddiff());
        if(strcmp(query, "CountHigh")==0) printf("high: %d\n", findhigh());
        if(strcmp(query, "CountLow")==0) printf("low: %d\n", findlow());
    }

    return 0;
}