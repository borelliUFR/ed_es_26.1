#include <stdio.h>

int soma_pares(int n) {
    // 1. Caso Base: Paramos quando n chega a 0
    if (n <= 0) {
        return 0;
    } 

    // 2. Casos Recursivos
    if (n % 2 == 0) {
        // Se for par, acumula n e pula para o próximo par (n-2)
        return n + soma_pares(n - 2);
    } else {
        // Se for ímpar, apenas pula para o número anterior
        return soma_pares(n - 1);
    }
}

int main() {
    int n = 6;
    printf("A soma dos pares ate %d eh %d\n", n, soma_pares(n));
    return 0;
}