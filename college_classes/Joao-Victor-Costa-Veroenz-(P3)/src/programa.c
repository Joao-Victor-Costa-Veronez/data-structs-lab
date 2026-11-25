#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhai.h"
#include "filai.h"
#include "filaprio.h"
#include "prova.h"

// ============================================================================
// FUNÇÕES AUXILIARES DE VERIFICAÇÃO (ESPELHADAS DO CORRETOR OFICIAL)
// ============================================================================

void popularPilhaTopoBase(PilhaI *p, int *v, int n) {
    for (int i = n - 1; i >= 0; i--) empilharI(v[i], p);
}

void popularFila(FilaI *f, int *v, int n) {
    for (int i = 0; i < n; i++) enfileirarI(v[i], f);
}

NoPrio* anexarFimPrioTeste(FilaPrio *f, char *nome, int prio) {
    NoPrio *novo = criarNoPrio(nome, prio, f->fim, NULL);
    if (f->tamanho == 0) f->inicio = novo;
    else f->fim->proximo = novo;
    f->fim = novo;
    f->tamanho++;
    return novo;
}

void salvarEnderecosPilha(PilhaI *p, NoSLI **vetorEnd) {
    NoSLI *aux = p->topo;
    int i = 0;
    while (aux != NULL) { vetorEnd[i++] = aux; aux = aux->proximo; }
}

void salvarEnderecosFila(FilaI *f, NoSLI **vetorEnd) {
    NoSLI *aux = f->inicio;
    int i = 0;
    while (aux != NULL) { vetorEnd[i++] = aux; aux = aux->proximo; }
}

int verificarPilhaI(PilhaI *p, int *valEsp, NoSLI **endEsp, int tamEsp, const char *nome) {
    if (p == NULL) { printf("    [ERRO] %s eh NULL!\n", nome); return 0; }
    int ok = 1;
    if (p->tamanho != tamEsp) {
        printf("    [ERRO] %s->tamanho = %d (Esperado: %d)\n", nome, p->tamanho, tamEsp);
        ok = 0;
    }
    if (tamEsp == 0) {
        if (p->topo != NULL) { printf("    [ERRO] %s vazia deve ter topo == NULL!\n", nome); ok = 0; }
        return ok;
    }
    NoSLI *aux = p->topo;
    int i = 0;
    while (aux != NULL && i < tamEsp) {
        if (aux->valor != valEsp[i]) {
            printf("    [ERRO] %s pos %d: valor = %d (Esperado: %d)\n", nome, i, aux->valor, valEsp[i]);
            ok = 0;
        }
        if (endEsp != NULL && aux != endEsp[i]) {
            printf("    [ERRO IN-PLACE] %s pos %d: endereco de memoria do no foi alterado!\n", nome, i);
            ok = 0;
        }
        aux = aux->proximo;
        i++;
    }
    if (i != tamEsp || aux != NULL) {
        printf("    [ERRO] %s encadeamento incorreto (tamanho real nao bate com %d)!\n", nome, tamEsp);
        ok = 0;
    }
    return ok;
}

int verificarFilaI(FilaI *f, int *valEsp, NoSLI **endEsp, int tamEsp, const char *nome) {
    if (f == NULL) { printf("    [ERRO] %s eh NULL!\n", nome); return 0; }
    int ok = 1;
    if (f->tamanho != tamEsp) {
        printf("    [ERRO] %s->tamanho = %d (Esperado: %d)\n", nome, f->tamanho, tamEsp);
        ok = 0;
    }
    if (tamEsp == 0) {
        if (f->inicio != NULL || f->fim != NULL) {
            printf("    [ERRO] %s vazia deve ter inicio == NULL e fim == NULL!\n", nome);
            ok = 0;
        }
        return ok;
    }
    if (f->inicio == NULL || f->fim == NULL) {
        printf("    [ERRO] %s tem inicio ou fim NULL quando nao deveria estar vazia!\n", nome);
        return 0;
    }
    NoSLI *aux = f->inicio;
    NoSLI *ultimo = NULL;
    int i = 0;
    while (aux != NULL && i < tamEsp) {
        if (aux->valor != valEsp[i]) {
            printf("    [ERRO] %s pos %d: valor = %d (Esperado: %d)\n", nome, i, aux->valor, valEsp[i]);
            ok = 0;
        }
        if (endEsp != NULL && aux != endEsp[i]) {
            printf("    [ERRO IN-PLACE] %s pos %d: endereco de memoria do no foi alterado!\n", nome, i);
            ok = 0;
        }
        ultimo = aux;
        aux = aux->proximo;
        i++;
    }
    if (i != tamEsp || aux != NULL) {
        printf("    [ERRO] %s quantidade de nos encadeados nao bate com %d!\n", nome, tamEsp);
        ok = 0;
    }
    if (f->fim != ultimo || f->fim->proximo != NULL) {
        printf("    [ERRO] %s->fim nao aponta para o ultimo no ou fim->proximo nao eh NULL!\n", nome);
        ok = 0;
    }
    return ok;
}

