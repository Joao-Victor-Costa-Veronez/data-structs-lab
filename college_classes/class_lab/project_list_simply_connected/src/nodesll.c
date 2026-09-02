#include "nodesll.h"

node_SLL *create_node_LSC(int value, node_SLL *next)
{
    node_SLL *new = (node_SLL *)malloc(sizeof(node_SLL));
    new->value = value;
    new->next = next;

    return new;
}