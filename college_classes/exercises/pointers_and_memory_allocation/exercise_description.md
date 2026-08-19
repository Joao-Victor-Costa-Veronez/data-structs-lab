# Ponteiros para variáveis Simples

1) Crie uma função que receba como parâmetros uma temperatura e um inteiro para indicar a operação, ambos via ponteiro. A função deve retornar a temperatura convertida de acordo com a operação escolhida: se a operação for 0, a temperatura deve ser convertida de Celsius para Fahrenheit e se a operação for 1, a temperatura deve ser convertida de Fahrenheit para Celsius.

Ponteiros, vetores e funções

2) Crie uma função em C que recebe como parâmetros um vetor de inteiros via ponteiro e seu tamanho. A função deve mostrar os elementos do vetor na tela. Use aritmética de ponteiros sem alterar o ponteiro.

3) Crie uma função em C que recebe como parâmetros um vetor de inteiros via ponteiro, seu tamanho, um valor máximo e um valor mínimo. A função deve preencher o vetor com números aleatórios dentro dessa faixa de valores. Use o operador de índice no ponteiro.

4) Crie uma função em C que recebe como parâmetros um vetor de inteiros via ponteiro e seu tamanho. A função deve calcular e retornar a média dos valores do vetor. Use aritmética de ponteiros alterando o ponteiro.

5) Crie uma função em C que recebe como parâmetros um vetor de inteiros via ponteiro e seu tamanho. A função deve encontrar e retornar o índice do maior valor do vetor. Use aritmética de ponteiros sem alterar o ponteiro.

6) Crie uma função em C que recebe como parâmetros um vetor de inteiros via ponteiro e seu tamanho. A função deve encontrar e retornar o índice do menor valor do vetor.  Use aritmética de ponteiros alterando o ponteiro.

7) Crie uma função em C que recebe como parâmetros um vetor de inteiros via ponteiro e seu tamanho. A função deve retornar 1 caso o vetor tenha elementos repetidos e 0 caso contrário. Use o operador de índice no ponteiro.

8) Crie uma função em C que recebe como parâmetros um vetor de inteiros via ponteiro, seu tamanho e um valor inteiro. A função deve retornar o índice do elemento do vetor com esse valor ou -1 caso ele não exista no vetor. Use aritmética de ponteiros sem alterar o ponteiro.

9) Crie uma função em C que recebe como parâmetros um vetor de inteiros via ponteiro e seu tamanho. A função deve retornar 1 caso os elementos estejam em ordem crescente, 2 caso os elementos estejam em ordem decrescente e 0 caso estejam fora de ordem. Use aritmética de ponteiros alterando o ponteiro.

10) No programa principal:

a) Criar um vetor de tamanho 20 de inteiros
b) Preencher os 10 primeiros valores do vetor com números digitados pelo usuário via teclado
c) Preencher os 10 últimos valores do vetor com números aleatórios entre 1 e 100
d) Mostrar o vetor inteiro na tela
e) Calcular e mostrar a média dos valores do vetor
f) Encontrar e mostrar o maior e o menor valor do vetor 
g)Verificar se há elementos repetidos no vetor e exibir uma mensagem em caso afirmativo 
h) Solicitar um valor ao usuário e verificar se esse valor existe no vetor. Se existir exibir a posição em que ele está, senão exibir uma mensagem de valor não encontrado 
i) Verificar se o vetor está em ordem crescente, ou seja, se a[0] <= a[1] <= a[2] <= ... para todos elementos do vetor 

Use as funções que você criou! (2 a 9)


Ponteiros, estruturas, vetores e funções

11) Deseja-se criar um programa em C para manter os dados dos clientes de uma loja.

a) Crie uma estrutura para representar um cliente, chamada cliente, contendo o nome do cliente (cadeia de caracteres de tamanho 60), o CPF do cliente (cadeia de caracteres de tamanho 16), o telefone do cliente (cadeia de caracteres de tamanho 16) e a idade do cliente.

b1) Crie uma função que obtém os dados de uma estrutura cliente pelo teclado e a retorna.

b2) Crie uma função que obtém os dados de uma estrutura cliente pelo teclado e a retorna por referência via um parâmetro do tipo ponteiro.

c) Crie uma função que receba uma estrutura cliente como parâmetro via ponteiro e imprima seus dados na tela.

d) Crie uma função que receba um vetor de estruturas cliente via ponteiro e a quantidade de clientes válidos no vetor como parâmetros e os imprime na tela. Use aritmética de ponteiros sem alterar o ponteiro e com o operador seta.

e) Crie uma função que receba um vetor de estruturas cliente via ponteiro, a quantidade de clientes válidos no vetor e um CPF de cliente como parâmetros. A função deve retornar a posição no vetor que tem um cliente com esse CPF ou -1 caso ele não exista. Use aritmética de ponteiros sem alterar o ponteiro e sem o operador seta.

f) Crie uma função que receba um vetor de estruturas cliente via ponteiro, a quantidade de clientes válidos no vetor, um valor mínimo de idade e um valor máximo de idade como parâmetros. A função deve imprimir os dados de todos os clientes que tiverem idade dentro da faixa recebida como parâmetro. Use aritmética de ponteiros alterando o ponteiro e com o operador seta.

g) Crie um programa principal que:

- Crie um vetor de clientes chamado vetClientes para conter 100 clientes.
- Obtenha via teclado o número de clientes que serão lidos no vetor vetClientes
- Obtenha os dados desse número de clientes, guardando-os no vetor vetClientes, usando a função da letra b2)
- Imprima na tela todos os clientes do vetor vetClientes, usando a função da letra d)
- Obtenha via teclado um CPF
- Mostre na tela o cliente com esse CPF ou avise o usuário caso ele não exista, usando a função da letra e)
- Obtenha via teclado uma faixa mínimo/máximo de idades e mostre os clientes do vetor com idade nessa faixa, usando a função da letra f).



Ponteiros, estruturas, vetores, funções e alocaçao dinâmica

12) Altere o exercício 10) de maneira que o tamanho do vetor seja determinado pelo usuário usando alocação dinâmica para criar o vetor. 

13) Altere o exercício 11) de maneira que o tamanho do vetor de clientes seja determinado pelo usuário usando alocação dinâmica para criar o vetor. 