int verificarFilaPrio(FilaPrio *f, const char **nomesEsp, int *prioEsp, NoPrio **endEsp, int tamEsp, const char *nome) {
    if (f == NULL) { printf("    [ERRO] %s eh NULL!\n", nome); return 0; }
    int ok = 1;
    if (f->tamanho != tamEsp) {
        printf("    [ERRO] %s->tamanho = %d (Esperado: %d)\n", nome, f->tamanho, tamEsp);
        ok = 0;
    }
    if (f->inicio == NULL || f->fim == NULL) {
        printf("    [ERRO] %s inicio ou fim eh NULL!\n", nome);
        return 0;
    }
    if (f->inicio->anterior != NULL) {
        printf("    [ERRO] %s->inicio->anterior nao eh NULL!\n", nome);
        ok = 0;
    }
    if (f->fim->proximo != NULL) {
        printf("    [ERRO] %s->fim->proximo nao eh NULL!\n", nome);
        ok = 0;
    }

    NoPrio *aux = f->inicio;
    int i = 0;
    while (aux != NULL && i < tamEsp) {
        if (strcmp(aux->nome, nomesEsp[i]) != 0 || aux->prioridade != prioEsp[i]) {
            printf("    [ERRO IDA] %s pos %d: [%s:%d] (Esperado: [%s:%d])\n",
                   nome, i, aux->nome, aux->prioridade, nomesEsp[i], prioEsp[i]);
            ok = 0;
        }
        if (endEsp != NULL && aux != endEsp[i]) {
            printf("    [ERRO IN-PLACE] %s pos %d: endereco do no [%s] mudou (proibido criar no ou copiar strings)!\n",
                   nome, i, aux->nome);
            ok = 0;
        }
        aux = aux->proximo;
        i++;
    }
    if (i != tamEsp || aux != NULL) {
        printf("    [ERRO IDA] Percurso inicio->fim incorreto!\n");
        ok = 0;
    }

    aux = f->fim;
    int j = tamEsp - 1;
    int contVolta = 0;
    while (aux != NULL && j >= 0) {
        if (strcmp(aux->nome, nomesEsp[j]) != 0 || aux->prioridade != prioEsp[j]) {
            printf("    [ERRO VOLTA] %s pos %d (fim->inicio): [%s:%d] (Esperado: [%s:%d]) - Ponteiro 'anterior' quebrado!\n",
                   nome, j, aux->nome, aux->prioridade, nomesEsp[j], prioEsp[j]);
            ok = 0;
        }
        aux = aux->anterior;
        j--;
        contVolta++;
    }
    if (contVolta != tamEsp || aux != NULL) {
        printf("    [ERRO VOLTA] Percurso fim->inicio quebrado!\n");
        ok = 0;
    }
    return ok;
}

// ============================================================================
// TESTES DA QUESTÃO 1: compactarAdjacentesPilhaI (15.0 pts)
// ============================================================================

