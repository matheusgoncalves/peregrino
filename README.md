# Jogo de Aventura baseado em Texto

Este projeto é um jogo de aventura baseado em texto desenvolvido para a disciplina de Algoritmos e Estruturas de Dados 1, inspirado na saga *O Senhor dos Anéis*. Nele, o jogador assume o papel de Frodo, um hobbit encarregado de levar o Um Anel até a Montanha da Perdição para destruí-lo. Durante a jornada, o jogador vai precisar tomar decisões que influenciam a história, coletar itens e enfrentar eventos aleatórios.

## **Explicação sobre a Escolha das Estruturas de Dados**

Aqui estão as estruturas de dados escolhidas para o projeto e como elas foram aplicadas:

### **1. Árvore Binária (Mapa)**
- **Escolha**: Optei por uma árvore binária para representar o mapa do jogo, pois ela reflete bem a ideia de exploração com escolhas limitadas em cada ponto da jornada.
- **Aplicação**: Cada nó da árvore (`NoMapa`) representa um local da Terra Média, como o *Topo do Vento* ou *Valfenda*, com um nome e uma descrição. Os ponteiros `filho_esq` e `filho_dir` indicam os caminhos possíveis (esquerda e direita), permitindo que o jogador navegue entre locais de forma estruturada.

### 2. Árvore Binária de Decisões (Sistema de Decisões)
- **Escolha**: Escolhi uma árvore binária para representar o sistema de decisões do jogo, pois ela modela perfeitamente escolhas binárias (duas opções) que o jogador enfrenta em vários pontos da jornada, como aceitar ou recusar uma oferta.
- **Aplicação**: Cada nó da árvore (`NoDecisao`) contém uma descrição do evento (ex.: "Um guarda exige o anel") e duas opções possíveis (ex.: "Entregar o anel" e "Recusar e lutar"). A estrutura permite ramificar a narrativa de forma clara e organizada, com cada escolha levando a um resultado específico no jogo.

### **3. Lista Encadeada (Inventário)**
- **Escolha**: Escolhi uma lista encadeada para o inventário porque ela é ideal para adicionar e remover itens dinamicamente, algo comum em jogos de aventura.
- **Aplicação**: Cada nó (`NoItem`) contém o nome de um item (como *"Pão Hobbit"* ou *"Adaga Enferrujada"*) e um ponteiro para o próximo item. Isso facilita a gestão do inventário sem desperdiçar memória ou exigir realocações.

### **4. Pilha (Registro da Jornada)**
- **Escolha**: Usei uma pilha para registrar os locais visitados, já que ela segue a lógica **LIFO** (*Last In, First Out*), perfeita para rastrear o caminho.
- **Aplicação**: A pilha (`Pilha`) armazena nós (`NoPilha`) que apontam para locais do mapa (`NoMapa`). Isso possibilita empilhar os locais conforme o jogador avança e desempilhar eles para consultá-los.

### 5. Fila (Sistema de Combate Futuro)
- **Escolha**: Para um possível sistema de combate, planejo usar uma fila, pois ela é ideal para gerenciar turnos em ordem sequencial, refletindo a dinâmica de quem ataca primeiro em um confronto. Já criei alguns itens e recursos no código, como a saúde do jogador, itens que aumentam o poder de ataque (ex.: "Adaga Enferrujada", "Lança de Rohan") e itens de cura (ex.: "Pão Hobbit"), que serão utilizados no combate, mas estão meio "perdidos" por enquanto, aguardando integração.
- **Aplicação**: A fila (`Fila`) armazenará nós (`NoFila`) representando os participantes do combate, como o jogador (Frodo) e inimigos (ex.: orcs ou Nazgûl). Cada nó conterá informações como o tipo de personagem, sua saúde e sua ação (ex.: atacar ou defender). O combate será baseado em turnos e usará rolagens de dados para determinar o sucesso das ações. Os participantes serão enfileirados na ordem de iniciativa, e a cada turno, o primeiro da fila executará sua ação (com resultado definido pela rolagem) e será movido para o final, mantendo o ciclo até o combate terminar.
  
## **Lógica das Decisões de Implementação**

Abaixo explico as principais decisões tomadas durante o desenvolvimento:

### **1. Fluxo do Jogo**
O jogo roda em um loop principal que só termina quando o jogador atinge a **Montanha da Perdição**. A cada iteração, o evento do local atual é exibido, e o jogador escolhe ações como:
1. Explorar novos caminhos
2. Checar o inventário
3. Ver a jornada percorrida

### **2. Exploração**
A função `explorar()` usa a árvore binária para oferecer ao jogador opções de caminhos (*esquerda ou direita*) a partir do local atual. Essa decisão mantém a navegação intuitiva e fiel à estrutura do mapa.

### **3. Registro da Jornada**
A pilha foi implementada para armazenar o histórico da jornada porque permite exibir a jornada completa em ordem inversa, dando ao jogador uma visão clara do caminho percorrido.

### **4. Eventos Aleatórios**
Para tornar o jogo mais dinâmico, adicionei alguns eventos aleatórios em pontos chave (como encontrar itens ou enfrentar perigos) usando a função `rand()`. Isso aumenta a imprevisibilidade e incentiva que joguem mais de uma vez.

---

## **Modo de Execução do Programa**

### **Pré-requisitos**
- Compilador C (ex.: GCC)
- Sistema operacional com suporte a terminal (Windows, Linux ou macOS)

### **Compilação**
Para compilar o programa, abra o terminal no diretório do projeto e execute:

```sh
make
```
Isso vai gerar o executável `peregrino`.

### **Execução**
Para jogar, digite no terminal:

```sh
./peregrino
```

### **Controles**
O jogo é controlado por entradas numéricas no terminal. Em cada local, o jogador pode:
1. Escolher um caminho (*esquerda ou direita*)
2. Verificar o inventário
3. Consultar a jornada percorrida
