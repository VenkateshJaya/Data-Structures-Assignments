#include<bits/stdc++.h>
using namespace std;
#define N 100001
int q1[N],q2[N],q3[N],length,rear,front,a[N];
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
int findMaxMultupleOf3(int arr[], int size) 
{ 
    bubbleSort(size,arr); 
    int queue0[N], queue1[N], queue2[N];
    memset(queue0,-1,sizeof(queue0));
    int i, sum;int a,b,c;
    a=b=c=0; 
    for (i = 0, sum = 0; i < size; ++i) 
    { 
        sum += arr[i]; 
        if ((arr[i] % 3) == 0) 
            queue0[a++]=arr[i];
        else if ((arr[i] % 3) == 1) 
            queue1 [b++]= arr[i]; 
        else
            queue2[c++] =arr[i]; 
    }
    if ((sum % 3) == 1) 
    {
        if (b>0) 
            queue1[0]=0,b--;
        else 
        { 
            if (c>0)
                queue2[0]=0 ,c--;
            else
                return 0; 
            if (c>0) 
                queue2[1]=0,c--; 
            else
                return 0; 
        } 
    }
    else if ((sum % 3) == 2) 
    { 
        if (c>0) 
            queue2[0] = 0,c--; 
        else 
        { 
            if (b>0)
                queue1[0]= 0,b--;
            else
                return 0; 
  
            if (b>0) 
                queue1[1]= 0,b--;
            else
                return 0; 
        } 
    }
    int aux[size], top = 0; 
    for(int i=0;i<a;i++)
        aux[top++]=queue0[i];
    for(int i=0;i<b+2;i++)
        if(queue1[i] % 3 ==1)
            aux[top++]=queue1[i];
    for(int i=0;i<c+2;i++)
        if(queue2[i] % 3 ==2)
            aux[top++]=queue2[i];
    bubbleSort(top,aux);
    for(int i=top-1;i>=0;i--)
        cout<<aux[i]; 
    return top;    
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    findMaxMultupleOf3(a,n);
}