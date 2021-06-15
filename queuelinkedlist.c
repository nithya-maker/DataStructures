//B171381
//Implementation of queue using linkedlist

#include<stdio.h>
#include<stdlib.h>
struct node{
	int e;
	struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void enqueue(int ele)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->e=ele;
	newnode->next=NULL;
	if(rear==NULL && front==NULL)
	{
		front=rear=newnode;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
}
void display()
{
	struct node *temp=front;
	if(rear==NULL && front==NULL)
		printf("queue is empty\n");
	else
	{
		while(temp!=NULL)
		{
			printf("%d\n",temp->e);
			temp=temp->next;
		}
	}
}
void dequeue()
{
	struct node *temp;
	if(front==NULL)
		printf("queue is empty\n");
	else
	{
		temp=front;
		front=front->next;
		free(temp);
	}

}
void main()
{
	int ele,op=1,ch;
	while(op==1)
	{
		printf("1-enqueue\n2-dequeue\n3-display\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("Enter element\n");
			scanf("%d",&ele);
			enqueue(ele);
			break;
			case 2:
			dequeue();
			break;
			case 3:
			display();
			break;
			default:
			printf("Enter valid option\n");
		}
		printf("Enter 1 to continue 0 to stop\n");
		scanf("%d",&op);

	}

}
