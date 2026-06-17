#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No *esq;
    struct No *dir;
    int altura; // Guardar a altura otimiza o cálculo do FB
} No;

// Retorna a altura do nó de forma segura
int altura(No *n) {
    if (n == NULL) return -1;
    return n->altura;
}

// Retorna o maior entre dois inteiros
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Calcula o Fator de Balanceamento
int obterFB(No *n) {
    if (n == NULL) return 0;
    return altura(n->esq) - altura(n->dir);
}

No* rotacaoDireita(No *y) {
    No *x = y->esq;
    No *T2 = x->dir;

    // Realiza a rotação
    x->dir = y;
    y->esq = T2;

    // Atualiza as alturas (a ordem importa: o filho 'y' primeiro)
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;

    // Retorna a nova raiz da subárvore
    return x;
}

No* rotacaoEsquerda(No *x) {
    No *y = x->dir;
    No *T2 = y->esq;

    // Realiza a rotação
    y->esq = x;
    x->dir = T2;

    // Atualiza as alturas
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;

    // Retorna a nova raiz da subárvore
    return y;
}

No* rotacaoEsquerdaDireita(No *n) {
    n->esq = rotacaoEsquerda(n->esq);
    return rotacaoDireita(n);
}

No* rotacaoDireitaEsquerda(No *n) {
    n->dir = rotacaoDireita(n->dir);
    return rotacaoEsquerda(n);
}

No* inserir(No* no, int chave) {
    // 1. Inserção BST padrão
    if (no == NULL) {
        No* novo = (No*)malloc(sizeof(No));
        novo->chave = chave;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->altura = 0; // Nó folha começa com altura 0
        return novo;
    }

    if (chave < no->chave)
        no->esq = inserir(no->esq, chave);
    else if (chave > no->chave)
        no->dir = inserir(no->dir, chave);
    else
        return no; // Chaves duplicadas não são permitidas na AVL padrão

    // 2. Atualiza a altura deste nó ancestral
    no->altura = 1 + max(altura(no->esq), altura(no->dir));

    // 3. Obtém o fator de balanceamento para verificar se desandou
    int fb = obterFB(no);

    // 4. Casos de Desbalanceamento

    // Caso Esquerda-Esquerda (LL)
    if (fb > 1 && chave < no->esq->chave)
        return rotacaoDireita(no);

    // Caso Direita-Direita (RR)
    if (fb < -1 && chave > no->dir->chave)
        return rotacaoEsquerda(no);

    // Caso Esquerda-Direita (LR)
    if (fb > 1 && chave > no->esq->chave) {
        return rotacaoEsquerdaDireita(no);
    }

    // Caso Direita-Esquerda (RL)
    if (fb < -1 && chave < no->dir->chave) {
        return rotacaoDireitaEsquerda(no);
    }

    // Retorna o ponteiro do nó (inalterado se já estava balanceado)
    return no;
}