int teste_Q1_1() {
    printf("  [Q1.1] Casos Base: Pilha vazia, 1 elem e alternados sem adj (3.0 pts)... ");
    PilhaI *p = criarPilhaI();
    int r_vaz = compactarAdjacentesPilhaI(p);
    empilharI(10, p);
    int r_unit = compactarAdjacentesPilhaI(p);
    limparPilhaI(p);
    int v[] = {10, 20, 10, 20};
    popularPilhaTopoBase(p, v, 4);
    int r_alt = compactarAdjacentesPilhaI(p);
    int ok_p = verificarPilhaI(p, v, NULL, 4, "Pilha Q1.1");
    destruirPilhaI(&p);

    if (r_vaz == 0 && r_unit == 0 && r_alt == 0 && ok_p) { printf("PASSOU!\n"); return 1; }
    printf("FALHOU!\n");
    return 0;
}

int teste_Q1_2() {
    printf("  [Q1.2] Duplicatas adjacentes no topo, meio e base (6.0 pts)... ");
    PilhaI *p = criarPilhaI();
    int v[] = {10, 10, 10, 20, 30, 30, 10, 40, 40};
    int esp[] = {10, 20, 30, 10, 40};
    popularPilhaTopoBase(p, v, 9);
    int ret = compactarAdjacentesPilhaI(p);
    int ok_p = verificarPilhaI(p, esp, NULL, 5, "Pilha Q1.2");
    destruirPilhaI(&p);

    if (ret == 4 && ok_p) { printf("PASSOU!\n"); return 1; }
    printf("FALHOU! (Retornou %d removidos, Esperado: 4)\n", ret);
    return 0;
}

int teste_Q1_3() {
    printf("  [Q1.3] Todos os elementos iguais na pilha (6.0 pts)... ");
    PilhaI *p = criarPilhaI();
    int v[] = {7, 7, 7, 7, 7};
    int esp[] = {7};
    popularPilhaTopoBase(p, v, 5);
    int ret = compactarAdjacentesPilhaI(p);
    int ok_p = verificarPilhaI(p, esp, NULL, 1, "Pilha Q1.3");
    destruirPilhaI(&p);

    if (ret == 4 && ok_p) { printf("PASSOU!\n"); return 1; }
    printf("FALHOU! (Retornou %d removidos, Esperado: 4)\n", ret);
    return 0;
}

// ============================================================================
// TESTES DA QUESTÃO 2: inverterPrimeirosKFilaI (20.0 pts)
// ============================================================================

int teste_Q2_1() {
    printf("  [Q2.1] Casos Base/Invalidos: Vazia, k<=0, k>tam e k=1 (4.0 pts)... ");
    FilaI *f = criarFilaI();
    int r_vaz = inverterPrimeirosKFilaI(2, f);
    int v[] = {10, 20, 30};
    popularFila(f, v, 3);
    int r_zero = inverterPrimeirosKFilaI(0, f);
    int r_neg = inverterPrimeirosKFilaI(-2, f);
    int r_maior = inverterPrimeirosKFilaI(4, f);
    int r_um = inverterPrimeirosKFilaI(1, f);
    int ok_f = verificarFilaI(f, v, NULL, 3, "Fila Q2.1");
    destruirFilaI(&f);

    if (r_vaz == 0 && r_zero == 0 && r_neg == 0 && r_maior == 0 && r_um == 1 && ok_f) {
        printf("PASSOU!\n"); return 1;
    }
    printf("FALHOU!\n");
    return 0;
}

int teste_Q2_2() {
    printf("  [Q2.2] Inversao parcial (k = 3 em fila de 5 elementos) (10.0 pts)... ");
    FilaI *f = criarFilaI();
    int v[] = {10, 20, 30, 40, 50};
    int esp[] = {30, 20, 10, 40, 50};
    popularFila(f, v, 5);
    int ret = inverterPrimeirosKFilaI(3, f);
    int ok_f = verificarFilaI(f, esp, NULL, 5, "Fila Q2.2");
    destruirFilaI(&f);

    if (ret == 1 && ok_f) { printf("PASSOU!\n"); return 1; }
    printf("FALHOU!\n");
    return 0;
}

