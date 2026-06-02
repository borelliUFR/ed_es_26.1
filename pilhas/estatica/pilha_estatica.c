#include <stdio.h>
#include <string.h>
#include "pilha_estatica.h"

// Inicializa o topo em -1 indicando pilha vazia
void inicializar(Pilha *p) {
    p->topo = -1;
}

int esta_vazia(Pilha *p) {
    return p->topo == -1;
}

int esta_cheia(Pilha *p) {
    return p->topo == MAX - 1;
}

// 1. Visitar uma nova página (Empilhar)
int push(Pilha *p, char *pagina) {
    if (esta_cheia(p)) {
        printf("\n[Erro] Histórico cheio! Não é possível avançar mais.\n");
        return 0;
    }
    p->topo++;
    strcpy(p->paginas[p->topo], pagina);
    return 1;
}

// 2. Voltar para a página anterior (Desempilhar)
int pop(Pilha *p, char *pagina_removida) {
    if (esta_vazia(p)) {
        printf("\n[Erro] Nenhum histórico para voltar.\n");
        return 0;
    }
    // Copia a página que está saindo para fins de exibição/log
    strcpy(pagina_removida, p->paginas[p->topo]);
    p->topo--;
    return 1;
}

// 3. Exibir a página atual
void exibir_atual(Pilha *p) {
    if (esta_vazia(p)) {
        printf("\nNavegador aberto na 'Tela Inicial' (vazia).\n");
    } else {
        printf("\nVocê está em: %s\n", p->paginas[p->topo]);
    }
}

// 4. Mostrar todo o histórico
void mostrar_historico(Pilha *p) {
    if (esta_vazia(p)) {
        printf("\nHistórico de navegação limpo.\n");
        return;
    }
    printf("\n--- HISTÓRICO DE NAVEGAÇÃO (Do Topo à Base) ---\n");
    for (int i = p->topo; i >= 0; i--) {
        if (i == p->topo) {
            printf("-> [%d] %s (PÁGINA ATUAL)\n", i, p->paginas[i]);
        } else {
            printf("   [%d] %s\n", i, p->paginas[i]);
        }
    }
    printf("---------------------------------------------\n");
}