//IMPLEMENTATION OF LINEAR QUEUE
//A LINEAR QUEUE IS A SIMPLE IMPLEMENTATION OF QUEUE USING ARRAYS IN WHICH THE QUEUE ONCE FILLED CANNOT BE REUSED AFTER VACANCIES ARE CREATED
//IT JUST OPERATES THE ENTRY AND EXIT WITHOUT ANY ROTATION
#include<stdio.h>
#define QUEUE_SIZE 100
struct lqueue{
	int front;
	int rear;
	int items[QUEUE_SIZE];
};
struct lqueue q;
//CHECKS IF THE QUEUE IS EMPTY
int empty(pq)
struct lqueue *pq;
{
	if(pq->front==pq->rear)
	return 1;
	else
	return 0;
}
//ENTERS AN ELEMENT TO THE END OF QUEUE
int enqueue(pq,x)
struct lqueue *pq;
int x;
{
	if(pq->rear==QUEUE_SIZE-1)
		printf("*****OVERFLOW*****");
	else
	  pq->items[++(pq->rear)]=x;
	return 0;
}
//DELETES THE ELEMENT IN THE FRONT OF QUEUE
int dequeue(pq)
struct lqueue *pq;
{
	if(empty(pq))
	{
		printf("*****UNDERFLOW*****");
		return 0;
	}
	else
		return pq->items[++(pq->front)];

}
//PRINTS THE ELEMENTS OF THE QUEUE
int traverse(pq)
struct lqueue *pq;
{
	int i;
	for(i=(pq->front)+1;i<=pq->rear;i++)
	printf("->%d",pq->items[i]);
	return 0;
}
//TO CALL THE RESCPECTIVE FUNCTION AS PER THE USER'S CHOICE
int main()
{
	int ch,ele,i=1;
	printf("******MENU*******\n");
	printf("1.TO ENQUEUE AN ELEMENT\n");
	printf("2.TO DEQUEUE THE ELEMENT\n");
	printf("3.TO TRAVERSE THE QUEUE\n");
	printf("4.TO STOP\n");
    q.front=q.rear=-1;
	while(i)
	{
		printf("\nEnter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the element:");
			       scanf("%d",&ele);
			       enqueue(&q,ele);
			       traverse(&q);
			       break;
			case 2:dequeue(&q);
		         traverse(&q);
		         break;
		  case 3:traverse(&q);
	           break;
			case 4:i=0;
		         break;
		}
	}
return 0;
}
//END OF PROGRAM
