//TO CONVERT A GIVEN INFIX EXPRESSION TO POSTFIX EXPRESSION
#include<stdio.h>
#define STACK_SIZE 100
char pos[100];//TO STORE THE POSTFIX EXPRESSION
int k=0;
//STACK STORES THE OPERATORS FROM THE INFIX EXPRESSION
struct stack{
			int top;
			char items[STACK_SIZE];
	};
	struct stack s;
int empty(ps)
struct stack *ps;
{
	if(ps->top==-1)
	return 1;
	else
	return 0;
}
//TO PUSH AN OPERATOR
int push(ps,x)
struct stack *ps;
char x;
{
	if(ps->top==STACK_SIZE-1)
		printf("----OVERFLOW----\n");
	else
		ps->items[++(ps->top)]=x;
  return 0;
}
//THIS FUNCTION POPS THE OPERATOR AT THE TOP OF THE STACK
char pop(ps)
struct stack *ps;
{
	if(empty(ps))
	{
		printf("----UNDERFLOW----\n");
		return 0;
	}
	else
    return (ps->items[(ps->top)--]);
}
//IT RETURNS THE TOPMOST OPERATOR IN THE STACK
char top_(ps)
struct stack *ps;
{
	return ps->items[ps->top];
}
//traverse() HELPS IN KEEPING A LOOK AT THE WORKING OF THE PROBLEM
int traverse(ps)
struct stack *ps;
{
	int i;
	for(i=0;i<=ps->top;i++)
	printf("->%c",ps->items[i]);
	 printf("\n");
	return 0;
}
int isdigit(c)
char c;
{
	return (c>='0' && c<='9');
}
int isoperator(c)
char c;
{
	return (c=='+' || c=='-' || c=='*' || c=='/' || c=='%');
}
//This is the most important function since it checks and pushes or pops operators from the stack according to the priority of the operators and puts the operands into the post[]
//it compares the operator in the infix string with the operator at the top of stack
int post(ps)
char *ps;
{
	push(&s,'(');
	char d;
	char p;
	while(*(ps)!='\0')
	{
		if(isdigit(*ps))
			pos[k++]=*(ps++);
		else
		if(isoperator(*ps))
		{
			d=*ps;
		    p=top_(&s);
			if(d=='+' || d=='-')//if the operator in the exp. is + or -
			{
				     if(p=='(')
				     push(&s,*(ps++));
				     else
	          {
							pos[k++]=pop(&s);
					 		push(&s,*(ps++));
						}
			}
			else //if the operator in the exp. is / or * or %
			{
				if(p=='+' || p=='-' || p=='(') //when a low priority operator is at the top of stack or the top has paren.
					 push(&s,*(ps++));
				if(p=='*' || p=='/' || p=='%')//when a same priority operator is at the top of stack
					 {pos[k++]=pop(&s);
					 push(&s,*(ps++));}

			}
		}
		else
		if(*ps=='(')//if the character in the exp. is a left paren.
		push(&s,*(ps++));
		else
		if(*(ps++)==')')//if the character in the exp. is a right paren.
			{
				while(top_(&s)!='(')//the top operator sare popped until a left paren. is encountered
				{
					pos[k++]=pop(&s);
			  }
				pop(&s);

			}
		traverse(&s);//to check the working
	}
	return 0;
}
int main()
{
	s.top=-1;
	int i=0;
	char str[STACK_SIZE];
	char *st;
	printf("ENTER THE INFIX EXPRESSION:");
	scanf("%s",str);
	while(str[i++]!='\0');
	str[i-1]=')';
	str[i]='\0';
	st=str;
	post(st);
	printf("POSTFIX EXPRESSION:%s\n",pos);
	return 0;
}
//END OF PROGRAM
