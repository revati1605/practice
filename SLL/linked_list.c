#include "header.h"

void main()
{
    struct node* head = NULL ;
    int  count = 0;
    int choice;
    while(1)
    {
        printf("Enter choice 1.add(at end) 2.display 3.add(at beginning) 4.add(at given position) 5.delete last node "
                "6.delete first node 7.delete middle node 8.get length 9.Reverse a list:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : head = add_end(head);
                     count = count +1;
                     break;
            case 2 : display(head);
                     break;
            case 3 : head = add_beg(head);
                     count = count + 1;
                     break;
            case 4 : head = add(head,count);
                     count = count + 1;
                     break;
            case 5 : head = del_last(head);
                     count--;
                     break;
            case 6 : head = del_first(head);
                     count --;
                     break;
            case 7 : head = del(head);
                     count--;
                     break;
            case 8 : get_length(head);
                        break;
            case 9 : head = reverse(head);
                    break;
            case 10 : exit(0);
         }
    }
}
struct node * reverse(struct node *ptr)
{
    struct node *prevnode = NULL , *currentnode = ptr ,*nextnode = ptr;
    while(nextnode != NULL)
    {
        nextnode = nextnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    ptr = prevnode;
return ptr;
}
void get_length(struct node *ptr)
{
    struct node *temp =NULL;
    int len;
    temp = ptr;
    while (temp)
    {
        len++;
        temp = temp->next;
   }
    printf("length is :%d\n",len);
}
struct node *del_first(struct node *ptr)
{
    struct node *temp = NULL;
    if(ptr == NULL)
    {
        printf("no node is created\n");
        return 0;
    }
    else
    {

        temp = ptr;
        ptr = ptr->next;
        free(temp);
        temp = NULL;
    }
    return ptr;
}
struct node *del(struct node *ptr)
{
    struct node *nextnode = NULL ,*temp = NULL;
    int  i=1, pos ;
    printf("enter position:\n");
    scanf("%d",&pos);
    temp = ptr;
    while(i < pos-1)
    {
        temp = temp->next;
        i++;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
//    temp = NULL;
    return ptr;
}
struct node *del_last(struct node *ptr)
{
    struct node *temp = NULL , *prev = NULL ;
    temp = ptr;
    while(temp->next  != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == ptr)
    {
        ptr = NULL;
        free(temp);
    }
    else
    {
        prev->next = NULL;
        free(temp);
    }
    return ptr;
}
struct node *add(struct node *ptr,int count)
{
    int pos,i=1;
    struct node *newnode = NULL, *temp = NULL;
    printf("enter position you want to insert data:\n");
    scanf("%d",&pos);
    if(pos > count)
    {
        printf("invalid pos\n");
        return 0;
    }
    else
    { 
        newnode = (struct node*)calloc(1,sizeof(struct node));
        if(newnode == NULL)
        {
            printf("node not created\n");
            return 0;
        }
        printf("enter data\n");
        scanf("%d",&newnode->data);
        temp = ptr;
        while(i < pos)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
  
    return ptr;
}
struct node * add_beg(struct node *ptr)
{
    struct node *newnode = NULL;
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
    	newnode->next = ptr;
  
    ptr = newnode;
    }
    return ptr;

}


struct node *add_end(struct node *ptr)
{
    struct node *newnode = NULL, *temp = NULL;
    newnode = (struct node*)calloc(1,sizeof(struct node));
    if(newnode == NULL)
    {
        printf("node not created\n");
    }
    else
    {
        printf("enter data:\n");
        scanf("%d",&newnode->data);
        if(ptr == NULL)
        {
           ptr = newnode;
        }
        else
        {
            temp = ptr;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
    return ptr;

}

struct node *display(struct node *ptr)
{
    if(ptr == NULL)
    {
        printf("list is empty\n");
     }
    else
    {
        while(ptr)
        {
            printf("%d\n",ptr->data);
            ptr = ptr->next;
        }
    }
}

