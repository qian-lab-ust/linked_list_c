#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node *head = NULL;

void insert(int data, int position)
{
    int i;
    int count = 0;
    struct node *p = head;

    while (p != NULL)
    {
        count++;
        p = p->next;
    }

    if (position < 1 || position > count + 1)
    {
        printf("invalid input\n");
        return;
    }

    struct node *new_node = malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("malloc failed\n");
        return;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (position == 1)
    {
        new_node->next = head;
        head = new_node;
        return;
    }

    p = head;

    for (i = 0; i < position - 2; i++)
    {
        p = p->next;
    }

    new_node->next = p->next;
    p->next = new_node;
}

void delete_node(int position)
{
    int i;
    int count = 0;
    struct node *p = head;

    while (p != NULL)
    {
        count++;
        p = p->next;
    }

    if (position < 1 || position > count)
    {
        printf("invalid input\n");
        return;
    }

    if (position == 1)
    {
        struct node *first = head;
        head = head->next;
        free(first);
        return;
    }

    p = head;

    for (i = 0; i < position - 2; i++)
    {
        p = p->next;
    }

    struct node *delete_node = p->next;
    p->next = delete_node->next;
    free(delete_node);
}

void print_list(void)
{
    struct node *p = head;

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}

struct node *reverse(struct node *head)
{
    struct node *prev = NULL;
    struct node *temp = head;
    struct node *future = NULL;

    while (temp != NULL)
    {
        future = temp->next;
        temp->next = prev;
        prev = temp;
        temp = future;
    }

    return prev;
}

void free_list(void)
{
    struct node *p = head;

    while (p != NULL)
    {
        struct node *next = p->next;
        free(p);
        p = next;
    }

    head = NULL;
}