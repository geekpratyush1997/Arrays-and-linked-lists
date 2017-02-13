//IMPLEMENTATION OF CIRCULAR LINKED LIST
//A CIRCULAR LINKED LIST IS A LIST WHERE THE TAIL IS CONNECTED TO THE HEAD
#include<stdio.h>
#include<stdlib.h>
struct node{
	int key;
	struct node *next;
		};
		typedef struct node *NODEPTR;
//FUNCTION THAT CREATES A NODE WITH key(value) and next(pointer to the next node)
NODEPTR getnode()
{
	NODEPTR p;
	p=(NODEPTR) malloc(sizeof(struct node));
	return p;
}
//FUNCTION THAT IS USES TO DELETE A NODE AFTER ITS USE IS COMPLETED
int freenode(p)
NODEPTR p;
{
	free(p);
	return 0;
}
//FUNCTION TO FIND A GIVEN NODE
NODEPTR find(head,n)
struct node **head;
int n;
{
	NODEPTR q;
	q=*head;
	while(q->key!=n)
	q=q->next;
	return q;
}
//FUNCTION TO ENTER A NODE AT FRONT
int pushfront(head,tail,x)
struct node **head;
struct node **tail;
int x;
{
	NODEPTR q;
	q=getnode();
	q->key=x;
	q->next=*head;
	*head=q;
	if(*tail==NULL)//WHEN THE LIST IS EMPTY
	*tail=q;
	else
	(*tail)->next=*head;
	return 0;
}
//FUNCTION TO POP A NODE FROM FRONT
int popfront(head,tail)
struct node **head;
struct node **tail;
{
	NODEPTR q;
	q=*head;
	if(*head==NULL)//WHEN THE LIST IS EMPTY
	{
		printf("*****UNDERFLOW*****");
		return 0;
	}
	if(*head==*tail)//WHEN THE LIST HAS ONLY ONE ELEMENT
	*head=*tail=NULL;
	else
	{
		*head=(*head)->next;
		(*tail)->next=*head;
	}
	freenode(q);
	return 0;
}
//FUNCTION TO PUSH A NODE AT THE REAR
int pushback(head,tail,x)
struct node **head;
struct node **tail;
int x;
{
	NODEPTR q;
	q=getnode();
	q->key=x;
	if(*head==NULL)//WHEN THE LIST IS EMPTY
	*head=*tail=q;
	else
	{
		(*tail)->next=q;
		*tail=q;
		q->next=*head;
	}
	return 0;
}
//FUNCTION TO DELETE A NODE FROM THE REAR
int popback(head,tail)
struct node **head;
struct node **tail;
{
	NODEPTR q;
	q=*head;
	if(*head==NULL)//WHEN THE LIST IS EMPTY
	{
		printf("*****UNDERFLOW*****");
		return 0;
	}
	if(*head==*tail)//WHEN THE IS ONLY ONE ELEMENT
	{
		*head=*tail=NULL;
		return 0;
	}
	while(q->next!=*tail)
	q=q->next;
	q->next=*head;
	*tail=q;
	return 0;
}
//FUNCTION TO ENTER NODE AFTER A GIVEN NODE
int insafter(head,tail,prev_node,x)
struct node **head;
struct node **tail;
NODEPTR prev_node;
int x;
{
	NODEPTR q;
	q=getnode();
	q->key=x;
	q->next=prev_node->next;
	prev_node->next=q;
	if(*tail==prev_node)
	{
		*tail=q;
		q->next=*head;
	}
	return 0;
}
//FUNCTION TO PRINT THE LIST
int traverse(h,t)
struct node *h;
struct node *t;
{
	while(h!=t)
	{
		printf("->%d",h->key);
		h=h->next;
	}
	if(h!=NULL)
	printf("->%d",h->key);
	printf("\n");
	return 0;
}
//TO CALL THE RESPECTIVE FUNCTIONS AS PER USER'S CHOICE
int main()
{
	struct node *head=NULL;
	struct node *tail=NULL;
	int i=1,ch,ele,no;
	printf("1.TO PUSH AN ELEMENT IN FRONT\n");
	printf("2.TO POP THE ELEMENT IN FRONT\n");
	printf("3.TO PUSH AN ELEMENT IN BACK\n");
	printf("4.TO POP THE ELEMENT IN BACK\n");
	printf("5.TO INSERT ELEMENT AFTER A NODE\n");
	printf("6.TO TRAVERSE THE STACK\n");
	printf("7.TO STOP\n");
	while(i)
	{
		printf("Enter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter element:");
				   scanf("%d",&ele);
				   pushfront(&head,&tail,ele);
				   traverse(head,tail);
				   break;
		    case 2:popfront(&head,&tail);
				   traverse(head,tail);
				   break;
			case 3:printf("Enter element:");
				   scanf("%d",&ele);
				   pushback(&head,&tail,ele);
				   traverse(head,tail);
				   break;
			case 4:popback(&head,&tail);
				   traverse(head,tail);
				   break;
			case 5:printf("Enter the node key:");
				   scanf("%d",&no);
				   printf("Enter the element to be inserted:");
				   scanf("%d",&ele);
				   insafter(&head,&tail,find(&head,no),ele);
				   traverse(head,tail);
				   break;
			case 6:traverse(head,tail);
				   break;
			case 7:i=0;
				   break;
			default:printf("Wrong choice entered\n");
		}
	}

	return 0;
}
