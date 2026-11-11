#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prova.h"

int main()
{
    printf("=== Area de testes do aluno ===\n");
    printf("Use este arquivo para testar suas funcoes.\n");
    printf("ATENCAO: A correção será APENAS do arquivo prova.c!\n\n");

    ListaDLI *lista1 = criarListaDLI();
    inserirFimLDLI(10, lista1);
    inserirFimLDLI(20, lista1);
    inserirFimLDLI(20, lista1);
    inserirFimLDLI(30, lista1);
    mostrarLDLI(lista1);

    /*
    // Testes da 3ª questão:
    ListaSLI *lista2 = criarListaSLI();
    inserirFimLSLI(10, lista2);
    inserirFimLSLI(20, lista2);
    inserirFimLSLI(20, lista2);
    inserirFimLSLI(30, lista2);
    mostrarLSLI(lista2);

    ListaSLI *lista3 = dividirListaLSLI(2, lista2);
    mostrarLSLI(lista2);
    mostrarLSLI(lista3);
    */

    /*
    // Testes da 4ª questão:
    printf("%d\n", removerTodasOcorrenciasLDLI(10, lista1));
    mostrarLDLI(lista1);
    */

    destruirLDLI(&lista1);
    /*
    destruirLSLI(&lista2);
    destruirLSLI(&lista3);
    */

    return 0;
}