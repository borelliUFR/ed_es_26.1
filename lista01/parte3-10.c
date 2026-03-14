/*
10. Implemente um programa que utilize ponteiros para trocar o valor de duas variaveis
(dica: use uma funcao void troca(int *a, int *b)).
*/

#include <stdio.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1, num2;

    printf("Digite o primeiro numero inteiro: ");
    scanf("%d", &num1);

    printf("Digite o segundo numero inteiro: ");
    scanf("%d", &num2);

    // imprimindo enderecos das variaveis
    printf("Enderecos de num1 e num2: %p e %p\n", (void*)&num1, (void*)&num2);

    printf("Valores antes da troca: %d e %d\n", num1, num2);

    troca(&num1, &num2);

    printf("Valores depois da troca: %d e %d\n", num1, num2);
    
    return 0;
}
  