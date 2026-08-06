#ifndef UTILITIES_H
#define UTILITIES_H 1

// Importing libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaring structs
typedef struct {
    char name[100];
    char address[100];
    float averagePrice;
    char foodType[100];
} restaurant;

// Declaring functions
restaurant createRestaurant();
void readString(char text[], int length);

#endif