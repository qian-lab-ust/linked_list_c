#include <stdio.h>
#include "list.h"

int main(void)
{
    insert(10, 1);
    insert(20, 2);
    insert(30, 3);

    print_list();

    head = reverse(head);

    print_list();

    delete_node(2);

    print_list();

    free_list();

    return 0;
}