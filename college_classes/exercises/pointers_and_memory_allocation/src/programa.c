/*
DATE: 08/19/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

float temperatureConversion(float *temperature, int *option);
void showVector(int *vector, int lenght);
void randomizeVector(int *vector, int length, int min, int max);
float averageVectorValue(int *vector, int length);
int findGreatestVectorValueIndex(int *vector, int length);
int findLowestVectorValueIndex(int *vector, int length);
int checkRepeatedValues(int *vector, int length);
int searchValueInVector(int *vector, int length, int a);
int checkOrdination(int *vector, int length);
int main()
{
    float temperature = 26.0;
    int option = 0;
    int length = 5, vector[length];
    int min = 0, max = 10;
    int a = 5;

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

    showVector(vector, length);

    printf("The average value of the vector is: %.2f\n\n", averageVectorValue(vector, length));

    printf("The index of the greatest number of the vector is: %d\n\n", findGreatestVectorValueIndex(vector, length));

    printf("The index of the lowest number of the vector is: %d\n\n", findLowestVectorValueIndex(vector, length));

    printf("The vector has repeated values? %d\n\n", checkRepeatedValues(vector, length));

    printf("The first index of the number %d in the vector (-1 for does not exist): %d\n\n", a, searchValueInVector(vector, length, a));

    printf("The ordination of the vector is (0: disorderly; 1: ascending; 2: descending): %d\n\n", checkOrdination(vector, length));

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
    srand((unsigned int)time(NULL));
    for (int i = 0; i < length; i++)
    {
        vector[i] = (rand() % (max - min + 1)) + min;
    }
}

float averageVectorValue(int *vector, int length)
{
    float sum = 0.0;

    for (int i = 0; i < length; i++, vector++)
    {
        sum += (float)*vector;
    }

    return sum / (float)length;
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

    for (int i = 0; i < length; i++, vector++)
    {
        if (lowestValue > *vector)
        {
            lowestValue = *vector;
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

int searchValueInVector(int *vector, int length, int a)
{
    for (int i = 0; i < length; i++)
    {
        if (a == *(vector + i))
        {
            return i;
        }
    }

    return -1;
}

int checkOrdination(int *vector, int length)
{
    int ascending = 0, descending = 0;

    for (int i = 1; i < length; i++, vector++)
    {
        if (*(vector - 1) < *vector)
        {
            ascending = 1;
        }
        else if (*(vector - 1) > *vector)
        {
            descending = 1;
        }
    }

    if ((ascending) && (descending == 0))
    {
        return 1;
    }
    else if ((ascending == 0) && (descending))
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
