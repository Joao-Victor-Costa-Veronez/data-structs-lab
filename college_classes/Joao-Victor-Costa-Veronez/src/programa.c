#include <stdio.h>
#include <stdlib.h>
#include "listasli.h"
#include "listadli.h"
#include "prova.h"

// ============================================================================
// FUNÇÕES AUXILIARES DE VERIFICAÇÃO (ESPELHADAS DO CORRETOR OFICIAL)
// ============================================================================

void popularLSLI(ListaSLI *l, int *valores, int n) {
    for (int i = 0; i < n; i++) inserirFimLSLI(valores[i], l);
}

void popularLDLI(ListaDLI *l, int *valores, int n) {
    for (int i = 0; i < n; i++) inserirFimLDLI(valores[i], l);
}

void salvarEnderecosLSLI(ListaSLI *l, NoSLI **vetorEnd) {
    NoSLI *aux = l->inicio;
    int i = 0;
    while (aux != NULL) {
        vetorEnd[i++] = aux;
        aux = aux->proximo;
    }
}

void salvarEnderecosLDLI(ListaDLI *l, NoDLI **vetorEnd) {
    NoDLI *aux = l->inicio;
    int i = 0;
    while (aux != NULL) {
        vetorEnd[i++] = aux;
        aux = aux->proximo;
    }
}

// Verifica integridade completa da Lista Simplesmente Ligada + Endereços In-Place
int verificarLSLI(ListaSLI *l, int *valEsp, NoSLI **endEsp, int tamEsp, const char *nomeLista) {
    if (l == NULL) {
        printf("    [ERRO] %s eh NULL!\n", nomeLista);
        return 0;
    }
    int ok = 1;
    if (l->tamanho != tamEsp) {
        printf("    [ERRO] %s->tamanho = %d (Esperado: %d)\n", nomeLista, l->tamanho, tamEsp);
        ok = 0;
    }
    if (tamEsp == 0) {
        if (l->inicio != NULL) {
            printf("    [ERRO] %s deveria estar vazia (inicio == NULL), mas inicio != NULL!\n", nomeLista);
            ok = 0;
        }
        return ok;
    }

    NoSLI *aux = l->inicio;
    int i = 0;
    while (aux != NULL && i < tamEsp) {
        if (aux->valor != valEsp[i]) {
            printf("    [ERRO] %s pos %d: valor = %d (Esperado: %d)\n", nomeLista, i, aux->valor, valEsp[i]);
            ok = 0;
        }
        if (endEsp != NULL && aux != endEsp[i]) {
            printf("    [ERRO IN-PLACE] %s pos %d: endereco do no foi alterado (proibido criar no ou trocar apenas os ints)!\n", nomeLista, i);
            ok = 0;
        }
        aux = aux->proximo;
        i++;
    }
    if (i < tamEsp) {
        printf("    [ERRO] %s terminou antes do esperado (faltam nos no encadeamento)!\n", nomeLista);
        ok = 0;
    } else if (aux != NULL) {
        printf("    [ERRO] %s tem mais nos do que o esperado (ultimo->proximo nao eh NULL)!\n", nomeLista);
        ok = 0;
    }
    return ok;
}

