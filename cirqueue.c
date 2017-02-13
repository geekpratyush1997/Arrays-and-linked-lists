//IMPLEMENTATION OF CIRCULAR QUEUE
// A circular queue is implemented in array to use the space that gets vacated by exit of elements(!there is no circular queue concept present in real world i.e. a queue cannot be circular)
#include<stdio.h>
#define QUEUE_SIZE 100
int f;
struct cqueue{
	int front;
	int rear;
	int items[QUEUE_SIZE];
};
struct cqueue q;
//To check if the queue is empty
int empty(pq)
struct cqueue *pq;
{
	if(pq->front==pq->rear)
	return 1;
	else
	return 0;
}
//To enter an element into the queue
int enqueue(pq,x)
struct cqueue *pq;
int x;
{
	if(pq->rear==QUEUE_SIZE-1)
		pq->rear=0;
	else
		(pq->rear)++;
	if(pq->rear==pq->front)
		{
			f=1;
			pq->rear--;
			printf("*****OVERFLOW*****\n");
			return 0;
		}
	pq->items[pq->rear]=x;
	return 0;
}
//To remove an element from the queue
int dequeue(pq)
struct cqueue *pq;
{
	if(empty(pq) && f!=1)
	{
		printf("*****UNDERFLOW*****");
		return 0;
	}
	if(pq->front==QUEUE_SIZE-1)
		pq->front=0;
	else
	    (pq->front)++;
	return pq->items[pq->front];
}
//Here the traverse is a bit different from the others since we cannot move in a linear array,we have a front and would need to rotate at end position to reach upto the rear
int traverse(pq)
struct cqueue *pq;
{
	int i;
	for(i=(pq->front);i!=pq->rear;)
	{
		if(i==QUEUE_SIZE-1)//when the last memory is encountered
			i=0;
		else
			i++;
		printf("->%d",pq->items[i]);
	}

	return 0;
}
//TO CALL THE RESPECTIVE FUNCTION AS PER USER'S CHOICE
int main()
{
	int ch,ele,i=1;
	printf("******MENU*******\n");
	printf("1.TO ENQUEUE AN ELEMENT\n");
	printf("2.TO DEQUEUE THE ELEMENT\n");
	printf("3.TO TRAVERSE THE QUEUE\n");
	printf("4.TO STOP\n");
    q.front=q.rear=QUEUE_SIZE-1;
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
				     f=0;
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
