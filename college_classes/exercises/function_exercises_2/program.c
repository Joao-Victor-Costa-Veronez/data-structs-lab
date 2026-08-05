/*
DATE: 08/05/2026
*/

// importing libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaring functions
void showVectorsIntegers(int vector[], int length);

// Main function
int main() {
    // Declaring variables
    int length = 10;
    int vector[length];

    // For each element in the vector
    for (int i = 0; i < length; i++) {
        // Ask and read the element
        printf("Inform the %d° of %d elements: ", (i+1), length);
        scanf("%d", &vector[i]);
    }

    // Show the integers of the element
    showVectorIntegers(vector, length);

    return 0;
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