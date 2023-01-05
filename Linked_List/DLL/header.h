#include<stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node *next ,*prev;
};
struct node* delete_beg(struct node*);
struct node* delete_end(struct node*);
struct node* delete_pos(struct node*);
struct node* add_beg(struct node*);
struct node* add_end(struct node*);
struct node* add(struct node*,int);
void length(struct node*);
void display(struct node*);
struct node* reverse(struct node*);