int teste_Q2_3() {
    printf("  [Q2.3] Inversao total da fila (k == tamanho) (6.0 pts)... ");
    FilaI *f = criarFilaI();
    int v[] = {10, 20, 30, 40};
    int esp[] = {40, 30, 20, 10};
    popularFila(f, v, 4);
    int ret = inverterPrimeirosKFilaI(4, f);
    int ok_f = verificarFilaI(f, esp, NULL, 4, "Fila Q2.3");
    destruirFilaI(&f);

    if (ret == 1 && ok_f) { printf("PASSOU!\n"); return 1; }
    printf("FALHOU!\n");
    return 0;
}

// ============================================================================
// TESTES DA QUESTÃO 3: transferirTopoParaFilaInPlace (30.0 pts)
// ============================================================================

int teste_Q3_1() {
    printf("  [Q3.1] Casos Invalidos: Pilha vazia, k<=0 e k>tam (5.0 pts)... ");
    PilhaI *p = criarPilhaI();
    FilaI *f = criarFilaI();
    int r_vaz = transferirTopoParaFilaInPlace(1, p, f);

    int vp[] = {10, 20, 30};
    popularPilhaTopoBase(p, vp, 3);
    NoSLI *origP[3]; salvarEnderecosPilha(p, origP);

    int vf[] = {80, 90};
    popularFila(f, vf, 2);
    NoSLI *origF[2]; salvarEnderecosFila(f, origF);

    int r0 = transferirTopoParaFilaInPlace(0, p, f);
    int rn = transferirTopoParaFilaInPlace(-1, p, f);
    int rm = transferirTopoParaFilaInPlace(4, p, f);

    int ok_p = verificarPilhaI(p, vp, origP, 3, "Pilha Q3.1");
    int ok_f = verificarFilaI(f, vf, origF, 2, "Fila Q3.1");
    destruirPilhaI(&p); destruirFilaI(&f);

    if (r_vaz == 0 && r0 == 0 && rn == 0 && rm == 0 && ok_p && ok_f) { printf("PASSOU!\n"); return 1; }
    printf("FALHOU!\n");
    return 0;
}

int teste_Q3_2() {
    printf("  [Q3.2] Transferencia parcial (k=2) para Fila NAO-VAZIA In-Place (10.0 pts)... ");
    PilhaI *p = criarPilhaI();
    FilaI *f = criarFilaI();
    int vp[] = {10, 20, 30, 40};
    popularPilhaTopoBase(p, vp, 4);
    NoSLI *origP[4]; salvarEnderecosPilha(p, origP);

    int vf[] = {80, 90};
    popularFila(f, vf, 2);
    NoSLI *origF[2]; salvarEnderecosFila(f, origF);

    int valEspP[] = {30, 40};
    NoSLI *endEspP[] = {origP[2], origP[3]};
    int valEspF[] = {80, 90, 10, 20};
    NoSLI *endEspF[] = {origF[0], origF[1], origP[0], origP[1]};

    int ret = transferirTopoParaFilaInPlace(2, p, f);
    int ok_p = verificarPilhaI(p, valEspP, endEspP, 2, "Pilha Q3.2");
    int ok_f = verificarFilaI(f, valEspF, endEspF, 4, "Fila Q3.2");
    destruirPilhaI(&p); destruirFilaI(&f);

    if (ret == 1 && ok_p && ok_f) { printf("PASSOU!\n"); return 1; }
    printf("FALHOU!\n");
    return 0;
}

int teste_Q3_3() {
    printf("  [Q3.3] Transferencia parcial (k=2) para Fila VAZIA In-Place (8.0 pts)... ");
    PilhaI *p = criarPilhaI();
    FilaI *f = criarFilaI();
    int vp[] = {10, 20, 30};
    popularPilhaTopoBase(p, vp, 3);
    NoSLI *origP[3]; salvarEnderecosPilha(p, origP);

    int valEspP[] = {30};
    NoSLI *endEspP[] = {origP[2]};
    int valEspF[] = {10, 20};
    NoSLI *endEspF[] = {origP[0], origP[1]};

    int ret = transferirTopoParaFilaInPlace(2, p, f);
    int ok_p = verificarPilhaI(p, valEspP, endEspP, 1, "Pilha Q3.3");
    int ok_f = verificarFilaI(f, valEspF, endEspF, 2, "Fila Q3.3");
    destruirPilhaI(&p); destruirFilaI(&f);

    if (ret == 1 && ok_p && ok_f) { printf("PASSOU!\n"); return 1; }
    printf("FALHOU!\n");
    return 0;
}

