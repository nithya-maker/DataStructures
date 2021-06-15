//B171381
//Implementation of queue using doublelinkedlist



#include<stdio.h>
#include<stdlib.h>
struct node 
{
  int data;
  struct node *next,*prev;
};
struct node *front=NULL;
struct node *rear=NULL;
void enqueue(int ele);
void dequeue();
void display();
void main()
{
  int ch,ele;
  printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
  while(1)
 {
   printf("enter your choice:");
  scanf("%d",&ch);
  switch(ch)
   {
     case 1:
      {
         printf("enter the element to be inserted:");
         scanf("%d",&ele);
         enqueue(ele);
         break;
      }
      case 2:
       {
          dequeue();
          break;
       }
     case 3:
     {
        printf("\t\tTHE QUEUE IS\t\t\n");
        display();
        break;
     }
   case 4:
     {
        break;
     }
    default:
     {
        printf("invalid choice\n");
        break;
     } 
  }
 }
}
void enqueue(int ele)
{
  struct node *newnode;
  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=ele;
  newnode->prev=NULL;
  newnode->next=NULL;
  if(front==NULL && rear==NULL)
   {
      front=rear=newnode;
   }
 else
  {
     newnode->prev=rear;
     rear->next=newnode;
     rear=newnode;
  }
}
void dequeue()
{
   struct node *temp;
   if(front==rear)
    {
       printf("queue is empty\n");
    }
  else if(front->prev==rear->prev)
  {
       printf("queue is empty\n");
  }
   else
    {
       temp=front;
       printf("the dequeued node is:%p-%d-%p\n",temp->prev,temp->data,temp->next);
       front=temp->next;
       front->prev=NULL;
       temp->next=NULL;
       free(temp);
   }
}
void display()
{
  struct node *temp;
  temp=front;
  if(front==rear)
   {
      printf("queue is empty\n");
   }
  else
   {
       while(temp!=NULL)
         {
            printf("%p-%d-%p\n",temp->prev,temp->data,temp->next);
             temp=temp->next;
        }
   }
}
