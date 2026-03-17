#include <stdio.h>

// Função que multiplica x por y através de somas sucessivas
int mult(int x, int y) {
    // 1. Caso Base: Se y for 1, o resultado é o próprio x
    if (y == 1) {
        return x;
    }

    // 2. Caso Recursivo: Soma x com a multiplicação de (y-1)
    // Ex: 2 * 4 = 2 + (2 * 3)
    return x + mult(x, y - 1);
}

int main() {
    int x = 2, y = 4;
    printf("%d x %d = %d\n", x, y, mult(x, y));
    return 0;
}