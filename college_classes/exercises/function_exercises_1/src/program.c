/*
EXERCISE: 1) Um número primo é qualquer inteiro positivo divisível apenas
por si próprio e por 1. Escreva uma função que receba um inteiro positivo e,
se este número for primo, retorne 1, caso contrário retorne 0.
DATE: 30/07/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numberIsPrime(int number);

int main() {
    int number = 0;

    printf("Inform a number: ");
    scanf("%d", &number);

    printf("This number is prime?: %d", numberIsPrime(number));

    return 0;
}

int numberIsPrime(int number) {
    // Declaring variables
    int gotDivided = 0;

    // For each number before the half of this number
    for (int i = 1; i < number; i++) {

        // If the rest of the number divided by i is 0
        if ((number % i) == 0) {

            // Saying that this division was sucssed
            gotDivided++;
        }
    }

    // If the were made just 2 divisions; return 1 (is prime)
    if (gotDivided == 2) return 1;

    // If it didn't has returned yet is not prime (return 0)
    return 0;
}