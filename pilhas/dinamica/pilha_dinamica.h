#ifndef PILHA_DINAMICA_H
#define PILHA_DINAMICA_H

// Definição do nó da pilha (lista encadeada)
typedef struct No {
    char pagina[100];
    struct No *proximo;
} No;

// Estrutura de controle da Pilha
typedef struct {
    No *topo;
} Pilha;

// Funções de manipulação
void inicializar(Pilha *p);
int esta_vazia(Pilha *p);
int push(Pilha *p, char *nova_pagina);
int pop(Pilha *p, char *pagina_removida);
void exibir_atual(Pilha *p);
void mostrar_historico(Pilha *p);
void liberar_pilha(Pilha *p); // Essencial para evitar memory leak

#endif