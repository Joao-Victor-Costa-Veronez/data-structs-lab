#include "iqueue.h"

IQueue *createIQueue()
{
    IQueue *new = (IQueue *)malloc(sizeof(IQueue));
    new->length = 0;
    new->inicial = NULL;
    new->final = NULL;
    return new;
}

void cleanUpIQueue(IQueue *queuePoint)
{
    // VAZIA
    if (queuePoint->length == 0)
    {
        printf("Fila Vazia!");
    }

    // 1 ou + DE 1 ELEMENTO
    else
    {
        NoSLI *pontAux = queuePoint->inicial; // guarda o endereço do primeiro nó

        NoSLI *pontAux2 = pontAux->proximo; // guarda o endereço do próximo nó

        while (pontAux2 != NULL)
        {
            free(pontAux);                // limpou o primeiro nó
            pontAux = pontAux2;           // fez o primeiro apontar para o proximo
            pontAux2 = pontAux2->proximo; // fez o próximo apontar para o outro próximo
        }
        free(pontAux); // limpou o último que ficou

        queuePoint->length = 0; // diminuiu o length pra 0
        queuePoint->inicial = NULL;
        queuePoint->final = NULL;
    }
}

void deleteIQueue(IQueue **queuePointPoint)
{
    clean_up_SLL(*queuePointPoint);
    free(*queuePointPoint);
    *queuePointPoint = NULL;
}

void showIQueue(IQueue *queuePoint)
{
    printf("length da Fila = %d\n", queuePoint->length); // SEMPRE MOSTRAR O length

    // VAZIA

    if (queuePoint->length == 0)
    {
        printf("Fila Vazia\n");
    }

    // 1 OU + ELEMENTOS
    else
    {
        NoSLI *pontAux = queuePoint->inicial;

        printf("%d(P) -> ", pontAux->valor);
        pontAux = pontAux->proximo;

        while (pontAux != NULL)
        {
            printf("%d -> ", pontAux->valor);
            pontAux = pontAux->proximo;
        }
        printf("NULL\n");
    }
}

void queueIQueue(int valor, IQueue *queuePoint)
{
    NoSLI *novo = create_node_SLL(valor, NULL); // A mesmo passo para todas as opções

    // VAZIA
    if (queuePoint->inicial == NULL) // serve os dois: (fila->length == 0) ou (fila->inicial == NULL)
    {
        queuePoint->inicial = novo; // B
    }

    // 1 ou + DE 1 ELEMENTO
    else
    {
        NoSLI *pontAux = queuePoint->inicial;
        while (pontAux->proximo != NULL) // Andar o ponteiro na fila
        {
            pontAux = pontAux->proximo;
        }
        pontAux->proximo = novo; // B
    }

    queuePoint->length++; // C mesmo passo para todas opções
}

int unqueueIQueue(IQueue *queuePoint)
{
    // VAZIA
    if (queuePoint->inicial == NULL)
    {
        printf("Fila Vazia! ");
        return 0;
    }

    // 1 ou + DE 1 ELEMENTO
    else
    {
        NoSLI *pontAux = queuePoint->inicial; // guarda o endereço do primeiro nó

        queuePoint->inicial = pontAux->proximo; // faz o inicial da fila apontar para o segundo nó

        free(pontAux); // remove o antigo primeiro nó da memória

        queuePoint->length--; // diminuindo o length da fila

        return 1;
    }
}

int proximoIQueue(IQueue *queuePoint)
{
    // VAZIA
    if (queuePoint->inicial == NULL)
    {
        printf("Fila Vazia! ");
        return 0;
    }

    // 1 OU + DE 1 ELEMENTO
    else
    {
        return queuePoint->inicial->valor;
    }
}