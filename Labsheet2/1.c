#include<stdio.h>
int check(char t[],char p[], int n);
int main(){

    char t[1000];
    char p[1000];
    int a[1000];
    int size;
    printf("Enter String t: ");
    gets(t);
    printf("Enter String p: ");
    gets(p);
    do{
        printf("Enter size of a (should be equal to size of t): ");
        scanf("%d",&size);
    }while(size!=strlen(t));
    
    int i,j;
    printf("Enter Array a: ");
    for(i=0;i<size;i++){
        scanf("%d",&a[i]);
    }
    int flag=0;
    int count =0;
    for(i=0;i<size;i++){ 
        int x = a[i] - 1;
        t[x] = ' ';
        flag = check(t,p,size);
        if(flag == 1){
            count++;
        }else
        {
            break;
        }
    }
    printf("%d",count);
}
int check(char t[],char p[], int n){
    int i,j;
    int size = strlen(p);
    int x=0;
    int confirmp[1000] = {0};
    for(i=0;i<size;i++){
        for(j=x;j<n;j++){
            if(p[i] == t[j]){
                confirmp[i] = 1;
                x = j+1;
                break;
            }
        }
    }
    int flag = 1;
    for(i = 0; i < size; i++)
    {
        if(confirmp[i] == 0){
            flag = 0;
            return flag;
        }
    }
    return flag;
}