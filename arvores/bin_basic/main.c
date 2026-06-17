#include <stdio.h>
#include <stdlib.h>
#include "arvore_bin.h"

void exibirMenu() {
    printf("\n========= MENU ARVORE BINARIA =========\n");
    printf("1. Inserir elemento\n");
    printf("2. Buscar elemento\n");
    printf("3. Exibir caminhamentos clássicos\n");
    printf("4. Exibir ESTRUTURA VISUAL (2D)\n"); // Nova Opção
    printf("5. Sair do programa\n");
    printf("Escolha uma opcao: ");
}

int main() {
    No* raiz = NULL;
    int opcao, valor;
    No* buscaResultado = NULL;

    do {
        exibirMenu();
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite um numero.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcao) {
            case 1:
                printf("Digite o valor inteiro para inserir: ");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                printf("Valor %d processado.\n", valor);
                break;

            case 2:
                printf("Digite o valor para buscar: ");
                scanf("%d", &valor);
                buscaResultado = buscar(raiz, valor);
                if (buscaResultado != NULL) {
                    printf("Sucesso! Chave %d encontrada.\n", buscaResultado->chave);
                } else {
                    printf("A chave %d NAO existe na arvore.\n", valor);
                }
                break;

            case 3:
                printf("\n--- CAMINHAMENTOS EM PROFUNDIDADE ---\n");
                printf("Pre-ordem: "); preOrdem(raiz); printf("\n");
                printf("Em-ordem:  "); emOrdem(raiz);  printf("\n");
                printf("Pos-ordem: "); posOrdem(raiz); printf("\n");
                break;

            case 4:
                printf("\n--- VISUALIZACAO GRAFICA DA ARVORE (Rotacionada 90 graus) ---\n");
                // Iniciamos o espaço base como 0
                imprimirArvore2D(raiz, 0);
                printf("-------------------------------------------------------------\n");
                break;

            case 5:
                printf("Liberando memoria da arvore e encerrando...\n");
                liberarArvore(raiz);
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}