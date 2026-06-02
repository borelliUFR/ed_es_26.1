#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila_dinamica.h"

// Função auxiliar para limpar a quebra de linha do fgets
void remove_quebra_linha(char *str) {
    size_t tamanho = strlen(str);
    if (tamanho > 0 && str[tamanho - 1] == '\n') {
        str[tamanho - 1] = '\0';
    }
}

int main() {
    Fila* fila_alunos = cria_Fila();
    if (fila_alunos == NULL) {
        printf("Erro fatal: Nao foi possivel inicializar a fila.\n");
        return 1;
    }

    int opcao;
    Aluno al_aux; // Estrutura auxiliar para leitura e consulta

    do {
        printf("\n===== SISTEMA DE ATENDIMENTO (FILA) =====");
        printf("\n1. Inserir aluno na fila (Enqueue)");
        printf("\n2. Atender proximo aluno (Dequeue)");
        printf("\n3. Consultar primeiro da fila (Peek)");
        printf("\n4. Mostrar todos da fila");
        printf("\n5. Exibir tamanho atual da fila");
        printf("\n6. Encerrar o programa");
        printf("\nEscolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("\nErro: Entrada invalida! Digite um numero.\n");
            while (getchar() != '\n'); // Limpa buffer em caso de entrada de texto
            continue;
        }
        getchar(); // Limpa o '\n' deixado pelo scanf antes dos fgets

        switch (opcao) {
            case 1:
                if (Fila_cheia(fila_alunos)) {
                    printf("\n[Erro] A fila esta cheia! Limite maximo atingido.\n");
                } else {
                    printf("\n--- CADASTRAR ALUNO NA FILA ---");
                    printf("\nDigite a matricula: ");
                    scanf("%d", &al_aux.matricula);
                    getchar(); // Limpa o buffer

                    printf("Digite o nome: ");
                    fgets(al_aux.nome, 30, stdin);
                    remove_quebra_linha(al_aux.nome);

                    printf("Digite a nota 1: ");
                    scanf("%f", &al_aux.n1);
                    printf("Digite a nota 2: ");
                    scanf("%f", &al_aux.n2);
                    printf("Digite a nota 3: ");
                    scanf("%f", &al_aux.n3);

                    if (insere_Fila(fila_alunos, al_aux)) {
                        printf("\nSucesso: %s foi inserido(a) no fim da fila.\n", al_aux.nome);
                    } else {
                        printf("\n[Erro] Nao foi possivel inserir o aluno.\n");
                    }
                }
                break;

            case 2:
                // Antes de remover, consulta para saber quem está sendo atendido
                if (consulta_Fila(fila_alunos, &al_aux)) {
                    printf("\nChamando para atendimento: %s (Matricula: %d)...", al_aux.nome, al_aux.matricula);
                    if (remove_Fila(fila_alunos)) {
                        printf("\nSucesso: Aluno atendido e removido da fila.\n");
                    }
                } else {
                    printf("\n[Erro] Nenhum aluno na fila para ser atendido (Fila Vazia).\n");
                }
                break;

            case 3:
                if (consulta_Fila(fila_alunos, &al_aux)) {
                    printf("\n--> Primeiro da fila atual: %s (Matricula: %d)", al_aux.nome, al_aux.matricula);
                    printf("\n    Notas: %.1f | %.1f | %.1f\n", al_aux.n1, al_aux.n2, al_aux.n3);
                } else {
                    printf("\nA fila esta completamente vazia.\n");
                }
                break;

            case 4:
                imprime_Fila(fila_alunos);
                break;

            case 5:
                printf("\nQuantidade de alunos aguardando: %d\n", tamanho_Fila(fila_alunos));
                break;

            case 6:
                printf("\nEncerrando sistema... Desalocando dados.\n");
                libera_Fila(fila_alunos);
                break;

            default:
                printf("\nOpcao invalida! Escolha um valor entre 1 e 6.\n");
        }
    } while (opcao != 6);

    return 0;
}