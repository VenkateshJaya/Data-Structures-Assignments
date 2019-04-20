#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>

int n,k;

int main(){
    scanf("%d %d", &n, &k);
    char pref[n]; scanf("%s", pref);
    int arr[n]; for(int i=0; i<n; i++) arr[i] = -1;
    int a = 0,b = 0;
    int maxa,maxb;
    for(int i=0; i<k; i++){
        a = b = 0;
        maxa = maxb = -1;
        while(a<n && b<n){
            a = b;
            while(a<n && arr[a]!=-1) a++;
            if(a>=n || arr[a]!=-1){printf("br1"); break;}
            b = a;
            while(b+1<n && arr[b+1]==-1) b++;
            if(b>=n || arr[b]!=-1){printf("br2"); break;}
            if(b-a>maxb-maxa){maxa=a;maxb=b;}
            b++;
        }

        if((maxb-maxa+1)%2==0 && pref[i]=='R') arr[(maxb+maxa+1)/2] = i+1;
        else arr[(maxb+maxa)/2] = i+1;
        printf("\n%d %d\n\n", maxa, maxb);
    }
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    int q; scanf("%d", &q);
    while(q--){
        int pos; scanf("%d", &pos);
        printf("%d\n", arr[pos-1]);
    }
    return 0;
}