#ifndef FILANOABBI_H
#define FILANOABBI_H 1

#include "noslnoabbi.h"

typedef struct fila_nodeBST
{
    NoSLNoABBI *inicio;
    NoSLNoABBI *fim;
    int tamanho;
} FilaNoABBI;

FilaNoABBI *criarFilaNoABBI();
void limparFilaNoABBI(FilaNoABBI *pontFila);
void destruirFilaNoABBI(FilaNoABBI **pontPontFila);
void mostrarFilaNoABBI(FilaNoABBI *pontFila);

void enfileirarNoABBI(nodeBST *valor, FilaNoABBI *pontFila);
int *desinfileirarNoABBI(FilaNoABBI *pontFila);
nodeBST *proximoNoABBI(FilaNoABBI *pontFila);

#endif