// Including libraries
#include "utilities.h"

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
    readString(text, 255);

    return atoi(text);
}

// Function that reads a float
float readFloat() {
    char text[255];
    readString(text, 255);

    return (float)atof(text);
}