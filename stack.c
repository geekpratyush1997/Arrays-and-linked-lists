//STACK OPERATIONS USING ARRAY
#include<stdio.h>
#define STACK_SIZE 100
struct stack{
			int top;
			int items[STACK_SIZE];
	};
	struct stack s;
//TO CHECK WHETHER THE STACK IS EMPTY
int empty(ps)
struct stack *ps;
{if(ps->top==-1)
	return 1;
	else
	return 0;
}
//TO ENTER AN ELEMENT INTO THE STACK
int push(ps,x)
struct stack *ps;
int x;
{
	if(ps->top==STACK_SIZE-1)  //TO CHECK IF THE STACK IS FULL
	printf("----OVERFLOW----\n");
else
		ps->items[++(ps->top)]=x;
return 0;
}
//TO DELETE AN ELEMENT FROM THE STACK
int pop(ps)
struct stack *ps;
{if(empty(ps))
	{printf("----UNDERFLOW----\n");
		return 0;}
else
    return (ps->items[(ps->top)--]);
}
//TO PRINT THE CURRENT STATE OF THE STACK
int traverse(ps)
struct stack *ps;
{int i;
	for(i=0;i<=ps->top;i++)
	printf("->%d",ps->items[i]);

	return 0;
}
//THE main() FUNCTIONS CALLS THE DIFFERENT SUB-FUNCTIONS ACCORDING TO THE USER'S REQUEST
int main()
{int ch,ele,i=1;
	printf("******MENU*******\n");
	printf("1.TO PUSH AN ELEMENT\n");
	printf("2.TO POP THE ELEMENT\n");
	printf("3.TO TRAVERSE THE STACK\n");
	printf("4.TO STOP\n");
	s.top=-1;
	while(i)
	{printf("\nEnter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the element:");
			     scanf("%d",&ele);
			     push(&s,ele);
			     traverse(&s);
			     break;
		    	case 2:pop(&s);
		               traverse(&s);
		               break;
		        case 3:traverse(&s);
		               break;
		        case 4:i=0;
		               break;
		}
	}
return 0;
}
//END OF THE PROGRAM
