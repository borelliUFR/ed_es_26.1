/*
Faca um programa que leia a idade de uma pessoa e informe se ela pode votar (idade
minima: 16 anos).
*/

#include <stdio.h>

int main() {

    int idade;

    printf("Digite a idade da pessoa: ");
    scanf("%d", &idade);

    if (idade >= 16) {
        printf("A pessoa pode votar.\n");
    } else {
        printf("A pessoa nao pode votar.\n");
    }

    return 0;
}
