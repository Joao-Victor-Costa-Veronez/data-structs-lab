#ifndef IPILE_H
#define IPILE_H 1

# include "nodesll.h"

typedef struct int_pile
{
    node_SLL *top;
    int length;
} iPile;

iPile *createIPile ();

#endif