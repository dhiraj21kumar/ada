#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char name[40];
	struct node *link;
};

struct node *add_player(char name[], struct node *cur)
{
	struct node *new;
	new = (struct node*)malloc(sizeof (struct node));
	strcpy(new->name, name);
	new->link = new;
	if(cur == NULL)
	return new;
	new->link = cur->link;
	cur->link = new;
	return new;	
};

struct node *next_turn(struct node *cur)
{
	cur = cur->link;
	return cur;
}

void whose_turn(struct node *cur)
{
	printf("%s must play now\n", cur->name );
}

int main()
{
	char ch[2], name[20];
	int n,i;
	struct node *cur;
	cur = NULL;
	printf("enter the number of players\n");
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		printf("Enter the name of player %d\n",i+1 );
		scanf("%s", name);
		cur = add_player(name, cur);
	}

	while(1)
	{
		printf("Type n for next move and q for quit game\n");
		scanf("%s",ch);
		if(strcmp(ch,"q")==0)
			break;
		cur = next_turn(cur);
		whose_turn(cur);
	}
return 0;
}


