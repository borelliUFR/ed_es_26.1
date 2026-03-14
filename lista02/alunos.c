#include <stdio.h>

struct alunos
{
    char matricula[10];
    char nome[50];
    float notas[3];
};

// funcao lerAluno(Aluno *a)
void lerAluno(struct alunos *a) {
    printf("Digite a matricula do aluno: ");
    scanf("%s", a->matricula);
    printf("Digite o nome do aluno: ");
    scanf("%s", a->nome);
    for (int i = 0; i < 3; i++)
    {
        printf("Digite a nota %d do aluno: ", i + 1);
        scanf("%f", &a->notas[i]);
    }
}

// funcao calcularMedia(Aluno a)
float calcularMedia(struct alunos a) {
    float soma = 0;
    for (int i = 0; i < 3; i++)    {
        soma += a.notas[i];
    }
    return soma / 3;
}  

// funcao imprimirAluno(Aluno a)
void imprimirAluno(struct alunos a) {
    printf("Matricula: %s\n", a.matricula);
    printf("Nome: %s\n", a.nome);
    for (int i = 0; i < 3; i++)    {
        printf("Nota %d: %.2f\n", i + 1, a.notas[i]);
    }
    printf("Media: %.2f\n", calcularMedia(a));
}  

int main() {
    struct alunos aluno[5];

    for (int i = 0; i < 5; i++)    {
        printf("Aluno %d:\n", i + 1);
        lerAluno(&aluno[i]);
    }

    for (int i = 0; i < 5; i++)    {
        printf("\nAluno %d:\n", i + 1);
        imprimirAluno(aluno[i]);
    }
    
    return 0;
}
