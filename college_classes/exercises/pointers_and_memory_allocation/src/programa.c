/*
DATE: 08/19/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float temperatureConversion(float *temperature, int *option);
void showVector(int *vector, int lenght);
void randomizeVector(int *vector, int length, int min, int max);
float averageVectorValue(int *vector, int length);
int main()
{
    float temperature = 26.0;
    int option = 0;
    int length = 5, vector[length];
    int min = 0, max = 100;

    temperature = temperatureConversion(&temperature, &option);
    printf("\nTemperature: %.2f\n", temperature);

    option++;

    temperature = temperatureConversion(&temperature, &option);
    printf("Temperature: %.2f\n\n", temperature);

    for (int i = 0; i < length; i++)
    {
        vector[i] = i;
    }

    showVector(vector, length);

    randomizeVector(vector, length, min, max);

    printf("The average value of the vector is: %.2f\n\n", averageVectorValue(vector, length));

    return 0;
}

float temperatureConversion(float *temperature, int *option)
{
    if (*option == 0)
    {
        return *temperature * 1.8 + 32.0;
    }
    else if (*option == 1)
    {
        return 5.0 / 9.0 * (*temperature - 32.0);
    }
}

void showVector(int *vector, int length)
{
    int i = 0;

    printf("[");
    for (i = 0; i < (length - 1); i++)
    {
        printf("%d, ", *(vector + i));
    }
    printf("%d]\n\n", *(vector + i));
}

void randomizeVector(int *vector, int length, int min, int max)
{
    srand(time(NULL));
    for (int i = 0; i < length; i++)
    {
        vector[i] = (rand() % (max - min + 1)) + min;
    }

    showVector(vector, length);
}

float averageVectorValue(int *vector, int length)
{
    int *pointVector;
    float sum = 0.0;

    pointVector = vector;

    for (int i = 0; i < length; i++, pointVector++)
    {
        sum += *pointVector;
    }

    return sum / length;
}