// Verifica integridade completa da Lista Duplamente Ligada (Ida, Volta, Aterramento e In-Place)
int verificarLDLI(ListaDLI *l, int *valEsp, NoDLI **endEsp, int tamEsp, const char *nomeLista) {
    if (l == NULL) {
        printf("    [ERRO] %s eh NULL!\n", nomeLista);
        return 0;
    }
    int ok = 1;
    if (l->tamanho != tamEsp) {
        printf("    [ERRO] %s->tamanho = %d (Esperado: %d)\n", nomeLista, l->tamanho, tamEsp);
        ok = 0;
    }
    if (tamEsp == 0) {
        if (l->inicio != NULL || l->fim != NULL) {
            printf("    [ERRO] %s vazia deve ter inicio == NULL e fim == NULL!\n", nomeLista);
            ok = 0;
        }
        return ok;
    }

    if (l->inicio == NULL || l->fim == NULL) {
        printf("    [ERRO] %s tem tamanho %d, mas inicio ou fim eh NULL!\n", nomeLista, tamEsp);
        return 0;
    }
    if (l->inicio->anterior != NULL) {
        printf("    [ERRO] %s->inicio->anterior nao eh NULL!\n", nomeLista);
        ok = 0;
    }
    if (l->fim->proximo != NULL) {
        printf("    [ERRO] %s->fim->proximo nao eh NULL!\n", nomeLista);
        ok = 0;
    }

    // 1. Verifica percurso de IDA (inicio -> proximo)
    NoDLI *aux = l->inicio;
    int i = 0;
    while (aux != NULL && i < tamEsp) {
        if (aux->valor != valEsp[i]) {
            printf("    [ERRO IDA] %s pos %d: valor = %d (Esperado: %d)\n", nomeLista, i, aux->valor, valEsp[i]);
            ok = 0;
        }
        if (endEsp != NULL && aux != endEsp[i]) {
            printf("    [ERRO IN-PLACE] %s pos %d: endereco do no foi alterado!\n", nomeLista, i);
            ok = 0;
        }
        aux = aux->proximo;
        i++;
    }
    if (i != tamEsp || aux != NULL) {
        printf("    [ERRO IDA] Quantidade de nos no percurso inicio->fim nao bate com %d!\n", tamEsp);
        ok = 0;
    }

    // 2. Verifica percurso de VOLTA (fim -> anterior)
    aux = l->fim;
    int j = tamEsp - 1;
    int contVolta = 0;
    while (aux != NULL && j >= 0) {
        if (aux->valor != valEsp[j]) {
            printf("    [ERRO VOLTA] %s (fim->inicio) pos %d: valor = %d (Esperado: %d) - Ponteiro 'anterior' quebrado!\n", nomeLista, j, aux->valor, valEsp[j]);
            ok = 0;
        }
        aux = aux->anterior;
        j--;
        contVolta++;
    }
    if (contVolta != tamEsp || aux != NULL) {
        printf("    [ERRO VOLTA] Percurso fim->inicio quebrado (verifique os ponteiros 'anterior' e 'fim')!\n");
        ok = 0;
    }

    return ok;
}

// ============================================================================
// CASOS DE TESTE DA QUESTÃO 1: ehPalindromoLDLI (15.0 pts)
// ============================================================================

int teste_Q1_1() {
    printf("  [Q1.1] Casos Base: Lista vazia (0) e 1 elemento (1) (3.0 pts)... ");
    ListaDLI *l = criarListaDLI();
    int r_vazia = ehPalindromoLDLI(l);
    inserirFimLDLI(42, l);
    int r_unit = ehPalindromoLDLI(l);
    destruirLDLI(&l);

    if (r_vazia == 0 && r_unit == 1) {
        printf("PASSOU!\n");
        return 1;
    }
    printf("FALHOU! (Retornou vazia=%d, 1_elem=%d | Esperado: 0 e 1)\n", r_vazia, r_unit);
    return 0;
}

int teste_Q1_2() {
    printf("  [Q1.2] Palindromos de tamanho impar e par (6.0 pts)... ");
    ListaDLI *l = criarListaDLI();
    int v1[] = {10, 20, 30, 20, 10};
    popularLDLI(l, v1, 5);
    NoDLI *ends[5];
    salvarEnderecosLDLI(l, ends);

    int r_impar = ehPalindromoLDLI(l);
    int intacta = verificarLDLI(l, v1, ends, 5, "Lista Q1.2");

    limparLDLI(l);
    int v2[] = {5, 15, 25, 25, 15, 5};
    popularLDLI(l, v2, 6);
    int r_par = ehPalindromoLDLI(l);
    destruirLDLI(&l);

    if (r_impar == 1 && r_par == 1 && intacta) {
        printf("PASSOU!\n");
        return 1;
    }
    printf("FALHOU! (impar=%d, par=%d, intacta=%d | Esperado: 1, 1, 1)\n", r_impar, r_par, intacta);
    return 0;
}

int teste_Q1_3() {
    printf("  [Q1.3] Nao-Palindromos: extremos diferentes e miolo diferente (6.0 pts)... ");
    ListaDLI *l = criarListaDLI();
    int v1[] = {10, 20, 30, 20, 99};
    popularLDLI(l, v1, 5);
    int r_ext = ehPalindromoLDLI(l);

    limparLDLI(l);
    int v2[] = {10, 20, 30, 40, 20, 10};
    popularLDLI(l, v2, 6);
    int r_miolo = ehPalindromoLDLI(l);
    destruirLDLI(&l);

    if (r_ext == 0 && r_miolo == 0) {
        printf("PASSOU!\n");
        return 1;
    }
    printf("FALHOU! (extremos=%d, miolo=%d | Esperado: 0 e 0)\n", r_ext, r_miolo);
    return 0;
}

