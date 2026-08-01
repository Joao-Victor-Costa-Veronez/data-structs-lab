# Exercícios sobre Funções 1

1. Um número primo é qualquer inteiro positivo divisível apenas por si próprio e por 1. Escreva uma função que receba um inteiro positivo e, se este número for primo, retorne 1, caso contrário retorne 0.

2. Escreva uma função que receba como argumento o ano e retorne 1 se for um ano bissexto e 0 se não for um ano bissexto. Um ano é bissexto se for divisível por 4, mas não por 100. Um ano também é bissexto se for divisível por 400.

3. Crie uma função que receba uma temperatura em graus Celsius como parâmetro e retorne a temperatura convertida para graus Fahrenheit.

4. Crie uma função que receba uma temperatura em graus Fahrenheit como parâmetro e retorne a
temperatura convertida para graus Celsius.

5. Crie uma função que receba como parâmetros uma temperatura e um inteiro para indicar a operação. Se a operação for 0, a temperatura deve ser convertida de Celsius para Fahrenheit e se a operação for 1, a temperatura deve ser convertida de Fahrenheit para Celsius.

6. Escreva uma função que receba dia, mês e ano e calcule o dia da semana. Esta função retorna 0 se for domingo, 1 se for segunda-feira, etc... Para calcular o dia da semana use o código a seguir no qual o dia da semana está na variável `f`:
```C
int f = ano + dia + 3 * (mês - 1) - 1;
if (mês < 3) ano--;
else f -= (int)(0.4 * mês + 2.3);
f += (int)(ano/4) - (int)((ano/100 + 1) * 0.75);
f %= 7;
```

7) Crie uma função que recebe como parâmetros um dia, um mês e um ano (inteiros) e escreva na tela por extenso o dia da semana.