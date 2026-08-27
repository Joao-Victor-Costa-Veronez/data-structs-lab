#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listsll.h"

int main()
{
    node_SLL *n1 = create_node_SLL(10, NULL);
    node_SLL *n2 = create_node_SLL(20, n1);
    node_SLL *n3 = create_node_SLL(30, n2);

    list_SLL *list = (list_SLL *)malloc(sizeof(list_SLL));
    list->inicial = n3;
    list->length = 3;

    return 0;
}