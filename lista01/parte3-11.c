/*
11. (Desafio) Faca um programa que leia uma string e use ponteiros para contar quantas
vogais ela contem.
*/

#include <stdio.h>
#include <string.h>

int contarVogais(char *str) {
    int count = 0;
    char *ptr = str;

    while (*ptr != '\0') {
        switch (*ptr) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                count++;
                break;
        }
        ptr++;
    }

    return count;
}

int main() {
    char str[50];

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    printf("Numero de vogais: %d\n", contarVogais(str));

    return 0;
}
 