#include<bits/stdc++.h>
using namespace std;
#define N 100001
int c=0,min1,max1,lef,righ;
int checkl(int a[],int l,int r);
int checkr(int a[],int l,int r);
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
int checkr(int a[],int l,int r)
{
    if(2*a[l]>=a[r])
    {
        lef = l,righ = r;
        min1=a[l],max1=a[r];
        return c;
    }
    else
    {
        c++;
        checkl(a,l+1,r);
    }
    return c;
}
int checkl(int a[],int l,int r)
{
    if(2*a[l]>=a[r])
    {
        lef = l,righ = r;
        min1=a[l],max1=a[r];
        return c;
    }
    else
    {
        c++;
        checkr(a,l,r-1);
    }
    return c;
}
int main()
{
    int n,a[N];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    bubbleSort(n,a);
    int v,b;
    if(2*a[0] >= a[n-1])
    {
        for(int i=1;i<n-1;i++)
            if(a[i] == a[0] || a[i] == a[n-1])
                c++;
        cout<<c;
        return 0;
    }
    else
    {
        c++;
        checkl(a,1,n-1);
        v=c;
        for(int i=lef+1;i<righ;i++)
            if(a[i] == max1 || a[i] == min1)
                v++;
        c=1;
        checkr(a,0,n-2);
        b=c;
        for(int i=lef+1;i<righ;i++)
            if(a[i] == max1 || a[i] == min1)
                b++;
    }
    cout<<min(v,b);
}