int teste_Q3_4() {
    printf("  [Q3.4] Transferencia TOTAL (k == tamanho: Pilha esvazia) (7.0 pts)... ");
    PilhaI *p = criarPilhaI();
    FilaI *f = criarFilaI();
    int vp[] = {10, 20, 30};
    popularPilhaTopoBase(p, vp, 3);
    NoSLI *origP[3]; salvarEnderecosPilha(p, origP);

    int vf[] = {70};
    popularFila(f, vf, 1);
    NoSLI *origF[1]; salvarEnderecosFila(f, origF);

    int valEspF[] = {70, 10, 20, 30};
    NoSLI *endEspF[] = {origF[0], origP[0], origP[1], origP[2]};

    int ret = transferirTopoParaFilaInPlace(3, p, f);
    int ok_p = verificarPilhaI(p, NULL, NULL, 0, "Pilha Q3.4 (Vazia)");
    int ok_f = verificarFilaI(f, valEspF, endEspF, 4, "Fila Q3.4");
    destruirPilhaI(&p); destruirFilaI(&f);

    if (ret == 1 && ok_p && ok_f) { printf("PASSOU!\n"); return 1; }
    printf("FALHOU!\n");
    return 0;
}

// ============================================================================
// TESTES DA QUESTÃO 4: alterarPrioridadePrio (35.0 pts)
// ============================================================================

int teste_Q4_1() {
    printf("  [Q4.1] Casos Base: Vazia, ausente, 1 arq e mesma prioridade (5.0 pts)... ");
    FilaPrio *f = criarFilaPrio();
    int r_vaz = alterarPrioridadePrio("relatorio.pdf", 1, f);

    NoPrio *n0 = anexarFimPrioTeste(f, "unico.txt", 5);
    int r_unit = alterarPrioridadePrio("unico.txt", 2, f);
    int unit_ok = (f->inicio == n0 && f->fim == n0 && n0->prioridade == 2 && n0->anterior == NULL && n0->proximo == NULL);

    limparFilaPrio(f);
    NoPrio *a = anexarFimPrioTeste(f, "relatorio.pdf", 2);
    NoPrio *b = anexarFimPrioTeste(f, "boleto.pdf", 2);
    NoPrio *c = anexarFimPrioTeste(f, "foto.png", 4);
    NoPrio *espEnd[] = {a, b, c};
    const char *espNomes[] = {"relatorio.pdf", "boleto.pdf", "foto.png"};
    int espPrios[] = {2, 2, 4};

    int r_inex = alterarPrioridadePrio("inexistente.txt", 1, f);
    int r_mesma = alterarPrioridadePrio("relatorio.pdf", 2, f);
    int ok_f = verificarFilaPrio(f, espNomes, espPrios, espEnd, 3, "FilaPrio Q4.1");
    destruirFilaPrio(&f);

    if (r_vaz == 0 && r_unit == 1 && unit_ok && r_inex == 0 && r_mesma == 1 && ok_f) {
        printf("PASSOU!\n"); return 1;
    }
    printf("FALHOU!\n");
    return 0;
}

int teste_Q4_2() {
    printf("  [Q4.2] Promocao e rebaixamento no MEIO + Desempate FIFO (10.0 pts)... ");
    FilaPrio *f = criarFilaPrio();
    NoPrio *nA = anexarFimPrioTeste(f, "relatorio.pdf", 2);
    NoPrio *nB = anexarFimPrioTeste(f, "boleto.pdf", 4);
    NoPrio *nC = anexarFimPrioTeste(f, "foto.png", 4);
    NoPrio *nD = anexarFimPrioTeste(f, "tcc.docx", 6);
    NoPrio *nE = anexarFimPrioTeste(f, "planilha.xlsx", 8);

    int r1 = alterarPrioridadePrio("tcc.docx", 4, f);
    int r2 = alterarPrioridadePrio("foto.png", 3, f);

    const char *espNomes[] = {"relatorio.pdf", "foto.png", "boleto.pdf", "tcc.docx", "planilha.xlsx"};
    int espPrios[] = {2, 3, 4, 4, 8};
    NoPrio *espEnd[] = {nA, nC, nB, nD, nE};

    int ok_f = verificarFilaPrio(f, espNomes, espPrios, espEnd, 5, "FilaPrio Q4.2");
    destruirFilaPrio(&f);

    if (r1 == 1 && r2 == 1 && ok_f) { printf("PASSOU!\n"); return 1; }
    printf("FALHOU!\n");
    return 0;
}

