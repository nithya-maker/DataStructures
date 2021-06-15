//B171381
//Implementation of linkedlist using functions

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
	int e;
	struct node *next;
};
struct node *temp;
inserthead(struct node *head)
{
	struct node *newnode;
	int ele;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter head insertion element");
	scanf("%d",&ele);
	newnode->e=ele;
	newnode->next=head;
	head=newnode;
	printf("****Result****\n");
	temp=head;
	while(temp!=NULL){
		printf("%d\n",temp->e);
		temp=temp->next;
	}
}
inserttail(struct node *head)
{
	struct node *te;
	te=head;
	struct node *nn;
	int el;
	while(te->next!=NULL)
	{
		te=te->next;
	}
	nn=(struct node *)malloc(sizeof(struct node));
	printf("Enter tail insertion element");
	scanf("%d",&el);
	nn->e=el;
	nn->next=NULL;
	te->next=nn;
	printf("****Result****\n");
	temp=head;
	while(temp!=NULL){
		printf("%d\n",temp->e);
		temp=temp->next;
	}
}
insertmiddle(struct node *head)
{
	//struct node *temp=head;
	temp=head;
	struct node *newnode;
	int pos,ele,c=0;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter insertion position\n");
	scanf("%d",&pos);
	while(c<pos-1)
	{
		if(temp->next!=NULL)
		{
			temp=temp->next;
		}
		else
		{
			printf("Inserton is not possbile\n");
		}
		c++;
	}
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter element\n");
	scanf("%d",&ele);
	newnode->e=ele;
	newnode->next=temp->next;
	temp->next=newnode;
	printf("****Result****\n");
	temp=head;
	while(temp!=NULL){
		printf("%d\n",temp->e);
		temp=temp->next;
	}
}
deletehead(struct node *head)
{
	head=head->next;
	printf("****Result****\n");
	temp=head;
	while(temp!=NULL){
		printf("%d\n",temp->e);
		temp=temp->next;
	}
}
deletetail(struct node *head)
{
	struct node *prenode;
	temp=head;
	while(temp->next!=0)
	{
		prenode=temp;
		temp=temp->next;
	}
	prenode->next=NULL;
	printf("****Result****\n");
	temp=head;
	while(temp!=NULL){
		printf("%d\n",temp->e);
		temp=temp->next;
	}
}
deletemiddle(struct node *head)
{
	struct node *tempo=head;
	struct node *pre;
	int u=1,po;
	printf("Enter MIDDLE DELETION position");
	scanf("%d",&po);
	while(u<po){
		pre=tempo;
		tempo=tempo->next;
		u++;
	}
	if(po==1){
		head=head->next;
	}
	else{
		pre->next=tempo->next;
	}
	printf("****Result****\n");
	temp=head;
	while(temp!=NULL){
		printf("%d\n",temp->e);
		temp=temp->next;
	}
}
void main()
{
	struct node *head=NULL;
	int ele;
	printf("Enter linked list elem1ents\n");
	/*struct node *nod;
	int op;
	nod=(struct node *)malloc(sizeof(struct node));
	printf("Enter elements");
	scanf("%d",&ele);
	nod->e=ele;
	nod->next=NULL;
	head=nod;
	for(int j=1;j<5;j++){
		printf("Enter elements");
		scanf("%d",&ele);
		nod->e=ele;
		nod->next=NULL;
	}*/
	struct node n[5];
	int op;
	printf("Enter element:");
	scanf("%d",&ele);
	n[0].e=ele;
	n[0].next=NULL;
	head=&n[0];
	//printf("%d\n",head);
	for (int j=1;j<5;j++){
		printf("Enter element:");
		scanf("%d",&ele);
		n[j].e=ele;
		n[j].next=NULL;
		n[j-1].next=&n[j];
		//printf("%d\n",&n[j]);
	}
	int flag;
	do
	{
		printf("Enter \"1\" for continue and \"0\"for exit" );
		scanf("%d",&flag);
		if(flag){
			printf("OPERATIONS\n1:head insertion\n2:tail insertion\n3:middle insertion\n4:head deletion\n5:tail deletion\n6:middle deletion......\n");
			scanf("%d",&op);
			switch(op)
			{
				case 1:
				inserthead(head);
				break;
				case 2:
				inserttail(head);
				break;
				case 3:
				insertmiddle(head);
				break;
				case 4:
				deletehead(head);
				break;
				case 5:
				deletetail(head);
				case 6:
				deletemiddle(head);
				break;
				default:
				printf("Enter valid option\n");
			}
		}
		else
		{
			break;
		}
		
	}while(1);
}
