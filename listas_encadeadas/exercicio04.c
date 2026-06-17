#include <stdio.h>
#include <stdlib.h>

/* Estrutura básica de um nó (célula) da lista encadeada */
typedef struct reg {
    int conteudo;
    struct reg *prox; 
} celula;

celula *cria_lista_com_cabeca(int n) {
    // Aloca o nó cabeça (conteudo aqui é irrelevante)
    celula *le = (celula *)malloc(sizeof(celula));
    le->prox = NULL;
    
    celula *ultimo = le;

    for (int i = 1; i <= n; i++) {
        celula *novo = (celula *)malloc(sizeof(celula));
        novo->conteudo = i * 10;
        novo->prox = NULL;
        
        ultimo->prox = novo;
        ultimo = novo;
    }
    return le;
}

/* Busca iterativa para lista com nó cabeça */
celula *busca_com_cabeca(int x, celula *le) {
    // Começamos a busca na primeira célula útil (pós-cabeça)
    celula *p = le->prox; 

    while (p != NULL) {
        if (p->conteudo == x) {
            return p; // Sucesso
        }
        p = p->prox;
    }
    return NULL; // Não encontrado
}

/* Função Auxiliar (Privada): Faz a recursão real nos nós de dados */
celula *busca_recursiva_aux(int x, celula *p) {
    // Caso Base: Fim da lista ou valor encontrado
    if (p == NULL) return NULL;
    if (p->conteudo == x) return p;

    // Chamada recursiva para o próximo nó
    return busca_recursiva_aux(x, p->prox);
}

/* Função Principal: Adaptada para ignorar o nó cabeça */
celula *busca_r_com_cabeca(int x, celula *le) {
    if (le == NULL) return NULL; 
    
    // Inicia a recursão a partir da primeira célula útil
    return busca_recursiva_aux(x, le->prox);
}

int esta_ordenada_com_cabeca(celula *le) {
    // Começamos na primeira célula útil
    celula *p = le->prox;

    // Se a lista útil estiver vazia ou tiver apenas um elemento, está ordenada
    if (p == NULL || p->prox == NULL) {
        return 1;
    }

    // Comparamos o nó atual com o próximo
    while (p->prox != NULL) {
        if (p->conteudo > p->prox->conteudo) {
            return 0; // Encontrou um valor maior antes de um menor
        }
        p = p->prox;
    }

    return 1; // Chegou ao fim mantendo a ordem
}

void imprime_com_cabeca(celula *le) {
    // Começamos a impressão a partir do nó seguinte ao cabeça
    celula *primeiro_util = le->prox;

    // Podemos reutilizar uma lógica recursiva ou iterativa a partir daqui
    celula *p = primeiro_util;
    while (p != NULL) {
        printf("%d -> ", p->conteudo);
        p = p->prox;
    }
    printf("NULL\n");
}

int main() {
    // 'le' aponta para o nó cabeça, não para o primeiro dado
    celula *le = cria_lista_com_cabeca(5); 
    imprime_com_cabeca(le);

    // Teste de Busca
    celula *res = busca_r_com_cabeca(30, le);
    if (res) printf("Achou: %d\n", res->conteudo);

    // Teste de Ordem
    if (esta_ordenada_com_cabeca(le)) {
        printf("Lista com cabeca esta em ordem!\n");
    }

    return 0;
}