//IMPLEMENTATION OF A DOUBLE ENDED QUEUE(OR DECK)
//HERE THE USER IS FREE TO ENTER OF DELETE ELMENTS FROM ANY END EITHER FRONT OR REAR
#include<stdio.h>
#define QUEUE_SIZE 100
struct dqueue{
	int front;
	int rear;
	int size;
	int items[QUEUE_SIZE];
};
struct dqueue q;
//TO ENQUE AN ELEMENT
int enqueue(pq,x)
struct dqueue *pq;
int x;
{   int ch,i;
	printf("1.To enter at back\n");
	printf("2.To enter in front\n");
	printf("Enter choice:");
	scanf("%d",&ch);
	switch(ch)
	{//TO ENQUEUE AT REAR END
		case 1:if(pq->rear==QUEUE_SIZE-1)
				{
					pq->items[(pq->rear)--]=x;
					pq->size++;
				}
				else
				if(pq->size==QUEUE_SIZE)
					printf("&&&&&&&NO MORE SPACE&&&&&&&\n");
				else
				{ //ELEMENTS ARE SHIFTED BACKWARD SO THAT THE NEW ELEMENT CAN BE QUEUED
					pq->rear--;
					for(i=(pq->rear)+1;i<QUEUE_SIZE-1;i++)
				    pq->items[i]=pq->items[i+1];
				    pq->items[i]=x;
				    pq->size++;
			    	}
			   break;
		//TO ENQUEUE AT FRONT END
		case 2:if(pq->front==-1)
				{
					pq->items[++(pq->front)]=x;
					pq->size++;
				}
				else
				if(pq->size==QUEUE_SIZE)
					printf("&&&&&&&NO MORE SPACE&&&&&&&\n");
				else
				{ //ELEMENTS ARE SHIFTED FORWARD SO THAT THE NEW ELEMENT CAN BE QUEUED
					pq->front++;
					for(i=pq->front;i>0;i--)
					pq->items[i]=pq->items[i-1];
					pq->items[i]=x;
					pq->size++;
	            		}
	            	    break;
	}
	return 0;
}
//TO DELETE AN ELEMENT FROM QUEUE
int dequeue(pq)
struct dqueue *pq;
{
	int ch,i,t;
	printf("1.To delete from front\n");
	printf("2.To delete from back\n");
	printf("Enter choice:");
	scanf("%d",&ch);
	switch(ch)
	{ //TO DELETE FROM FRONT END
		case 1:if(pq->size==0)
	        {
		        printf("*****UNDERFLOW*****");
		        return 0;
	        }
	        else
			if(pq->front==-1)
			{
				pq->rear++;
				pq->size--;
				return pq->items[pq->rear-1];
			}
			else
			{  //ELEMENTS ARE MOVED BACKWARD TO OCCUPPY THE VACATED SPACE
				t=pq->items[0];
				for(i=0;i<pq->front;i++)
				pq->items[i]=pq->items[i+1];
				pq->size--;
				pq->front--;
			    return t;
			}
			return 0;
		//TO DELETE FRON REAR END
	 case 2:if(pq->size==0)
			{
				printf("*****UNDERFLOW*****");
				return 0;
			}
			else
			if(pq->rear==QUEUE_SIZE-1)
			{
				pq->front--;
				pq->size--;
				return pq->items[pq->front+1];
			}
			else
			{	//ELEMENTS ARE MOVED FORWARD TO OCCUPPY THE VACATED SPACE
				t=pq->items[QUEUE_SIZE-1];
				for(i=QUEUE_SIZE-1;i<pq->rear;i--)
				pq->items[i]=pq->items[i-1];
				pq->rear++;
				pq->size--;
				return t;
			}
	}
	return 0;
}
//TO TRAVERSE THE QUEUE
int traverse(pq)
struct dqueue *pq;
{
	int i;
	for(i=0;i<=pq->front;i++)
	printf("->%d",pq->items[i]);
	for(i=(pq->rear)+1;i<QUEUE_SIZE;i++)
	printf("->%d",pq->items[i]);
	return 0;
}
//TO CALL RESPECTIVE FUNCTIONS AS PER USER'S CHOICE
int main()
{
	int ch,ele,i=1;
	printf("******MENU*******\n");
	printf("1.TO ENQUEUE AN ELEMENT\n");
	printf("2.TO DEQUEUE THE ELEMENT\n");
	printf("3.TO TRAVERSE THE QUEUE\n");
	printf("4.TO STOP\n");
    q.front=-1;
    q.rear=QUEUE_SIZE-1;
    q.size=0;
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
