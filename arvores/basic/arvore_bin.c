#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do Nó da Árvore
typedef struct no {
    int chave;
    struct no *esq; // Ponteiro para a subárvore esquerda (valores menores)
    struct no *dir; // Ponteiro para a subárvore direita (valores maiores)
} No;

// Função para criar um novo nó na memória
No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo != NULL) {
        novo->chave = valor;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

// 1. Função de Inserção Recursiva (Mantém a Regra de Ouro da ABB)
No* inserir(No* raiz, int valor) {
    // Caso base: se a árvore (ou subárvore) estiver vazia, cria o nó aqui
    if (raiz == NULL) {
        return criarNo(valor);
    }
    
    // Se o valor for menor, ruma para a esquerda
    if (valor < raiz->chave) {
        raiz->esq = inserir(raiz->esq, valor);
    } 
    // Se o valor for maior, ruma para a direita
    else if (valor > raiz->chave) {
        raiz->dir = inserir(raiz->dir, valor);
    }
    // Valores duplicados não são inseridos nesta implementação padrão
    
    return raiz;
}

// 2. Função de Busca (Eficiência O(log n) se estiver balanceada)
No* buscar(No* raiz, int valor) {
    // Caso base: não encontrou (NULL) ou encontrou o nó correto
    if (raiz == NULL || raiz->chave == valor) {
        return raiz;
    }
    
    // Se o valor procurado for menor, busca na subárvore esquerda
    if (valor < raiz->chave) {
        return buscar(raiz->esq, valor);
    }
    
    // Caso contrário, busca na subárvore direita
    return buscar(raiz->dir, valor);
}

// 3. Caminhamento PRÉ-ORDEM (Raiz - Esquerda - Direita)
void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->chave);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

// 4. Caminhamento EM-ORDEM (Esquerda - Raiz - Direita) -> Dá o resultado ordenado!
void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d ", raiz->chave);
        emOrdem(raiz->dir);
    }
}

// 4. Caminhamento EM-ORDEM (Esquerda - Raiz - Direita) -> Dá o resultado ordenado!
void emOrdemIterativo(No* raiz) {
    if (raiz == NULL) return;

    // Criamos uma pilha manual para armazenar os ponteiros dos nós pais
    No* pilha[100]; 
    int topo = -1;
    
    No* atual = raiz;

    // O laço precisa rodar enquanto houver nós para processar ou elementos na pilha
    while (atual != NULL || topo != -1) {
        
        // Passo 1: Avança o máximo possível para a esquerda, empilhando os nós passados
        while (atual != NULL) {
            topo++;
            pilha[topo] = atual; // "Empilha" o nó pai
            atual = atual->esq;
        }

        // Passo 2: Se chegou em NULL à esquerda, desempilha o último nó e o visita
        atual = pilha[topo];
        topo--; // "Desempilha"
        
        printf("%d ", atual->chave); // Visita o nó atual

        // Passo 3: Agora, move o ponteiro para a subárvore direita do nó visitado
        atual = atual->dir;
    }
}

// 5. Caminhamento PÓS-ORDEM (Esquerda - Direita - Raiz)
void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->chave);
    }
}

int max(int esq, int dir) {
    if (esq > dir)
        return esq;
    else
        return dir;
}

// Calcular a atura de uma arvore
int altura(No* raiz) {
    if (raiz == NULL)
        return -1;
    else
        return 1 + max(altura(raiz->esq), altura(raiz->dir));
}

int balaceado(No* raiz) {
    if (raiz != NULL)
        return altura(raiz->esq) - altura(raiz->dir);
    return 0;
}

// Função auxiliar para liberar a memória da árvore (Usa lógica de Pós-Ordem)
void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
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

// Função Principal para Teste
int main() {
    No* raiz = NULL;
    
    // Inserindo os elementos do exemplo anterior: [8, 3, 10, 1, 6, 14]
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 70);
    // raiz = inserir(raiz, 75);
    
    printf("--- CAMINHAMENTOS ---\n");
    printf("Pre-ordem: "); preOrdem(raiz); printf("\n"); // Esperado: 8 3 1 6 10 14
    printf("Em-ordem:  "); emOrdem(raiz);  printf("\n"); // Esperado: 1 3 6 8 10 14 (Ordenado!)
    printf("Pos-ordem: "); posOrdem(raiz); printf("\n\n"); // Esperado: 1 6 3 14 10 8

    imprimirArvore2D(raiz, 5);
    
    printf("--- TESTE DE BUSCA ---\n");
    int chaveProcurada = 6;
    No* resultado = buscar(raiz, chaveProcurada);
    if (resultado != NULL) {
        printf("Chave %d encontrada com sucesso na arvore!\n", resultado->chave);
    } else {
        printf("Chave %d nao existe na arvore.\n", chaveProcurada);
    }

    printf("\nA altura da arvore eh %d\n", altura(raiz));\

    printf("O balanceamento é %d\n", balaceado(raiz));
    
    // Desalocando memória
    liberarArvore(raiz);
    return 0;
}