// ============================================================================
// CASOS DE TESTE DA QUESTÃO 2: moverParaInicioLSLI (20.0 pts)
// ============================================================================

int teste_Q2_1() {
    printf("  [Q2.1] Casos Base: Vazia (0), inexistente (0) e ja no inicio (1) (4.0 pts)... ");
    ListaSLI *l = criarListaSLI();
    int r_vaz = moverParaInicioLSLI(10, l);

    int v[] = {10, 20, 30};
    popularLSLI(l, v, 3);
    NoSLI *ends[3];
    salvarEnderecosLSLI(l, ends);

    int r_inex = moverParaInicioLSLI(99, l);
    int r_ini = moverParaInicioLSLI(10, l);
    int ok_lista = verificarLSLI(l, v, ends, 3, "Lista Q2.1");
    destruirLSLI(&l);

    if (r_vaz == 0 && r_inex == 0 && r_ini == 1 && ok_lista) {
        printf("PASSOU!\n");
        return 1;
    }
    printf("FALHOU! (Retornos: vazia=%d, inex=%d, ja_inicio=%d | Esperado: 0, 0, 1)\n", r_vaz, r_inex, r_ini);
    return 0;
}

int teste_Q2_2() {
    printf("  [Q2.2] Mover no do MEIO + 1a ocorrencia de duplicados In-Place (8.0 pts)... ");
    ListaSLI *l = criarListaSLI();
    int v[] = {10, 20, 30, 20, 40};
    popularLSLI(l, v, 5);
    NoSLI *orig[5];
    salvarEnderecosLSLI(l, orig);

    int valEsp[] = {20, 10, 30, 20, 40};
    NoSLI *endEsp[] = {orig[1], orig[0], orig[2], orig[3], orig[4]};

    int ret = moverParaInicioLSLI(20, l);
    int ok_lista = verificarLSLI(l, valEsp, endEsp, 5, "Lista Q2.2");
    destruirLSLI(&l);

    if (ret == 1 && ok_lista) {
        printf("PASSOU!\n");
        return 1;
    }
    printf("FALHOU! (Retorno=%d, Esperado=1)\n", ret);
    return 0;
}

int teste_Q2_3() {
    printf("  [Q2.3] Mover no do FIM da lista In-Place (8.0 pts)... ");
    ListaSLI *l = criarListaSLI();
    int v[] = {10, 20, 30, 40};
    popularLSLI(l, v, 4);
    NoSLI *orig[4];
    salvarEnderecosLSLI(l, orig);

    int valEsp[] = {40, 10, 20, 30};
    NoSLI *endEsp[] = {orig[3], orig[0], orig[1], orig[2]};

    int ret = moverParaInicioLSLI(40, l);
    int ok_lista = verificarLSLI(l, valEsp, endEsp, 4, "Lista Q2.3");
    destruirLSLI(&l);

    if (ret == 1 && ok_lista) {
        printf("PASSOU!\n");
        return 1;
    }
    printf("FALHOU! (Retorno=%d, Esperado=1)\n", ret);
    return 0;
}

// ============================================================================
// CASOS DE TESTE DA QUESTÃO 3: dividirListaLSLI (30.0 pts)
// ============================================================================

int teste_Q3_1() {
    printf("  [Q3.1] Casos Invalidos: Vazia, pos < 0 e pos >= tamanho (5.0 pts)... ");
    ListaSLI *l1 = criarListaSLI();
    ListaSLI *r_vaz = dividirListaLSLI(0, l1);

    int v[] = {10, 20, 30};
    popularLSLI(l1, v, 3);
    NoSLI *orig[3];
    salvarEnderecosLSLI(l1, orig);

    ListaSLI *r_neg = dividirListaLSLI(-1, l1);
    ListaSLI *r_maior = dividirListaLSLI(3, l1);

    int nulos_ok = (r_vaz == NULL && r_neg == NULL && r_maior == NULL);
    int ok_l1 = verificarLSLI(l1, v, orig, 3, "L1 Q3.1");
    destruirLSLI(&l1);

    if (nulos_ok && ok_l1) {
        printf("PASSOU!\n");
        return 1;
    }
    printf("FALHOU! (Retornos deveriam ser todos NULL e L1 intacta)\n");
    return 0;
}

