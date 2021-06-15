//B171381
//Implementation of linkedlist without using functions

#include<stdio.h>
#include<stdlib.h>
struct node{
	int e;
	struct node *next;
};
void main(){
	struct node *head;
	struct node n[10];
	int ele;
	/*int ele;
	printf("Enter element:");
	scanf("%d",&ele);
	n.e=ele;
	n.next=NULL;
	head=&n;
	//printf("%d\n",head->e/n.e(element));printf("%d\n",n.next/head.next(NULL));
	*/
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
	//HEAD INSERTION
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	int element;
	printf("Enter HEAD INSERTION element");
	scanf("%d",&element);
	temp->e=element;
	temp->next=head;
	head=temp;	
	//TAIL INSERTION
	struct node *tmp=head;
	while(tmp->next!=NULL){
		tmp=tmp->next;
	}
	struct node *nn;//nn=newnode
	nn=(struct node *)malloc(sizeof(struct node));
	int el;
	printf("Enter ur TAIL INSERTION element");
	scanf("%d",&el);
	nn->e=el;
	nn->next=NULL;
	tmp->next=nn;
	//MIDDLE INSERTION
	int pos,elem;
	int c=0;
	printf("Enter ur INSERTION position");
	scanf("%d",&pos);
	printf("Enter ur element");
	scanf("%d",&elem);
	struct node *t=head;//t=temporary
	while(c<(pos-1)){
		if(t->next!=NULL){
			t=t->next;
		}
		else{
			printf("INSERTION is not possible");
		}
		c++;
	}
	//PRINTING LINKEDLIST ELEMENTS
	struct node *newn;//newn=newnode
	newn=(struct node *)malloc(sizeof(struct node));
	newn->e=elem;
	newn->next=temp->next;
	temp->next=newn;
	
	//HEAD AND TAIL DELETION
	printf("Enter 1 for head DELETION and  for TAIL DELETION");
	int f;
	scanf("%d",&f);
	if(f==1){
		head=head->next;
	}
	else{
		struct node *del=head;
		struct node *prevnode;
		while(del->next!=NULL){
			prevnode=del;
			del=del->next;
		}
		if(head==del){
			head=NULL;
		}
		else{
			prevnode->next=NULL;
		}
	}
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
	pre->next=tempo->next;
	struct node *h=head;
	while(h!=0){
		printf("%d\n",h->e);
		h=h->next;
	}	
}