int teste_Q4_3() {
    printf("  [Q4.3] Promocao do FIM e do MEIO para o INICIO (10.0 pts)... ");
    FilaPrio *f = criarFilaPrio();
    NoPrio *nA = anexarFimPrioTeste(f, "relatorio.pdf", 3);
    NoPrio *nB = anexarFimPrioTeste(f, "boleto.pdf", 5);
    NoPrio *nC = anexarFimPrioTeste(f, "foto.png", 7);

    int r1 = alterarPrioridadePrio("foto.png", 2, f);
    int r2 = alterarPrioridadePrio("relatorio.pdf", 1, f);

    const char *espNomes[] = {"relatorio.pdf", "foto.png", "boleto.pdf"};
    int espPrios[] = {1, 2, 5};
    NoPrio *espEnd[] = {nA, nC, nB};

    int ok_f = verificarFilaPrio(f, espNomes, espPrios, espEnd, 3, "FilaPrio Q4.3");
    destruirFilaPrio(&f);

    if (r1 == 1 && r2 == 1 && ok_f) { printf("PASSOU!\n"); return 1; }
    printf("FALHOU!\n");
    return 0;
}

int teste_Q4_4() {
    printf("  [Q4.4] Rebaixamento do INICIO para o MEIO e para o FIM (10.0 pts)... ");
    FilaPrio *f = criarFilaPrio();
    NoPrio *nA = anexarFimPrioTeste(f, "relatorio.pdf", 1);
    NoPrio *nB = anexarFimPrioTeste(f, "boleto.pdf", 3);
    NoPrio *nC = anexarFimPrioTeste(f, "foto.png", 5);

    int r1 = alterarPrioridadePrio("relatorio.pdf", 4, f);
    int r2 = alterarPrioridadePrio("boleto.pdf", 5, f);

    const char *espNomes[] = {"relatorio.pdf", "foto.png", "boleto.pdf"};
    int espPrios[] = {4, 5, 5};
    NoPrio *espEnd[] = {nA, nC, nB};

    int ok_f = verificarFilaPrio(f, espNomes, espPrios, espEnd, 3, "FilaPrio Q4.4");
    destruirFilaPrio(&f);

    if (r1 == 1 && r2 == 1 && ok_f) { printf("PASSOU!\n"); return 1; }
    printf("FALHOU!\n");
    return 0;
}

