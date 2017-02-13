//IMPLEMENTATION OF QUEUE
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
//FUNCTION TO ENQUEUE AN ELEMENT AT THE END OF THE QUEUE
int enqueue(head,tail,x)
struct node **head;
struct node **tail;
int x;
{
	NODEPTR q;
	q=getnode();
	q->key=x;
	q->next=NULL;
	if(*head==NULL)//WHEN THE QUEUE IS EMPTY
	*head=*tail=q;
	else
	{
		(*tail)->next=q;
		*tail=q;
	}
	return 0;
}
//FUNCTION TO REMOVE AN ELEMENT FRON TH EFRONT OF QUEUE
int dequeue(head,tail)
struct node **head;
struct node **tail;
{
	NODEPTR q;
	q=*head;
	if(*head==NULL)//WHEN THE QUEUE HAS NO ELEMENT
	{
		printf("*****UNDERFLOW*****");
		return 0;
	}
	if(*head==*tail)//WHEN THE QUEUE HAS ONLY ONE ELEMENT
	*head=*tail=NULL;
	else
	*head=(*head)->next;
	freenode(q);
	return 0;
}
//FUNCTION TO PRINT THE QUEUE
int traverse(h)
struct node *h;
{
	while(h!=NULL)
	{
		printf("->%d",h->key);
		h=h->next;
	}
	printf("\n");
	return 0;
}
//FUNCTION TO CALL RESPECTIVE FUNCTIONS AS PER USER'S CHOICE
int main()
{
	struct node *head=NULL;
	struct node *tail=NULL;
	int i=1,ch,ele;
	printf("1.TO ENQUEUE AN ELEMENT\n");
	printf("2.TO DEQUEUE AN ELEMENT\n");
	printf("3.TO TRAVERSE THE QUEUE\n");
	printf("4.TO STOP\n");
	while(i)
	{
		printf("Enter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter element:");
				   scanf("%d",&ele);
				   enqueue(&head,&tail,ele);
				   traverse(head);
				   break;
		    case 2:dequeue(&head,&tail);
				   traverse(head);
				   break;
			case 3:traverse(head);
				   break;
			case 4:i=0;
				   break;
			default:printf("Wrong choice entered\n");
		}
	}

	return 0;
}
