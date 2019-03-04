#include<stdio.h>
#include<stdlib.h>

int indexable(int n, int m, int i, int j)
{
    return (i>=0 && i<n) && (j>=0 && j<m);
}

int dfs(char** arr, int n, int m, int x, int y, char string[], int index, int len)
{
    if(index >= len || arr[x][y] != string[index])
    {
        return 0;
    }
    if(index == len - 1)
    {
        return 1;
    }    
    int ans = 0;
    if(indexable(n,m,x,y+1))
    {
        ans += dfs(arr,n,m,x,y+1,string,index+1,len);
    }
    if(!ans && indexable(n,m,x,y-1))
    {
        ans += dfs(arr,n,m,x,y-1,string,index+1,len);
    }
    if(!ans && indexable(n,m,x+1,y))
    {
        ans += dfs(arr,n,m,x+1,y,string,index+1,len);
    }
    if(!ans && indexable(n,m,x-1,y))
    {
        ans += dfs(arr,n,m,x-1,y,string,index+1,len);
    }
    if(!ans)
    {
        ans += dfs(arr,n,m,x,y,string,index+1,len);  
    }
    return ans;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    char** arr = malloc(n*sizeof(char*));
    for(int i=0;i<n;i++)
    {
        arr[i] = malloc(m*sizeof(char));
        scanf("%s", arr[i]);
    }

    int t;
    scanf("%d\n", &t);
    const int MAX = 10000;
    while(t--)
    {
        char string[MAX];
        int len = 0;
        while(1)
        {
            char c;
            scanf("%c", &c);
            if(c == '\n')
            {
                break;
            }
            string[len++] = c;
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j] == string[0])
                {
                    ans += dfs(arr,n,m,i,j,string,0,len);
                }
            }
        }
        if(ans)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}