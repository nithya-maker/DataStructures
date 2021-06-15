//B171381
//Implementation of Binarysearchtree

#include<stdio.h>
#include<stdlib.h>
struct tnode
{
	struct tnode *left;
	int e;
	struct tnode *right;
};
struct tnode *root=NULL;
struct queue
{
	struct tnode * a[32];
	int front,rear,sz;
};
void enqueue(struct queue *q,struct tnode *t)
{
	if(q->rear==q->sz-1)
		printf("queue is full\n");
	else
	{
		q->rear++;
		q->a[q->rear]=t;
	}
}
struct tnode * dequeue(struct queue *q){

	if(q->rear==q->front)
		printf("queue is empty\n");
	else
	{
		q->front++;
		return q->a[q->front];
	}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
}
void insert(int ele)
{
	struct tnode *temp;
	struct tnode *newnode;
	newnode=(struct tnode*)malloc(sizeof(struct tnode));
	newnode->e=ele;
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL)
	{
		root=newnode;
	}
	else
	{
		struct queue *q;
		temp=root;
		q->rear=q->front=-1;
		q->sz=31;
		enqueue(q,temp);
		while(1)
		{
			temp=dequeue(q);
			//temp=q.a[q.front];
			//printf("%d %d\n",q.rear,q.front);
			if(temp->left!=NULL){
				enqueue(q,temp->left);
			}
			else
				break;
			if(temp->right!=NULL){
				enqueue(q,temp->right);
			}
			else
				break;
		}
		//printf("%d %d\n",q.rear,q.front );
		if(temp->left==NULL)
			temp->left=newnode;
		else
			temp->right=newnode;
	}

}
int isempty(struct queue *q)
{
	if(q->rear==q->front)
		return 1;
	else
		return 0;
}
void display()
{
	struct tnode *temp1;
	struct queue *q;
	q=(struct queue *)malloc(sizeof(struct queue));
	temp1=root;
	q->rear=q->front=-1;
	q->sz=31;
	enqueue(q,temp1);
	while(!(isempty(q)))
	{
		temp1=dequeue(q);
		if(temp1->left!=NULL)
			enqueue(q,temp1->left);
		if(temp1->right!=NULL)
			enqueue(q,temp1->right);
		printf("%d %u\n",temp1->e,temp1);
	}
}
void count()
{
		int c=0;
		struct tnode *temp1;
		struct queue *q;
		q=(struct queue *)malloc(sizeof(struct queue));
		temp1=root;
		q->rear=q->front=-1;
		q->sz=31;
		enqueue(q,temp1);
		while(!(isempty(q)))
		{
			temp1=dequeue(q);
			if(temp1->left!=NULL)
				enqueue(q,temp1->left);
			if(temp1->right!=NULL)
				enqueue(q,temp1->right);
			c++;
		}
		printf("No of element are %d\n",c);
}
int search(int ele)
{
	int flag=0;
	struct tnode *temp1;
	struct queue *q;
	q=(struct queue *)malloc(sizeof(struct queue));
	temp1=root;
	q->rear=q->front=-1;
	q->sz=31;
	enqueue(q,temp1);
	while(!(isempty(q)))
	{
		temp1=dequeue(q);
		if(temp1->left!=NULL)
			enqueue(q,temp1->left);
		if(temp1->right!=NULL)
			enqueue(q,temp1->right);
		if(temp1->e==ele)
		{
			flag=1;
			return 1;
			//printf("%d Element found\n",temp1->e);
		}
	}
	if(flag==0)
		return 0;
		//printf("Element not found\n");
}
struct tnode * find(int ele)
{

	struct tnode *temp=root;
	struct queue *q;
	q=(struct queue *)malloc(sizeof(struct queue));
	q->rear=q->front=-1;
	q->sz=11;
	enqueue(q,temp);
	while(!(isempty(q)))
	{
		temp=dequeue(q);
		if(temp->left!=NULL)
			enqueue(q,temp->left);
		if(temp->right!=NULL)
			enqueue(q,temp->right);
		if(ele==temp->e){
			return temp;
		}
	}
}
struct tnode * lastnode()
{
	struct tnode *temp=root;
	struct queue *q;
	q=(struct queue *)malloc(sizeof(struct queue));
	q->rear=q->front=-1;
	q->sz=11;
	enqueue(q,temp);
	while(!(isempty(q)))
	{
		temp=dequeue(q);
		if(temp->left!=NULL)
			enqueue(q,temp->left);
		if(temp->right!=NULL)
			enqueue(q,temp->right);
	}
	return temp;
}
struct tnode * parent(struct tnode *temp1)
{
	struct tnode *temp=root;
	struct queue *q;
	q=(struct queue *)malloc(sizeof(struct queue));
	q->rear=q->front=-1;
	q->sz=11;
	enqueue(q,temp);
	while(!(isempty(q)))
	{
		temp=dequeue(q);
		if(temp->left==temp1)
			return temp;
		else{
			if(temp->left!=NULL)
				enqueue(q,temp->left);
		}
		if(temp->right==temp1)
			return temp;
		else{
			if(temp->right!=NULL)
				enqueue(q,temp->right);
		}
	}		
}
void deletion(int ele)
{
	struct tnode * temp;
	struct tnode * temp1;
	struct tnode * temp2;
	temp=find(ele);
	temp1=lastnode();
	temp2=parent(temp1);
	temp->e=temp1->e;
	if(temp2->left==temp1)
		temp2->left=NULL;
	else
		temp2->right=NULL;
}
void main()
{
	int ch,op=1,ele;
	do
	{
		printf("1:insert\n2:display\n3:count\n4:search\n5:deletion\n6:exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter element:\n");
				scanf("%d",&ele);
				insert(ele);
				break;
			case 2:
				display();
				break;
			case 3:
				count();
				break;
			case 4:
				printf("Enter ur searching element:\n");
				scanf("%d",&ele);
				if(search(ele))
				{
					printf("Element found %d\n",ele);
				}
				else
					printf("Element not found\n");
				break;
			case 5:
				printf("Enter ur deletion element:\n");
				scanf("%d",&ele);
				deletion(ele);
				break;
			case 6:
				break;
			default:
				printf("Enter valid option\n");
		}
	}while(ch!=6);
}

