/*
DATE: 12/08/2026
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"

typedef struct
{
    char nome[255];
    char endereco[255];
    float precoMedio;
    char tipoComida[255];
} Restaurante;

// - Crie uma função que obtém os dados de uma estrutura
//  restaurante pelo teclado e a retorna.
Restaurante obterRestaurante();

// - Crie uma função que recebe uma estrutura restaurante
//  como parâmetro e escreve seus dados na tela.
void mostrarRestaurante(Restaurante r);

// - Crie uma função que recebe um vetor de estruturas 
// restaurante e a quantidade de restaurantes válidos no 
// vetor como parâmetros e os imprime na tela.
void mostrarRestaurantes(Restaurante restaurantes[], int quantidade);

// - Crie uma função que recebe um vetor de estruturas 
// restaurantes, a quantidade de restaurantes válidos no
// vetor e valores mínimo e máximo de preço como parâmetros. 
// A função deve imprimir os restaurantes com valor médio 
// de preço nesse intervalo.
void mostrarRestaurantesIntervaloPreco(Restaurante restaurantes[], int quantidade, 
                                       float minPreco, float maxPreco);

// - Crie uma função que recebe um vetor de estruturas 
// restaurantes, a quantidade de restaurantes válidos no 
// vetor e um tipo de comida como parâmetros. A função 
// deve imprimir os restaurantes com tipo de comida desse tipo.
void mostrarRestaurantesTipoComida(Restaurante restaurantes[], int quantidade, char tipoComida[]);

void preguica(Restaurante restaurantes[]);

int main()
{
    // - Crie um programa principal que crie uma matriz de 50 estruturas restaurante;
    Restaurante restaurantes[50];

    //  pergunte a quantidade de restaurantes a serem lidos;
    int quantidade;
    do {
        printf("Quantos restaurantes serão digitados (Máx. 50): ");
        quantidade = lerInt();
    } while (quantidade < 1 || quantidade > 50);

    //  leia os dados desses restaurantes no vetor;
    // for(int cont = 0; cont < quantidade; cont++)
    // {
    //     restaurantes[cont] = obterRestaurante();
    // }
    quantidade = 3;
    preguica(restaurantes);

    //  mostre os dados dos restaurantes lidos;
    mostrarRestaurantes(restaurantes, quantidade);

    //  pergunte uma faixa de valores de preço;
    float min, max;
    printf("Preço mínimo: R$ ");
    min = lerFloat();
    printf("Preço máximo: R$ ");
    max = lerFloat();

    //  mostre os restaurantes com preço médio nessa faixa;
    mostrarRestaurantesIntervaloPreco(restaurantes, quantidade, min, max);

    //  pergunte um tipo de comida;
    char tipo[255];
    printf("Tipo comida: ");
    lerString(tipo, 255);

    //  mostre os restaurantes com esse tipo de comida.
    mostrarRestaurantesTipoComida(restaurantes, quantidade, tipo);

    return 0;
}

Restaurante obterRestaurante()
{
    Restaurante r;

    printf("Digite o nome: ");
    lerString(r.nome, 255);
    printf("Digite o endereço: ");
    lerString(r.endereco, 255);
    printf("Digite o preço médio: R$ ");
    r.precoMedio = lerFloat();
    printf("Digite o tipo da comida: ");
    lerString(r.tipoComida, 255);

    return r;
}

void mostrarRestaurante(Restaurante r)
{
    printf("Nome: %s\n", r.nome);
    printf("Endereço: %s\n", r.endereco);
    printf("Preço Médio: R$ %.2f\n", r.precoMedio);
    printf("Tipo da comida: %s\n", r.tipoComida);
}

void mostrarRestaurantes(Restaurante restaurantes[], int quantidade)
{
    for (int cont = 0; cont < quantidade; cont++)
    {
        mostrarRestaurante(restaurantes[cont]);
    }
}

void mostrarRestaurantesIntervaloPreco(Restaurante restaurantes[], int quantidade, 
                                       float minPreco, float maxPreco)
{
    for (int cont = 0; cont < quantidade; cont++)
    {
        if (restaurantes[cont].precoMedio >= minPreco && restaurantes[cont].precoMedio <= maxPreco)
        {
            mostrarRestaurante(restaurantes[cont]);
        }
    }                       
}

void preguica(Restaurante restaurantes[])
{
    strcpy(restaurantes[0].nome, "McDonalds");
    strcpy(restaurantes[0].endereco, "Rua Seilah, 222");
    restaurantes[0].precoMedio = 50.0;
    strcpy(restaurantes[0].tipoComida, "Fast Food");

    strcpy(restaurantes[1].nome, "Habibs");
    strcpy(restaurantes[1].endereco, "Rua Seilah, 333");
    restaurantes[1].precoMedio = 20.0;
    strcpy(restaurantes[1].tipoComida, "Arabe");

    strcpy(restaurantes[2].nome, "Burger King");
    strcpy(restaurantes[2].endereco, "Rua Seilah, 444");
    restaurantes[2].precoMedio = 50.0;
    strcpy(restaurantes[2].tipoComida, "Fast Food");
}

void mostrarRestaurantesTipoComida(Restaurante restaurantes[], int quantidade, char tipoComida[])
{
    char tipoRestaurante[255], tipoRecebido[255];
    strcpy(tipoRecebido, tipoComida);
    minuscula(tipoRecebido);
    for (int cont = 0; cont < quantidade; cont++)
    {
        strcpy(tipoRestaurante, restaurantes[cont].tipoComida);
        minuscula(tipoRestaurante);
        if (strcmp(tipoRecebido, tipoRestaurante) == 0)
        {
            mostrarRestaurante(restaurantes[cont]);
        }
    } 
}
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"

typedef struct
    print
{
    char nome[255];
    char endereco[255];
    float precoMedio;
    char tipoComida[255];
} Restaurante;

// - Crie uma função que obtém os dados de uma estrutura
//  restaurante pelo teclado e a retorna.
Restaurante obterRestaurante();

// - Crie uma função que recebe uma estrutura restaurante
//  como parâmetro e escreve seus dados na tela.
void mostrarRestaurante(Restaurante r);

// - Crie uma função que recebe um vetor de estruturas 
// restaurante e a quantidade de restaurantes válidos no 
// vetor como parâmetros e os imprime na tela.
void mostrarRestaurantes(Restaurante restaurantes[], int quantidade);

// - Crie uma função que recebe um vetor de estruturas 
// restaurantes, a quantidade de restaurantes válidos no
// vetor e valores mínimo e máximo de preço como parâmetros. 
// A função deve imprimir os restaurantes com valor médio 
// de preço nesse intervalo.
void mostrarRestaurantesIntervaloPreco(Restaurante restaurantes[], int quantidade, 
                                       float minPreco, float maxPreco);

// - Crie uma função que recebe um vetor de estruturas 
// restaurantes, a quantidade de restaurantes válidos no 
// vetor e um tipo de comida como parâmetros. A função 
// deve imprimir os restaurantes com tipo de comida desse tipo.
void mostrarRestaurantesTipoComida(Restaurante restaurantes[], int quantidade, char tipoComida[]);

void preguica(Restaurante restaurantes[]);

int main()
{
    // - Crie um programa principal que crie uma matriz de 50 estruturas restaurante;
    Restaurante restaurantes[50];

    //  pergunte a quantidade de restaurantes a serem lidos;
    int quantidade;
    do {
        printf("Quantos restaurantes serão digitados (Máx. 50): ");
        quantidade = lerInt();
    } while (quantidade < 1 || quantidade > 50);

    //  leia os dados desses restaurantes no vetor;
    // for(int cont = 0; cont < quantidade; cont++)
    // {
    //     restaurantes[cont] = obterRestaurante();
    // }
    quantidade = 3;
    preguica(restaurantes);

    //  mostre os dados dos restaurantes lidos;
    mostrarRestaurantes(restaurantes, quantidade);

    //  pergunte uma faixa de valores de preço;
    float min, max;
    printf("Preço mínimo: R$ ");
    min = lerFloat();
    printf("Preço máximo: R$ ");
    max = lerFloat();

    //  mostre os restaurantes com preço médio nessa faixa;
    mostrarRestaurantesIntervaloPreco(restaurantes, quantidade, min, max);

    //  pergunte um tipo de comida;
    char tipo[255];
    printf("Tipo comida: ");
    lerString(tipo, 255);

    //  mostre os restaurantes com esse tipo de comida.
    mostrarRestaurantesTipoComida(restaurantes, quantidade, tipo);

    return 0;
}

Restaurante obterRestaurante()
{
    Restaurante r;

    printf("Digite o nome: ");
    lerString(r.nome, 255);
    printf("Digite o endereço: ");
    lerString(r.endereco, 255);
    printf("Digite o preço médio: R$ ");
    r.precoMedio = lerFloat();
    printf("Digite o tipo da comida: ");
    lerString(r.tipoComida, 255);

    return r;
}

void mostrarRestaurante(Restaurante r)
{
    printf("Nome: %s\n", r.nome);
    printf("Endereço: %s\n", r.endereco);
    printf("Preço Médio: R$ %.2f\n", r.precoMedio);
    printf("Tipo da comida: %s\n", r.tipoComida);
}

void mostrarRestaurantes(Restaurante restaurantes[], int quantidade)
{
    for (int cont = 0; cont < quantidade; cont++)
    {
        mostrarRestaurante(restaurantes[cont]);
    }
}

void mostrarRestaurantesIntervaloPreco(Restaurante restaurantes[], int quantidade, 
                                       float minPreco, float maxPreco)
{
    for (int cont = 0; cont < quantidade; cont++)
    {
        if (restaurantes[cont].precoMedio >= minPreco && restaurantes[cont].precoMedio <= maxPreco)
        {
            mostrarRestaurante(restaurantes[cont]);
        }
    }                       
}

void preguica(Restaurante restaurantes[])
{
    strcpy(restaurantes[0].nome, "McDonalds");
    strcpy(restaurantes[0].endereco, "Rua Seilah, 222");
    restaurantes[0].precoMedio = 50.0;
    strcpy(restaurantes[0].tipoComida, "Fast Food");

    strcpy(restaurantes[1].nome, "Habibs");
    strcpy(restaurantes[1].endereco, "Rua Seilah, 333");
    restaurantes[1].precoMedio = 20.0;
    strcpy(restaurantes[1].tipoComida, "Arabe");

    strcpy(restaurantes[2].nome, "Burger King");
    strcpy(restaurantes[2].endereco, "Rua Seilah, 444");
    restaurantes[2].precoMedio = 50.0;
    strcpy(restaurantes[2].tipoComida, "Fast Food");
}

void mostrarRestaurantesTipoComida(Restaurante restaurantes[], int quantidade, char tipoComida[])
{
    char tipoRestaurante[255], tipoRecebido[255];
    strcpy(tipoRecebido, tipoComida);
    minuscula(tipoRecebido);
    for (int cont = 0; cont < quantidade; cont++)
    {
        strcpy(tipoRestaurante, restaurantes[cont].tipoComida);
        minuscula(tipoRestaurante);
        if (strcmp(tipoRecebido, tipoRestaurante) == 0)
        {
            mostrarRestaurante(restaurantes[cont]);
        }
    } 
}