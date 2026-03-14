// Funcoes
// • void cadastrarLivro(struct Livro *l)
// • void listarLivros(struct Livro livros[], int n)
// • void buscarPorAutor(struct Livro livros[], int n, char autor[])

#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct livro
{
    int codigo;
    char titulo[100];
    char autor[50];
    int ano;
} Livro;

void cadastrarLivro(struct livro *l);
void listarLivros(struct livro livros[], int n);
void buscarPorAutor(struct livro livros[], int n, char autor[]);

#endif // FUNCOES_H