#ifndef UTILITIES_H
#define UTILITIES_H 1

// Importing libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaring structs
typedef struct {
    char name[255];
    char address[255];
    float averagePrice;
    char foodType[255];
} restaurant;

// Declaring functions
restaurant createRestaurant();
void readString(char text[], int length);
int readInteger();
float readFloat();

#endif