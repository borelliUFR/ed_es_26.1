#include <stdio.h>
#include <time.h>

#define MAX_SIZE 10000

int buscaSequencial(int arr[], int n, int x, int *comp) {
    *comp = 0;
    for (int i = 0; i < n; i++) {
        (*comp)++;
        if (arr[i] == x) {
            printf("Elemento encontrado na posição: %d\n", i);
            return i;
        }
    }
    printf("Elemento não encontrado.\n");
    return -1;
}

int buscaBinaria(int arr[], int n, int x, int *comp) {
    int left = 0, right = n - 1;
    *comp = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        (*comp)++;
        if (arr[mid] == x) {
            printf("Elemento encontrado na posição: %d\n", mid);
            return mid;
        }
        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Elemento não encontrado.\n");
    return -1;
}

int main() {
    int arr[MAX_SIZE];
    int n = MAX_SIZE;
    int x = 1000;
    int comp;

    for (size_t i = 0; i < n; i++)
    {
        arr[i] = i; // Preenchendo o array com valores ordenados
    }
    
    clock_t start, end;
    double cpu_time_used;

    // Teste da busca sequencial
    start = clock();
    buscaSequencial(arr, n, x, &comp);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução da busca sequencial: %f segundos\n", cpu_time_used);
    printf("Número de comparações na busca sequencial: %d\n", comp);

    // Teste da busca binária
    comp = 0; // Resetar o contador de comparações para a busca binária
    start = clock();
    buscaBinaria(arr, n, x, &comp);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução da busca binária: %f segundos\n", cpu_time_used);
    printf("Número de comparações na busca binária: %d\n", comp);

    return 0;
}