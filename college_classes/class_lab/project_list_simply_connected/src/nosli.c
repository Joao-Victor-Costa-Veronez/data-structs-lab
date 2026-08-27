#include "nosli.h"

node_LSC *create_node_LSC(int value, node_LSC *next)
{
    node_LSC *new = (node_LSC *)malloc(sizeof(node_LSC));
    new->value = value;
    new->next = next;

    return new;
}