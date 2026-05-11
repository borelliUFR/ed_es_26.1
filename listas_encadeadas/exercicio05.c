#include <stdio.h>
#include <stdlib.h>

/* Estrutura básica de um nó (célula) da lista encadeada */
typedef struct reg {
    int conteudo;
    struct reg *prox; 
} celula;

void insere(int x, celula *p) {
    celula nova; // Variável local (alocada na Stack)
    nova.conteudo = x;
    nova.prox = p->prox;
    p->prox = &nova;

    /* 
    O Problema: A variável nova é local (automática). Ela é alocada na Pilha (Stack) e sua memória é liberada assim que a função insere termina. 
    O ponteiro p->prox fica apontando para um endereço de memória que não pertence mais ao programa (um "ponteiro dangling"). 
    Ao tentar acessar a lista depois, o programa sofrerá um crash ou lerá lixo. 
    */

    // A Solução: Para que o nó persista, ele deve ser alocado dinamicamente no Heap usando malloc.
}

celula* insere_sem_cabeca(int x, celula *ini) {
    celula *nova = (celula*) malloc(sizeof(celula));
    nova->conteudo = x;
    nova->prox = ini; // A nova célula aponta para o antigo início
    return nova;      // O novo início agora é a nova célula
}

celula* copia_interativa(celula *lst) {
    celula *nova_lista = NULL, *ultimo = NULL;
    for (celula *p = lst; p != NULL; p = p->prox) {
        celula *novo = (celula*) malloc(sizeof(celula));
        novo->conteudo = p->conteudo;
        novo->prox = NULL;
        if (nova_lista == NULL) nova_lista = novo;
        else ultimo->prox = novo;
        ultimo = novo;
    }
    return nova_lista;
}

celula* copia_recursiva(celula *lst) {
    if (lst == NULL) return NULL;
    celula *novo = (celula*) malloc(sizeof(celula));
    novo->conteudo = lst->conteudo;
    novo->prox = copia_recursiva(lst->prox);
    return novo;
}

void concatena_interativa(celula *l1, celula *l2) {
    if (l1 == NULL) return; 
    celula *p = l1;
    while (p->prox != NULL) p = p->prox;
    p->prox = l2;
}

void concatena_recursiva(celula *l1, celula *l2) {
    if (l1 == NULL || l1->prox == NULL) {
        if (l1 != NULL) l1->prox = l2;
        return;
    }
    concatena_recursiva(l1->prox, l2);
}

void insere_apos_k(int x, int k, celula *lst) {
    celula *p = lst;
    for (int i = 1; i < k && p != NULL; i++) p = p->prox;
    if (p != NULL) {
        celula *novo = (celula*) malloc(sizeof(celula));
        novo->conteudo = x;
        novo->prox = p->prox;
        p->prox = novo;
    }
}

celula* inverte_iterativa(celula *ini) {
    celula *ant = NULL, *atual = ini, *prox = NULL;
    while (atual != NULL) {
        prox = atual->prox; // Salva o próximo
        atual->prox = ant;  // Inverte o ponteiro
        ant = atual;        // Move o anterior
        atual = prox;       // Move o atual
    }
    return ant;
}

celula* inverte_recursiva(celula *ini) {
    if (ini == NULL || ini->prox == NULL) return ini;
    celula *novo_ini = inverte_recursiva(ini->prox);
    ini->prox->prox = ini;
    ini->prox = NULL;
    return novo_ini;
}

int main() {
    // TO DO

    return 0;
}

/*
Discussão: Eficiência do malloc
    É adequado alocar uma a uma?
        Para listas pequenas, sim. Para sistemas de alta performance, não. O malloc tem um custo (overhead) de tempo e memória 
        (cada bloco alocado gasta alguns bytes extras para controle do SO).

Alternativas:
    - Memory Pooling (Pool de Memória): Alocar um grande bloco (um vetor de celulas) de uma vez e gerenciar a entrega dessas células manualmente.
    - Lista de Livres: Manter uma lista de células que já foram "removidas" e reutilizá-las em vez de dar free e depois malloc novamente. 
    Isso reduz drasticamente a fragmentação da memória.

*/

/*
RESPOSTA EM ALTO NÍVEL PARA TROCA DE DUAS CÉLUAS DISTINTAS

FUNÇÃO trocar_nos(lista, valor_A, valor_B)
    SE valor_A == valor_B ENTÃO RETORNE (nada a fazer)

    // 1. Localizar os nós e seus predecessores
    Definir ant_A = NULL, atual_A = lista
    ENQUANTO atual_A != NULL E atual_A.conteudo != valor_A:
        ant_A = atual_A
        atual_A = atual_A.proximo

    Definir ant_B = NULL, atual_B = lista
    ENQUANTO atual_B != NULL E atual_B.conteudo != valor_B:
        ant_B = atual_B
        atual_B = atual_B.proximo

    // 2. Verificar se ambos os nós existem na lista
    SE atual_A == NULL OU atual_B == NULL ENTÃO RETORNE

    // 3. Ajustar o ponteiro do nó anterior a A
    SE ant_A != NULL:
        ant_A.proximo = atual_B
    SENÃO:
        lista = atual_B  // A era a cabeça da lista

    // 4. Ajustar o ponteiro do nó anterior a B
    SE ant_B != NULL:
        ant_B.proximo = atual_A
    SENÃO:
        lista = atual_A  // B era a cabeça da lista

    // 5. Trocar os ponteiros 'proximo' de A e B
    Definir temp = atual_A.proximo
    atual_A.proximo = atual_B.proximo
    atual_B.proximo = temp

FIM FUNÇÃO
*/