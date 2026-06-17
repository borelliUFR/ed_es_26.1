#include <stdio.h>
#include <stdlib.h>

typedef enum { VERMELHO, PRETO } Cor;

typedef struct No {
    int chave;
    Cor cor;
    struct No *esq, *dir, *pai; // O ponteiro para o pai é essencial na Red-Black
} No;

// Cria um novo nó sempre como VERMELHO inicialmente
No* criarNo(int chave) {
    No* novo = (No*)malloc(sizeof(No));
    novo->chave = chave;
    novo->cor = VERMELHO; // Sempre entra como vermelho
    novo->esq = novo->dir = novo->pai = NULL;
    return novo;
}

void rotacaoEsquerda(No **raiz, No *x) {
    No *y = x->dir;
    x->dir = y->esq;

    if (y->esq != NULL)
        y->esq->pai = x;

    y->pai = x->pai;

    if (x->pai == NULL)
        *raiz = y;
    else if (x == x->pai->esq)
        x->pai->esq = y;
    else
        x->pai->dir = y;

    y->esq = x;
    x->pai = y;
}

void balancearInsercao(No **raiz, No *z) {
    // Enquanto o pai de z for Vermelho, temos uma violação
    while (z != *raiz && z->pai->cor == VERMELHO) {
        
        // Se o pai de z for filho à esquerda do avô
        if (z->pai == z->pai->pai->esq) {
            No *tio = z->pai->pai->dir;

            // Caso 1: O tio é Vermelho (Recolorir)
            if (tio != NULL && tio->cor == VERMELHO) {
                z->pai->cor = PRETO;
                tio->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                z = z->pai->pai; // Joga o problema para o avô
            } 
            else {
                // Caso 2: O tio é Preto e z é filho à direita (Zigue-zague)
                if (z == z->pai->dir) {
                    z = z->pai;
                    rotacaoEsquerda(raiz, z);
                }
                // Caso 3: O tio é Preto e z é filho à esquerda (Linha reta)
                z->pai->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                rotacaoDireita(raiz, z->pai->pai);
            }
        } 
        // Se o pai de z for filho à direita do avô (Espelho do código acima)
        else {
            No *tio = z->pai->pai->esq;

            // Caso 1: O tio é Vermelho
            if (tio != NULL && tio->cor == VERMELHO) {
                z->pai->cor = PRETO;
                tio->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                z = z->pai->pai;
            } 
            else {
                // Caso 2: Zigue-zague
                if (z == z->pai->esq) {
                    z = z->pai;
                    rotacaoDireita(raiz, z);
                }
                // Caso 3: Linha reta
                z->pai->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                rotacaoEsquerda(raiz, z->pai->pai);
            }
        }
    }
    // Regra 2: A raiz deve ser sempre Preta
    (*raiz)->cor = PRETO;
}

void inserirRedBlack(No **raiz, int chave) {
    No *z = criarNo(chave);
    No *y = NULL;
    No *x = *raiz;

    // Busca o local de inserção como em uma BST comum
    while (x != NULL) {
        y = x;
        if (z->chave < x->chave)
            x = x->esq;
        else if (z->chave > x->chave)
            x = x->dir;
        else {
            free(z); // Ignora duplicatas
            return;
        }
    }

    z->pai = y;
    if (y == NULL)
        *raiz = z; // Árvore estava vazia
    else if (z->chave < y->chave)
        y->esq = z;
    else
        y->dir = z;

    // Se o novo nó é a raiz, apenas pinta de preto. Se não, ajusta.
    if (z->pai == NULL) {
        z->cor = PRETO;
        return;
    }
    if (z->pai->pai == NULL) {
        return; // Pai é a raiz (Preta), então está seguro
    }

    // Chama o algoritmo para consertar as propriedades Red-Black
    balancearInsercao(raiz, z);
}