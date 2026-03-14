/*
4. Utilize o comando switch para criar um pequeno menu com 3 opcoes:
• 1 - Novo cadastro
• 2 - Consultar
• 3 - Sair
*/

#include <stdio.h>

int main() {

    int opcao;

    printf("1 - Novo cadastro\n");
    printf("2 - Consultar\n");
    printf("3 - Sair\n");
    
    do {
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Novo cadastro selecionado.\n");
                break;
            case 2:
                printf("Consultar selecionado.\n");
                break;
            case 3:
                printf("Sair selecionado.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 3);

    return 0;
}
