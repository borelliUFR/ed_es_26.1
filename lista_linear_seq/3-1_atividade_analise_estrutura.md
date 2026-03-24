### Resolução do Exercício de Fixação #3 (Análise de Estrutura)

#### 1. Cálculo de Memória
A variável `minhaLista` é uma `struct` que contém um array de 50 inteiros e uma variável inteira de controle.

* **Vetor `A[50]`:** $50 \times 4\text{ bytes} = 200\text{ bytes}$.
* **Variável `nroElem`:** $1 \times 4\text{ bytes} = 4\text{ bytes}$.
* **Total:** **204 bytes**.

> **Nota para a aula:** Reforce que esses 204 bytes são ocupados na memória **assim que o programa declara a variável**, mesmo que a lista esteja "vazia" (`nroElem = 0`). É por isso que chamamos de lista **estática**.

#### 2. Estado da Lista
Se `nroElem` vale 5, isso significa que temos 5 elementos armazenados. Como em C os vetores começam no índice 0:

* **Índices Válidos:** **0, 1, 2, 3 e 4**.
* O índice **5** é a primeira posição livre para uma futura inserção.

#### 3. Alteração da Struct (Reutilização de Tipos)
Para armazenar a estrutura `PesoAltura`, basta trocar o tipo base do array `A`.

**Código Modificado:**
```c
typedef struct {
    PesoAltura A[MAX]; // Agora o vetor guarda structs, não apenas ints
    int nroElem;
} LISTA;
```

* **Impacto na Memória (Curiosidade):** Se cada `PesoAltura` tem 8 bytes (como vimos no exercício anterior), a nova `LISTA` ocuparia $(50 \times 8) + 4 = \mathbf{404\text{ bytes}}$.
