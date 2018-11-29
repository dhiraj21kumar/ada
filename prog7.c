#include<stdio.h>
#include<stdlib.h>
#define Q_size 5

void InsertQ(int item, int *r, int *q, int *c)
{
	if(c == Q_size)
	{
		printf("Queue is full\n");
		return;
	}

	*r= (*r+1) % Q_size;
	q[*r] = item;
	(*c)++;
}

int DeleteQ(int *f, int q[], int *c)
{
	int item;
	if(*c == 0)
		return 0 ;
	item = q[*f];
	*f= ((*f)+1)% Q_size;
	*c--;
	return item;

}

void DisplayQ(int f, int q[], int c)
{
	int i;
	if(c == 0)
	{
		printf("Queue is empty\n");
		return;
	}
	printf("contents of Queue\n");
	for (int i = 0; i <=c; ++i)
	{
		printf("%d\n",q[f] );
		f=(f+1) % Q_size;

	}
}

int main()

{
	int ch,item,f,r,c,q[Q_size];
	f=0;
	r=-1;
	c=0;
	while(1)
	{
		printf("1.Insert 2.Delete 3.Display 4.Exit\n");
		printf("Enter your choice\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("Enter the item to be inserted\n");
					scanf("%d", &item);
					InsertQ(item, &r,q,&c);
					break;

			case 2: item = DeleteQ(&f,q,&c);
					if(item == 0)
					{
						printf("Queue is empty\n");
						return 0;
					}

					printf("item deleted is %d\n", item);
					break;

			case 3: DisplayQ(f,q,c);
					break;

			case 4: exit(0);
		}
	}
}

