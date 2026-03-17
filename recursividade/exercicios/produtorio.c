#include <stdio.h>

// Calcula o produto de todos os inteiros entre m e n (m <= n)
int prod(int m, int n) {
    // 1. Caso Base: O intervalo reduziu a um único número
    if (m == n) {
        return m;
    } 
    
    // 2. Caso Recursivo: Multiplica o limite superior (n) 
    // pelo produto do restante do intervalo (n-1)
    return n * prod(m, n - 1);
}

int main() {
    int m = 2, n = 4;
    printf("O produto no intervalo [%d, %d] = %d\n", m, n, prod(m, n));
    return 0;
}