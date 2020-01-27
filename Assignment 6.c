#include "stdio.h"
#define SIZE 2
enum options{EXIT,ENQUEUE,DEQUEUE,DISPLAY};
enum subject{ENG=0,MATH,SCIENCE};

typedef struct 
{
	int id;
	char name[20];
	int sub[3];
}DATA;

typedef struct
{
	int front;
	int rear;
	DATA stud[SIZE];
}QUEUE;

void init(QUEUE *q)
{
	q->front = -1;
	q->rear = -1;

	for(int i=0;i<SIZE;i++)
	{
		q->stud[i].id = -1;
	}
}

// Checking the queue is full or not
int isFull(QUEUE *q)
{
	return (q->front==0) && (q->rear == SIZE-1) || (q->front == q->rear+1)?1:0;
}

// Checking the queue is empty or not
int isEmpty(QUEUE *q)
{
	return (q->front == -1) && (q->rear == -1)?1:0;
}

// Collecting DATA from user
void collectData(QUEUE *q)
{

	printf("Enter ID\n");
	scanf("%d",&q->stud[q->rear].id);

	printf("Enter Name\n");
	scanf("%s",q->stud[q->rear].name);

	printf("Enter English marks\n");
	scanf("%d", &q->stud[q->rear].sub[ENG]);

	printf("Enter Math marks\n");
	scanf("%d", &q->stud[q->rear].sub[MATH]);

	printf("Enter Science marks\n");
	scanf("%d", &q->stud[q->rear].sub[SCIENCE]);
}

void enqueue(QUEUE *q)
{
	if(q->front == -1)
	{
		q->front = 0;
	}

	if(q->rear == SIZE-1)
	{
		q->rear = 0;
	}
	else
	{
		q->rear += 1;
	}

}

// Deleting element from queue
void dequeue(QUEUE *q)
{
	if(q->front == q->rear)
	{
		q->front = -1;
		q->rear = -1;
	}
	else
	{
		if(q->front == SIZE-1)
		{
			q->front = 0;
		}
		else
		{
			q->front += 1;
		}
	}

}


int getOption()
{
	enum options op;

	printf("0. EXIT\n1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n");
	printf("Enter Your choice\n");
	scanf("%d",&op);

	return op;
}


void display(DATA d)
{
	printf("=======================\n");

	printf("ID : %d\n", d.id);
	printf("NAME : %s\n", d.name);
	printf("ENGLISH\t\tMATHS\t\tSCIENCE\n");
	printf("%5d",d.sub[ENG]);
	printf("%15d",d.sub[MATH]);
	printf("%15d",d.sub[SCIENCE]);
	printf("\n");
	printf("========================\n");
}
int main()
{
	QUEUE q;

	init(&q);

	int op;


	while(op = getOption())
	{
		switch(op)
		{
			case ENQUEUE:
				if(!isFull(&q))
				{
					enqueue(&q);

					collectData(&q);
				}
				else
				{
					printf("**********************QUEUE IS FULL********************\n");
				}
				break;

			case DEQUEUE:
				if(!isEmpty(&q))
				{
					q.stud[q.front].id = -1;
					dequeue(&q);
					
				}
				else
				{
					printf("-----------------------QUEUE IS EMPTY-------------------\n");
				}
				break;
			case DISPLAY:
				if(!isEmpty(&q))
				{
					for(int i=0;i<SIZE;i++)
					{
						if(q.stud[i].id != -1)
						{
							display(q.stud[i]);
						}
					}
				}
				else
				{
					printf("-----------------------QUEUE IS EMPTY-------------------\n");
				}

				break;
			default:
				printf("Invalid Choice\n");
				break;
		}

	}
}