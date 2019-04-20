#include<stdio.h>
#include<stdlib.h>

int s=0;
int e= -1;
char stk[200005] = {};
int val =1;

void push(char ch){
	e++;
	stk[e]=ch;
}

void pop(){
	if(e==-1)printf("Stack is empty.\n" );
	stk[e] = '\0';
	e--;
}



int main(){
	int n;
	scanf("%d",&n);
	char a[n];
	scanf("%s",a);

	for(int i=0; i < n ;++i ){
		if(a[i]==']' || a[i]=='}' || a[i]==')'){
			if(a[i]==']' && stk[e]=='[' && e>=0)pop();
			else if(a[i]==']') {val=0;break;}
			else if(a[i]=='}' && stk[e]=='{' && e>=0)pop();
			else if(a[i]=='}') {val=0;break;}
			else if(a[i]==')' && stk[e]=='(' && e>=0)pop();
			else if(a[i]==')') {val=0;break;}
		}
		else push(a[i]);
	
	}

	if(e!=-1)val=0;

	if(val) printf("True.\n");
	else printf("False.\n");

}