#include <stdio.h>
#include <stdlib.h>
#include "fila_dinamica.h" 

// Definição do Nó da Lista Encadeada
typedef struct elemento {
    Aluno dados;
    struct elemento *proximo;
} Elemento;

// Definição da estrutura de controle da Fila (Oculta ao usuário)
struct fila {
    Elemento *inicio;
    Elemento *fim;
    int qtd;
};

// Cria a Fila Dinâmica definindo os ponteiros iniciais como NULL
Fila* cria_Fila() {
    Fila* fi = (Fila*) malloc(sizeof(struct fila));
    if (fi != NULL) {
        fi->inicio = NULL;
        fi->fim = NULL;
        fi->qtd = 0;
    }
    return fi;
}

// Libera cada nó individualmente antes de liberar a estrutura de controle
void libera_Fila(Fila* fi) {
    if (fi != NULL) {
        Elemento* no;
        while (fi->inicio != NULL) {
            no = fi->inicio;
            fi->inicio = fi->inicio->proximo;
            free(no);
        }
        free(fi);
    }
}

int tamanho_Fila(Fila* fi) {
    if (fi == NULL) return -1;
    return fi->qtd;
}

int Fila_vazia(Fila* fi) {
    if (fi == NULL) return -1;
    return (fi->inicio == NULL);
}

// Em teoria, a fila dinâmica só estará cheia se a memória RAM do sistema esgotar
int Fila_cheia(Fila* fi) {
    if (fi == NULL) return -1;
    return 0; 
}

// Insere sempre no FIM da fila (Enqueue Dinâmico)
int insere_Fila(Fila* fi, Aluno al) {
    if (fi == NULL) return 0;
    
    Elemento* no = (Elemento*) malloc(sizeof(Elemento));
    if (no == NULL) return 0; // Falha na alocação de memória
    
    no->dados = al;
    no->proximo = NULL;
    
    if (fi->inicio == NULL) { 
        // Se a fila estava vazia, o novo nó é o início e o fim
        fi->inicio = no;
    } else {
        // Caso contrário, conecta o antigo fim ao novo nó
        fi->fim->proximo = no;
    }
    
    fi->fim = no; // O ponteiro de fim passa a apontar para o novo nó
    fi->qtd++;
    return 1;
}

// Remove sempre do INÍCIO da fila (Dequeue Dinâmico)
int remove_Fila(Fila* fi) {
    if (fi == NULL || Fila_vazia(fi)) return 0;
    
    Elemento* no = fi->inicio; // Guarda o primeiro nó para liberar depois
    fi->inicio = fi->inicio->proximo; // O início avança para o segundo elemento
    
    if (fi->inicio == NULL) {
        // Se a fila ficou vazia após a remoção, o fim também vira NULL
        fi->fim = NULL;
    }
    
    free(no); // Desaloca a memória do nó atendido
    fi->qtd--;
    return 1;
}

// Consulta o primeiro elemento sem removê-lo
int consulta_Fila(Fila* fi, Aluno *al) {
    if (fi == NULL || Fila_vazia(fi)) return 0;
    
    *al = fi->inicio->dados;
    return 1;
}

// Caminhamento sequencial pelos nós alocados dinamicamente
void imprime_Fila(Fila* fi) {
    if (fi == NULL || Fila_vazia(fi)) {
        printf("\nA fila dinamica de alunos esta vazia.\n");
        return;
    }
    
    printf("\n======= FILA DINÂMICA DE ALUNOS (Qtd: %d) =======", fi->qtd);
    Elemento* atual = fi->inicio;
    int posicao = 1;
    
    while (atual != NULL) {
        printf("\n[%d] Matrícula: %d | Nome: %s | Notas: %.1f, %.1f, %.1f", 
               posicao, atual->dados.matricula, atual->dados.nome, 
               atual->dados.n1, atual->dados.n2, atual->dados.n3);
        atual = atual->proximo;
        posicao++;
    }
    printf("\n================================================\n");
}