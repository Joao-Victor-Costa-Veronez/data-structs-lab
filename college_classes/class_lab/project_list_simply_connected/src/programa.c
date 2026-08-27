#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listlsc.h"

int main()
{
    node_LSC *new = (node_LSC *)malloc(sizeof(node_LSC));
    new->value = 0;
    new->next = NULL;

    return 0;
}