/*
DATE: 10/14/2026
*/

// Importing libraries
#include <string.h>
#include "listsll.h"
#include "ipile.h"

// Main function
int main()
{
    // Test: Creating a int pile
    iPile *pile1 = createIPile();

    // Test: Showing the pile
    showIPile(pile1);

    // Test: Showing the top's pile
    showTopIPile(pile1);

    // Test: Adding nodes to the pile
    stackIPile(3, pile1);
    showIPile(pile1);
    printf("%d\n\n", showTopIPile(pile1));
    stackIPile(2, pile1);
    showIPile(pile1);
    printf("%d\n\n", showTopIPile(pile1));
    stackIPile(1, pile1);
    showIPile(pile1);
    printf("%d\n\n", showTopIPile(pile1));

    return 0;
}
