//IMPLEMENTATION OF LINKED LIST
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
//FUNCTION TO PUSH A NODE AT THE FRONT
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
	if(*tail==NULL)//WHEN THE LIST WAS EMPTY
	*tail=q;
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
	*head=*tail=NULL;
	else
	*head=(*head)->next;
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
	*head=*tail=q;
	else
	{
		(*tail)->next=q;
		*tail=q;
	}
	return 0;
}
//FUNCTION TO POP THE NODE AT REAR END
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
	if(*head==*tail)//WHEN THERE IS A SINGLE NODE IN THE LIST
	{
		*head=*tail=NULL;
		return 0;
	}
	while((q->next)->next!=NULL)
	q=q->next;
	q->next=NULL;
	*tail=q;
	return 0;
}
//FUNCTION TO POP 
int pop(head,tail,n)
struct node **head;
struct node **tail;
NODEPTR n;
{
	NODEPTR p;
	if(*head==NULL)//WHEN THE LIST IS EMPTY 
	{
		printf("*****UNDERFLOW*****\n");
		return 0;
	}
	if(*head==n)//WHEN THE GIVEN NODE IS AT FRONT
	{
		popfront(head,tail);
		return 0;
	}
	if(*tail==n)//WHEN THE GIVEN NODE IS AT BACK
	{
		popback(head,tail);
		return 0;
	}
	if(*head==*tail)//WHEN THERE IS ONLY ONE ELEMENT
	{
		*head=*tail=NULL;
		return 0;
	}
	p=*head;
	while(p->next!=n)//TO FIND THE PREVIOUS NODE
	p=p->next;
	p->next=n->next;
	freenode(n);
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
	q->next=prev_node->next;
	prev_node->next=q;
	if(*tail==prev_node)
	*tail=q;
	return 0;
}
//FUNCTION TO SORT THE LIST
int sort(head,tail)
struct node **head;
struct node **tail;
{
	NODEPTR h;
	h=*head;
	int size=0,arr[100],i,j,s;
	while(h!=NULL)
	{
		arr[size++]=h->key;
		h=h->next;
	}
	//INSERTION SORT
	for(i=1;i<size;i++)
	{
		s=arr[i];
		j=i-1;
		//EACH ELEMENT ENTERS INTO SOMEWHAT A SORTED ARRAY AND IS PLACED AT PROPER INDEX
		while(j>=0 && arr[j]>s)
		{//ELEMENTS ARE MOVED ONE INDEX AHEAD TO MAKE A GAP FOR THE INCOMING ELEMENT
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=s;
	}
	//THE LIST IS EMPTIED FIRST
	for(i=0;i<size;i++)
	popfront(head,tail);
	//THE LIST IS UPDATED
	for(i=0;i<size;i++)
	pushback(head,tail,arr[i]);
	return 0;
} 
//FUNCTION TO REVERSE THE LIST
int reverse(head,tail)
struct node **head;
struct node **tail;
{
	NODEPTR h;
	h=*head;
	int size=0,arr[100],i;
	while(h!=NULL)
	{
		arr[size++]=h->key;
		h=h->next;
	}
	//THE LIST IS EMPTIED FIRST
	for(i=0;i<size;i++)
	popfront(head,tail);
	//THE NODES ARE INSERTED AT FRONT TO REVERSE THE SEQUENCE
	for(i=0;i<size;i++)
	pushfront(head,tail,arr[i]);
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
	struct node *head=NULL;
	struct node *tail=NULL;
	int i=1,ch,ele,no;
	printf("1.TO PUSH AN ELEMENT IN FRONT\n");
	printf("2.TO POP THE ELEMENT IN FRONT\n");
	printf("3.TO PUSH AN ELEMENT IN BACK\n");
	printf("4.TO POP THE ELEMENT IN BACK\n");
	printf("5.TO INSERT ELEMENT AFTER A NODE\n");
	printf("6.TO POP A NODE FROM ANY POSITION\n");
	printf("7.TO ARRANGE THE LIST\n");
	printf("8.TO REVERSE THE LIST\n");
	printf("9.TO TRAVERSE THE LIST\n");
	printf("10.TO STOP\n");
	while(i)
	{
		printf("Enter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter element:");
			       scanf("%d",&ele);
			       pushfront(&head,&tail,ele);
			       traverse(head);
			       break;
		    	case 2:popfront(&head,&tail);
			       traverse(head);
		               break;
			case 3:printf("Enter element:");
			       scanf("%d",&ele);
			       pushback(&head,&tail,ele);
		               traverse(head);
			       break;
			case 4:popback(&head,&tail);
			       traverse(head);
			       break;
			case 5:printf("Enter the node key:");
			       scanf("%d",&no);
			       printf("Enter the element to be inserted:");
			       scanf("%d",&ele);
			       insafter(&tail,find(&head,no),ele);
			       traverse(head);
			       break;
			case 6:printf("Enter the node to be popped:");
			       scanf("%d",&no);
			       pop(&head,&tail,find(&head,no));
			       traverse(head);
			       break;
			case 7:sort(&head,&tail);
			       printf("LIST AFTER BEING SORTED:\n");
			       traverse(head);
			       break;
			case 8:reverse(&head,&tail);
			       printf("LIST REVERSED:\n");
			       traverse(head);
			       break;
			case 9:traverse(head);
			       break;
			case 10:i=0;
			       break;
			default:printf("Wrong choice entered\n");
		}
	}

	return 0;
}
//END OF PROGRAM
