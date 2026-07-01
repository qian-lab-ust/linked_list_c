#ifndef LIST_H
#define LIST_H

struct node
{
    int data;
    struct node *next;
};

extern struct node *head;

void insert(int data, int position);
void delete_node(int position);
void print_list(void);
struct node *reverse(struct node *head);
void free_list(void);

#endif