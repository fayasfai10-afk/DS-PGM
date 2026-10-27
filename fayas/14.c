#include <stdio.h>

#define MAX 5

int queue[MAX];
int front=-1 , rear=-1;

void enqueue(int value)
{
	if(front == (rear+1) %MAX)
	{
		printf("queue overflow\n");
		return;
	}
	if(front==-1)
	{
		front=rear=0;
	}else{
		rear=(rear+1)%MAX;
	}
	queue[rear]=value;
	printf("%d inserted element to the queue\n",value);
}	
void dequeue()
{
	int value;
	if(front==-1)
	{
		printf("stack underflow\n");
		return;
	}
	value=queue[front];
	if(front==rear)
	{
		front=rear=-1;
	}
	else
	{
		front=(front+1)%MAX;
	}
	printf("%d deleted from the queue\n",value);	
}	
			
void display()
{
	int i;
	if(front==-1)
	{
		printf("queue is empty\n");
		return;
	}
		printf("circluar queue.\n");
		i=front;
	while(1)
	{
		printf("%d",queue[i]);
		if(i==rear)
			break;
		i=(i+1)%MAX;
		}
}

int main()
{
	int choice,val;
	
	while(1)
	{
	printf("..circluar queue..\n");
	printf("1.enqueue\n");
	printf("2.dequeue\n");
	printf("3.display\n");
	printf("exit\n");
	printf("enter your choice:\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			printf("enter the value:");
			scanf("%d",&val);
			enqueue(val);
			break;
		case 2:
			dequeue();
			break;	
		case 3:
			display();
			break;
		case 4:
			return 0;
		default:
			printf("invalid choice\n	");
		}
	}					
return 0;
}	
	
			
				
