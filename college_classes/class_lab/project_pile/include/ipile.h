#ifndef IPILE_H
#define IPILE_H 1

// Including libraries
#include "nodesll.h"

// Defining structs
typedef struct int_pile
{
    // Declaring variables
    nodeSLL *top;
    int length;
} iPile;

// Declaring functions
iPile *createIPile();
void showIPile(iPile *pilePoint);
int showTopIPile(iPile *pilePoint);
void stackIPile(int value, iPile *pilePoint);
int unStackIPile(iPile *pilePoint);
void cleanUpIPile(iPile *pilePoint);
void deleteIPile(iPile **pilePointPoint);

#endif