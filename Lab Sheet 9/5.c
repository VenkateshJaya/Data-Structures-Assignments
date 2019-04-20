#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char str[100]; scanf("%s", str);
    int n = strlen(str);
    int alph[256] = {};
    for(int i=0; i<n; i++){
        alph[str[i]]++;
    }
    char a = 'a',b='a'-1;

    for(int j=0; j<n; j++){
        int max = 0;
        a = 0;
        for(int i='a'; i<='z'; i++){
            if(i!=b && alph[i] >= max){
                max = alph[i];
                a = i;
            }
        }
        printf("%c ", a);
        if(a==b || a=='z'){
            printf("\nNo\n");
            return 0;
        }
        alph[a]--;
        b = a;
    }
   printf("\nYes\n");
    return 0;
}