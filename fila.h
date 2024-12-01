#ifndef FILA_H
#define FILA_H

// Estrutura representando um nó da fila (elemento da fila)
typedef struct No{
    int idade;               // Idade do cliente armazenada no nó
    struct No* proximo;      // Ponteiro para o próximo nó (elemento) na fila
    struct No* anterior;     // Ponteiro para o nó anterior na fila (estrutura duplamente encadeada)
} No;

// Estrutura representando a fila em si
typedef struct Fila{
    No* primeiro;            // Ponteiro para o primeiro nó da fila (início da fila)
    No* ultimo;              // Ponteiro para o último nó da fila (fim da fila)
} Fila;

// Função para inicializar uma fila vazia
void inicializarFila(Fila* fila);

// Função para inserir um novo elemento (idade) na fila
void inserirFila(Fila* fila, int idade);

// Função para remover um elemento (cliente) da fila
int removerFila(Fila* fila);

// Função para imprimir todos os elementos da fila (idades)
void imprimirFila(Fila* fila);

// Função para ordenar a fila com o algoritmo Bubble Sort (ordem decrescente de idade)
void bubble_sort(Fila* fila);

// Função para liberar a memória de todos os nós da fila
void liberarFila(Fila* fila);

#endif  
