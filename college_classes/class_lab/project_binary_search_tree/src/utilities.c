#include "utilities.h"

void readString(char text[], int size)
{
    if (fgets(text, size, stdin) != NULL) {
        text[strcspn(text, "\n")] = '\0';
    } else {
        printf("Error reading a string.\n");
        exit(1);
    }
}

int readInt()
{
    char text[255];
    readString(text, 255);
    return atoi(text);
}

float readFloat()
{
    char text[255];
    readString(text, 255);
    return (float)atof(text);
} 