/*
DATE: 12/08/2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[255];
    char endereco[255];
    float precoMedio;
    char tipoComida[255];
} Restaurante;

int main()
{
    int x;
    float y;
    char z;
    Restaurante r;

    printf("Tamanho x: %d\n", sizeof(x));
    printf("&x: %p\n", &x);
    printf("Tamanho y: %d\n", sizeof(y));
    printf("&y: %p\n", &y);
    printf("Tamanho z: %d\n", sizeof(z));
    printf("&z: %p\n", &z);
    printf("Tamanho r: %d\n", sizeof(r));
    printf("&r: %p\n", &r);

    int *pontInt;
    float *pontFloat;
    char *pontChar;
    Restaurante *pontRestaurante;
    int **pontPontInt;

    printf("Tamanho pontInt: %d\n", sizeof(pontInt));
    printf("&pontInt: %p\n", &pontInt);
    printf("Tamanho pontFloat: %d\n", sizeof(pontFloat));
    printf("&pontFloat: %p\n", &pontFloat);
    printf("Tamanho pontChar: %d\n", sizeof(pontChar));
    printf("&pontChar: %p\n", &pontChar);
    printf("Tamanho pontRestaurante: %d\n", sizeof(pontRestaurante));
    printf("&pontRestaurante: %p\n", &pontRestaurante);
    printf("Tamanho pontPontInt: %d\n", sizeof(pontPontInt));
    printf("&pontPontInt: %p\n", &pontPontInt);

    pontInt = &x;
    pontFloat = &y;
    pontChar = &z;
    pontRestaurante = &r;
    pontPontInt = &pontInt;

    printf("pontInt: %p\n", pontInt);
    printf("pontFloat: %p\n", pontFloat);
    printf("pontChar: %p\n", pontChar);
    printf("pontRestaurante: %p\n", pontRestaurante);
    printf("pontPontInt: %p\n", pontPontInt);

    return 0;
}