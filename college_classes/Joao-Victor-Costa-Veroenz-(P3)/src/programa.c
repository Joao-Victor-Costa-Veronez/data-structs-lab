#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filai.h"
#include "pilhai.h"
#include "prova.h"

int main()
{
    /*
    Teste questão 1:

    FilaI *fila1 = criarFilaI();

    enfileirarI(10, fila1);
    enfileirarI(20, fila1);
    enfileirarI(30, fila1);
    enfileirarI(40, fila1);
    enfileirarI(50, fila1);
    mostrarFilaI(fila1);
    printf("\n");

    printf("%d\n", inverterPrimeirosKFilaI(3, fila1));
    mostrarFilaI(fila1);

    destruirFilaI(&fila1);
    */

    /*
    Teste questão 2:

    FilaI *fila1 = criarFilaI();
    PilhaI *pilha1 = criarPilhaI();

    enfileirarI(10, fila1);
    enfileirarI(20, fila1);
    enfileirarI(30, fila1);
    enfileirarI(40, fila1);
    enfileirarI(50, fila1);
    
    empilharI(30, pilha1);
    empilharI(20, pilha1);
    empilharI(10, pilha1);
    empilharI(20, pilha1);
    empilharI(10, pilha1);
    empilharI(10, pilha1);
    empilharI(10, pilha1);

    printf("Pilha: ");
    mostrarPilhaI(pilha1);
    printf("\n");
    
    printf("Fila: ");
    mostrarFilaI(fila1);
    printf("\n");

    printf("%d\n", transferirTopoParaFilaInPlace(2, pilha1, fila1));
    
    destruirFilaI(&fila1);
    destruirPilhaI(&pilha1);
    */
    
    /*
    Teste questão 3:

    FilaI *fila1 = criarFilaI();
    PilhaI *pilha1 = criarPilhaI();

    enfileirarI(80, fila1);
    enfileirarI(90, fila1);
    
    empilharI(30, pilha1);
    empilharI(20, pilha1);
    empilharI(10, pilha1);

    printf("Pilha: ");
    mostrarPilhaI(pilha1);
    
    printf("Fila: ");
    mostrarFilaI(fila1);
    printf("\n");

    printf("Retorno: %d\n", transferirTopoParaFilaInPlace(2, pilha1, fila1));
    
    printf("Pilha: ");
    mostrarPilhaI(pilha1);
    
    printf("Fila: ");
    mostrarFilaI(fila1);
    printf("\n");

    printf("Inicio: %d, fim: %d", fila1->inicio->valor, fila1->fim->valor);

    destruirFilaI(&fila1);
    destruirPilhaI(&pilha1);
    */
    
    /*
    Teste questão 4:

    FilaI *fila1 = criarFilaI();
    PilhaI *pilha1 = criarPilhaI();

    enfileirarI(80, fila1);
    enfileirarI(90, fila1);
    
    empilharI(30, pilha1);
    empilharI(20, pilha1);
    empilharI(10, pilha1);

    printf("Pilha: ");
    mostrarPilhaI(pilha1);
    
    printf("Fila: ");
    mostrarFilaI(fila1);
    printf("\n");

    printf("Retorno: %d\n", transferirTopoParaFilaInPlace(2, pilha1, fila1));
    
    printf("Pilha: ");
    mostrarPilhaI(pilha1);
    
    printf("Fila: ");
    mostrarFilaI(fila1);
    printf("\n");

    destruirFilaI(&fila1);
    destruirPilhaI(&pilha1);
    */

    return 0;
}