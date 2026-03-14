#include <stdio.h>

struct funcionarios
{
    int id;
    char nome[50];
    float salarioBruto;
    float per_desconto;
    float salarioLiquido;
};

// Funcoes
// • void lerFuncionario(struct Funcionario *f)
// • float calcularSalarioLiquido(struct Funcionario f)
// • void imprimirFuncionario(struct Funcionario f)

void lerFuncionario(struct funcionarios *f) {
    printf("Digite o id do funcionario: ");
    scanf("%d", &f->id);
    printf("Digite o nome do funcionario: ");
    scanf("%s", f->nome);
    printf("Digite o salario bruto do funcionario: ");
    scanf("%f", &f->salarioBruto);
    printf("Digite o percentual de desconto do funcionario: ");
    scanf("%f", &f->per_desconto);
}

float calcularSalarioLiquido(struct funcionarios f) {
    return f.salarioBruto * (1 - f.per_desconto/100);
}

void imprimirFuncionario(struct funcionarios f) {
    printf("ID: %d\n", f.id);
    printf("Nome: %s\n", f.nome);
    printf("Salario Bruto: %.2f\n", f.salarioBruto);
    printf("Desconto: %.2f\n", f.per_desconto);
    printf("Salario Liquido: %.2f\n", calcularSalarioLiquido(f));
}

// 1. Ler dados de 3 funcionarios.
// 2. Calcular o salario lıquido.
// 3. Mostrar os dados na tela.

int main() {
    struct funcionarios funcionario[3];

    for (int i = 0; i < 3; i++)    {
        printf("Funcionario %d:\n", i + 1);
        lerFuncionario(&funcionario[i]);
    }

    for (int i = 0; i < 3; i++)    {
        printf("\nFuncionario %d:\n", i + 1);
        imprimirFuncionario(funcionario[i]);
    }
    
    return 0;
}