int teste_Q3_2() {
    printf("  [Q3.2] Divisao no MEIO (pos = 2 em lista de 5 elementos) (10.0 pts)... ");
    ListaSLI *l1 = criarListaSLI();
    int v[] = {10, 20, 30, 40, 50};
    popularLSLI(l1, v, 5);
    NoSLI *orig[5];
    salvarEnderecosLSLI(l1, orig);

    int valEsp1[] = {10, 20};
    NoSLI *endEsp1[] = {orig[0], orig[1]};
    int valEsp2[] = {30, 40, 50};
    NoSLI *endEsp2[] = {orig[2], orig[3], orig[4]};

    ListaSLI *l2 = dividirListaLSLI(2, l1);
    int ok1 = verificarLSLI(l1, valEsp1, endEsp1, 2, "L1 (Original)");
    int ok2 = verificarLSLI(l2, valEsp2, endEsp2, 3, "L2 (Nova)");

    destruirLSLI(&l1);
    if (l2 != NULL) destruirLSLI(&l2);

    if (ok1 && ok2) {
        printf("PASSOU!\n");
        return 1;
    }
    printf("FALHOU!\n");
    return 0;
}

int teste_Q3_3() {
    printf("  [Q3.3] Divisao no ULTIMO elemento (pos = tam - 1) (5.0 pts)... ");
    ListaSLI *l1 = criarListaSLI();
    int v[] = {10, 20, 30, 40};
    popularLSLI(l1, v, 4);
    NoSLI *orig[4];
    salvarEnderecosLSLI(l1, orig);

    int valEsp1[] = {10, 20, 30};
    NoSLI *endEsp1[] = {orig[0], orig[1], orig[2]};
    int valEsp2[] = {40};
    NoSLI *endEsp2[] = {orig[3]};

    ListaSLI *l2 = dividirListaLSLI(3, l1);
    int ok1 = verificarLSLI(l1, valEsp1, endEsp1, 3, "L1 (Original)");
    int ok2 = verificarLSLI(l2, valEsp2, endEsp2, 1, "L2 (Nova)");

    destruirLSLI(&l1);
    if (l2 != NULL) destruirLSLI(&l2);

    if (ok1 && ok2) {
        printf("PASSOU!\n");
        return 1;
    }
    printf("FALHOU!\n");
    return 0;
}

int teste_Q3_4() {
    printf("  [Q3.4] Divisao na CABECA (pos = 0: L1 fica vazia e L2 leva tudo) (10.0 pts)... ");
    ListaSLI *l1 = criarListaSLI();
    int v[] = {10, 20, 30};
    popularLSLI(l1, v, 3);
    NoSLI *orig[3];
    salvarEnderecosLSLI(l1, orig);

    ListaSLI *l2 = dividirListaLSLI(0, l1);
    int ok1 = verificarLSLI(l1, NULL, NULL, 0, "L1 (Deve ficar vazia)");
    int ok2 = verificarLSLI(l2, v, orig, 3, "L2 (Nova)");

    destruirLSLI(&l1);
    if (l2 != NULL) destruirLSLI(&l2);

    if (ok1 && ok2) {
        printf("PASSOU!\n");
        return 1;
    }
    printf("FALHOU!\n");
    return 0;
}

// ============================================================================
// CASOS DE TESTE DA QUESTÃO 4: removerTodasOcorrenciasLDLI (35.0 pts)
// ============================================================================

int teste_Q4_1() {
    printf("  [Q4.1] Casos Base: Lista vazia (0) e valor ausente (0) (5.0 pts)... ");
    ListaDLI *l = criarListaDLI();
    int r_vaz = removerTodasOcorrenciasLDLI(10, l);

    int v[] = {10, 20, 30};
    popularLDLI(l, v, 3);
    NoDLI *orig[3];
    salvarEnderecosLDLI(l, orig);

    int r_aus = removerTodasOcorrenciasLDLI(99, l);
    int ok_l = verificarLDLI(l, v, orig, 3, "Lista Q4.1");
    destruirLDLI(&l);

    if (r_vaz == 0 && r_aus == 0 && ok_l) {
        printf("PASSOU!\n");
        return 1;
    }
    printf("FALHOU! (vazia=%d, ausente=%d | Esperado: 0 e 0)\n", r_vaz, r_aus);
    return 0;
}

