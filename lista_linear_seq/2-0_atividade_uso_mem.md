### Resolução do Exercício de Fixação #2 (Uso de Memória)

#### 1. Alteração da Estrutura
Ao adicionar o campo `int idade;`, a estrutura passa a ter três inteiros.

**Código Modificado:**
```c
typedef struct {
    int peso;   // 4 bytes
    int altura; // 4 bytes
    int idade;  // 4 bytes
} PesoAltura;
```
* **Novo Tamanho Total:** $4 + 4 + 4 = \mathbf{12\ bytes}$.

#### 2. Operador `sizeof`
Ao rodar `printf("%zu", sizeof(PesoAltura));`, o resultado esperado na maioria das arquiteturas modernas (32 ou 64 bits) é **12**. 

* **Por que isso é importante?** Alguns alunos podem esperar valores diferentes se esquecerem que o `int` padrão em C costuma ocupar 4 bytes. O `sizeof` é a única forma segura de saber o espaço que o compilador realmente reservou.

#### 3. Desafio de Endereço e Distância
Ao imprimir os endereços com `%p`, os alunos verão valores em hexadecimal (ex: `0x7ffed1`).

**Exemplo de saída:**
`End. Peso: 0x1000 | End. Altura: 0x1004`

* **A Distância:** A subtração dos endereços (em valor absoluto) será **4**.
* **A Conclusão:** Isso prova fisicamente que a `struct` é **contígua**. O campo `altura` começa exatamente onde o campo `peso` termina. Não há espaços vazios entre eles; eles estão "colados" na memória.
