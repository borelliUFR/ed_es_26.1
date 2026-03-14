#include <stdio.h>
#include <string.h>

struct contato
{
    char nome[50];
    char telefone[20];
    char email[50];
};

// Funcoes
// • void cadastrarContato(struct Contato *c)
// • void listarContatos(struct Contato contatos[], int n)
// • int buscarContato(struct Contato contatos[], int n, char nome[])

void cadastrarContato(struct contato *c)
{
    printf("Digite o nome do contato: ");
    fgets(c->nome, sizeof(c->nome), stdin);
    printf("Digite o telefone do contato: ");
    fgets(c->telefone, sizeof(c->telefone), stdin);
    printf("Digite o email do contato: ");
    fgets(c->email, sizeof(c->email), stdin);
}

void listarContatos(struct contato contatos[], int n)
{
    printf("Lista de Contatos:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Contato %d:\n", i + 1);
        printf("Nome: %s", contatos[i].nome);
        printf("Telefone: %s", contatos[i].telefone);
        printf("Email: %s", contatos[i].email);
        printf("\n");
    }
}

int buscarContato(struct contato contatos[], int n, char nome[])
{
    for (int i = 0; i < n; i++)
    {
        // strcmp retorna 0 se as strings são iguais 
        //(requer uso da biblioteca string.h para comparação de strings)
        if (strcmp(contatos[i].nome, nome) == 0)
        {
            return i; // Contato encontrado, retorna o índice
        }
    }
    return -1; // Contato não encontrado
}

// 1. Cadastrar ate 10 contatos (declarar contante).
// 2. Listar todos os contatos.
// 3. Permitir busca por nome.

#define MAX_CONTATOS 10

int main()
{
    struct contato contatos[MAX_CONTATOS];
    int n = 0; // Número de contatos cadastrados

    // usando o do while e switch case para criar um menu
    int opcao;
    do
    {        
        printf("Menu:\n");
        printf("1. Cadastrar Contato\n");
        printf("2. Listar Contatos\n");
        printf("3. Buscar Contato\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch (opcao)
        {
        case 1:
            if (n < MAX_CONTATOS)
            {
                cadastrarContato(&contatos[n]);
                n++;
            }
            else
            {
                printf("Limite de contatos atingido.\n");
            }
            break;
        case 2:
            listarContatos(contatos, n);
            break;
        case 3:
            {
                char nomeBusca[50];
                printf("Digite o nome do contato para buscar: ");
                fgets(nomeBusca, sizeof(nomeBusca), stdin);
                int indice = buscarContato(contatos, n, nomeBusca);
                if (indice != -1)
                {
                    printf("Contato encontrado:\n");
                    printf("Nome: %s", contatos[indice].nome);
                    printf("Telefone: %s", contatos[indice].telefone);
                    printf("Email: %s", contatos[indice].email);
                }
                else
                {
                    printf("Contato não encontrado.\n");
                }
            }
            break;
        case 4:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida.\n");
        }
    } while (opcao != 4);

    return 0;
}