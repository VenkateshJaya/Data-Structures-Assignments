#include<bits/stdc++.h>
using namespace std;
#define N 100001
void swap(int a[], int x ,int y){
    int t0 = a[x];
    a[x] = a[y];
    a[y] = t0;
}
void bubbleSort(int n, int a[]){
    int f = 1;
    while(f){
        f = 0;
        for(int i=0; i<n-1; i++){
            if(a[i] > a[i+1]){
                f = 1;
                swap(a, i, i+1);
            }
        }
    }
}
int main()
{
    int n,m;
    int ans[N];
    int k[N];
    memset(ans,-1,sizeof(ans));
    scanf("%d %d",&n,&m);
    int a1[N],a2[N];
    for(int i=0;i<n;i++)
        scanf("%d",&a1[i]);
    for(int i=0;i<m;i++)
        scanf("%d",&a2[i]);
    int g=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            if(a1[j] == a2[i])
            {
                ans[g++]=a1[j];
                a1[j]=-1;
            }
    }
    int h=0;
    for(int i=0;i<n;i++)
        if(a1[i] != -1)
            k[h++]=a1[i];
    bubbleSort(h,k);
    for(int i=0;i<g;i++)
        cout<<ans[i]<<" ";
    for(int i=0;i<h;i++)
        cout<<k[i]<<" "; 
}