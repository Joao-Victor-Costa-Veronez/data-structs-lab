/*
DATE: 08/19/2022
*/

#include <time.h>
#include "utilidades.h"

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
    // Declaring variables
    int length = 20, vector[length];
    int lowestValueIndex = findLowestVectorValueIndex(vector, length), greatestValueIndex = findGreatestVectorValueIndex(vector, length);

    // The user fills the first 10 elements
    for (int i = 0; i < 10; i++)
    {
        printf("Please, inform the vector[%d] element: ", i);
        vector[i] = lerInt();
    }
    printf("\n");

    // Randomly filling the last 10 elements 
    randomizeVector(&vector[(length - 10)], (length - 10), 1, 100);

    // Showing the vector
    showVector(vector, length);

    // Showing the vector average value
    printf("The vector average value is: %d\n\n", averageVectorValue(vector, length));

    // Showing the vector lowest and greatest value
    printf("The vector lowest index value is: %d\nAnd it's value is %d\n\n", lowestValueIndex, vector[lowestValueIndex]);
    printf("The vector greatest index value is: %d\nAnd it's value is %d\n\n", greatestValueIndex, vector[greatestValueIndex]);

    // Return 0
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

// Function that check for repeated values in the vector
int checkRepeatedValues(int *vector, int length)
{
    // For each element in the vector
    for (int i = 0; i < length; i++)
    {
        // For each value after the element I'm comparing with the others
        for (int j = i; j < length; j++)
        {
            // If the
            if ((vector[i] == vector[j]) && (i != j))
            {
                return 1;
            }
        }
    }

    return 0;
}

// Function that search for a value in the vector
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

// Function that checks the ordination of a vector
int checkOrdination(int *vector, int length)
{
    // Declaring variables
    int ascending = 0, descending = 0;

    vector++;
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
