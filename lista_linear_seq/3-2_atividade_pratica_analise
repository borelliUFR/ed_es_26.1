### Resolução do Exercício de Fixação #5 (Prática e Análise)

#### 1. Simulação de Inserção (`insere(&l, 1, 20)`)
* **O que acontece:** Como a posição 1 já está ocupada pelo valor 25, todos os elementos do índice 1 em diante devem "abrir espaço".
    * O **55** vai para o índice 5.
    * O **45** vai para o índice 4.
    * O **35** vai para o índice 3.
    * O **25** vai para o índice 2.
    * O valor **20** é então colocado no índice 1.
* **Novo valor do tamanho:** O campo `tamanho` passará de 5 para **6**.



#### 2. Análise de Limite (Posição 11)
* **Retorno:** A função retornará **0** (falha).
* **Por que é importante:** Em C, os vetores têm tamanho fixo. Tentar acessar a posição 11 em um vetor de `MAX = 10` resultaria em uma invasão de memória (*Buffer Overflow*). Sem essa verificação (`pos > l->tamanho`), o programa poderia sobrescrever dados de outras variáveis ou causar um erro de execução (*Segmentation Fault*).

#### 3. Complexidade na Prática ($O(1)$ vs $O(n)$)
* **Atualização $O(1)$:** É instantânea porque conhecemos o endereço exato (índice). O computador não precisa "procurar", ele vai direto na "gaveta" correta e troca o conteúdo.
* **Busca $O(n)$:** Como os dados não estão necessariamente em ordem ou em uma posição conhecida, o computador precisa olhar o índice 0, depois o 1, depois o 2... até encontrar o valor ou chegar ao fim. No pior caso, ele fará $n$ comparações.

#### 4. Desafio de Programação (Remoção do Último)
* **Resposta:** **Não**, o laço `for` não será executado.
* **Justificativa:** Na função `remove`, o laço é definido como `for (int i = pos; i < l->tamanho - 1; i++)`. 
    * Se `pos` for igual a `tamanho - 1`, a condição de parada (`i < l->tamanho - 1`) já começa como **falsa** (ex: `4 < 4` é falso). 
    * Portanto, o programa pula o deslocamento (já que não há ninguém à direita para "puxar") e apenas executa `l->tamanho--`, o que é logicamente correto e muito eficiente ($O(1)$ para o último elemento).
