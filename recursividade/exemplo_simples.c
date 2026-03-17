#include <stdio.h>

// Função que imprime na IDA (antes de aprofundar na recursão)
void rec1(int n) {
    // A ação (printf) ocorre ANTES da chamada recursiva.
    // O aluno verá o número no console assim que a função for criada.
    printf("%d\n", n); 

    if (n > 0) {
        rec1(n - 1); // "Mergulha" para a próxima moldura na pilha
    }
    // Quando a função volta para cá, não há mais nada a fazer.
}

// Função que imprime na VOLTA (depois que a recursão retorna)
void rec2(int n) {
    if (n > 0) {
        rec2(n - 1); // "Mergulha" primeiro até chegar ao caso base (0)
    }

    // A ação (printf) ocorre DEPOIS da chamada recursiva.
    // A função fica "pausada" aqui enquanto as de cima não terminarem.
    // Ela só imprime quando a moldura acima dela é destruída.
    printf("%d\n", n); 
}

int main() {
    // Na rec1, o primeiro a entrar na pilha (4) é o primeiro a imprimir.
    printf("execucao rec1 (Imprime na IDA):\n");
    rec1(4);

    // Na rec2, a main chama o 4, que chama o 3... até o 0.
    // O 0 é o primeiro a imprimir e terminar, liberando o 1, depois o 2...
    printf("\n\nexecucao rec2 (Imprime na VOLTA):\n");
    rec2(4);

    return 0;
}