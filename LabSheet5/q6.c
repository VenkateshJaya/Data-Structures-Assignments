#include<bits/stdc++.h>
using namespace std;
#define N 100001
int q1[N],q2[N],q3[N],length,rear,front;
int merge(int a[], int p, int q, int r)
{
    int countingInversion = 0;
    int n1 = q-p+1;
    int n2 = r-q;
    int temp1[n1+1];
    int temp2[n2+1];
    for(int i=0; i<n1; i++) temp1[i] = a[p+i];
    for(int i=0; i<n2; i++) temp2[i] = a[q+1+i];

    temp1[n1] = INT_MAX;
    temp2[n2] = INT_MAX;
    int i = 0, j = 0;

    for(int k=p; k<=r; k++)
    {
        if(temp1[i] <= temp2[j])
        {
            a[k] = temp1[i];
            i++;
        }
        else
        {
            a[k] = temp2[j];
            j++;
            countingInversion=countingInversion+(n1-i); 
        }
    }
    return countingInversion;
}
int mergeSort(int a[], int p, int r)
{
    int countInversion = 0;
    if(p < r)
    {
        int q = (p + r)/2;
        countInversion = mergeSort(a, p, q);
        countInversion += mergeSort(a, q+1, r);
        countInversion += merge(a, p, q, r);
    }
    return countInversion;
}

int main()
{
    int n,a[N];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    cout<<mergeSort(a,0,n-1);
}