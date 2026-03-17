#include <stdio.h>

int sum_dig(int n) {
    // 1. Caso Base: O número foi totalmente reduzido
    if (n == 0) {
        return 0;
    }

    // 2. Passo Recursivo:
    // Reduz o número (n/10) e soma com o dígito isolado (n % 10)
    return sum_dig(n / 10) + (n % 10);
}

int main() {
    int n = 123;
    printf("A soma dos digitos de %d = %d\n", n, sum_dig(n));
    return 0;
}