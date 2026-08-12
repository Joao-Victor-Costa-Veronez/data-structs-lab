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
    restaurant restaurants[10];

    preguica(restaurants);

    // Showing the restaurant
    showRestaurants(restaurants, 3);

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
        if (restaurants[i].averagePrice <= minPrice && restaurants[i].averagePrice <= maxPrice) {
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
