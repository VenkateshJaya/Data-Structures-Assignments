#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int deg;
    int* adj;
} Node;

void initNodes(Node[], int);
void addEdge(Node[], int, int);
void dfs(Node[], int, int, int);

int ans, m;
int *cat;

int main()
{
    int n;
    scanf("%d %d", &n, &m);

    cat = malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {  
        scanf("%d", &cat[i]);
    }

    Node v[n];
    initNodes(v, n);
    for(int i=0;i<n-1;i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        addEdge(v, x-1, y-1);
    }

    ans = 0;
    dfs(v,0,-1,0);
    printf("%d\n", ans);
}

void initNodes(Node v[], int n)
{
    for(int i=0;i<n;i++)
    {
        v[i].deg = 0;
        v[i].adj = malloc(n*sizeof(int));
    }
}

void addEdge(Node v[], int x, int y)
{
    v[x].adj[v[x].deg++] = y;
    v[y].adj[v[y].deg++] = x;
}

void dfs(Node v[], int curr, int par, int count)
{
    count = (count+1)*cat[curr];
    if(count > m)
    {
        return;
    }
    if(v[curr].deg == 0 || (v[curr].deg == 1 && curr != 0))
    {
        ans++;
        return;
    }
    for(int i=0;i<v[curr].deg;i++)
    {
        int it = v[curr].adj[i];
        if(it != par)
        {
            dfs(v, it, curr, count);
        }
    }
}