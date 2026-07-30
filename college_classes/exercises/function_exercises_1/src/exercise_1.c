/*
EXERCISE:
- 1) Um número primo é qualquer inteiro positivo divisível apenas
    por si próprio e por 1. Escreva uma função que receba um inteiro positivo e,
    se este número for primo, retorne 1, caso contrário retorne 0.
- 6) Escreva uma função que receba dia, mês e ano e calcule o dia da semana.
    Esta função retorna 0 se for domingo, 1 se for segunda-feira, etc...
    Para calcular o dia da semana use o código a seguir no qual o dia da semana está na variável f:
- 7) Crie uma função que recebe como parâmetros um dia,
    um mês e um ano (inteiros) e escreva na tela por extenso o dia da semana.

DATE: 30/07/2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numberIsPrime(int number);
int dayWeek(int day, int month, int year);

int main() {
    /*
    int number = 0;

    printf("Inform a number: ");
    scanf("%d", &number);

    printf("This number is prime?: %d", numberIsPrime(number));
    */
    int day = 0, month = 0, year = 0;

    printf("Inform a day inf the format dd/mm/yyyy: ");
    scanf("%d/%d/%d", &day, &month, &year);

    printf("This day is a: %d", dayWeek(day, month, year));

    return 0;
}

int numberIsPrime(int number) {
    // Declaring variables
    int gotDivided = 0;

    // For each number before this number
    for (int i = 1; i < number; i++) {

        // If the rest of the number divided by i is 0
        if ((number % i) == 0) {

            // Saying that this division was sucssed
            gotDivided++;
        }
    }

    // If the were made just 2 divisions; return 1 (is prime)
    if (gotDivided == 2) return 1;

    // If it didn't has returned yet, is not prime (return 0)
    return 0;
}

int dayWeek(int day, int month, int year) {

    int f = year + day + 3 * (month - 1) - 1;
    if (month < 3) year--;
    else f -= (int)(0.4 * month + 2.3);
    f += (int)(year/4) - (int)((year/100 + 1) * 0.75);
    f %= 7;
    return f;

}

/*
PROFESSOR RESULOTION:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1) Um número primo é qualquer inteiro positivo divisível apenas por si
//  próprio e por 1. Escreva uma função que receba como parametro um inteiro
//  positivo e, se este número for primo, retorne 1, caso contrário retorne 0.

int ehNumeroPrimo(int numero);

// 6) Escreva uma função que receba dia, mês e ano e calcule o dia da semana.
//  Esta função retorna 0 se for domingo, 1 se for segunda-feira, etc... Para 
// calcular o dia da semana use o código a seguir no qual o dia da semana está
//  na variável f:

// int f = ano + dia + 3 * (mês - 1) - 1;
// if (mês < 3) ano--;
// else f -= (int)(0.4 * mês + 2.3);
// f += (int)(ano/4) - (int)((ano/100 + 1) * 0.75);
// f %= 7;

int diaDaSemana(int dia, int mes, int ano);

// 7) Crie uma função que recebe como parâmetros um dia, um mês e um ano (inteiros)
//  e escreva na tela por extenso o dia da semana.

void mostrarDiaSemana(int dia, int mes, int ano);

int main()
{
    // printf("10: %d\n", ehNumeroPrimo(10));
    // printf("15: %d\n", ehNumeroPrimo(15));
    // printf("17: %d\n", ehNumeroPrimo(17));
    // printf("19: %d\n", ehNumeroPrimo(19));
    // printf("71: %d\n", ehNumeroPrimo(71));
    // printf("72: %d\n", ehNumeroPrimo(72));

    mostrarDiaSemana(30, 7, 2026);
    mostrarDiaSemana(20, 7, 1969);
    mostrarDiaSemana(30, 7, 2050);
    mostrarDiaSemana(11, 9, 2001);

    return 0;
}

void mostrarDiaSemana(int dia, int mes, int ano)
{
    int d = diaDaSemana(dia, mes, ano);
    switch(d) {
        case 0: printf("Domingo\n"); break;
        case 1: printf("Segunda-Feira\n"); break;
        case 2: printf("Terça-Feira\n"); break;
        case 3: printf("Quarta-Feira\n"); break;
        case 4: printf("Quinta-Feira\n"); break;
        case 5: printf("Sexta-Feira\n"); break;
        case 6: printf("Sábado\n"); break;
    }
}

int diaDaSemana(int dia, int mes, int ano)
{
    int f = ano + dia + 3 * (mes - 1) - 1;
    if (mes < 3) ano--;
    else f -= (int)(0.4 * mes + 2.3);
    f += (int)(ano/4) - (int)((ano/100 + 1) * 0.75);
    f %= 7;
    return f;
}

int ehNumeroPrimo(int numero)
{
    int divisoes = 0;
    for (int cont = 1; cont <= numero; cont++)
    {
        if (numero % cont == 0)
        {
            divisoes++;
        }
    }
    if (divisoes == 2)
    {
        return 1;
    }
    return 0;
}
*/