#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
char url[40];
struct node*rlink;
struct node*llink;
};

struct node*add_url(char url[], struct node*cur)
{
struct node*new;
new=(struct node*)malloc(sizeof(struct node));
strcpy(new->url,url);
new->rlink=NULL;
new->llink=NULL;
if(cur==NULL)
return new;
else
{
new->llink=cur;
cur->rlink=new;
return new;
}
}

struct node*browse_fwd(struct node*cur)
{
if(cur==NULL)
{
printf("\nHistor clean\n");
return cur;
}
if(cur->rlink==NULL)
{
printf("\nAt the most recent page\n");
return cur;
}
cur=cur->rlink;
return cur;
}

struct node*browse_bck(struct node *cur)
{
if(cur==NULL)
{
printf("\nHistory clean\n");
return NULL;
}
if(cur->llink==NULL)
{
printf("\nNo records before this\n");
return cur;
}
cur=cur->llink;
return cur;
}

void show_cur_site(struct node *cur)
{
if(cur==NULL)
{
printf("\nHistory clean\n");
return;
}
printf("\nYou are viewing %s\n",cur->url);
}

void main()
{
char url[40];
int ch;
struct node *cur;
cur=NULL;
while(1)
{
printf("\n1.Browse forward\n 2.Browse backward\n 3.Open new url\n 4.Show current site\n 5.Exit\n Enter choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: cur=browse_fwd(cur);break;
case 2: cur=browse_bck(cur);break;
case 3: printf("Enter a new URL ");
scanf("%s",&url);
cur=add_url(url,cur);
break;
case 4: show_cur_site(cur);break;
case 5: exit(1); break;
}
}
}

