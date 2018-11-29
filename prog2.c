#define stack_size 5
#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int item[5];
	int top;
}s;

void push()
	{
		int ele;
		printf("Enter the element to be pushed\n");
		scanf("%d", &ele);
		if(s.top == stack_size-1)
			printf("\n Overflow\n");
		
		else
			{
				s.top++;
				s.item[s.top] = ele;
			}
	}

void pop()
	{
		int k;
		if(s.top == -1)
		    printf("\n Underflow\n");
		else
			{
				k = s.item[s.top];
				printf("The popped value is %d", k);
				s.top = s.top-1;
			}
	}

void display()
	{
		int i;
		if(s.top == -1)
		    printf("Empty stack");
		else
			printf("\n\n");
		for(i=0;i<=s.top;i++)
			printf("%d\t", s.item[i]);
	}

int main()
	{
		int i;
		s.top =-1;
		
		while(1)
			{
				printf("\n 1.PUSH\n 2.POP\n 3.DISPLAY\n 4.EXIT\n");
				printf("\n Enter your choice:");
				scanf("%d", &i);
				
				   switch(i)
							{
								case 1: push();
										break;
								case 2: pop();
										break;
								case 3: display();
										break;
								case 4: exit(0);
										break;
								default: printf("\n invalid input");
							}
			}
}


