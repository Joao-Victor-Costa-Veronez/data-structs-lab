/*
DATE: 10/15/2026
*/

// Importing libraries
#include <string.h>
#include "utilidades.h"
#include "listsll.h"
#include "ipile.h"

// Declaring functions
int checkRightExpression(char expression[255]);

// Main function
int main()
{
    // Declaring variables
    char expression[255];

    // Reading the string
    printf("\n");
    lerString(expression, 255);

    // Test: Checking if the math expression is well-formed
    printf("%d\n\n", checkRightExpression(expression));

    return 0;
}

// Function that checks if a math expression is well-formed
int checkRightExpression(char expression[255])
{
    // Declaring variables
    iPile *pile = createIPile();
    int value = 0, correct = 1;

    // For each character in the expression
    for (int i = 0; expression[i] != '\0'; i++)
    {
        // If the current character is '(' or '[' or '{'
        if (((expression[i] == '(') ||
             expression[i] == '[') ||
            expression == '{')
        {
            // Stack this character
            stackIPile(expression[i], pile);
        }
        // Else if, the character is ')' or ']' or '}'
        else if (((expression[i] == ')') ||
                  expression[i] == ']') ||
                 expression == '}')
        {
            // Saving the stack's top value
            value = showTopIPile(pile);

            // Stack this character
            unStackIPile(pile);

            // If the character is corresponding to the current pile's top
            if ((((((expression[i] == '(') && showTopIPile(pile) == ')') ||
                   expression[i] == '[') &&
                  showTopIPile(pile) == ']') ||
                 expression[i] == '{') &&
                showTopIPile(pile) == '}')
            {
                // It isn't correct anymore
                correct = 0;
            }
        }
    }

    if (pile->length > 0)
    {
        correct = 0;
    }

    deleteIPile(&pile);

    // If it didn't returned yet, is well-formed
    return correct;
}
