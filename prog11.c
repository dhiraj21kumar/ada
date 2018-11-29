#include <stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *lt, *rt;
};

struct node *root = NULL;

void brt(int);
struct node *maketree(int);
void setleft(struct node*, int);
void setright(struct node*, int);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);

int main()
{
	int ch,x;
	while(1)
	{
		printf("\n 1.Create tree\n 2.inorder\n 3.preorder\n 4.postorder\n 5.exit\n Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)

		{
			case 1: printf("\nEnter the elements to be inserted\n");
					scanf("%d", &x);
					brt(x);
					break;

			case 2: if(root == NULL)
					printf("The tree does not exist\n");
					else
					{
						printf("Inorder traversal is: \n");
						inorder(root);

					}
					break;

			case 3: if(root == NULL)
					printf("Tree does not exist\n");
					else
						preorder(root);
					break;

			case 4: if(root == NULL)
					printf("The tree does not exist\n");
					else
						postorder(root);
					break;

			case 5: exit(1);

			default: printf("Invalid choice\n");
	}	}
} 


void brt(int x)
{
	struct node *p,*q;
	if(root == NULL)
		root = maketree(x);
	else
	{
		p=q=root;
		while(q!=NULL)
		{
			p=q;
			if(p->info>= x)
				q=p->lt;
			else
				q=p->rt;
		
			
		}
		if(p->info <= x)
			setright(p,x);
		else
			setleft(p,x);
	}
}

struct node *maketree(int x)
{
	struct  node *p;
	p = (struct node*)malloc(sizeof (struct node));
	if(p == NULL)
	{
		printf("Memory can't be allocated\n");
		return 0;
	}
	p->info = x;
	p->lt = p->rt = NULL;
	return p;
};

void setleft(struct node*p, int x)
{
	if(p == NULL)
		printf("Insertion is not possible\n");
	else
		if(p->lt!=NULL)
			printf("left node already exists\n");
		else
			p->lt = maketree(x);
}

void setright(struct node *p,int x)
{
	if(p == NULL)
		printf("Insertion is not possible\n");
	else
		if(p->rt!=NULL)
			printf("Right node already exists\n");
		else
			p->rt = maketree(x);
}

void inorder(struct node *p)
{
	if(p!= NULL)
	{
		inorder(p->lt);
		printf("%d",p->info );
		inorder(p->rt);
	}
}

void preorder(struct node *p)
{
	if(p!=NULL)
	{
		printf("%d",p->info );
		preorder(p->lt);
		preorder(p->rt);
	}
}

void postorder(struct node *p)
{
	if(p!=NULL)
	{
		postorder(p->lt);
		postorder(p->rt);

		printf("%d",p->info );
	}
}


