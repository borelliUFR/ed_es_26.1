#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha_estatica.h"

int main() {
    Pilha navegador;
    inicializar(&navegador);
    
    int opcao;
    char url[100];
    char url_removida[100];

    do {
        printf("\n===== NAVEGADOR WEB SIMPLIFICADO =====");
        printf("\n1. Visitar nova pagina");
        printf("\n2. Voltar para pagina anterior (Voltar)");
        printf("\n3. Exibir pagina atual");
        printf("\n4. Mostrar todo o historico");
        printf("\n5. Encerrar o programa");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado (evita problemas com fgets)

        switch(opcao) {
            case 1:
                printf("Digite a URL da nova pagina (ex: google.com): ");
                fgets(url, 100, stdin);
                url[strcspn(url, "\n")] = 0; // Remove a quebra de linha do fgets
                if (push(&navegador, url)) {
                    printf("Página adicionada com sucesso!\n");
                }
                break;
            case 2:
                if (pop(&navegador, url_removida)) {
                    printf("Saindo de: %s...\n", url_removida);
                    exibir_atual(&navegador);
                }
                break;
            case 3:
                exibir_atual(&navegador);
                break;
            case 4:
                mostrar_historico(&navegador);
                break;
            case 5:
                printf("\nFechando o navegador... Histórico descartado.\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}