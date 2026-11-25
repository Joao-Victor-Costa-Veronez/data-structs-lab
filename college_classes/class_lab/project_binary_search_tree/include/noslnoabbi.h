#ifndef NOSLNOABBI_H
#define NOSLNOABBI_H 1

#include <stdlib.h>
#include <stdio.h>
#include "nodeBST.h"

typedef struct nosimples_noabbi
{
    nodeBST *valor;
    struct nosimples_noabbi *proximo;
} NoSLNoABBI;

NoSLNoABBI *criarNoSLNoABBI(nodeBST *valor, NoSLNoABBI *proximo);

#endif