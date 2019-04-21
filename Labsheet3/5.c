#include<stdio.h>

int main(int argc, char const *argv[]) {
  int n;
  printf("ENTER N:\n");
  scanf("%d",&n);
  printf("ENTER MATRIX:\n");
  int mat[n][n];
  int marked[n][n];
  int count =1;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      scanf("%d",&mat[i][j] );
      if(mat[i][j]==1)
      {
        mat[i][j]=count;
        count++;
      }
    }
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(mat[i][j]!=0)
      {
        if(mat[i+1][j] && i!=n-1)
          mat[i+1][j]=mat[i][j];
        if(mat[i+1][j-1] && i!=n-1 && j!=0)
          mat[i+1][j-1]=mat[i][j];
        if(mat[i+1][j+1] && i!=n-1 && j!=n-1)
          mat[i+1][j+1]=mat[i][j];
        if(mat[i][j+1] && j!=n-1)
          mat[i][j+1]=mat[i][j];
      }
    }
  }
  int max =0;
  int val=0;
  for(int i=1;i<count;i++)
  {
    int  sum=0;
    for(int j=0;i<n;i++)
    {
      for(int k=0;j<n;j++)
      {
        if(mat[j][k]==i)
        {
          sum++;
        }
      }
    }
    if(max<sum)
    {
      max=sum;
      val=i;
    }
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(mat[i][j]==max)
      {
        printf("%d ",max );
      }
      else
      {
        printf("0 ");
      }
    }
    printf("\n");
  }

  return 0;
}
