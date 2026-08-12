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

// Main function
int main() {
    // Declaring variables
    restaurant unitedBurgers;

    // Creating a restaurant
    unitedBurgers = createRestaurant();

    // Showing the restaurant
    showRestaurant(unitedBurgers);

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