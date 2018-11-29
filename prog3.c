#include<stdio.h>
//#define stack_size 25
#include<ctype.h>
int ele,i,top;
char str[25],pf[25],stack[25];


int push(char ele)
{
	if(top == 24)
	{
		printf("overflow\n");
		return(-1);
	}
	else
		stack[++top]=ele;
}


char pop()
{
	if(top == -1)
	{
		printf("underflow\n");
		return(-1);
	}
		return(stack[top--]);
}


void convert()
{
	int i=0,j=0;
	for(i=0; str[i]!='\0'; i++)
	{
		if(isalpha(str[i]) || isdigit(str[i]))
			pf[j++] = str[i];
		else
		
			switch(str[i])
			{
				case '(': push(str[i]);
						  break;

				case '$': while(stack[top] == '$')
							{
								pf[j++] = pop();
							}
							push(str[i]);
							break;

				case '/':

				case '*': while(stack[top] == '$' || stack[top] =='/' || stack[top] == '*')
							{
								pf[j++] = pop();
							}
							push(str[i]);
							break;

				case '+': 

				case '-': while(stack[top] == '*' || stack[top] == '/' || stack[top] == '+' || stack[top] == '-' || stack[top] == '$')
							{
								pf[j++] = pop();
							}
							push(str[i]);
							break;

				case ')': while(stack[top]!= '(')
							pf[j++] = pop();
								pop();
								break;
			}
		}
					
			while(top> -1)
			{
				pf[j++] = pop();
				pf[j] = '\0';
				printf("Postfix expression is : %s",pf );
			}
}

int main()
{
	top = -1;
	printf("Enter an infix expression:\n");
	scanf("%s", str);
	convert();
}

