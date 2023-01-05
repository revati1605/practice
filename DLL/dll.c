#include "header.h"
void main()
{
    int choice,count = 0;
    struct node *head = NULL;
    while(1)
    {
        printf("enter your choice 1.add_beginning 2.add_end 3.add_position 4.display 5.delete_beg 6.delete_end 7.delete_pos 8.length 9.reverse:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : head = add_beg(head);
                     count++;
                     break;
            case 2 : head = add_end(head);
                     count++;
                     break;
            case 3 : head = add(head,count);
                     count++;
                     break;
            case 4 : display(head);
                     break;
            case 5 : head = delete_beg(head);
                     count--;
                    break;
            case 6 : head = delete_end(head);
                     count--;
                     break;
            case 7 : head = delete_pos(head);
                     count--;
                     break;
            case 8 : length(head);
                     break;
            case 9 : head = reverse(head);
                     break; 
        }
    }
}
void length(struct node *ptr)
{
    struct node *temp =NULL;
    int len = 0;
    temp = ptr;
    while (temp)
    {
        len++;
        temp = temp->next;
   }
    printf("length is :%d\n",len);
}
struct node* reverse(struct node *ptr)
{
    struct node *current = NULL, *prev = NULL;
    current = ptr;
    while(current != NULL)
    {
       prev = current->prev;
      current->prev = current->next;
      current->next = prev;
      current = current->prev;
    }
//    if(prev != NULL)
    ptr = prev;
    return ptr;
  }
struct node*delete_pos(struct node *ptr)
{
   
		struct node *temp = NULL;
		int pos,i=1;
		printf("Enter the pos...\n");
		scanf("%d",&pos);
			temp = ptr;
			while(i<pos)
			{
				temp=temp->next;
				i++;
			}
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			free(temp);
			
    return ptr;
	}
		
struct node* delete_end(struct node *ptr)
{
    struct node *temp = NULL;
    temp = ptr;
    while(temp->next != NULL)
    {
        temp =temp->next;
    }
/*    if(temp = ptr)
    {
        ptr = NULL;
        free(temp);
    }
    else
    {*/
        temp->prev->next = NULL;
        free(temp);
  // }
    return ptr;
}
struct node *delete_beg(struct node *ptr)
{
    struct node *temp = NULL;
    temp =ptr;
    ptr = ptr->next;
    ptr->prev = NULL;
    free(temp);
    return ptr;
}
struct node *add(struct node *ptr,int count)
{
    struct node *temp = NULL,*newnode = NULL;
    int pos ,i=1;
    printf("enter position you want to insert node\n");
    scanf("%d",&pos);
    if(pos < 1)
    printf("invalid position\n");
    else if(pos > count)
    printf("invalid position\n");
    else
    {
        newnode = (struct node*)calloc(1,sizeof(struct node));
        if(newnode == NULL)
        {
            printf("node not created\n");
        }
        printf("enter data:\n");
        scanf("%d",&newnode->data);
        temp = ptr;
        while(i<pos-1)//at position if we want after position then while(i < pos)
        {
            temp =temp->next;
            i++;
        }
        newnode ->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;
            
     }
     return ptr;
}
struct node * add_beg(struct node *ptr)
{
    struct node *newnode = NULL, *temp = NULL;
    newnode = (struct node*)calloc(1,sizeof(struct node));
    if(newnode == NULL)
    {
        printf("node not created\n");
        return 0;
    }
   
    printf("enter data:\n");
    scanf("%d",&newnode->data);
    if(ptr == NULL)
    {
        ptr = newnode;
    }
    else
    {
        ptr->prev = newnode;    
        newnode->next = ptr;
        ptr = newnode;
    }
    return ptr;
}
struct node *add_end(struct node * ptr)
{
    struct node *newnode = NULL , *temp = NULL;
    newnode = (struct node*)calloc(1,sizeof(struct node));
    if(newnode == NULL)
    {
        printf("node not created\n");
        return 0;
    }
    printf("enter data:\n");
    scanf("%d",&newnode ->data);
    if(ptr == NULL)
    {
        ptr = newnode;
    }
    else
    {
        temp = ptr;
        while(temp->next != NULL)
        {
            temp =temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
    return ptr;
}

void display(struct node *ptr)
{
    if(ptr == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        struct node *temp = ptr;
        while(temp != NULL)
        {
            printf("%d\n",temp->data);
            temp = temp->next;
        }
    }
}
