#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char const *argv[]) {
  char s[100];
  printf("ENTER STRING:\n");
  scanf("%[^\n]s",s);
  int m;
  printf("ENTER M:\n");
  scanf("%d",&m );
  int f,r,k;
  for(int i=0;i<m;i++)
  {
    scanf("%d,%d,%d",&f,&r,&k);
    int x=0;
    char temp[100];
    for(int j=f-1;j<r;j++)
    {
      temp[x]=s[j];
      x++;
    }
    for(int j=0;j<k;j++)
    {
      char t= temp[r-f];
      for(int i=r-f;i>=1;i--)
      {
        temp[i]=temp[i-1];
      }
      temp[0]=t;
      for(int i=0;i<r-f+1;i++)
      {
        s[f-1+i]=temp[i];
      }
    }
  }
  for(int i=0;i<strlen(s);i++)
  {
    printf("%c",s[i]);
  }
  printf("\n");
  return 0;
}
