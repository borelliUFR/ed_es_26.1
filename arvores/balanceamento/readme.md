# Estruturas de Dados Avançadas: Árvores Auto-Balanceáveis (AVL e Red-Black)

Este repositório contém implementações robustas e didáticas em C de duas das principais árvores binárias de busca auto-balanceáveis: **Árvores AVL** e **Árvores Red-Black (Rubro-Negras)**. O objetivo deste projeto é fornecer uma referência limpa de código, detalhando os mecanismos de rotação, recolorização e as decisões de projeto que garantem a complexidade de tempo de pior caso em $O(\log n)$ para operações de busca, inserção e remoção.

## 1. Visão Geral das Estruturas

### Árvore AVL
A árvore AVL (Adelson-Velsky e Landis) adota um critério estrito de balanceamento baseado na **altura** dos nós. Para cada nó, a diferença entre a altura da subárvore esquerda e direita (Fator de Balanceamento - FB) deve pertencer estritamente ao conjunto $\{-1, 0, 1\}$. 
* **Vantagem:** Busca extremamente rápida devido ao balanceamento rigoroso.
* **Desvantagem:** Operações de escrita (inserção/remoção) podem exigir múltiplas rotações ao longo do caminho de retorno da pilha recursiva.

### Árvore Red-Black
A árvore Red-Black (Rubro-Negra) utiliza uma abordagem de balanceamento mais flexível baseada na **coloração** dos nós (Vermelho ou Preto) e no conceito de *altura preta* (todos os caminhos da raiz às folhas nulas contêm o mesmo número de nós pretos).
* **Vantagem:** Menor custo computacional nas operações de modificação (no máximo duas rotações por inserção).
* **Desvantagem:** A altura máxima pode chegar a aproximadamente $2 \times \log_2(n + 1)$, o que torna a busca ligeiramente mais lenta que na AVL em cenários de leitura intensa.

---

## 2. Casos de Balanceamento Implementados

### Mecanismos de Correção AVL
O balanceamento é verificado de baixo para cima durante o retorno da recursão da inserção:
1. **Rotação Simples à Direita (LL):** Aplicada quando o nó possui $FB = 2$ e seu filho esquerdo possui $FB \ge 0$.
2. **Rotação Simples à Esquerda (RR):** Aplicada quando o nó possui $FB = -2$ e seu filho direito possui $FB \le 0$.
3. **Rotação Dupla Esquerda-Direita (LR):** Ocorre quando o nó possui $FB = 2$ e o filho esquerdo possui $FB = -1$.
4. **Rotação Dupla Direita-Esquerda (RL):** Ocorre quando o nó possui $FB = -2$ e o filho direito possui $FB = 1$.

### Mecanismos de Correção Red-Black (Fix-Up)
A inserção iterativa insere um nó sempre como **Vermelho**. Se o pai do novo nó também for Vermelho, viola-se a regra de adjacência e dispara-se a correção baseada na cor do **Tio**:
1. **Caso 1 (Tio Vermelho):** Recolorização do Pai e do Tio para Preto, e do Avô para Vermelho. O problema é propagado para o Avô.
2. **Caso 2 (Tio Preto - Configuração em Zigue-Zague):** Uma rotação simples no Pai transforma a estrutura em uma linha reta (Caso 3).
3. **Caso 3 (Tio Preto - Configuração em Linha Reta):** Uma rotação no Avô combinada com a inversão de cores do Pai e do Avô reestabelece a propriedade.

---

## 3. Estruturas de Dados em C

### Nó da Árvore AVL
```c
typedef struct NoAVL {
    int chave;
    struct NoAVL *esq;
    struct NoAVL *dir;
    int altura; 
} NoAVL;
```
### Nó da Árvore Red-Black
```c
typedef enum { VERMELHO, PRETO } Cor;

typedef struct NoRB {
    int chave;
    Cor cor;
    struct NoRB *esq;
    struct NoRB *dir;
    struct NoRB *pai;
} NoRB;
```
---

## 4. Análise de Complexidade

| Operação | Árvore AVL (Pior Caso) | Árvore Red-Black (Pior Caso) |
| :--- | :---: | :---: |
| **Busca** | $O(\log n)$ | $O(\log n)$ |
| **Inserção** | $O(\log n)$ | $O(\log n)$ |
| **Remoção** | $O(\log n)$ | $O(\log n)$ |
| **Altura Máxima** | $\approx 1.44 \times \log_2 n$ | $\approx 2 \times \log_2 (n+1)$ |
| **Rotações (Inserção)** | Até $O(\log n)$ | No máximo 2 |

## 5. Compilação e Execução
O projeto está estruturado em arquivos fonte separados para facilitar a modularização. Certifique-se de ter um compilador compatível com o padrão C99 (como gcc) instalado.

Estrutura de Arquivos Recomendada
```c
├── avl.h
├── avl.c
├── red_black.h
├── red_black.c
└── main.c
```
---

## 6. Considerações de Projeto

Gerenciamento de Memória: O código foi projetado para evitar vazamentos de memória (memory leaks), liberando os nós alocados dinamicamente via caminhamento pós-ordem na destruição das árvores.

Ponteiros Extras: A árvore Red-Black utiliza explicitamente um ponteiro para o nó pai. Isso simplifica a subida iterativa no método de ajuste (Fix-Up), eliminando a necessidade de gerenciar uma pilha manual de ancestrais.