//EVALUATION OF POSTFIX EXPRESSION
#include<stdio.h>
#define STACK_SIZE 100
int f=0;
struct stack{
			int top;
			float items[STACK_SIZE];
	};
	struct stack s;
//TO CHECK WHETHER THE FUNCTION IS EMPTY
int empty(ps)
struct stack *ps;
{if(ps->top==-1)
	return 1;
	else
	return 0;
}
//TO PUSH OPERAND INTO THE STACK
float push(ps,x)
struct stack *ps;
float x;
{
	if(ps->top==STACK_SIZE-1)
		printf("----OVERFLOW----\n");
	else
		ps->items[++(ps->top)]=x;
return 0;
}
//TO POP OPERAND FROM STACK
float pop(ps)
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
//TO LOOK INTO THE WORKING OF THE EVALUATION
int traverse(ps)
struct stack *ps;
{int i;
	for(i=0;i<=ps->top;i++)
	printf("->%0.1f",ps->items[i]);
    printf("\n");
	return 0;
}
//TO GET THE RESULT AFTER OPERATION ON THE POPPED OPERANDS
float oper(symb,op1,op2)
char symb;
float op1;
float op2;
{
	switch(symb)
	{
		case '+':return op1+op2;
		case '-':return op1-op2;
		case '*':return op1*op2;
		case '/':return op1/op2;
		default:printf("ILLEGAL\n");
				f=1;
	}
	return 0;
}
int isdigit(c)
char c;
{
	return (c>='0' && c<='9');
}
//FUNCTION TO CHECK WHETHER IT IS A OPERATOR OR OPERAND THEN PUSH IF IT IS A OPERAND ELSE POP 2 TIMES IF OPERATOR IS ENCOUNTERED AND THEN PUSH THE RESULT
float eval(ps)
char *ps;
{
	float opnd1,opnd2,value;
	while(*ps!='\0')
	{
		if(isdigit(*ps))//CHECKS FOR OPERAND
			{push(&s,(float)(*(ps++)-'0'));//PUSHES THE OPERAND
				traverse(&s);
			}
		else
		{
			opnd2=pop(&s);
			opnd1=pop(&s);
			value=oper(*(ps++),opnd1,opnd2);//CALLS oper()
			push(&s,value);
		}

	}
	return pop(&s);
}

int main()
{   s.top=-1;
	float res;
	char str[STACK_SIZE];
	char *st;
	printf("ENTER THE POSTFIX EXPRESSION:");
	scanf("%s",str);
	st=str;
	res=eval(st);
	if(f==1 || s.top!=-1) //TO CHECK IF THE USER HAS GIVEN ANY INAPPROPRIATE FORM OF POSTFIX EXPRESSION
		printf("WRONG EXPRESSION\n");
	else
		printf("RESULT:%0.2f\n",res);
	return 0;
}
