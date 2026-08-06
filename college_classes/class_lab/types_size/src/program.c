#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("%d\n", sizeof(int));
    printf("%d\n", sizeof(char));
    printf("%d\n", sizeof(float));
    printf("%d\n", sizeof(int[10]));
    printf("%d\n", sizeof(char[10]));
    printf("%d\n", sizeof(float[10]));
    printf("%d\n", sizeof(int));
    
    return 0;
}