#include <stdio.h>
#include <stdlib.h>

// Definimos o tipo 'celula' ao mesmo tempo que a estrutura
typedef struct reg {
    int conteudo;
    struct reg *prox; // Aqui usamos 'struct reg' porque o typedef 'celula' 
                      // ainda nao foi finalizado pelo compilador
} celula;

int main() {

    // 1. Inicialização dos ponteiros
    celula *lista = NULL;  // Ponteiro de cabeça (início da lista)
    celula *ultimo = NULL; // Ponteiro auxiliar para o último nó inserido

    int num_elementos = 10;
    
    printf("Criando lista encadeada com %d elementos:\n", num_elementos);

    // 2. Criação e inserção dos 10 elementos
    for (int i = 0; i <= num_elementos; i++) {
        // Aloca memória para uma nova célula
        celula *nova_celula = (celula *)malloc(sizeof(celula));

        // Verificação de erro de alocação
        if (nova_celula == NULL) {
            printf("Erro de alocação de memória.\n");
            break; // Sai do loop
        }

        // Preenche o conteúdo e garante que o novo nó aponta para NULL
        nova_celula->conteudo = i * 10;
        nova_celula->prox = NULL;

        // Conecta a nova célula à lista
        if (lista == NULL) {
            // Se a lista estiver vazia, a nova célula é a cabeça
            lista = nova_celula;
        } else {
            // Se não estiver vazia, o 'prox' do último nó aponta para o novo
            ultimo->prox = nova_celula;
        }

        // Atualiza o ponteiro 'ultimo' para o nó recém-adicionado
        ultimo = nova_celula;
    }
    
    // --- Exibição da Lista ---
    printf("Elementos: \n");
    celula *atual = lista; // Ponteiro auxiliar para percorrer
    while (atual != NULL) {
        printf("%d -> ", atual->conteudo);
        atual = atual->prox;
    }
    printf("NULL\n");

    return 0;
}