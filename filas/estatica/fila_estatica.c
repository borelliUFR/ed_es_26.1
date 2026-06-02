#include <stdio.h>
#include <stdlib.h>
#include "fila_estatica.h"

// Definição da estrutura da Fila Controlada por Índices
struct fila {
    int inicio;
    int fim;
    int qtd;
    Aluno dados[MAX];
};

// Aloca a fila dinamicamente, mas armazena os elementos de forma estática (vetor)
Fila* cria_Fila() {
    Fila* fi = (Fila*) malloc(sizeof(struct fila));
    if (fi != NULL) {
        fi->inicio = 0;
        fi->fim = 0;
        fi->qtd = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi) {
    free(fi);
}

int tamanho_Fila(Fila* fi) {
    if (fi == NULL) return -1;
    return fi->qtd;
}

int Fila_vazia(Fila* fi) {
    if (fi == NULL) return -1;
    return (fi->qtd == 0);
}

int Fila_cheia(Fila* fi) {
    if (fi == NULL) return -1;
    return (fi->qtd == MAX);
}

// Insere sempre no FIM da fila (Enqueue)
int insere_Fila(Fila* fi, Aluno al) {
    if (fi == NULL || Fila_cheia(fi)) return 0;
    
    fi->dados[fi->fim] = al;
    fi->fim = (fi->fim + 1) % MAX; // Incremento circular para reaproveitar espaço
    fi->qtd++;
    return 1;
}

// Remove sempre do INÍCIO da fila (Dequeue)
int remove_Fila(Fila* fi) {
    if (fi == NULL || Fila_vazia(fi)) return 0;
    
    fi->inicio = (fi->inicio + 1) % MAX; // Avança o início de forma circular
    fi->qtd--;
    return 1;
}

// Consulta quem é o PRIMEIRO da fila (Front/Peek)
int consulta_Fila(Fila* fi, Aluno *al) {
    if (fi == NULL || Fila_vazia(fi)) return 0;
    
    *al = fi->dados[fi->inicio];
    return 1;
}

// Exibe a fila na ordem correta de atendimento
void imprime_Fila(Fila* fi) {
    if (fi == NULL || Fila_vazia(fi)) {
        printf("\nA fila de alunos esta vazia.\n");
        return;
    }
    
    printf("\n======= FILA DE ALUNOS ATUAL (Qtd: %d) =======", fi->qtd);
    int idx = fi->inicio;
    for (int i = 0; i < fi->qtd; i++) {
        printf("\n[%d] Matrícula: %d | Nome: %s | Notas: %.1f, %.1f, %.1f", 
               i + 1, fi->dados[idx].matricula, fi->dados[idx].nome, 
               fi->dados[idx].n1, fi->dados[idx].n2, fi->dados[idx].n3);
        idx = (idx + 1) % MAX;
    }
    printf("\n=============================================\n");
}