//IMPLEMENTATION OF POLYNOMIAL ADDITION OF SINGLE VARIABLE
//NOTE:THE TERMS SHOULD BE ENTERED IN DESCENDING ORDER OF THEIR POWERS!!
#include<stdio.h>
#include<stdlib.h>
//EACH NODE CONSISTS OF THE POWER,THE CO-EFFICIENT AND THE NEXT POINT
struct node{
	int power;
	int coeff;
	struct node *next;
		};
		typedef struct node *NODEPTR;
NODEPTR getnode()
{
	NODEPTR p=(NODEPTR) malloc(sizeof(struct node));
	return p;
}
int freenode(n)
NODEPTR n;
{
	free(n);
	return 0;
}
//EACH TERM OF A POLYNOMIAL IS INSERTED AT THE BACK
int pushback(head,tail,x,y)
struct node **head;
struct node **tail;
int x,y;
{
	NODEPTR q;
	q=getnode();
	q->coeff=x;
	q->power=y;
	q->next=NULL;
	if(*head==NULL)//WHEN THE LIST IS EMPTY
	*head=*tail=q;
	else
	{
		(*tail)->next=q;
		*tail=q;
	}
	return 0;
}
//FUNCTION TO ADD THE TWO POLYNOMIALS
int add(h1,h2,h3,t3)
struct node *h1,*h2;
struct node **h3,**t3;
{
	int s;
	//COMPARISON OF POWERS
	while(h1!=NULL && h2!=NULL)
	{
		if(h1->power==h2->power)
		{
			s=h1->coeff+h2->coeff;
			pushback(h3,t3,s,h1->power);
			h1=h1->next;
			h2=h2->next;
		}
		else
		if(h1->power>h2->power)
		{
			s=h1->coeff;
			pushback(h3,t3,s,h1->power);
			h1=h1->next;
		}
		else
		{
			s=h2->coeff;
			pushback(h3,t3,s,h2->power);
			h2=h2->next;
		}
	}
	//THE REMAINING TERMS BEING INSERTED INTO THE RESULT LIST
	while(h1!=NULL)
	{
		pushback(h3,t3,h1->coeff,h1->power);
		h1=h1->next;
	}
	while(h2!=NULL)
	{
		pushback(h3,t3,h2->coeff,h2->power);
		h2=h2->next;
	}
		return 0;
}
//FUNCTION TO PRINT THE POLYNOMIALS
int traverse(h)
struct node *h;
{
	while(h!=NULL)
	{
		if(h->power!=0)
		printf("+%dx^%d",h->coeff,h->power);
		else
		printf("+%d",h->coeff);
		h=h->next;
	}
	printf("\n");
	return 0;
}
int main()
{
	struct node *h1=NULL,*t1=NULL,*h2=NULL,*t2=NULL,*h3=NULL,*t3=NULL;
	int c,p,s,i=1;
	printf("ENTER THE VALUES OF THE FIRST POLYNOMIAL\n");
	printf("ENTER THE CO-EFFICIENT AND POWER\n");
	printf("ENTER 1 TO CONTINUE AND 0 TO STOP\n");
	while(i)
	{
		scanf("%d%d%d",&c,&p,&s);
		pushback(&h1,&t1,c,p);
		i=s;
	}
	i=1;
	printf("ENTER THE VALUES OF THE SECOND POLYNOMIAL\n");
	printf("ENTER THE CO-EFFICIENT AND POWER\n");
	printf("ENTER 1 TO CONTINUE AND 0 TO STOP\n");
	while(i)
	{
		scanf("%d%d%d",&c,&p,&s);
		pushback(&h2,&t2,c,p);
		i=s;
	}
	traverse(h1);
	traverse(h2);
	add(h1,h2,&h3,&t3);
	printf("RESULT:");
	traverse(h3);
	return 0;
}
//END OF PROGRAM
