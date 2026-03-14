/*
3. Elabore um algoritmo que calcule a media de 4 notas e imprima se o aluno foi
aprovado (media ≥ 6), reprovado ou em recuperacao (media entre 4 e 5.9).
*/

#include <stdio.h>

int main() {

    float nota1, nota2, nota3, nota4, media;

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    printf("Digite a quarta nota: ");
    scanf("%f", &nota4);

    media = (nota1 + nota2 + nota3 + nota4) / 4;

    printf("A media do aluno e: %.2f\n", media);

    if (media >= 6) {
        printf("O aluno foi aprovado.\n");
    } else if (media >= 4) {
        printf("O aluno esta em recuperacao.\n");
    } else {
        printf("O aluno foi reprovado.\n");
    }

    return 0;
}
