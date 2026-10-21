/*
DATE: 10/21/2026
*/

// Importing libraries
#include <string.h>
#include "listsll.h"
#include "istack.h"
#include "iqueue.h"

// Declaring functions
int checkPalindrome(char *text);
char removeAccent(char original);
int isLetter(char character);

// Declaring variables
char accentsTable[][2] = {
    {-31, 'a'}, {-32, 'a'}, {-30, 'a'}, {-29, 'a'}, {-28, 'a'}, // á, à, â, ã, ä
    {-63, 'A'},
    {-64, 'A'},
    {-62, 'A'},
    {-61, 'A'},
    {-60, 'A'}, // Á, À, Â, Ã, Ä
    {-23, 'e'},
    {-22, 'e'}, // é, ê
    {-55, 'E'},
    {-54, 'E'}, // É, Ê
    {-19, 'i'}, // í
    {-51, 'I'}, // Í
    {-13, 'o'},
    {-12, 'o'},
    {-11, 'o'},
    {-10, 'o'}, // ó, ô, õ, ö
    {-45, 'O'},
    {-44, 'O'},
    {-43, 'O'},
    {-42, 'O'}, // Ó, Ô, Õ, Ö
    {-6, 'u'},
    {-5, 'u'}, // ú, ü
    {-38, 'U'},
    {-37, 'U'}, // Ú, Ü
    {-25, 'c'},
    {-57, 'C'} // ç, Ç
};

// Main function
int main()
{
    return 0;
}

// Function that checks is a text is a palindrome
int checkPalindrome(char *text)
{
    char letter;
    iStack *stack = createIStack();
    IQueue *queue = createIQueue();

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isLetter(text[i]))
        {

        }
    }
    

    deleteIStack(&stack);
    deleteIQueue(&queue);

    return 1;
}

// Function that remove accents
char removeAccents(char letter)
{
    int totalElements = sizeof(accentsTable) / sizeof(accentsTable[0]);
    for (int i = 0; i < totalElements; i++)
    {
        if (accentsTable[i][0] == letter)
        {
            return accentsTable[i][1];
        }
    }
    return letter;
}

int isLetter(char character)
{
    // 1. Letras do ASCII Padrão: A-Z (65-90) e a-z (97-122)
    if ((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z'))
    {
        return 1;
    }

    // 2. Letras Acentuadas e Cedilha no ISO-8859-1:
    // Maiúsculas: À até Þ (192-222) - excluindo o símbolo de multiplicação '×' (215)
    // Minúsculas: à até ÿ (223-255) - excluindo o símbolo de divisão '÷' (247)
    if ((character >= 192 && character <= 222 && character != 215) ||
        (character >= 223 && character <= 255 && character != 247))
    {
        return 1;
    }

    return 0;
}

/*PROFESSOR'S RESOLUTION:



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhai.h"
#include "filai.h"
#include <ctype.h>

char tabelaAcentos[][2] = {
    {-31, 'a'}, {-32, 'a'}, {-30, 'a'}, {-29, 'a'}, {-28, 'a'}, // á, à, â, ã, ä
    {-63, 'A'}, {-64, 'A'}, {-62, 'A'}, {-61, 'A'}, {-60, 'A'}, // Á, À, Â, Ã, Ä
    {-23, 'e'}, {-22, 'e'},                                     // é, ê
    {-55, 'E'}, {-54, 'E'},                                     // É, Ê
    {-19, 'i'},                                                 // í
    {-51, 'I'},                                                 // Í
    {-13, 'o'}, {-12, 'o'}, {-11, 'o'}, {-10, 'o'},             // ó, ô, õ, ö
    {-45, 'O'}, {-44, 'O'}, {-43, 'O'}, {-42, 'O'},             // Ó, Ô, Õ, Ö
    {-6,  'u'}, {-5,  'u'},                                     // ú, ü
    {-38, 'U'}, {-37, 'U'},                                     // Ú, Ü
    {-25, 'c'}, {-57, 'C'}                                      // ç, Ç
};

int ehLetra(char caractere);
char removerAcento(char original);
int ehPalindromo(char texto[]);

int main()
{
    char texto[] = "A cara rajada da jararaca";

    if (ehPalindromo(texto))
    {
        printf("É palindromo\n");
    }
    else {
        printf("Não é palindromo\n");
    }    
    return 0;
}

int ehLetra(char caractere)
{
    // 1. Letras do ASCII Padrão: A-Z (65-90) e a-z (97-122)
    if ((caractere >= 'A' && caractere <= 'Z') || (caractere >= 'a' && caractere <= 'z')) {
        return 1;
    }
    
    // 2. Letras Acentuadas e Cedilha no ISO-8859-1:
    // Maiúsculas: À até Þ (192-222) - excluindo o símbolo de multiplicação '×' (215)
    // Minúsculas: à até ÿ (223-255) - excluindo o símbolo de divisão '÷' (247)
    if ((caractere >= 192 && caractere <= 222 && caractere != 215) || 
        (caractere >= 223 && caractere <= 255 && caractere != 247)) {
        return 1;
    }
    
    return 0;
}

char removerAcento(char letra) {
    int total_elementos = sizeof(tabelaAcentos) / sizeof(tabelaAcentos[0]);
    for (int i = 0; i < total_elementos; i++) {
        if (tabelaAcentos[i][0] == letra) {
            return tabelaAcentos[i][1];
        }
    }
    return letra; 
}

int ehPalindromo(char texto[])
{
    int cont = 0;
    char letra;
    PilhaI * pilha = criarPilhaI();
    FilaI * fila = criarFilaI();
    while (texto[cont] != '\0')
    {
        if (ehLetra(texto[cont]))
        {
            letra = removerAcento(texto[cont]);
            letra = (char)tolower(texto[cont]);
            empilharI(letra, pilha);
            enfileirarI(letra, fila);
        }
        cont++;
    }
    while (fila->tamanho > 0)
    {
        if (proximoI(fila) != topoI(pilha))
        {
            return 0;
        }
        desinfileirarI(fila);
        desempilharI(pilha);
    }
    destruirFilaI(&fila);
    destruirPilhaI(&pilha);
    return 1;
}*/