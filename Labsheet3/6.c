#include<stdio.h>
int formPalindrome(char s[]);
int main(){

    char s[11];
    gets(s);

    int flag = formPalindrome(s);

    if(flag == 1){
        printf("Yes");
    }else
    {
        printf("No");
    }
}
int formPalindrome(char s[]){

    int count[256] = {0};
    int i;
    for(i=0;s[i]!='\0';i++){
        count[s[i]]++;
    }
    int odd=0;
    for(i=0;i<256;i++){
        if(count[i]%2!=0){
            odd++;            
        }
        if(odd >1)
            return 0;
    }
    return 1;
}