int teste_Q4_2() {
    printf("  [Q4.2] Remocao no MEIO com elementos CONSECUTIVOS (8.0 pts)... ");
    ListaDLI *l = criarListaDLI();
    int v[] = {10, 5, 5, 20, 5, 30};
    popularLDLI(l, v, 6);
    NoDLI *orig[6];
    salvarEnderecosLDLI(l, orig);

    int valEsp[] = {10, 20, 30};
    NoDLI *endEsp[] = {orig[0], orig[3], orig[5]};

    int ret = removerTodasOcorrenciasLDLI(5, l);
    int ok_l = verificarLDLI(l, valEsp, endEsp, 3, "Lista Q4.2");
    destruirLDLI(&l);

    if (ret == 3 && ok_l) {
        printf("PASSOU!\n");
        return 1;
    }
    printf("FALHOU! (Retornou %d removidos, Esperado: 3)\n", ret);
    return 0;
}

int teste_Q4_3() {
    printf("  [Q4.3] Remocao nas EXTREMIDADES: inicio e fim multiplos (10.0 pts)... ");
    ListaDLI *l = criarListaDLI();
    int v[] = {7, 7, 10, 20, 7};
    popularLDLI(l, v, 5);
    NoDLI *orig[5];
    salvarEnderecosLDLI(l, orig);

    int valEsp[] = {10, 20};
    NoDLI *endEsp[] = {orig[2], orig[3]};

    int ret = removerTodasOcorrenciasLDLI(7, l);
    int ok_l = verificarLDLI(l, valEsp, endEsp, 2, "Lista Q4.3");
    destruirLDLI(&l);

    if (ret == 3 && ok_l) {
        printf("PASSOU!\n");
        return 1;
    }
    printf("FALHOU! (Retornou %d removidos, Esperado: 3)\n", ret);
    return 0;
}

int teste_Q4_4() {
    printf("  [Q4.4] Esvaziamento TOTAL da lista (todos os nos removidos) (12.0 pts)... ");
    ListaDLI *l = criarListaDLI();
    int v[] = {9, 9, 9, 9};
    popularLDLI(l, v, 4);

    int ret = removerTodasOcorrenciasLDLI(9, l);
    int ok_l = verificarLDLI(l, NULL, NULL, 0, "Lista Q4.4 (Vazia)");
    destruirLDLI(&l);

    if (ret == 4 && ok_l) {
        printf("PASSOU!\n");
        return 1;
    }
    printf("FALHOU! (Retornou %d removidos, Esperado: 4 e inicio=fim=NULL)\n", ret);
    return 0;
}

