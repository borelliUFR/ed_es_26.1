// 1. Operações Básicas com Vetor
    // Objetivo: Praticar a criação, o preenchimento e o cálculo em um vetor.
    // 1. Declare um vetor de 5 posições do tipo int.
    // 2. Preencha o vetor com valores fornecidos pelo usuário.
    // 3. Calcule e exiba a soma de todos os elementos.
    // 4. Encontre e exiba o maior e o menor valor do vetor

// importando a biblioteca padrão de entrada e saída
#include <stdio.h>

// Definindo o número máximo de posições
#define MAX 5

// Função principal
int main() 
{
    // definindo vetor, embora não seja pedido no enunciado 
    // a predefinição dos valores, acabei fazendo.
	int v[MAX] = {5, 2, 3, 1, 9};

    // laço para preenchimento dos valores do vetor
    printf("Preencha o vetor com %d valores inteiros:\n", MAX);
    for(int i = 0; i < MAX; i++)
    {
        printf("Valor %d: ", i + 1);
        scanf("%d", &v[i]);
    }

    // definição das variáveis para armazenar a soma, o maior e o menor
    int soma = 0;
    int maior = v[0];
    int menor = v[0];

    // novo laço para coletar os dados de soma, maior e menor
    // poderíamos utilizar somente um laço? Se sim, qual a razão para fazer isso?
    for(int i = 0; i < MAX; i++)
    {
        soma += v[i];
        if(v[i] > maior) maior = v[i];
        if(v[i] < menor) menor = v[i];
    }

    // mostrando os resultados
    printf("Soma dos elementos: %d\n", soma);
    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

	return 0;
}