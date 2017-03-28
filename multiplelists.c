//IMPLEMENTATION OF A DOUBLYLINKED LIST
//IN A DOUBLYLINKED LIST EACH NODE IS CONNECTED WITH THE NEXT AS WELL AS THE PREVIOUS NODE
//THIS IMPLEMENTATION HELPS IN REDUCING THE TIME FOR POPBACK OPERATION
#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
struct node{
	int key;
	struct node *next;
	struct node *prev;
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
//FUNCTION TO PUSH A NODE AT THE FRONT
int pushfront(head,tail,x)
struct node **head;
struct node **tail;
int x;
{
	NODEPTR q;
	q=getnode();
	q->key=x;
	if(*head==NULL)//WHEN THE LIST IS EMPTY
	{
		*head=*tail=q;
		q->next=NULL;
		q->prev=NULL;
	}
	else
	{
		q->next=*head;
		(*head)->prev=q;
		q->prev=NULL;
		*head=q;
	}
	return 0;
}
//FUNCTION TO POP A NODE FROM THE REAR
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
	{
		*head=*tail=NULL;}
	else
	{
		*head=(*head)->next;
		(*head)->prev=NULL;
	}
	freenode(q);
	return 0;
}
//FUNCTION TO PUSH A NODE AT THE BACK
int pushback(head,tail,x)
struct node **head;
struct node **tail;
int x;
{
	NODEPTR q;
	q=getnode();
	q->key=x;
	q->next=NULL;
	if(*head==NULL)//WHEN THE LIST IS EMPTY
	{
		*head=*tail=q;
		q->prev=NULL;
		return 0;
	}
		(*tail)->next=q;
		q->prev=*tail;
		*tail=q;
	return 0;
}
//FUNCTION TO POP THE NODE AT REAR END
int popback(head,tail)
struct node **head;
struct node **tail;
{
	NODEPTR q;
	q=*tail;
	if(*tail==NULL)//WHEN THE LIST IS EMPTY
	{
		printf("*****UNDERFLOW*****");
		return 0;
	}
	if(*head==*tail)//WHEN THERE IS A SINGLE NODE IN THE LIST
	{
		*head=*tail=NULL;
		return 0;
	}
	((*tail)->prev)->next=NULL;
	*tail=(*tail)->prev;
	freenode(q);
	return 0;
}
//FUNCTION TO INSERT A NODE AFTER A GIVEN NODE
int insafter(tail,prev_node,x)
struct node **tail;
NODEPTR prev_node;
int x;
{
	NODEPTR q;
	q=getnode();
	q->key=x;
	if(*tail==prev_node)//WHEN THE GIVEN NODE IS TAIL ITSELF
	{
		q->prev=*tail;
		q->next=NULL;
		(*tail)->next=q;
		*tail=q;
	}
	else
	{
		q->next=prev_node->next;
		(prev_node->next)->prev=q;
		q->prev=prev_node;
		prev_node->next=q;
	}
	return 0;
}
//FUNCTION TO INSERT A NODE BEFORE A GIVEN NODE
int insbefore(head,after_node,x)
struct node **head;
NODEPTR after_node;
int x;
{
	NODEPTR q;
	q=getnode();
	q->key=x;
	if(*head==after_node)//WHEN THE GIVEN NODE IS HEAD ITSELF
	{
		q->next=*head;
		q->prev=NULL;
		(*head)->prev=q;
		*head=q;
	}
	else
	{
		q->prev=after_node->prev;
		(after_node->prev)->next=q;
		q->next=after_node;
		after_node->prev=q;
	}
	return 0;
}
//FUNCTION TO PRINT THE LIST
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
//TO CALL THE RESPECTIVE FUNCTIONS AS PER USER'S CHOICE
int main()
{
	int x=1,ch,ele,no,j=SIZE,i;
	struct node *head[SIZE];
	struct node *tail[SIZE];
	while(j--)
	{
		head[j]=NULL;
		tail[j]=NULL;
	}
	printf("1.TO PUSH AN ELEMENT IN FRONT\n");
	printf("2.TO POP THE ELEMENT IN FRONT\n");
	printf("3.TO PUSH AN ELEMENT IN BACK\n");
	printf("4.TO POP THE ELEMENT IN BACK\n");
	printf("5.TO INSERT ELEMENT AFTER A NODE\n");
	printf("6.TO INSERT ELEMENT BEFORE A NODE\n");
	printf("7.TO TRAVERSE THE LIST\n");
	printf("8.TO STOP\n");
	while(x)
	{
		printf("Enter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the list no.:");
				   scanf("%d",&i);
				   printf("Enter element:");
				   scanf("%d",&ele);
				   pushfront(&head[i-1],&tail[i-1],ele);
				   traverse(head[i-1]);
				   break;
		    case 2:printf("Enter the list no.:");
				   scanf("%d",&i);
				   popfront(&head[i-1],&tail[i-1]);
				   traverse(head[i-1]);
				   break;
			case 3:printf("Enter the list no.:");
				   scanf("%d",&i);
				   printf("Enter element:");
				   scanf("%d",&ele);
				   pushback(&head[i-1],&tail[i-1],ele);
				   traverse(head[i-1]);
				   break;
			case 4:printf("Enter the list no.:");
				   scanf("%d",&i);
				   popback(&head[i-1],&tail[i-1]);
				   traverse(head[i-1]);
				   break;
			case 5:printf("Enter the list no.:");
				   scanf("%d",&i);
				   printf("Enter the  node key:");
				   scanf("%d",&no);
				   printf("Enter the element to be inserted:");
				   scanf("%d",&ele);
				   insafter(&tail[i-1],find(&head[i-1],no),ele);
				   traverse(head[i-1]);
				   break;
			case 6:printf("Enter the list no.:");
				   scanf("%d",&i);
				   printf("Enter the node key:");
				   scanf("%d",&no);
				   printf("Enter the element to be inserted:");
				   scanf("%d",&ele);
				   insbefore(&head[i-1],find(&head[i-1],no),ele);
				   traverse(head[i-1]);
				   break;
			case 7:printf("Enter list no. to traverse a particular list or 0 to print all the lists:");
				   scanf("%d",&i);
				   if(i!=0)
				   traverse(head[i-1]);
				   else
				   {
					   for(j=0;head[j]!=NULL;j++)
					   traverse(head[j]);
				   }
				   break;
			case 8:x=0;
				   break;
			default:printf("Wrong choice entered\n");
		}
	}

	return 0;
}
//END OF PROGRAM
