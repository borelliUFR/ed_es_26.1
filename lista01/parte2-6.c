/*
6. Modifique o programa anterior para contar quantos dos numeros lidos sao pares.
*/

#include <stdio.h>

int main() {
    int numeros[10];
    int pares = 0;

    printf("Digite 10 numeros inteiros:\n");
    for (int i = 0; i < 10; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
        if (numeros[i] % 2 == 0) {
            pares++;
        }
    }

    printf("Quantidade de numeros pares: %d\n", pares);

    return 0;
}