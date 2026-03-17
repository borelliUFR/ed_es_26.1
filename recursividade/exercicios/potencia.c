#include <stdio.h>

int potencia(int k, int n) {
    // 1. Caso Base
    if (n == 0) return 1;

    // 2. Passo Recursivo: Calcula a metade da potência
    int aux = potencia(k, n / 2);

    // 3. Combinação dos resultados
    if (n % 2 == 0) {
        return aux * aux; // Ex: 2^4 = 2^2 * 2^2
    } else {
        return k * aux * aux; // Ex: 2^5 = 2 * 2^2 * 2^2
    }
}

int main() {
    int k = 2, n = 3;
    printf("%d elevado a %d = %d\n", k, n, potencia(k, n));
    return 0;
}