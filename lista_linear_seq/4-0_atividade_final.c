#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int itens[MAX];
    int tamanho;
} Lista;

// --- Implementação das Operações ---

// 1. Inicialização
void inicializa(Lista *l) {
    l->tamanho = 0;
}

// 2. Inserção
// Retorna 1 para sucesso e 0 para falha (lista cheia ou posição inválida)
int insere(Lista *l, int pos, int elem) {
    // Validação: lista cheia ou posição fora do intervalo permitido [0, tamanho]
    if (l->tamanho == MAX || pos < 0 || pos > l->tamanho) {
        return 0; 
    }

    // Deslocamento para a direita (do fim para o início)
    for (int i = l->tamanho; i > pos; i--) {
        l->itens[i] = l->itens[i - 1];
    }

    l->itens[pos] = elem;
    l->tamanho++;
    return 1;
}

// 3. Remoção
// Retorna 1 para sucesso e 0 para falha (lista vazia ou posição inexistente)
int removeElem(Lista *l, int pos) {
    // Validação: lista vazia ou posição fora do intervalo [0, tamanho-1]
    if (l->tamanho == 0 || pos < 0 || pos >= l->tamanho) {
        return 0;
    }

    // Deslocamento para a esquerda (sobrepõe o elemento removido)
    for (int i = pos; i < l->tamanho - 1; i++) {
        l->itens[i] = l->itens[i + 1];
    }

    l->tamanho--;
    return 1;
}

// 4. Busca
// Retorna o índice do elemento ou -1 se não for encontrado
int busca(Lista *l, int elem) {
    for (int i = 0; i < l->tamanho; i++) {
        if (l->itens[i] == elem) {
            return i;
        }
    }
    return -1;
}

// 5. Atualização
int atualiza(Lista *l, int pos, int novoValor) {
    if (pos < 0 || pos >= l->tamanho) {
        return 0;
    }
    l->itens[pos] = novoValor;
    return 1;
}

// 6. Exibição
void exibe(Lista *l) {
    if (l->tamanho == 0) {
        printf("Lista vazia.\n");
        return;
    }
    printf("Lista: [ ");
    for (int i = 0; i < l->tamanho; i++) {
        printf("%d ", l->itens[i]);
    }
    printf("] (Tamanho: %d)\n", l->tamanho);
}

// --- Programa Principal para Testes ---

int main() {
    Lista lista;
    inicializa(&lista);

    printf("--- Testando Inserções ---\n");
    insere(&lista, 0, 10); // [10]
    insere(&lista, 1, 30); // [10, 30]
    insere(&lista, 1, 20); // [10, 20, 30] - inserção no meio
    exibe(&lista);

    printf("\n--- Testando Busca ---\n");
    int pos = busca(&lista, 20);
    if (pos != -1) printf("Valor 20 encontrado na posicao: %d\n", pos);

    printf("\n--- Testando Atualizacao ---\n");
    atualiza(&lista, 2, 35); // Troca 30 por 35
    exibe(&lista);

    printf("\n--- Testando Remocao ---\n");
    removeElem(&lista, 0); // Remove o 10
    exibe(&lista);

    return 0;
}