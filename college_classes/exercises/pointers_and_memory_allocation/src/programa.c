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
int findGreatestVectorValueIndex(int *vector, int length);
int findLowestVectorValueIndex(int *vector, int length);
int checkRepeatedValues(int *vector, int length);
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

    printf("The index of the greatest number of the vector is: %d\n\n", findGreatestVectorValueIndex(vector, length));

    printf("The index of the lowest number of the vector is: %d\n\n", findLowestVectorValueIndex(vector, length));

    printf("The vector has repeated values? %d\n\n", checkRepeatedValues(vector, length));

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

int findGreatestVectorValueIndex(int *vector, int length)
{
    int greatestValue = *vector, greatestValueIndex = 0;

    for (int i = 0; i < length; i++)
    {
        if (greatestValue < *(vector + i))
        {
            greatestValue = *(vector + i);
            greatestValueIndex = i;
        }
    }

    return greatestValueIndex;
}

int findLowestVectorValueIndex(int *vector, int length)
{
    int lowestValue = *vector, lowestValueIndex = 0;
    int *pointer;

    pointer = vector;

    for (int i = 0; i < length; i++, pointer++)
    {
        if (lowestValue > *pointer)
        {
            lowestValue = *pointer;
            lowestValueIndex = i;
        }
    }

    return lowestValueIndex;
}

int checkRepeatedValues(int *vector, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = i; j < length; j++)
        {
            if ((vector[i] == vector[j]) && (i != j))
            {
                return 1;
            }
        }
    }

    return 0;
}
