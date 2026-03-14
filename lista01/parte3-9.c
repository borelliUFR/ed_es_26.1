/*
9. Crie uma funcao que receba dois numeros inteiros e retorne o resultado 
da multiplicacao sem usar o operador *.
*/

#include <stdio.h>

int multiplicar(int a, int b) {
    int resultado = 0;
    int negativo = 0;

    if (a < 0) {
        a = -a;
        negativo++;
    }
    if (b < 0) {
        b = -b;
        negativo++;
    }

    for (int i = 0; i < b; i++) {
        resultado += a;
    }

    if (negativo == 1) {
        resultado = -resultado;
    }

    return resultado;
}

int main() {
    int num1, num2;

    printf("Digite o primeiro numero inteiro: ");
    scanf("%d", &num1);

    printf("Digite o segundo numero inteiro: ");
    scanf("%d", &num2);

    printf("Resultado da multiplicacao: %d\n", multiplicar(num1, num2));

    return 0;
}