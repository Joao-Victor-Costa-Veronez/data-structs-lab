/*
DATE CREATION: 30/07/2026
LAST UPDATE: 01/08/2026
*/

// Importing libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaring functions
int numberIsPrime(int number);
int yearIsLeap(int year);
int dayWeek(int day, int month, int year);
void showWeekDay(int day, int month, int year);

// Main function
int main() {
    int number = 0;
    int day = 0, month = 0, year = 0;

    printf("Inform a number: ");
    scanf("%d", &number);

    printf("This number is prime?: %d\n", numberIsPrime(number));

    printf("Inform a day inf the format dd/mm/yyyy: ");
    scanf("%d/%d/%d", &day, &month, &year);

    printf("This year was/is/is going to be leap? %d\n", yearIsLeap(year));

    printf("This day was/is/is going to be a: %d\n", dayWeek(day, month, year));

    printf("Or, better sayng, was/is/going to be a: ");
    showWeekDay(day, month, year);

    return 0;
}

// Function that checks if a number is prime
int numberIsPrime(int number) {
    // Declaring variables
    int gotDivided = 0;

    // For each number before half of this number
    for (int i = 1; i <= (number/2); i++) {

        // If the rest of the number divided by i is 0
        if ((number % i) == 0) {

            // Saying that this division was sucssed
            gotDivided++;
        }
    }

    // If the were made just 1 division; return 1 (is prime)
    if (gotDivided == 1) return 1;

    // If it didn't has returned yet, is not prime (return 0)
    return 0;
}

// Function that checks if a year is leap
int yearIsLeap(int year) {
    /* If the year is (divisible for 4, AND not for 100), OR is divisible for 400;
    return 1 (is a leap year) */
    if ((((year % 4) == 0) && ((year % 100) != 100))
        || ((year % 400) == 0)) return 1;

    // if it didn't has returned yet, is not a leap year (return 0)
    return 0;
}

// Function that calculates the day of the week
int dayWeek(int day, int month, int year) {

    // Declaring variables
    int f = year + day + 3 * (month - 1) - 1;

    // If the month is less than 3; Decrement the year
    if (month < 3) year--;
    // Else; f is decremented by the result of the formula
    else f -= (int)(0.4 * month + 2.3);

    // f is incremented by the result of the formula
    f += (int)(year/4) - (int)((year/100 + 1) * 0.75);

    // f is decremented by 7
    f %= 7;

    // Return the result of f
    return f;
}

// Function that shows the day of the week
void showWeekDay(int day, int month, int year) {
    // Declaring variables
    int d = dayWeek(day, month, year);

    // In case of d be
    switch(d) {
        // 0
        case 0: printf("Sunday\n");
            break;

        // 1
        case 1: printf("Monday\n");
            break;

        // 2 
        case 2: printf("Tuesday\n");
            break;

        // 3
        case 3: printf("Wednesday\n");
            break;

        // 4
        case 4: printf("Thursday\n");
            break;

        // 5
        case 5: printf("Friday\n");
            break;
            
        // 6
        case 6: printf("Saturday\n");
            break;

        // None of the above
        default: printf("Invalid day.\n");
            break;
    }
}