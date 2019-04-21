#include<stdio.h>
#include<stdlib.h>
int count=0;

void dfs(int node,int visited[],int n,int mat[][n],int x,int y,int flag)
{
  if(node==y-1 && flag==1)
  {
    count--;
  }
  else
  {
    if(node==x-1)
    {
      flag=1;
    }
    for(int i=0;i<n;i++)
    {
      if(mat[node][i]==1 && visited[i]==0)
      {
        visited[i]=1;
        count++;
        dfs(i,visited,n,mat,x,y,flag);
        visited[i]=0;
      }
    }
  }
}


int main(int argc, char const *argv[]) {
  int n,x,y;
  scanf("%d %d %d\n",&n,&x,&y);
  int mat[n][n];
  int u,v;
  int  visited[n];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      mat[i][j]=0;
    }
    visited[i]=0;
  }
  int flag;
  for(int i=0;i<n-1;i++)
  {
    scanf("%d %d",&u,&v );
    mat[u-1][v-1]=1;
    mat[v-1][u-1]=1;
  }
  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<n-1;j++)
    {
      printf("%d ",mat[i][j] );
    }
    printf("\n");
  }
  for(int i=0;i<n;i++)
  {
    flag=0;
    visited[i]=1;
    dfs(i,visited,n,mat,x,y,flag);
    visited[i]=0;
  }
  printf("%d\n",count);
  return 0;
}
