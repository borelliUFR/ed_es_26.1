
### Resolução do Exercício de Fixação #1

#### 1. Representação Visual
A lista é um bloco contíguo na memória. Mesmo com nomes de comprimentos diferentes, o vetor reserva um espaço fixo para cada "caixa" (índice).

| Índice | Conteúdo (Valor) | Status |
| :--- | :--- | :--- |
| **0** | "Ana" | Ocupado |
| **1** | "Beto" | Ocupado |
| **2** | "Caio" | Ocupado |
| **3** | — | Vazio (Livre) |
| **4** | — | Vazio (Livre) |

> **Nota pedagógica:** Mostre aos alunos que, embora a capacidade seja 5, o tamanho atual (nroElem) é 3.

#### 2. Acesso Direto
Para imprimir "Beto", acessamos o índice **1** (já que a contagem em C começa sempre em 0).

**Comando em C:**
```c
printf("%s", lista.nomes[1]);
```
*(Considerando que `nomes` é o array dentro da nossa struct).*

#### 3. Reflexão (Dinâmica de Inserção)

* **Adicionar "Daniela" no final:** **É fácil!** Como sabemos que a lista tem 3 elementos, basta inserir Daniela diretamente no próximo índice disponível (índice **3**). Não é necessário mover ninguém. 
    *Complexidade: **O(1)***.

* **Adicionar "Alice" na posição 0:**
    **É trabalhoso.** Para Alice entrar no índice 0, os outros nomes não podem ser simplesmente apagados. Precisamos "arredar" todo mundo para a direita:
    1. Caio vai para o índice 3.
    2. Beto vai para o índice 2.
    3. Ana vai para o índice 1.
    4. **Só então** Alice ocupa o índice 0.
    *Complexidade: **O(n)***.
