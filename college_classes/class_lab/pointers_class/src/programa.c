#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[255];
    char endereco[255];
    float precoMedio;
    char tipoComida[255];
} restaurant;

int main() {
    int *pontInt;
    float *pontFloat;
    char *pontChar;
    restaurant *pontRestaurant;

    printf("%d\n", sizeof(pontInt));
    printf("%d\n", sizeof(pontFloat));
    printf("%d\n", sizeof(pontChar));
    printf("%d\n", sizeof(pontRestaurant));

    return 0;
}