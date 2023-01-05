#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int top=-1;
int stack[MAX];
void push(int);
int pop();
int peek();
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
		case 2:if(top==-1)
		       {
			       printf("stack is empty\n");
		       }
		       else
		       {
			       printf("data poped is %d\n",pop());
		       }
		       break;
		 case 3:if(top==-1)
			{
				printf("stack is empty\n");
			}
			else
			{
				printf("data pointed by top of stack is %d\n",peek());
			}
			break;
		case 5: exit (0);
		case 4: for(i=0;i<MAX;i++)
				printf("%d\n",stack[i]);

	}
}

}
void push(int d)
{

	if(top==MAX-1)
		printf("stack is full \n");
	else
	{
		stack[++top]=d;
	}
}
int pop()
{
	return stack[top--];
}
int peek()
{
	return stack[top];
}
