#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *reverse(struct node*);
void get_length(struct node*);
struct node *add_beg(struct node*);
struct node *add_end(struct node*);
struct node *display(struct node*);
struct node * del_first(struct node*);
struct node * del_last(struct node *);
struct node *del(struct node*);
struct node *add(struct  node*,int);
