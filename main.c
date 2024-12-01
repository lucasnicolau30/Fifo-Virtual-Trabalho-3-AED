#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
    // Aloca memória para a fila
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    if(fila == NULL){  // Verifica se a alocação foi bem-sucedida
        printf("Erro ao alocar memória para a fila.\n");
        return 1;  // Encerra o programa em caso de erro
    }
    
    inicializarFila(fila);

    // Leitura das idades dos clientes a partir do arquivo
    FILE *arquivo = fopen("clientes.txt", "r");  // Abre o arquivo de leitura
    if(arquivo == NULL){  // Verifica se o arquivo foi aberto corretamente
        printf("Erro ao abrir o arquivo.\n");
        return 1;  // Encerra o programa em caso de erro
    }

    int idade;
    while(fscanf(arquivo, "%d", &idade) != EOF){  // Lê idades até o final do arquivo
        inserirFila(fila, idade);  // Insere cada idade na fila
    }

    fclose(arquivo);  // Fecha o arquivo após a leitura

    // Imprime a fila antes da ordenação
    printf("Fila antes da ordenação:\n");
    imprimirFila(fila);

    // Ordena a fila usando o Bubble Sort (de maior para menor idade)
    bubble_sort(fila);

    // Imprime a fila após a ordenação
    printf("\nFila após a ordenação (de maior para menor idade):\n");
    imprimirFila(fila);

    // Atende os clientes (remove da fila e imprime a idade)
    printf("\nAtendendo clientes:\n");
    while(fila -> primeiro != NULL){  // Enquanto houver clientes na fila
        int idadeAtendido = removerFila(fila);  // Remove um cliente
        printf("Cliente atendido com idade: %d\n", idadeAtendido);  // Imprime a idade do cliente atendido
    }

    // Libera a memória alocada para a fila
    liberarFila(fila);
    free(fila);  // Libera a memória da estrutura da fila

    return 0; 
}
