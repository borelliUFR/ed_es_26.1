#ifndef ARVORE_BIN_H
#define ARVORE_BIN_H

// Definição da estrutura do Nó da Árvore Binária de Busca (ABB)
typedef struct no {
    int chave;
    struct no *esq; // Subárvore esquerda (valores menores)
    struct no *dir; // Subárvore direita (valores maiores)
} No;

// Declaração das funções principais
No* criarNo(int valor);
No* inserir(No* raiz, int valor);
No* buscar(No* raiz, int valor);

// Declaração dos caminhamentos
void preOrdem(No* raiz);
void emOrdem(No* raiz);
void posOrdem(No* raiz);

// Liberação de memória
void liberarArvore(No* raiz);

// --- NOVA FUNÇÃO ADICIONADA ---
void imprimirArvore2D(No* raiz, int espaco);

#endif