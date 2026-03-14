/*
7. Escreva uma funcao em C que receba um vetor de inteiros e retorne o maior valor
contido nele.
*/

#include <stdio.h>

int maiorValor(int vetor[], int tamanho) {
    int maior = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }
    return maior;
}

int main() {
    int numeros[10];

    printf("Digite 10 numeros inteiros:\n");
    for (int i = 0; i < 10; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    printf("Maior valor: %d\n", maiorValor(numeros, 10));

    return 0;
}