#include <stdio.h>
#include <string.h>

struct livro
{
    int codigo;
    char titulo[100];
    char autor[50];
    int ano;
};

// Funcoes
// • void cadastrarLivro(struct Livro *l)
// • void listarLivros(struct Livro livros[], int n)
// • void buscarPorAutor(struct Livro livros[], int n, char autor[])

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
