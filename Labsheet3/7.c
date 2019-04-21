#include<stdio.h>
int main(){
    char string[100];
    gets(string);
    int i=0;
    while(string[i]!='\0'){
        // Caeser Cipher: (input + shift - 'a' ASCII)%26{total no of characters} + 'a' ASCII
            string[i] = (char)((int)(string[i] + 3 - 97)%26 + 97); 
        i++;
    }
    
    printf("%s",string);
    return 0;
}