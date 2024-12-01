#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void inicializarFila(Fila* fila){
    fila->primeiro = NULL;  // A fila começa vazia, então o primeiro nó é NULL
    fila->ultimo = NULL;    // O último nó também é NULL inicialmente
}

// Função para inserir um novo elemento na fila
void inserirFila(Fila* fila, int idade){
    // Aloca memória para um novo nó
    No* novo_no = (No*)malloc(sizeof(No));
    if(novo_no == NULL){  // Verifica se a alocação foi bem-sucedida
        printf("Erro ao alocar memória para o novo nó.\n");
        return;
    }
    
    novo_no -> idade = idade;  // Atribui a idade ao novo nó
    novo_no -> proximo = NULL;  // Como é o último nó, o ponteiro para o próximo é NULL
    novo_no -> anterior = fila -> ultimo;  // O anterior ao novo nó é o último nó da fila

    if(fila -> ultimo != NULL){
        fila -> ultimo -> proximo = novo_no;  // Se a fila não está vazia, o último nó aponta para o novo nó
    } 
    else{
        fila -> primeiro = novo_no;  // Se for o primeiro nó, ele será tanto o primeiro quanto o último
    }

    fila -> ultimo = novo_no;  // O novo nó passa a ser o último da fila
}

// Função para remover o primeiro elemento da fila
int removerFila(Fila* fila){
    if(fila -> primeiro == NULL){  // Verifica se a fila está vazia
        printf("Fila vazia!\n");
        return -1;  // Retorna -1 se a fila estiver vazia
    }

    No* temp = fila -> primeiro;  // Aponta para o primeiro nó da fila
    int idade = temp -> idade;    // Armazena a idade do cliente atendido
    
    fila -> primeiro = fila -> primeiro -> proximo;  // Move o ponteiro para o próximo nó
    if(fila -> primeiro != NULL){
        fila -> primeiro -> anterior = NULL;  // Se houver um novo primeiro, o ponteiro para o anterior é NULL
    } 
    else{
        fila -> ultimo = NULL;  // Se a fila ficou vazia, o último nó também é NULL
    }

    free(temp);  // Libera a memória do nó removido
    return idade;  // Retorna a idade do cliente atendido
}

// Função para imprimir os elementos da fila
void imprimirFila(Fila* fila){
    if(fila -> primeiro == NULL){  // Verifica se a fila está vazia
        printf("Fila vazia!\n");
        return;
    }

    No* temp = fila -> primeiro;  // Começa a imprimir a partir do primeiro nó
    while(temp != NULL){ // Laço para apenas no final da fila
        printf("Idade do cliente: %d\n", temp -> idade);  // Imprime a idade do cliente
        temp = temp -> proximo;  // Avança para o próximo nó
    }
}

// Função para ordenar a fila usando o algoritmo Bubble Sort (de maior para menor idade)
void bubble_sort(Fila* fila){
    if(fila -> primeiro == NULL){  // Se a fila estiver vazia, não há nada para ordenar
        return;
    }

    int trocou;
    do{
        trocou = 0;
        No* atual = fila -> primeiro;

        while(atual != NULL && atual -> proximo != NULL){  // Itera pelos nós da fila
            if(atual -> idade < atual -> proximo -> idade){  // Se a idade do nó atual for menor que a do próximo
                // Troca as idades dos nós
                int temp = atual -> idade;
                atual -> idade = atual -> proximo -> idade;
                atual -> proximo -> idade = temp;
                
                trocou = 1;  // Marca que houve uma troca
            }
            atual = atual -> proximo;  // Avança para o próximo nó
        }
    } 
    while(trocou);  // Repete até não haver mais trocas
}

// Função para liberar a memória de todos os nós da fila
void liberarFila(Fila* fila){
    No* temp;
    while(fila -> primeiro != NULL){
        temp = fila -> primeiro;  // Salva o primeiro nó
        fila -> primeiro = fila -> primeiro -> proximo;  // Avança para o próximo nó
        free(temp);  // Libera a memória do nó antigo
    }
    fila -> ultimo = NULL;  // Como a fila está vazia, o último nó também é NULL
}
