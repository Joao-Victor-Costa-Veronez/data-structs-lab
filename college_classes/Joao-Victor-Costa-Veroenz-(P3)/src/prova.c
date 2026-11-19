#include "prova.h"

// Questão 1 (15%)
int compactarAdjacentesPilhaI(PilhaI *pontPilha)
{
    if ((pontPilha->tamanho == 0) || (pontPilha->tamanho == 1))
    {
        return 0;
    }

    PilhaI *pilhaAux = criarPilhaI();
    int quantidadeExcluida = 0;

    while (pontPilha->tamanho != 0)
    {
        int valor = topoI(pontPilha);
        desempilharI(pontPilha);

        if (valor != topoI(pontPilha))
        {
            empilharI(valor, pilhaAux);
        }
        else
        {
            quantidadeExcluida++;
        }
    }

    while (pilhaAux->tamanho != 0)
    {
        int valor = topoI(pilhaAux);
        desempilharI(pilhaAux);
        empilharI(valor, pontPilha);
    }

    destruirPilhaI(&pilhaAux);

    return quantidadeExcluida;
}

// Questão 2 (20%)
int inverterPrimeirosKFilaI(int k, FilaI *pontFila)
{
    if ((k <= 0) || (k > pontFila->tamanho))
    {
        return 0;
    }

    if (k == 1)
    {
        return 1;
    }

    PilhaI *pilhaAux = criarPilhaI();
    PilhaI *pilhaAux2 = criarPilhaI();

    for (int i = 0; i < k; i++)
    {
        int valor = proximoI(pontFila);
        desinfileirarI(pontFila);
        empilharI(valor, pilhaAux);
    }

    while (pontFila->tamanho != 0)
    {
        int valor = proximoI(pontFila);
        desinfileirarI(pontFila);
        empilharI(valor, pilhaAux2);
    }

    for (int i = 0; i < k; i++)
    {
        int valor = topoI(pilhaAux);
        desempilharI(pilhaAux);
        enfileirarI(valor, pontFila);
    }

    while (pilhaAux2->tamanho != 0)
    {
        int valor = topoI(pilhaAux2);
        desempilharI(pilhaAux2);
        empilharI(valor, pilhaAux);
    }

    for (int i = 0; i < (pilhaAux->tamanho + 1); i++)
    {
        int valor = topoI(pilhaAux);
        desempilharI(pilhaAux);
        enfileirarI(valor, pontFila);
    }

    destruirPilhaI(&pilhaAux);
    destruirPilhaI(&pilhaAux2);

    return 1;
}

// Questão 3 (30%)
int transferirTopoParaFilaInPlace(int k, PilhaI *pontPilha, FilaI *pontFila)
{
    if ((k <= 0) || (k > pontPilha->tamanho))
    {
        return 0;
    }

    for (int i = 0; i < k; i++)
    {
        if (pontPilha->tamanho == 0)
        {
            printf("Esta mensagem não deveria ser vista\n");
            return 0;
        }

        NoSLI *pontAux = pontPilha->topo;
        pontPilha->topo = pontAux->proximo;
        pontAux->proximo = NULL;
        pontPilha->tamanho--;

        if (pontFila->tamanho == 0) // pontFila->inicio == NULL
        {
            pontFila->inicio = pontAux;
        }
        else // 1 OU + DE 1 ELEM
        {
            pontFila->fim->proximo = pontAux;
        }

        pontFila->fim = pontAux;
        pontFila->tamanho++;
    }

    return 1;
}

// Questão 4 (35%)
int alterarPrioridadePrio(char nome[], int novaPrioridade, FilaPrio *pontFila)
{
    if (pontFila->tamanho == 0)
    {
        return 0;
    }

    if (pontFila->tamanho == 1)
    {
        pontFila->inicio->prioridade = novaPrioridade;

        return 1;
    }

    NoPrio *pontAux = pontFila->inicio;
    int arquivoDiferente = 1;

    while (arquivoDiferente)
    {
        if (pontAux == NULL)
        {
            return 0;
        }

        if ((strcmp(nome, pontAux->nome) == -1) || (strcmp(nome, pontAux->nome) == 1))
        {
            arquivoDiferente = 1;
        }
        else
        {
            arquivoDiferente == 0;
        }

        pontAux = pontAux->proximo;
    }

    if (novaPrioridade == pontAux->prioridade)
    {
        return 1;
    }

    pontAux->anterior->proximo = pontAux->proximo;
    pontAux->anterior = NULL;

    pontAux->proximo->anterior = pontAux->anterior;
    pontAux->proximo = NULL;

    pontAux->prioridade = novaPrioridade;

    if (pontFila->inicio->prioridade > novaPrioridade)
    {
        pontAux->proximo = pontFila->inicio;
        pontAux->proximo->anterior = pontAux;
        pontFila->inicio = pontAux;
    }
    else if (pontFila->fim->prioridade < novaPrioridade)
    {
        pontAux->anterior = pontFila->fim;
        pontAux->anterior->proximo = pontAux;
        pontFila->fim = pontAux;
    }
    else
    {
        NoPrio *pontAux2 = pontFila->inicio;

        while (pontAux2->prioridade <= novaPrioridade)
        {
            pontAux2 = pontAux2->proximo;
        }

        pontAux2->anterior->proximo = pontAux;
        pontAux->anterior = pontAux2->anterior;

        pontAux2->anterior = pontAux;
        pontAux->proximo = pontAux2;

        pontFila->fim = pontAux;
    }

    return 1;
}