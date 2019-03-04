#include<stdio.h>
#include<stdlib.h>

int *vis;

typedef struct
{
    int elem, pos;
} Pair;

void dfs(char* a[], int curr, int n, int c[], int k)
{
    if(vis[curr])
    {
        return;
    }
    vis[curr] = 1;
    c[curr] = k;
    for(int i=0;i<n;i++)
    {
        if(vis[i] != 1 && a[curr][i] == '1')
        {
            dfs(a,i,n,c,k);
        }
    }
}

void swap(Pair* x, Pair* y)
{
    Pair t = *x;
    *x = *y;
    *y = t;
}

void bubblesort(Pair arr[], int n)
{
    for(int     i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j].elem > arr[j+1].elem)
            {
                int t = arr[j].pos;
                arr[j].pos = arr[j+1].pos;
                arr[j+1].pos = t;
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int p[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &p[i]);
    }
    
    char* a[n];
    for(int i=0;i<n;i++)
    {   
        a[i] = malloc(n*sizeof(char));
        scanf("%s", a[i]);
    }

    vis = calloc(n, sizeof(int));
    int c[n];
    int k = 0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            k++;
            dfs(a,i,n,c,k);
        }
    }

    for(int i=1;i<=k;i++)
    {
        Pair arr[n];
        int index = 0;
        for(int j=0;j<n;j++)
        {
            if(c[j] == i)
            {
                arr[index].elem = p[j];
                arr[index].pos = j;
                index++;
            }
        }
        bubblesort(arr,index);
        for(int j=0;j<index;j++)
        {
            p[arr[j].pos] = arr[j].elem;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
    return 0;
}