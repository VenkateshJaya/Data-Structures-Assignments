#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int* arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i] = malloc(m*sizeof(int));
        for(int j=0;j<m;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}