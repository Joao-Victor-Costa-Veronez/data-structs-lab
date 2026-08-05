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
void fillsVectorRandomly(int vector[], int length, int min, int max);
int hasRepeatedValues(int vector[], int length);

// Main function
int main() {
    // Declaring variables
    int option = 0;
    int length = 10;
    int vector[length];

    // Title
    printf("\n+=====    FUNCTIONS   -   EXERCISE    2   =====+\n\n");

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
        case 2: // Randomize tge vector
                fillsVectorRandomly(vector, length, 1, 10);
                // Show the vector
                showVectorIntegers(vector, length);

                break;

        // 3
        case 3:

        // 6
        case 6: // Verify if the vector has repeated elements
                printf("\nThe vector has repeated elements?: %d\n", hasRepeatedValues(vector, length));

                break;

        }
      // While option is different of 8
    } while (option != 8);

    return 0;
}

// Function that shows the temperature convertions menu
void showMainMenu() {
    printf("\n+=====================================================+\n");
    printf("|           OPERATIONS AND VERIFICATIONS MENU           |\n");
    printf("+=======================================================+\n");
    printf("|   1. Show the integers of a vector                    |\n");
    printf("|   2. Randomize the integers of a vector               |\n");
    printf("|   6. Verify if the vector has repeated values         |\n");
    printf("+=======================================================+\n");
    printf("|   Choose your operation: ");
}

// Funtion that shows the integers of a vector
void showVectorIntegers(int vector[], int length) {
    printf("\n[");
    // For each element in the vector
    for (int i = 0; i < (length-1); i++) {
        // Show the number
        printf("%d, ", vector[i]);
    }
    // Show the laste element
    printf("%d]\n\n", vector[length-1]);
}

// Function that fills a vector randomly
void fillsVectorRandomly(int vector[], int length, int min, int max) {
    srand(time(NULL)); // Seed
    for (int i = 0; i < length; i++) {
        vector[i] = (rand() % (max - min + 1)) + min;
    }
}

// Function that tells if a vector has repeated values
int hasRepeatedValues(int vector[], int length) {
    // For each element in the vector
    for (int i = 0; i < length; i++) {
        // For each element after the current one
        for (int j = (i+1); j < length; j++) {
            // If the current element is equals to other element
            if (vector[i] == vector[j]) {
                // Has repeated values (return 1)
                return 1;
            }
        }
    }

    // If the function hasn't returned yet, it hasn't repeated elements (return 0)
    return 0;
}