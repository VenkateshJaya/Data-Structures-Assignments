#include <bits/stdc++.h>
using namespace std;
#define N 100001
int arr[N][2],n,b[N],visited[N],ans;
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
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i][0]);
        arr[i][1]=i;
        b[i]=arr[i][0];
    }
    bubbleSort(n,b);
    for(int i=0;i<n;i++)
    {
        int k;
        for(int j=0;j<n;j++)
            if(arr[j][0]==b[i])
            {
                k=j;
                if(visited[j] || arr[j][1]==i)
                    continue;
            }
        int j=k;
        int cycle_size=0;
        while(!visited[j])
        {

            visited[j]=1;
            int h= b[arr[j][1]];
            for(int g=0;g<n;g++)
                if(arr[g][0]== h)
                    j=g;
            cycle_size++;
        }
        if(cycle_size > 0)
            ans+=cycle_size-1;
    }
    cout<<ans;
}