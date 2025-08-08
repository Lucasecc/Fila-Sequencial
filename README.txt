# Fila Circular em C (usando vetor com incremento circular)

Este projeto implementa uma **fila circular** usando um vetor em C, com operações básicas e um menu interativo limpo. Além disso, as operações realizadas no modo interativo são registradas em um arquivo de texto.

---

##  Estrutura

- `fila.h` — Declarações das funções e da estrutura `Fila`.
- `fila.c` — Implementação das operações da fila (inserir, remover, consultar, etc.).
- `main.c` — Contém casos de teste automáticos e um menu interativo que registra operações em arquivo.

---

##  Funcionalidades

### Filas (implementação em **fila.c**)
- **inicializarFila**: inicia os índices da fila.
- **isEmpty**: verifica se a fila está vazia.
- **isFull**: verifica se a fila está cheia.
- **enqueue**: insere elemento no fim da fila circular.
- **dequeue**: remove elemento do início da fila circular.
- **peek**: consulta o elemento do início sem removê-lo.

### Menu interativo (em **main.c**)
- Apresenta um menu com as opções:
  1. Inserir no fim da fila  
  2. Remover do início da fila  
  3. Consultar o início da fila  
  4. Verificar se a fila está vazia  
  5. Verificar se a fila está cheia  
  0. Sair do programa
- Interface limpa no terminal usando `system("clear")` (Linux/Mac) ou `system("cls")` (Windows).
- Pausa após cada operação com uma mensagem “Pressione ENTER para continuar…” para evitar sobrecarga no terminal.
- Todas as ações do usuário no modo interativo são registradas no arquivo `operacoes_fila.txt`.

---

##  Como compilar e executar

No terminal (Linux/Mac ou PowerShell no Windows):

```bash
gcc main.c fila.c -o fila
./fila     # ou apenas: fila.exe no Windows
