#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
}*top =NULL;
#define MAX 5
//int top=-1;
int stack[MAX];
void push(int);
void pop();
void peek();
void display();
void main()
{
int data,choice,i;
while(1)
{
	printf("enter choice 1.push 2.pop 3.peek 4.display 5.exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:printf("enter data to be pushed:\n");
		       scanf("%d",&data);
		       push(data);
		       break;
		case 2:pop();
                break; 
        case 3 : peek();
                break; 
		case 5: exit (0);
		case 4: display();
                break;

	}
}

}
void push(int value)
{
   struct node *newNode;
   newNode = (struct node*)malloc(sizeof(struct node));
   newNode->data = value;
   if(top == NULL)
      top = newNode;
   else
      newNode->next = top;
   top = newNode;
   printf("\nInsertion is Success!!!\n");
}
void pop()
{
   if(top == NULL)
      printf("\nStack is Empty!!!\n");
   else{
      struct node *temp = top;
      printf("\nDeleted element: %d\n", temp->data);
      top = temp->next;
      free(temp);
   }
}
void display()
{
   if(top == NULL)
      printf("\nStack is Empty!!!\n");
   else{
      struct node *temp = top;
      while(temp != NULL){
	 printf("%d\n",temp->data);
	 temp = temp -> next;
      }
    
   }
}
void peek()
{   
    struct node *temp = top;
    printf("%d\n",temp->data);
}
