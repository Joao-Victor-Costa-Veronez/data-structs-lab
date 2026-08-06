/*
DATE: 06/08/2026
*/

// Importing libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaring structs
struct point2D {
    int x;  // 4
    int y;  // 4
    // Total: 8
};

struct person {
    char name[25];  // 25
    char gender;    // 1
    int age;    // 4
    // Total: 30 (adding); Real size: 32
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
    printf("%ld\n", sizeof(struct point2D[10]));  // 8
    printf("%ld\n", sizeof(struct person));  // 32

    return 0;
}