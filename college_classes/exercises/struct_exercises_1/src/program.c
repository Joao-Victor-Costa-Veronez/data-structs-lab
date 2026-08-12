/*
DATE: 06/08/2026
*/

// Importing libraries
#include "utilities.h"

// Declaring structs
typedef struct {
    char name[255];
    char address[255];
    float averagePrice;
    char foodType[255];
} restaurant;

// Including libraries
restaurant createRestaurant();
void showRestaurant(restaurant r);
void showRestaurants(restaurant restaurants[], int quantity);
void showRestaurantsPriceRange(restaurant restaurants[], int quantity, float minPrice, float maxPrice);
void preguica(restaurant restaurantes[]);

// Main function
int main() {
    // Declaring variables
    restaurant restaurants[50];
    int quantity;

    // Asking
    do {
        printf("Inform how manu restaurants will be added (Max. 50): ");
        quantity = readInteger();
    } while (quantity < 1 && quantity > 50);
    
    quantity = 3;
    preguica[restaurant];

    showRestaurants(restaurants, quantity);

    float min, max;
    printf("Minimun price: $ ");
    min = readFloat();
    printf("Maximun price: $ ");
    max = readFloat();

    // Showing the restaurant
    showRestaurantsPriceRange(restaurants, 3, 15.0, 30.0);

    return 0;
}

// Function that create a restaurant
restaurant createRestaurant() {
    // Declaring variables
    restaurant r;

    printf("Inform the name: ");
    readString(r.name, 255);

    printf("Inform the address: ");
    readString(r.address, 255);

    printf("Inform the average price: $ ");
    r.averagePrice = readFloat();

    printf("Inform the food type: ");
    readString(r.foodType, 255);
    
    return r;
}

// Function that shows a restaurant
void showRestaurant(restaurant r) {
    // Showing all informations of the restaurant
    printf("Name: %s\n", r.name);
    printf("Address: %s\n", r.address);
    printf("Average price: $ %.2f\n", r.averagePrice);
    printf("Food type: %s\n", r.foodType);
}

// Function that shows retaurants
void showRestaurants(restaurant restaurants[], int quantity) {
    for (int i = 0; i < quantity; i++) {
        showRestaurant(restaurants[i]);
    }
}

// Function that shows the restaurants in the range of prices
void showRestaurantsPriceRange(restaurant restaurants[], int quantity, float minPrice, float maxPrice) {
    for (int i = 0; i < quantity; i++) {
        if ((restaurants[i].averagePrice <= minPrice) && (restaurants[i].averagePrice <= maxPrice)) {
            showRestaurant(restaurants[i]);
        }
    }
}

void preguica(restaurant restaurantes[])
{
    strcpy(restaurantes[0].name, "McDonalds");
    strcpy(restaurantes[0].address, "Rua Seilah, 222");
    restaurantes[0].averagePrice = 50.0;
    strcpy(restaurantes[0].foodType, "Fast Food");

    strcpy(restaurantes[1].name, "Habibs");
    strcpy(restaurantes[1].address, "Rua Seilah, 333");
    restaurantes[1].averagePrice = 20.0;
    strcpy(restaurantes[1].foodType, "Arabe");

    strcpy(restaurantes[2].name, "Burger King");
    strcpy(restaurantes[2].address, "Rua Seilah, 444");
    restaurantes[2].averagePrice = 50.0;
    strcpy(restaurantes[2].foodType, "Fast Food");
}

// Function that shows the restaurants in the range of prices
void showRestaurantsFoodType(restaurant restaurants[], int quantity, char foodType[]) {
    char text[255];
    lowerCase(foodType);
    for (int i = 0; i < quantity; i++) {
        strcpy(text, restaurants[i].foodType);
        lowerCase(text);
        if (strcmp(foodType, text) == 0) {
            showRestaurant(restaurants[i]);
        }
    }
}

/*

PROFESSOR REOLUTION:


#ifndef UTILIDADES_H
#define UTILIDADES_H 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void lerString(char texto[], int tamanho);
int lerInt();
float lerFloat();

void maiuscula(char texto[]);
void minuscula(char texto[]);

#endif



#include "utilidades.h"

void lerString(char texto[], int tamanho)
{
    if (fgets(texto, tamanho, stdin) != NULL) {
        texto[strcspn(texto, "\n")] = '\0';
    } else {
        printf("Erro lendo uma String.\n");
        exit(1);
    }
}

int lerInt()
{
    char texto[255];
    lerString(texto, 255);
    return atoi(texto);
}

float lerFloat()
{
    char texto[255];
    lerString(texto, 255);
    return (float)atof(texto);
}

void maiuscula(char texto[])
{
    for (int cont = 0; texto[cont] != '\0'; cont++) {
        texto[cont] = (char)toupper(texto[cont]);
    }
}

void minuscula(char texto[])
{
    for (int cont = 0; texto[cont] != '\0'; cont++) {
        texto[cont] = (char)tolower(texto[cont]);
    }
}




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