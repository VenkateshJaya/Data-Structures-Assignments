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
    int a,b,c,n,m,d=0;
    cin>>a>>b>>c;
    char s[100];
    int p[N],x[N];
    scanf("%d",&n);
    int g,h,ans;
    g=h=ans=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d %s", &m, s);
        if(s[0]== 'P')
            p[g++]=m;
        else if(s[0]=='X')
            x[h++]=m;
    }
    bubbleSort(g,p);
    bubbleSort(h,x);
    if(a>=g)
        for(int i=0;i<g;i++)
            ans+=p[i];
    else
        for(int i=0;i<a;i++)
            ans+=p[i];
        d+=min(a,g);
    if(b>=h)
        for(int i=0;i<h;i++)
            ans+=x[i];
    else
        for(int i=0;i<b;i++)
            ans+=x[i];
        d+=min(b,h);
    int n1 = g-a;
    int n2 = h-b;
    if(n1<=0)
    {
        if(n2<=0)
        {
            cout<<ans;
            return 0;
        }
        else
            for(int i=b;i<b+min(n2,c);i++)
                ans+=x[i];
            d+=min(n2,c);
    }
    else
    {
        if(n2<=0)
        {
            for(int i=a;i<a+min(n1,c);i++)
                ans+=p[i];
            d+=min(n1,c);
        }
        else
        {
            int i,j,k=0;i=a,j=b;
            while(i<=g && j<=h)
            {
                if(k==min(n1+n2,c))
                    break;
                if(p[i]<x[j])
                {
                    ans+=p[i];
                    i++;
                }
                else
                {
                    ans+=x[j];
                    j++;
                }
                k++;
            }
            d+=min(n1+n2,c);   
        }
    }
    cout<<d<<" "<<ans;
}