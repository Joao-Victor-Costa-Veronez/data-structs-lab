#include "noslnoabbi.h"

NoSLNoABBI * criarNoSLNoABBI(nodeBST * valor, NoSLNoABBI * proximo)
{
    NoSLNoABBI * novo = (NoSLNoABBI *) malloc(sizeof(NoSLNoABBI));
    if (novo == NULL)   // ERRO alocando memoria
    {
        printf("Erro fatal: Falha na alocacao de memoria para o NoSLNoABBI.\n");
        exit(1);
    }
    novo->valor = valor;
    novo->proximo = proximo;
    return novo;
}