# Estrutura de Dados: Árvore Binária de Busca (ABB) em C

Este repositório contém uma implementação didática e modularizada de uma **Árvore Binária de Busca (ABB)** — em inglês, *Binary Search Tree (BST)* — desenvolvida em linguagem C. 

O objetivo principal deste projeto é consolidar conceitos de estruturas de dados não lineares, algoritmos recursivos, gerenciamento dinâmico de memória e demonstrar o impacto do uso de **Recursividade versus Iteração** na complexidade do código.

---

## Conteúdo Teórico

### 1. O que é uma Árvore Binária de Busca?
Uma Árvore Binária é uma estrutura onde cada nó possui, no máximo, dois filhos (convencionalmente chamados de *esquerdo* e *direito*). Para que ela seja uma Árvore Binária de **Busca**, uma regra fundamental de ordenação deve ser respeitada em toda a estrutura:

> **A Regra de Ouro da ABB:**
> Para qualquer nó escolhido:
> * Todos os valores na sua **subárvore esquerda** devem ser *menores* que o valor do nó.
> * Todos os valores na sua **subárvore direita** devem ser *maiores* que o valor do nó.

Essa regra garante que possamos efetuar buscas rápidas na estrutura, dividindo o espaço de pesquisa pela metade a cada passo — resultando em uma complexidade média de **$O(\log n)$**.

---

### 2. Caminhamentos em Profundidade (Traversal)
Como as árvores não são lineares, existem diferentes maneiras sistemáticas de visitar todos os nós exatamente uma vez. As três formas clássicas baseadas em profundidade são:

* **Pré-ordem (Pre-order):** Visita a Raiz, depois caminha na Esquerda e na Direita. (Ideal para clonar a árvore).
* **Em-ordem (In-order):** Caminha na Esquerda, visita a Raiz, depois caminha na Direita. Em uma ABB, este caminhamento exibe os elementos em **ordem estritamente crescente**.
* **Pós-ordem (Post-order):** Caminha na Esquerda, caminha na Direita e por fim visita a Raiz. (Ideal para desalocar a árvore da memória de baixo para cima com segurança).

---

### 3. O Paradoxo da Recursividade vs. Iteração
As árvores são estruturas conceitualmente recursivas, pois cada subárvore é, por si só, uma nova árvore menor. Por conta disso, algoritmos recursivos costumam ser infinitamente mais simples e elegantes.

Para provar esse ponto, este projeto traz o contraste do caminhamento **Em-Ordem**:
1. **Versão Recursiva:** É resolvida de forma natural e limpa com apenas 4 linhas de código.
2. **Versão Iterativa (Sem recursão):** Obriga o programador a criar e gerenciar uma **Pilha auxiliar de ponteiros na unha** para simular os bastidores do compilador, elevando drasticamente a complexidade visual e a chance de bugs.

---

## Organização dos Arquivos

O projeto está estritamente modularizado seguindo as boas práticas de engenharia de software:

* **`arvore_bin.h`**: Interface do módulo (definição de tipos e protótipos).
* **`arvore_bin.c`**: Implementação das regras de negócio e algoritmos.
* **`main.c`**: Interface com o usuário (menu iterativo via console).

---

##  Códigos Fonte Completos

### 1. Interface (`arvore_bin.h`)
```c
#ifndef ARVORE_BIN_H
#define ARVORE_BIN_H

// Definição da estrutura do Nó da Árvore
typedef struct no {
    int chave;
    struct no *esq; // Subárvore esquerda (valores menores)
    struct no *dir; // Subárvore direita (valores maiores)
} No;

// Funções de manipulação base
No* criarNo(int valor);
No* inserir(No* raiz, int valor);
No* buscarIterativo(No* raiz, int valor);

// Caminhamentos clássicos recursivos
void preOrdem(No* raiz);
void emOrdemRecursivo(No* raiz);
void posOrdem(No* raiz);

// Estudo de Caso: Caminhamento Iterativo (Sem Recursão)
void emOrdemIterativo(No* raiz);

// Impressão visual e liberação de memória
void imprimirArvore2D(No* raiz, int espaco);
void liberarArvore(No* raiz);

#endif