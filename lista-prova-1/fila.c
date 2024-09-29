#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila * inicializa_fila ()
{
	return NULL;
}

Fila * encontra_ultimo_fila(Fila * ini)
{
	if(ini == NULL) return NULL;
	
	Fila *aux = ini;
	
	while(aux->prox != NULL)
	{
		aux = aux->prox;
	}
	
	return aux;
}

Fila * enqueue (Fila * ini, int info)
{
    Fila * novo = (Fila *) malloc(sizeof(Fila));
    novo->prox = NULL;
    novo->info = info;
    
    if(ini == NULL)  // Caso a fila esteja vazia
    {
        return novo;
    }

    Fila * ult = encontra_ultimo_fila(ini);
    ult->prox = novo;
    
    return ini;
}


void enqueue_ref (Fila **p_inicio_fila, int info)
{
    Fila * ult = encontra_ultimo_fila(*p_inicio_fila);
    
    Fila * novo = (Fila *) malloc(sizeof(Fila));
    novo->prox = NULL;
    novo->info = info;
    
    if(ult != NULL)
    {
        ult->prox = novo;
    }
    else
    {
        *p_inicio_fila = novo;
    }
}



Fila * dequeue (Fila * ini)
{
	Fila * aux = ini;
	
	if (aux == NULL) return NULL;
	
	ini = ini->prox;
	
	free(aux);
	
	return ini;
}

void dequeue_ref (Fila **p_inicio_fila)
{
	Fila * aux = *p_inicio_fila;
	
	if (aux == NULL) return;
	
	*p_inicio_fila = (*p_inicio_fila)->prox;
	
	free(aux);
	
	return;
}

int front(Fila *ini)
{
    if (ini == NULL)
    {
        printf("Fila vazia.\n");
        return -1; // Ou outro valor que indique erro
    }
    return ini->info;
}


void print_queue(Fila * ini)
{
	printf("\n");
	Fila * aux = ini;
	while(aux != NULL)
	{
		printf(" %d ", aux->info);
		printf("|");
		aux = aux->prox;
	}
	printf("\n");
}

void fill_queue(Fila **p_front, int qtd_nos, int n)
{
	if(qtd_nos <= 0) return;
	for(int i = 1; i <= qtd_nos; i++)
	{
		enqueue_ref(p_front, i*n);
	}
}
