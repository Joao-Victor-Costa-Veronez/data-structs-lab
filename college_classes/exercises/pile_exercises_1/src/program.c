/*
DATE: 10/14/2026
*/

// Importing libraries
#include <string.h>
#include "listsll.h"
#include "ipile.h"

// Declaring functions
void showBinaryFormat(int value);

// Main function
int main()
{
    // Test: Showing a number on a binary format
    showBinaryFormat(7);

    return 0;
}

// Function that shows a number on a binary format
void showBinaryFormat(int value)
{
    // Creating a pile
    iPile *pile = createIPile();

    // While the value is greater than 0
    while (value > 0)
    {
        // Add the rest of the value when divided by 2
        stackIPile(value % 2, pile);

        // Value now is half of it's the value 
        value = value / 2;
    }

    // While pile's length is greater than 0
    while (pile->length > 0)
    {
        // Show the pile's top
        printf("%d", showTopIPile(pile));

        // Removing the pile's top
        unStackIPile(pile);
    }
    printf("\n");

    // Deleting the pile
    deleteIPile(&pile);
}
