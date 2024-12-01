# Implementação de Fila com Lista Duplamente Encadeada em C

Este repositório contém uma implementação de **fila** utilizando uma **lista duplamente encadeada** na linguagem **C**. A fila é gerenciada com operações como inserção, remoção, impressão e ordenação.

## Funcionalidades

- **inicializarFila**: Inicializa uma fila vazia.
- **inserirFila**: Insere um novo elemento (idade) na fila.
- **removerFila**: Remove o primeiro elemento da fila.
- **imprimirFila**: Imprime todos os elementos da fila.
- **bubble_sort**: Ordena a fila em ordem decrescente de idade (usando o algoritmo Bubble Sort).
- **liberarFila**: Libera a memória de todos os nós da fila.

## Estrutura de Dados

- **No**: Representa cada elemento da fila, contendo:
  - `idade`: Idade do cliente.
  - `proximo`: Ponteiro para o próximo nó.
  - `anterior`: Ponteiro para o nó anterior.

- **Fila**: Representa a fila, contendo:
  - `primeiro`: Ponteiro para o primeiro nó.
  - `ultimo`: Ponteiro para o último nó.

## Como Usar

1. Clone o repositório:
   ```bash
   git clone https://github.com/seu-usuario/nome-do-repositorio.git
