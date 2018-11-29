#include<stdio.h>
struct student 
{
	char name[30];
	int m1,m2,m3;

	float total;
}s[10];


int main()
{
	int i,m;
	printf("Enter the number of students:\n");
	scanf("%d",&m);
	
	for (int i = 0; i < m; i++)
    {
    	printf("Enter the name of the student\n");
		scanf("%s", s[i].name);
    	printf("Enter the three  marks of student:\n");
	    scanf("%d %d %d", &s[i].m1,&s[i].m2,&s[i].m3);
	    s[i].total=s[i].m1+s[i].m2+s[i].m3;
	}
		
	
	for ( i = 0; i < m; i++)
	{
		printf("the mark of student :\n name:\t\t%s\ntotal marks:%f \n",s[i].name,s[i].total);
	}

	
}
