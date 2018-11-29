#include <stdio.h>
#include <stdlib.h>

void insert_begins();
void insert_ends();
void insert_pos();
void display();

struct node
{
	int id;
	char name[20];
	int sem;
	struct node *next;

};

struct node *start = NULL;
int main()
{
	int choice;
	while(1)
	{
		printf("\n 1.Insert all at the beginning\n2.Insert all at end\n3.Insert at specific position\n4.Display\n5.Exit\n");

		printf("Enter your choice\t");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: insert_begins();
					break;
			case 2: insert_ends();
					break;
			case 3: insert_pos();
					break;
			case 4: display();
					break;
			case 5: exit(0);

			default: printf("Wrong choice: \n");
		}
	}
	return 0;
}

void insert_begins()
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof (struct node));
	if(temp == NULL)
	{
		printf("\n Out of memory space: \n");
		return;
	}

	printf("\n Enter the ID, name and semester: \t");
	scanf("%d%s%d", &temp->id, temp->name, &temp->sem);

	temp->next = NULL;
	if(start == NULL)
		start = temp;
	else
	{
		temp->next = start;
		start = temp;
	}
}

void insert_ends()
{
	struct node *temp, *ptr;
	temp = (struct node*)malloc(sizeof (struct node));

	if(temp == NULL)
	{
		printf("\n out of memory space\n");
		return;
	}

	printf("\n Enter ID, name and semester: \t");
	scanf("%d%s%d", &temp->id, temp->name, &temp->sem);

	temp->next = NULL;
	if(start == NULL)
		start = temp;
	else
	{
		ptr = start;
		while(ptr->next!=NULL)
			ptr = ptr->next;
			ptr->next = temp;

	}
	
}


void insert_pos()
{
	struct node *ptr, *temp;
	int i,pos;
	temp = (struct node*)malloc(sizeof (struct node));
	if(temp == NULL)
	{
		printf("\n out of memory space\n");
		return;
	}

	printf("\n Enter the position for the new node:\n");
	scanf("%d", &pos);
	printf("\n Enter the ID, name and semester\t");
	scanf("%d%s%d", &temp->id, temp->name, &temp->sem);

	temp->next = NULL;

	if(pos == 1)
	{
		temp->next = start;
		start = temp;

	}

	else
	{
		ptr = start;
		for(i=0; i<pos-2; i++)
		{
			ptr = ptr->next;
			if(ptr == NULL)
			{
				printf("\n Position not found\n");
				return;
			}

		}
	  temp-> next = ptr->next;
	  ptr-> next = temp;
	}

}


void display()
{
	struct node *ptr;
	if(start == NULL)
	{
		printf("\n List is empty\n");
		return;
	}

	else
	{
		ptr = start;
		printf("\n The list elements are : \n");
		while(ptr != NULL)
		{
			printf("%d  %s  %d\t\t", ptr->id, ptr->name, ptr->sem );
			ptr = ptr->next;
		}
	}
}

