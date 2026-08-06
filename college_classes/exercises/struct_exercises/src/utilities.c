#include "utilities.h"

// Function that create a restaurant
restaurant createRestaurant() {
    // Declaring variables
    restaurant r;

    return r;
}

void readString(char text[], int length) {
    if (fgets(text, length, stdin) != NULL) {
        text[strcspn(text, "\n")] = '\0';
    } else {
        printf("Error reading the string.\n");
        exit(1);
    }
}