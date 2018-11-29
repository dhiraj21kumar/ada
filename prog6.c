#include<stdio.h>
#include<stdlib.h>
#define max 5
int queue[max];
int rear=-1, front=-1;
void insert()
{
	int e;
	if(rear == max-1)
		printf("Queue onerflow\n");
	else
	{
		if(front == -1)
			front = 0;
		printf("Insert the token number of the new patient\n");
		scanf("%d", &e);
		queue[++rear] = e;
	}
}

void delete()
{
	if(front == -1 || front>rear)
		{
			printf("Queue underflow\n");
			return;
		}

		else
		{
			printf("Token number of patient deleted from the queue is %d\n",queue[front]);
			front++;
		}
}

void display()
{
	int i;
	if(front == -1 || front>rear)
		printf("Queue is empty\n");
	else
	{
		printf("Token number of the patient in the queue is :\n");
		for(i=front; i<=rear; i++)
			printf("%d\t",queue[i]);
	}
}

int main()
{
	int ch;
	while(1)
		{
			printf("1.insert\n 2.Remove\n 3.display\n 4.exit\n");
			printf("Enter your choice\n");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1: insert();
						break;

				case 2: delete();
						break;

				case 3: display();
						break;

				case 4: exit(0);
						break;

				default: printf("Wrong choice\n");
			}
		}
}

