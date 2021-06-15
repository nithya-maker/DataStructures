//B171381
//Implementation of queue using doublelinkedlist



#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next,*prev;
};
struct node *top=NULL;
struct node* push(int ele);
struct node* pop();
void display();
void main()
{
  int ele,ch;
 printf("1.push\n2.pop\n3.display\n4.exit\n");
do
{
      printf("enter your choice:");
      scanf("%d",&ch);
    switch(ch)
   {
     case 1:
     {
        printf("enter the element to be inserted:");
        scanf("%d",&ele);
       push(ele);
       break;
     }
    case 2:
    {
       pop();
       break;
    }
   case 3:
   {
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
while(ch!=4);
}
struct node* push(int ele)
{
 struct node *newnode;
  newnode->data=ele;
  newnode->next=NULL;
if(top==NULL)
{
  top=newnode;
  top->prev=NULL;
}
else
 {
   top->next=newnode;
  newnode->prev=top;
  top=newnode;
}
}
struct node* pop()
{
  struct node *temp;
  if(top==NULL)
  {
    printf("list is empty");
 }
else
{
   temp=top;
   top=top->prev;
   top->next=NULL;
  printf("the deleted node is %p-%d-%p\n",temp->prev,temp->data,temp->next);
   free(temp);
}
 return top;
}
void display()
{

 if(top==NULL)
 {
    printf("stack is empty\n");
 }
else
{
  while(top!=NULL)
   {
      printf("%p-%d-%p\n",top->prev,top->data,top->next);
      top=top->prev;
   }
}
}
  
  
