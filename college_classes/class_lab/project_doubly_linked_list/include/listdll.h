#ifndef LISTADLL_H
#define LISTADLL_H 1

#include "nodedll.h"

typedef struct intDoublyList
{
    nodeDLL *inicial;
    nodeDLL *final;
    int length;
} listDLL;

listDLL *createListDLL();

#endif