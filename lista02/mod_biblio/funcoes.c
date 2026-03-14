// Implementação das funções da biblioteca
#include <stdio.h>
#include <string.h>

struct livro
{
    int codigo;
    char titulo[100];
    char autor[50];
    int ano;
};

void cadastrarLivro(struct livro *l)
{
    printf("Digite o código do livro: ");
    scanf("%d", &l->codigo);
    printf("Digite o título do livro: ");
    scanf(" %[^\n]", l->titulo); // Lê uma linha inteira
    printf("Digite o autor do livro: ");
    scanf(" %[^\n]", l->autor); // Lê uma linha inteira
    printf("Digite o ano de publicação do livro: ");
    scanf("%d", &l->ano);
}

void listarLivros(struct livro livros[], int n)
{
    printf("Lista de Livros:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Livro %d:\n", i + 1);
        printf("Código: %d\n", livros[i].codigo);
        printf("Título: %s\n", livros[i].titulo);
        printf("Autor: %s\n", livros[i].autor);
        printf("Ano: %d\n", livros[i].ano);
        printf("\n");
    }
}

void buscarPorAutor(struct livro livros[], int n, char autor[])
{
    printf("Livros do autor %s:\n", autor);
    for (int i = 0; i < n; i++)
    {
        // strcmp retorna 0 se as strings são iguais 
        //(requer uso da biblioteca string.h para comparação de strings)
        if (strcmp(livros[i].autor, autor) == 0)
        {
            printf("Código: %d\n", livros[i].codigo);
            printf("Título: %s\n", livros[i].titulo);
            printf("Ano: %d\n", livros[i].ano);
            printf("\n");
        }
    }
}

