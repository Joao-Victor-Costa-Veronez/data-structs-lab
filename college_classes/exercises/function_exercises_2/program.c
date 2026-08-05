/*
DATE: 08/05/2026
*/

// importing libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaring functions
void showMainMenu();
void showVectorsIntegers(int vector[], int length);

// Main function
int main() {
    // Declaring variables
    int option = 0;
    int length = 10;
    int vector[length];

    // Title
    printf("+=====          FUNCTIONS   -   EXERCISE    2      =====+\n\n");

    // For each element in the vector
    for (int i = 0; i < length; i++) {
        // Ask and read the element
        printf("Inform the %d° of %d elements: ", (i+1), length);
        scanf("%d", &vector[i]);
    }

    // Do
    do {
        // Showing the menu
        showMainMenu();
        // Getting the chose option
        scanf("%d", &option);

        // In the case of the option be
        switch (option) {
        // 1
        case 1: // Show the integers of the element
                showVectorIntegers(vector, length);

                break;

        // 2
        case 2:

        }
      // While option is different of 8
    } while (option != 6);

    return 0;
}

// Function that shows the temperature convertions menu
void showTemperatureConvertionsMenu() {
    printf("+=======================================================+\n");
    printf("|           OPERATIONS AND VERIFICATIONS MENU           |\n");
    printf("+=======================================================+\n");
    printf("|   1. Show the integers of a vector.                   |\n");
    printf("|   2.                         |\n");
    printf("+=======================================================+\n");
    printf("|   Choose your operation: ");
}

// Funtion that shows the integers of a vector
void showVectorIntegers(int vector[], int length) {
    printf("[");
    // For each element in the vector
    for (int i = 0; i < (length-1); i++) {
        // Show the number
        printf("%d, ", vector[i]);
    }
    // Show the laste element
    printf("%d]\n", vector[length-1]);
}