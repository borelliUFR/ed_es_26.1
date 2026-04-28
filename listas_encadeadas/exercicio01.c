#include <stdio.h>
#include <stdlib.h>

// Definimos o tipo 'celula' ao mesmo tempo que a estrutura
typedef struct reg {
    int conteudo;
    struct reg *prox; // Aqui usamos 'struct reg' porque o typedef 'celula' 
                      // ainda nao foi finalizado pelo compilador
} celula;

int main(void) {
    // %zu e o especificador correto para size_t (retorno do sizeof)
    printf("sizeof(celula) = %zu bytes\n", sizeof(celula));
    
    return EXIT_SUCCESS;
}