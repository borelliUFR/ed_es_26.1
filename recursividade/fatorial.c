#include <stdio.h>

/*
    Função: fatorial_rec
    Descrição: Calcula o fatorial de n utilizando recursão.
    Definição matemática:
        n! = n * (n-1)!
        0! = 1
*/
int fatorial_rec(int n) {
    if (n < 0) {
        return -1; // indica erro (fatorial não definido para negativos)
    }

    if (n == 0) {
        return 1;  // caso base
    }

    return n * fatorial_rec(n - 1);
}

/*
    Função: fatorial_iter
    Descrição: Calcula o fatorial de n utilizando abordagem iterativa.
*/
int fatorial_iter(int n) {
    if (n < 0) {
        return -1; // indica erro
    }

    int fat = 1;

    for (int i = 2; i <= n; i++) {
        fat *= i;
    }

    return fat;
}

int main() {
    int n = 3;

    printf("Calculo do fatorial de %d\n", n);
    printf("---------------------------\n");

    printf("Versao recursiva:\n");
    printf("%d! = %d\n", n, fatorial_rec(n));

    printf("\nVersao iterativa:\n");
    printf("%d! = %d\n", n, fatorial_iter(n));

    return 0;
}