// ============================================================================
// FUNÇÃO PRINCIPAL (COMENTE QUALQUER TESTE QUE ESTEJA DANDO SEGFAULT/LOOP)
// ============================================================================
int main() {
    printf("======================================================================\n");
    printf("   BATERIA COMPLETA DE TESTES DO ALUNO (ESPELHO DO CORRETOR OFICIAL)  \n");
    printf("   Dica: Se um teste travar (SegFault/Loop), comente a linha dele     \n");
    printf("   na funcao main() para que os demais testes possam ser executados.  \n");
    printf("======================================================================\n\n");

    double n1 = 0.0, n2 = 0.0, n3 = 0.0, n4 = 0.0;

    // ------------------------------------------------------------------------
    // QUESTÃO 1 (15.0 pts)
    // ------------------------------------------------------------------------
    printf(">>> TESTANDO QUESTAO 1: ehPalindromoLDLI (15.0 pts)\n");
    int q1_1 = 0, q1_2 = 0, q1_3 = 0;

    q1_1 = teste_Q1_1(); // Comente esta linha se Q1.1 der SegFault/Loop
    q1_2 = teste_Q1_2(); // Comente esta linha se Q1.2 der SegFault/Loop
    q1_3 = teste_Q1_3(); // Comente esta linha se Q1.3 der SegFault/Loop

    if (q1_2 && (q1_3 || q1_1)) {
        if (q1_1) n1 += 3.0;
        if (q1_2) n1 += 6.0;
        if (q1_3) n1 += 6.0;
    } else if (q1_1 || q1_3) {
        printf("  [AVISO Q1] Casos de retorno 0/base so pontuam se o teste principal [Q1.2] passar!\n");
    }
    printf("  --> Subtotal Q1: %.1f / 15.0 pts\n\n", n1);

    // ------------------------------------------------------------------------
    // QUESTÃO 2 (20.0 pts)
    // ------------------------------------------------------------------------
    printf(">>> TESTANDO QUESTAO 2: moverParaInicioLSLI (20.0 pts)\n");
    int q2_1 = 0, q2_2 = 0, q2_3 = 0;

    q2_1 = teste_Q2_1(); // Comente esta linha se Q2.1 der SegFault/Loop
    q2_2 = teste_Q2_2(); // Comente esta linha se Q2.2 der SegFault/Loop
    q2_3 = teste_Q2_3(); // Comente esta linha se Q2.3 der SegFault/Loop

    if (q2_2) n2 += 8.0;
    if (q2_3) n2 += 8.0;
    if ((q2_2 || q2_3) && q2_1) {
        n2 += 4.0;
    } else if (q2_1) {
        printf("  [AVISO Q2] Caso base [Q2.1] so pontua se mover nos reais em [Q2.2] ou [Q2.3]!\n");
    }
    printf("  --> Subtotal Q2: %.1f / 20.0 pts\n\n", n2);

    // ------------------------------------------------------------------------
    // QUESTÃO 3 (30.0 pts)
    // ------------------------------------------------------------------------
    printf(">>> TESTANDO QUESTAO 3: dividirListaLSLI (30.0 pts)\n");
    int q3_1 = 0, q3_2 = 0, q3_3 = 0, q3_4 = 0;

    q3_1 = teste_Q3_1(); // Comente esta linha se Q3.1 der SegFault/Loop
    q3_2 = teste_Q3_2(); // Comente esta linha se Q3.2 der SegFault/Loop
    q3_3 = teste_Q3_3(); // Comente esta linha se Q3.3 der SegFault/Loop
    q3_4 = teste_Q3_4(); // Comente esta linha se Q3.4 der SegFault/Loop

    if (q3_2) n3 += 10.0;
    if (q3_3) n3 += 5.0;
    if (q3_4) n3 += 10.0;
    if ((q3_2 || q3_3) && q3_1) {
        n3 += 5.0;
    } else if (q3_1) {
        printf("  [AVISO Q3] Casos invalidos [Q3.1] so pontuam se dividir a lista em [Q3.2] ou [Q3.3]!\n");
    }
    printf("  --> Subtotal Q3: %.1f / 30.0 pts\n\n", n3);

    // ------------------------------------------------------------------------
    // QUESTÃO 4 (35.0 pts)
    // ------------------------------------------------------------------------
    printf(">>> TESTANDO QUESTAO 4: removerTodasOcorrenciasLDLI (35.0 pts)\n");
    int q4_1 = 0, q4_2 = 0, q4_3 = 0, q4_4 = 0;

    q4_1 = teste_Q4_1(); // Comente esta linha se Q4.1 der SegFault/Loop
    q4_2 = teste_Q4_2(); // Comente esta linha se Q4.2 der SegFault/Loop
    q4_3 = teste_Q4_3(); // Comente esta linha se Q4.3 der SegFault/Loop
    q4_4 = teste_Q4_4(); // Comente esta linha se Q4.4 der SegFault/Loop

    if (q4_2) n4 += 8.0;
    if (q4_3) n4 += 10.0;
    if (q4_4) n4 += 12.0;
    if ((q4_2 || q4_3) && q4_1) {
        n4 += 5.0;
    } else if (q4_1) {
        printf("  [AVISO Q4] Caso base [Q4.1] so pontua se remover nos reais em [Q4.2] ou [Q4.3]!\n");
    }
    printf("  --> Subtotal Q4: %.1f / 35.0 pts\n\n", n4);

    // ------------------------------------------------------------------------
    // RESUMO FINAL
    // ------------------------------------------------------------------------
    double total = n1 + n2 + n3 + n4;
    printf("======================================================================\n");
    printf("   NOTA ESTIMADA NOS TESTES: %.1f / 100.0 pts\n", total);
    printf("   (Sujeita a verificacao automatica de restricoes/funcoes proibidas) \n");
    printf("======================================================================\n");

    return 0;
}