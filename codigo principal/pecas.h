#ifndef PECAS_H
#define PECAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct peca {
    char cor[20];
    int tipo;
    float peso;
    float tamanho;
    char borda[10];
    struct peca *prox;
} peca;

// Variáveis globais
extern int tam;
extern peca *head;

// Declaração das funções
void cadastro();
void listar_pecas();
void reorganizar_pecas();

#endif // PECAS_H
