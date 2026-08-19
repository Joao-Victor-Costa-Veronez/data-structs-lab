/*
DATE: 08/19/2022
*/
/*

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float temperatureConversion(float *temperature, int *option);
int main()
{
    printf("Funciona!\n");
    return 0;
}

float temperatureConversion(float *temperature, int *option)
{
    if (*option == 0)
    {
        return *temperature * 1.8 + 32;
    }
    else if (*option == 1)
    {
        return 5 / 9 * (*temperature - 32);
    }
}