// ============================================================================
// FUNÇÃO PRINCIPAL (COMENTE QUALQUER TESTE QUE ESTEJA DANDO SEGFAULT/LOOP)
// ============================================================================
int main() {
    printf("======================================================================\n");
    printf("   BATERIA COMPLETA DE TESTES DO ALUNO - PROVA 3 (PILHA E FILA)       \n");
    printf("   Dica: Se um teste travar (SegFault/Loop), comente a linha dele     \n");
    printf("   na funcao main() para que os demais testes possam ser executados.  \n");
    printf("   Lembre-se de destruir estruturas auxiliares (destruirPilhaI)       \n");
    printf("   criadas nas Questoes 1 e 2 para nao perder 20%% de cada teste!     \n");
    printf("======================================================================\n\n");

    double n1 = 0.0, n2 = 0.0, n3 = 0.0, n4 = 0.0;

    // --- QUESTÃO 1 (15.0 pts) ---
    printf(">>> TESTANDO QUESTAO 1: compactarAdjacentesPilhaI (15.0 pts)\n");
    int q1_1 = 0, q1_2 = 0, q1_3 = 0;
    q1_1 = teste_Q1_1(); // Comente se Q1.1 travar
    q1_2 = teste_Q1_2(); // Comente se Q1.2 travar
    q1_3 = teste_Q1_3(); // Comente se Q1.3 travar

    if (q1_2) n1 += 6.0;
    if (q1_3) n1 += 6.0;
    if ((q1_2 || q1_3) && q1_1) n1 += 3.0;
    else if (q1_1) printf("  [AVISO Q1] Caso base [Q1.1] so pontua se acertar [Q1.2] ou [Q1.3]!\n");
    printf("  --> Subtotal Q1: %.1f / 15.0 pts\n\n", n1);

    // --- QUESTÃO 2 (20.0 pts) ---
    printf(">>> TESTANDO QUESTAO 2: inverterPrimeirosKFilaI (20.0 pts)\n");
    int q2_1 = 0, q2_2 = 0, q2_3 = 0;
    q2_1 = teste_Q2_1(); // Comente se Q2.1 travar
    q2_2 = teste_Q2_2(); // Comente se Q2.2 travar
    q2_3 = teste_Q2_3(); // Comente se Q2.3 travar

    if (q2_2) n2 += 10.0;
    if (q2_3) n2 += 6.0;
    if ((q2_2 || q2_3) && q2_1) n2 += 4.0;
    else if (q2_1) printf("  [AVISO Q2] Caso base [Q2.1] so pontua se acertar [Q2.2] ou [Q2.3]!\n");
    printf("  --> Subtotal Q2: %.1f / 20.0 pts\n\n", n2);

    // --- QUESTÃO 3 (30.0 pts) ---
    printf(">>> TESTANDO QUESTAO 3: transferirTopoParaFilaInPlace (30.0 pts)\n");
    int q3_1 = 0, q3_2 = 0, q3_3 = 0, q3_4 = 0;
    q3_1 = teste_Q3_1(); // Comente se Q3.1 travar
    q3_2 = teste_Q3_2(); // Comente se Q3.2 travar
    q3_3 = teste_Q3_3(); // Comente se Q3.3 travar
    q3_4 = teste_Q3_4(); // Comente se Q3.4 travar

    if (q3_2) n3 += 10.0;
    if (q3_3) n3 += 8.0;
    if (q3_4) n3 += 7.0;
    if ((q3_2 || q3_3 || q3_4) && q3_1) n3 += 5.0;
    else if (q3_1) printf("  [AVISO Q3] Caso base [Q3.1] so pontua se transferir nos em [Q3.2..4]!\n");
    printf("  --> Subtotal Q3: %.1f / 30.0 pts\n\n", n3);

    // --- QUESTÃO 4 (35.0 pts) ---
    printf(">>> TESTANDO QUESTAO 4: alterarPrioridadePrio (35.0 pts)\n");
    int q4_1 = 0, q4_2 = 0, q4_3 = 0, q4_4 = 0;
    q4_1 = teste_Q4_1(); // Comente se Q4.1 travar
    q4_2 = teste_Q4_2(); // Comente se Q4.2 travar
    q4_3 = teste_Q4_3(); // Comente se Q4.3 travar
    q4_4 = teste_Q4_4(); // Comente se Q4.4 travar

    if (q4_2) n4 += 10.0;
    if (q4_3) n4 += 10.0;
    if (q4_4) n4 += 10.0;
    if ((q4_2 || q4_3 || q4_4) && q4_1) n4 += 5.0;
    else if (q4_1) printf("  [AVISO Q4] Caso base [Q4.1] so pontua se reposicionar nos em [Q4.2..4]!\n");
    printf("  --> Subtotal Q4: %.1f / 35.0 pts\n\n", n4);

    double total = n1 + n2 + n3 + n4;
    printf("======================================================================\n");
    printf("   NOTA ESTIMADA NOS TESTES: %.1f / 100.0 pts\n", total);
    printf("   (Sujeita a verificacao de destruicao de memoria e restricoes)      \n");
    printf("======================================================================\n");

    return 0;
}