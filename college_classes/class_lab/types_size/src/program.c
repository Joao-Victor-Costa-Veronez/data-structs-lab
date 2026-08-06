/*
DATE: 06/08/2026
*/

// Importing libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaring structs
struct point2D {
    int x;
    int y;
};

// Main function
int main() {
    // Showing the sizes of the types
    printf("%ld\n", sizeof(int));    // 4
    printf("%ld\n", sizeof(char));   // 1
    printf("%ld\n", sizeof(float));  // 4
    printf("%ld\n", sizeof(int[10]));    // 40
    printf("%ld\n", sizeof(char[10]));   // 10
    printf("%ld\n", sizeof(float[10]));  // 40
    printf("%ld\n", sizeof(struct point2D));  // 8

    return 0;
}