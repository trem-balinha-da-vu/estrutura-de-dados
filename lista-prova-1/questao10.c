#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "fila.h"

/**
 * 10. Considere uma pilha P vazia e uma fila F não vazia. Utilizando apenas 
 * as operações da fila e da pilha, implemente uma função que inverta a ordem 
 * dos elementos da fila.
 * */

void inverte_fila_com_pilha(Fila **p_front)
{
    Pilha *pilha = inicializa_pilha();
    Fila *aux = *p_front;

    // Fluxo 1: Empilhar os elementos da fila
    while (aux != NULL) // Verifica se a fila não está vazia
    {
        push(&pilha, front(*p_front));  // Empilha o elemento na pilha
        dequeue_ref(p_front);  // Remove o elemento da fila
        aux = aux->prox;
    }

    // Fluxo 2: Desempilhar e enfileirar novamente
    while (!pilha_vazia(pilha))  // Verifica se a pilha não está vazia
    {
        enqueue_ref(p_front, topo(pilha));  // Enfileira o topo da pilha
        pop(&pilha);  // Remove o elemento do topo da pilha
    }

    libera_pilha(pilha); // Libera a memória da pilha após o uso
}

int main(int argc, char const *argv[])
{
	Fila * fila = inicializa_fila();

    fill_queue(&fila, 10, 3);  
    print_queue(fila);  

    inverte_fila_com_pilha(&fila);

    print_queue(fila); 

    getchar();
    return 0;
}