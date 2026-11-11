#include "prova.h"

// Questão 1 (15%)
int ehPalindromoLDLI(ListaDLI *pontLista)
{
    // Implemente sua solução aqui
    return 0;
}

// Questão 2 (20%)
int moverParaInicioLSLI(int valor, ListaSLI *pontLista)
{
    // Implemente sua solução aqui
    return 0;
}

// Questão 3 (30%)
ListaSLI *dividirListaLSLI(int posicao, ListaSLI *pontLista)
{
    // Se a lista estiver vazia OU a posição < 0 OU a posição for maior que o tamanho da lista
    if (((pontLista->tamanho == 0) || posicao < 0) || posicao >= pontLista->tamanho)
    {
        // Retorna NULL
        return NULL;
    }
    // Se não, se a posição for a primeira
    else if (posicao == 0)
    {
        // Crio uma nova lista
        ListaSLI *novaLista = criarListaSLI();

        // Colocar os ponteiros de início da primeira lista na nova lista
        novaLista->inicio = pontLista->inicio;

        // Copiar o tamanho
        novaLista->tamanho = pontLista->tamanho;

        // Resetando as informações da primeira lista
        pontLista->inicio = NULL;
        pontLista->tamanho = 0;

        // Retorno a nova lista
        return novaLista;
    }
    // Se não
    else
    {
        // Crio uma nova lista
        ListaSLI *novaLista = criarListaSLI();

        // Crio um ponteiro auxiliar
        NoSLI *aux = pontLista->inicio;

        // Crio contadores
        int i = 0;
        int j = 0;

        // Para cada nó até a posição; o aux vai para o próximo nó
        while (i < posicao)
        {
            // Ao final, o aux estará no nó que será o primeiro da nova lista
            aux = aux->proximo;
            i++;
        }

        // Fazendo o início da nova lista receber o nó da posição enviada
        novaLista->inicio = aux;

        // Retorno aux pro começo da lista
        aux = pontLista->inicio;

        // Para cada nó antes do nó que será o primeiro da nova lsita; o aux vai para o próximo nó
        while (j != (posicao - 1))
        {
            // Ao final, o aux estará no nó que deve trocar o próximo nó
            aux = aux->proximo;
            j++;
        }

        // Colocando nulo no nó
        aux->proximo = NULL;

        // Atualizando o tamanho da nova lista
        novaLista->tamanho = (pontLista->tamanho - i);

        // Atualizando o tamanho da primeira lista
        pontLista->tamanho = i;

        // Retornando a nova lista
        return novaLista;
    }
}

// Questão 4 (35%)
int removerTodasOcorrenciasLDLI(int valor, ListaDLI *pontLista)
{
    // Variável que conta a quantidade de itens removidos da lista
    int quantidade_removida = 0;

    // Se a lista não estiver vazia
    if (pontLista->tamanho != 0)
    {
        // Se a lista possui apenas 1 elemento
        if (pontLista->tamanho == 1)
        {
            // Criando ponteiros auxiliares
            NoDLI *aux = pontLista->inicio;

            // Se o elemento for igual ao valor
            if (aux->valor == valor)
            {
                // Ajeito os ponteiros da lista (os ponteiros do nó já estão no NULL)
                pontLista->inicio = NULL;
                pontLista->fim = NULL;

                // Libero o nó
                free(aux);

                // Aumento a quantidade de itens removidos
                quantidade_removida++;

                // Diminuo o tamanho da lista
                pontLista->tamanho--;
            }
            // Se não
            else
            {
                // Retorno a quantidade removida (0)
                return quantidade_removida;
            }
        }
        // Se não
        else
        {
            // Criando ponteiros auxiliares
            NoDLI *aux = pontLista->inicio->proximo, *aux2 = pontLista->inicio;

            // Enquanto o ponteiro auxiliar não for nulo
            while (aux2 != NULL)
            {
                // Se o valor atual do ponteiro auxiliar, for igual ao valor buscado
                if (aux2->valor == valor)
                {
                    // Se for o primeiro valor da lista
                    if (aux2->anterior == NULL)
                    {
                        // Ajustando os ponteiros da lista
                        pontLista->inicio = aux2->proximo;

                        // Ajustando os ponteiros dos nós em volta
                        aux2->proximo->anterior = NULL;

                        // Ajustando os próximos ponteiros do nó
                        aux2->proximo = NULL;
                    }
                    // Se não, se for o último valor da lista
                    else if (aux2->proximo == NULL)
                    {
                        // Ajustando os ponteiros da lista
                        pontLista->fim = aux2->anterior;

                        // Ajustando os ponteiros dos nós em volta
                        aux2->anterior->proximo = NULL;

                        // Ajustando os próximos ponteiros do nó
                        aux2->anterior = NULL;
                    }
                    // Se não
                    else
                    {
                        // Ajustando os ponteiros dos nós em volta
                        aux2->anterior->proximo = aux2->proximo;
                        aux2->proximo->anterior = aux2->anterior;

                        // Ajustando os próximos ponteiros do nó
                        aux2->anterior = NULL;
                        aux2->proximo = NULL;
                    }

                    // Libero o nó
                    free(aux2);

                    // Aumento a quantidade de itens removidos
                    quantidade_removida++;

                    // Diminuo o tamanho da lista
                    pontLista->tamanho--;
                }

                // Colocando o segundo auxiliar no nó encontrado
                aux2 = aux;

                // Se estou não estou na última rodada
                if (aux != NULL)
                {
                    // O ponteiro auxiliar anda para o próximo nó
                    aux = aux->proximo;
                }
            }
        }
    }

    // Retorno o valor da quantidade removida
    return quantidade_removida;
}