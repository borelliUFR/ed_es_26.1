#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha_dinamica.h"

// Inicializa o ponteiro do topo como NULL (Pilha Vazia)
void inicializar(Pilha *p) {
    p->topo = NULL;
}

int esta_vazia(Pilha *p) {
    return p->topo == NULL;
}

// 1. Visitar uma nova página (Empilhar dinamicamente)
int push(Pilha *p, char *nova_pagina) {
    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("\n[Erro] Falha de memória do sistema! Não foi possível carregar a página.\n");
        return 0;
    }
    
    // Copia o conteúdo e faz o novo nó apontar para o antigo topo
    strcpy(novo_no->pagina, nova_pagina);
    novo_no->proximo = p->topo;
    
    // O novo nó passa a ser o topo da pilha
    p->topo = novo_no;
    return 1;
}

// 2. Voltar para a página anterior (Desempilhar e liberar memória)
int pop(Pilha *p, char *pagina_removida) {
    if (esta_vazia(p)) {
        printf("\n[Erro] Nenhum histórico para retornar.\n");
        return 0;
    }
    
    No *aux = p->topo; // Guarda o nó que será removido
    strcpy(pagina_removida, aux->pagina); // Salva a URL para retorno
    
    p->topo = p->topo->proximo; // O topo avança para o nó de baixo
    free(aux); // Libera a memória do nó desempilhado
    
    return 1;
}

// 3. Exibir a página atual
void exibir_atual(Pilha *p) {
    if (esta_vazia(p)) {
        printf("\nNavegador aberto na 'Tela Inicial' (vazia).\n");
    } else {
        printf("\nVocê está em: %s\n", p->topo->pagina);
    }
}

// 4. Mostrar todo o histórico (Caminhamento Linear)
void mostrar_historico(Pilha *p) {
    if (esta_vazia(p)) {
        printf("\nHistórico de navegação limpo.\n");
        return;
    }
    
    printf("\n--- HISTÓRICO DE NAVEGAÇÃO DINÂMICO (Do Topo à Base) ---\n");
    No *atual = p->topo;
    int indice = 0;
    
    while (atual != NULL) {
        if (atual == p->topo) {
            printf("-> [%d] %s (PÁGINA ATUAL)\n", indice, atual->pagina);
        } else {
            printf("   [%d] %s\n", indice, atual->pagina);
        }
        atual = atual->proximo;
        indice++;
    }
    printf("-----------------------------------------------------\n");
}

// Libera toda a memória alocada antes de fechar o programa
void liberar_pilha(Pilha *p) {
    No *atual = p->topo;
    while (atual != NULL) {
        No *aux = atual;
        atual = atual->proximo;
        free(aux);
    }
    p->topo = NULL;
}