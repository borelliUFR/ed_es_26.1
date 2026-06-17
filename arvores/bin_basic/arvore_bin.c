#include <stdio.h>
#include <stdlib.h>
#include "arvore_bin.h"

// Cria um novo nó alocado dinamicamente na memória
No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo != NULL) {
        novo->chave = valor;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

// Inserção recursiva mantendo a propriedade da ABB
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor); // Caso base: ponto de inserção encontrado
    }
    
    if (valor < raiz->chave) {
        raiz->esq = inserir(raiz->esq, valor);
    } 
    else if (valor > raiz->chave) {
        raiz->dir = inserir(raiz->dir, valor);
    }
    // Valores iguais não fazem nada (evita duplicatas nesta implementação)
    
    return raiz;
}

// Busca recursiva com complexidade média O(log n)
No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->chave == valor) {
        return raiz; // Caso base: encontrou ou chegou a uma folha nula
    }
    
    if (valor < raiz->chave) {
        return buscar(raiz->esq, valor);
    }
    
    return buscar(raiz->dir, valor);
}

// Caminhamento Pré-Ordem: Raiz -> Esquerda -> Direita
void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->chave);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

// Caminhamento Em-Ordem: Esquerda -> Raiz -> Direita (Exibe ordenado)
void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d ", raiz->chave);
        emOrdem(raiz->dir);
    }
}

// Caminhamento Pós-Ordem: Esquerda -> Direita -> Raiz
void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->chave);
    }
}

// Desalocação segura de memória usando lógica Pós-Ordem
void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz); // Só apaga o pai depois de liberar os filhos
    }
}

// Função recursiva para exibição gráfica/visual em 2D
void imprimirArvore2D(No* raiz, int espaco) {
    // Caso base: se o nó é nulo, não imprime nada
    if (raiz == NULL) {
        return;
    }

    // Aumenta a distância entre os níveis de forma hierárquica
    espaco += 5;

    // 1. Processa primeiro a Subárvore Direita (fica no topo do console)
    imprimirArvore2D(raiz->dir, espaco);

    // 2. Imprime o nó atual após aplicar os espaços necessários
    printf("\n");
    for (int i = 5; i < espaco; i++) {
        printf(" ");
    }
    printf("%d\n", raiz->chave);

    // 3. Processa a Subárvore Esquerda (fica na base do console)
    imprimirArvore2D(raiz->esq, espaco);
}