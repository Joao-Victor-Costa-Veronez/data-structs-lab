#include "utilities.h"

// Function that create a restaurant
restaurant createRestaurant() {
    // Declaring variables
    restaurant r;

    return r;
}

// Function that reads a string
void readString(char text[], int length) {
    if (fgets(text, length, stdin) != NULL) {
        text[strcspn(text, "\n")] = '\0';
    } else {
        printf("Error reading the string.\n");
        exit(1);
    }
}

// Function that reads an integer
int readInteger() {
    char text[255];
    readInteger(text, 255);

    return atoi(text);
}