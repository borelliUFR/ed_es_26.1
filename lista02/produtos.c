#include <stdio.h>

struct produtos
{
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
};

// • void cadastrarProduto(struct Produto *p)
// • float calcularValorEstoque(struct Produto p)
// • void mostrarProduto(struct Produto p)

void cadastrarProduto(struct produtos *p) {
    printf("Digite o codigo do produto: ");
    scanf("%d", &p->codigo);
    printf("Digite o nome do produto: ");
    scanf("%s", p->nome);
    printf("Digite o preco do produto: ");
    scanf("%f", &p->preco);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &p->quantidade);
}

float calcularValorEstoque(struct produtos p) {
    return p.preco * p.quantidade;
}

void mostrarProduto(struct produtos p) {
    printf("Codigo: %d\n", p.codigo);
    printf("Nome: %s\n", p.nome);
    printf("Preco: %.2f\n", p.preco);
    printf("Quantidade: %d\n", p.quantidade);
    printf("Valor do estoque: %.2f\n", calcularValorEstoque(p));
}

// 1. Cadastrar 4 produtos.
// 2. Calcular o valor total de cada item (preco * quantidade).
// 3. Mostrar todos os produtos e o valor total do estoque.

int main() {
    struct produtos produto[4];

    for (int i = 0; i < 4; i++)    {
        printf("Produto %d:\n", i + 1);
        cadastrarProduto(&produto[i]);
    }

    for (int i = 0; i < 4; i++)    {
        printf("\nProduto %d:\n", i + 1);
        mostrarProduto(produto[i]);
    }
    
    return 0;
}