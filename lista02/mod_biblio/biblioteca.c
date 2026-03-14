#include <stdio.h>
#include <string.h>

// usar biblioteca criada em funcoes.c
// para compilar: gcc biblioteca.c funcoes.c -o biblioteca
#include "funcoes.h"

// 1. Cadastrar 5 livros (declarar constante).
// 2. Listar todos os livros.
// 3. Permitir busca por autor

#define MAX_LIVROS 5

int main()
{
    struct livro livros[MAX_LIVROS];
    int n = 0; // Número de livros cadastrados

    // criar menu para cadastrar, listar e buscar livros
    int opcao;
    do
    {        
        printf("Menu:\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Listar Livros\n");
        printf("3. Buscar por Autor\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {        case 1:
            if (n < MAX_LIVROS)
            {                
                cadastrarLivro(&livros[n]);
                n++;
            }
            else
            {                
                printf("Limite de livros cadastrados atingido.\n");
            }
            break;
        case 2:
            listarLivros(livros, n);
            break;
        case 3:
            {                
                char autorBusca[50];
                printf("Digite o nome do autor para buscar: ");
                scanf(" %[^\n]", autorBusca); // Lê uma linha inteira
                buscarPorAutor(livros, n, autorBusca);
            }
            break;
        case 4:
            printf("Saindo do programa.\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }   

        printf("\n");
    } while (opcao != 4);

    return 0;
}
