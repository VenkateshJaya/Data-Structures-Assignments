#include<stdio.h>
#include<stdlib.h>


int main(){
    int n,k;
    scanf("%d %d",&n,&k);
  	
    int a[n];
    int b[n];
    char ch;
    for(int i=0 ; i < n ;++i){
        scanf("%c",&ch);
        if(ch=='Y')a[i]=1;
        if(ch=='G')a[i]=2;
    }
    int ans =0;
    int p = 0;
    
    for(int i=0 ; i < n ; ++i){
        a[i] += p + b[i];
        a[i] %=3;
        if(a[i]==0){
            p+=2;
            ans+=2;
        }
        else if(a[i]==1)p+=1,ans+=1;
        if(i+k<n) b[i+k]-=p;
    }
    
    printf("%d\n",ans);
    
}