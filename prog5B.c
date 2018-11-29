#include<stdio.h>

void tower(int n,char fp, char tp, char ap)
{
	if(n==1)
	{
		printf("move disc 1 from peg %c to peg %c\n",fp,tp );
		return;
	}

	tower(n-1,fp,ap,tp);
	printf("move disc %d from peg %c to peg %c\n",n,fp,tp );
	tower(n-1,ap,tp,fp);
}

int main()
{
	int n;
	printf("Enter the number of disc\n");
	scanf("%d",&n);
	tower(n,'a','b','c');
	return 0;
}

