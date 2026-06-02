#ifndef PILHA_ESTATICA_H
#define PILHA_ESTATICA_H

// fiz uma redução no tamanho do vetor, mas basta mudar aqui
#define MAX 10

// Estrutura sugerida no exercicio
typedef struct {
    char paginas[MAX][100];
    int topo;
} Pilha;

// Funções de manipulação da Pilha
void inicializar(Pilha *p);
int esta_vazia(Pilha *p);
int esta_cheia(Pilha *p);
int push(Pilha *p, char *pagina);
int pop(Pilha *p, char *pagina_removida);
void exibir_atual(Pilha *p);
void mostrar_historico(Pilha *p);

#endif