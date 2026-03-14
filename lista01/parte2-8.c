/*
8. Implemente um programa que leia 5 nomes e os imprima em ordem inversa.
*/

#include <stdio.h>

int main() {
    char nomes[5][100];

    printf("Digite 5 nomes:\n");
    for (int i = 0; i < 5; i++) {
        printf("Nome %d: ", i + 1);
        scanf("%s", nomes[i]);
    }

    printf("Nomes em ordem inversa:\n");
    for (int i = 4; i >= 0; i--) {
        printf("%s\n", nomes[i]);
    }

    return 0;
}
