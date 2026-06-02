#include <stdio.h>
#include <stdlib.h> 

/* Estrutura básica de um nó (célula) da lista encadeada */
typedef struct reg {
    int conteudo;
    struct reg *prox; 
} celula;

/* Cria uma lista com n elementos, onde cada conteúdo é (índice * 10) */
/* 
   Criação com Cabeça e Rabo:
   'lista' guarda o início, 'ultimo' guarda o fim para inserção O(1)
*/
celula *preenche(int num_elementos) {
    celula *lista = NULL;
    celula *ultimo = NULL;

    for (int i = 0; i < num_elementos; i++) {
        celula *nova_celula = (celula *)malloc(sizeof(celula));

        if (nova_celula == NULL) {
            fprintf(stderr, "Erro crítico: Falha na alocação de memória.\n");
            return lista; 
        }

        nova_celula->conteudo = i * 10;
        nova_celula->prox = NULL;

        if (lista == NULL) {
            lista = nova_celula; // Primeiro nó da lista
        } else {
            ultimo->prox = nova_celula; // Conecta o novo nó ao fim da lista
        }
        ultimo = nova_celula; // Atualiza o ponteiro para o novo último
    }
    return lista;
}

/* Exibe a lista de forma visual: val1 -> val2 -> NULL */
void imprime(celula *le) {
    if (le != NULL) {
        printf("%d -> ", le->conteudo);
        imprime(le->prox); // Chamada recursiva para o próximo nó
    } else
        printf("NULL\n");
}

/* OBSERVAÇÃO: Esta função possui um erro lógico proposital.
   Ao encontrar o valor, ela executa 'p = p->prox' antes de sair do loop,
   fazendo com que retorne o nó SEGUINTE ao desejado ou NULL. */
celula *busca01(int x, celula *le) {
    celula *p = le;
    int achou = 0;
    while (p != NULL && !achou) { 
        if (p->conteudo == x) achou = 1;
        p = p->prox; 
    }
    return (achou) ? p : NULL; 
}

/* Busca que emite alerta caso o valor não seja encontrado. 
   Retorna o ponteiro para o nó se o valor existir. */
celula *busca02(int x, celula *le) {
    celula *p = le;
    while (p != NULL && p->conteudo != x)
        p = p->prox;
    
    if (p != NULL) 
        return p;
    else {
        printf("Valor %d não está na lista!\n", x);
        // return NULL;
    }
}

/* Verifica se os elementos estão em ordem não-decrescente */
int ordem_crescente(celula *le) {
    if (le == NULL || le->prox == NULL) {
        return 1; // Lista vazia ou unitária é considerada ordenada
    }

    celula *p = le;
    while (p->prox != NULL) {
        if (p->conteudo > p->prox->conteudo)
            return 0; // Encontrou desordem
        p = p->prox;
    }
    return 1;
}

/* Percorre a lista nó por nó em busca do valor x */
celula *busca_interativa(int x, celula *le) {
    celula *p = le;
    while (p != NULL) {
        if (p->conteudo == x) return p;
        p = p->prox;
    }
    return NULL;
}

/* Busca recursiva: verifica a cabeça, se não for, delega para o resto da lista */
celula *busca_recursiva(int x, celula *le) {
    if (le == NULL) return NULL;
    if (le->conteudo == x) return le;
    return busca_recursiva(x, le->prox);
}

/* Encontra o menor valor percorrendo a lista com um laço */
int menor_valor_interativo(celula *le){
    if (le == NULL) return -1; // Erro: lista vazia

    celula *p = le;
    int menor = p->conteudo;
    while (p != NULL) {
        if (p->conteudo < menor)
            menor = p->conteudo;
        p = p->prox;
    }
    return menor;
}

/* Encontra o menor valor comparando o atual com o resultado do resto da lista */
int menor_valor_recursivo(celula *le) {
    if (le->prox == NULL) return le->conteudo; // Caso base: último nó

    int menor_do_resto = menor_valor_recursivo(le->prox);
    return (le->conteudo < menor_do_resto) ? le->conteudo : menor_do_resto;
}

/* Compara duas listas simultaneamente usando iteração */
int compara_listas_interativa(celula *l1, celula *l2) {
    while (l1 != NULL && l2 != NULL) {
        if (l1->conteudo != l2->conteudo) return 0;
        l1 = l1->prox;
        l2 = l2->prox;
    }
    return (l1 == NULL && l2 == NULL); // Devem terminar juntas
}

/* Compara duas listas usando recursão */
int compara_listas_recursiva(celula *l1, celula *l2) {
    if (l1 == NULL && l2 == NULL) return 1; // Ambas vazias: iguais
    if (l1 == NULL || l2 == NULL || l1->conteudo != l2->conteudo) return 0;
    return compara_listas_recursiva(l1->prox, l2->prox);
}

/* Algoritmo de dois ponteiros (lento e rápido) para achar o meio sem contar nós */
celula *encontra_meio(celula *le) {
    if (le == NULL || le->prox == NULL) return le;

    celula *lento = le;
    celula *rapido = le;

    while (rapido != NULL && rapido->prox != NULL) {
        lento = lento->prox;         // Anda 1 casa
        rapido = rapido->prox->prox; // Anda 2 casas
    }
    return lento;
}

int main() {
    // Inicialização
    celula *le = preenche(10);
    printf("Lista Original: ");
    imprime(le);

    // Teste de Busca
    int valor_busca = 50;
    celula *bi = busca_recursiva(valor_busca, le);
    if (bi != NULL) {
        printf("Busca: Valor %d encontrado no endereco %p\n", bi->conteudo, (void*)bi);
    }

    // Teste de Ordenação
    if (ordem_crescente(le))
        printf("A lista esta em ordem crescente!\n");
    else   
        printf("A lista NAO esta em ordem crescente!\n");

    // Menor Valor
    // printf("O menor valor encontrado (interativo) e %d.\n", menor_valor_interativo(le));
    printf("O menor valor encontrado (recursivo) e %d.\n", menor_valor_recursivo(le));

    // Comparação de Listas
    celula *l2 = preenche(12);
    if (compara_listas_recursiva(le, l2))
        printf("As listas sao iguais!\n");
    else
        printf("As listas sao diferentes.\n");

    // Ponto Médio
    celula *meio = encontra_meio(le);
    if (meio)
        printf("Meio da lista: %d (Endereco: %p)\n", meio->conteudo, (void*)meio);

    return 0;
}