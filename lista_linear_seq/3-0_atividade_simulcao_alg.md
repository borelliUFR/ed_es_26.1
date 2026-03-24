### Resolução do Exercício de Fixação #4 (Simulação de Algoritmo)

#### 1. Inserção na Posição 0
Para inserir o valor **5** no índice **0**, todos os elementos atuais precisam "abrir caminho".
* **Elementos a serem deslocados:** 10, 20, 30, 40 e 50.
* **Total de deslocamentos:** **5 elementos**.
* **Lógica:** O 50 vai para o índice 5, o 40 para o 4, o 30 para o 3, o 20 para o 2 e o 10 para o 1. Só então o 5 ocupa o índice 0.

#### 2. Análise de Limite (Overflow)
Se tentarmos inserir um 11º elemento em um vetor de `MAX 10`:
* **O que aconteceria:** Ocorrerá um **Overflow** (estouro de buffer). O programa tentaria escrever em um endereço de memória que não pertence à lista, o que pode causar o fechamento repentino do programa (*Segmentation Fault*) ou corromper outras variáveis.
* **Como o `tamanho` ajuda:** Antes de qualquer inserção, fazemos um teste lógico: `if (lista.tamanho == MAX)`. Se for verdadeiro, barramos a operação e exibimos um erro, garantindo a integridade do sistema.

#### 3. Prática (Acesso ao Último Elemento)
Como os vetores em C começam no índice **0**, o último elemento válido não está na posição `tamanho`, mas sim uma posição antes.

**Linha de código em C:**
```c
printf("Último elemento: %d", lista.itens[lista.tamanho - 1]);
```

> **Atenção Alunos:** Se você tentar acessar `lista.itens[lista.tamanho]`, você estará acessando a primeira posição **vazia** (lixo de memória ou espaço para a próxima inserção), um erro muito comum em provas!
