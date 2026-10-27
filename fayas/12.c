#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 10
int top=-1,stack[MAX];
 
void push(int n){
stack[++top]=n;
}
int pop(){
return stack[top--];
} 
int main()
{
	char postfix[MAX];
	int i,a,b,res;
	
	printf("enter the expression:");
	scanf("%s",postfix);
	
	for(i=0;postfix[i] !='\0';i++)
	{
		if (isdigit(postfix[i]))		
		{
	 		push(postfix[i] -'0');
	 	}
	 	else
	 	{
	 		b=pop();
	 		a=pop();
	 		switch(postfix[i])
	 		{
	 			case '+':
	 				res=a+b;
	 				break;
	 			case '-':
	 				res=a-b;
	 				break;
	 			case '*':
	 				res=a*b;
	 				break;
	 			case '%':
	 				res=a%b;
	 				break;
	 			case '/':
	 				res=a/b;
	 				break;
	 			default:
	 				printf("invalid");
	 				return 1;
	 			}
	 			
	 			push(res);
	 		}				
	 	}
	 	printf("result=%d\n",pop());
	 	return 0;
	 }												
