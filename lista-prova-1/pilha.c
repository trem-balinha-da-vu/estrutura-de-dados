#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

PilhaC * pop_valorC(PilhaC *topo)
{
	PilhaC *novo_topo = topo;
	if(novo_topo == NULL) return NULL;
	
	topo = topo->prox;
	
	free(novo_topo);

	return topo;
}

PilhaC * push_valorC(PilhaC *topo, char caractere)
{
	PilhaC *novo_topo = (PilhaC *) malloc(sizeof(PilhaC));
	
	novo_topo->caractere = caractere;
	novo_topo->prox = topo;
	
	return novo_topo;
}

void popC (PilhaC **topo)
{
	PilhaC *novo_topo = *topo;
	if(novo_topo == NULL) return;
	
	*topo = (*topo)->prox;
	
	free(novo_topo);
}

void pushC(PilhaC **p_topo, char caractere)
{
	PilhaC *novo_topo = (PilhaC *) malloc(sizeof(PilhaC));
	
	novo_topo->caractere = caractere;
	novo_topo->prox = *p_topo;
	
	if(*p_topo == NULL)
	{
		novo_topo->prox = NULL;
		*p_topo = novo_topo;
		return;
	}

	novo_topo->prox = *p_topo;
	*p_topo= novo_topo;
}

char topoC(PilhaC *topo)
{	
	if (topo == NULL) return '@';

	//printf("\n %c\n", topo->caractere);
	return topo->caractere;
}

PilhaC * inicializa_pilhaC()
{
	return NULL;
}

int pilha_vaziaC(PilhaC * topo)
{
	if (topo == NULL) return 1;

	return 0;
}

void libera_pilhaC(PilhaC *topo) {
    PilhaC *aux;

    // Itera enquanto a pilha não estiver vazia
    while (topo != NULL) {
        aux = topo;       // Guarda o nó atual
        topo = topo->prox; // Avança para o próximo nó
        free(aux);        // Libera o nó atual
    }
}

void print_stackC(PilhaC * topo)
{
	printf("\n");
	PilhaC * aux = topo;
	if(aux == NULL){ printf("pilha vazia.\n"); return;}
	while(aux != NULL)
	{
		printf(" %c ", aux->caractere);
		printf("|");
		aux = aux->prox;
	}
	printf("\n");
}













Pilha * pop_valor(Pilha *topo)
{
	Pilha *novo_topo = topo;
	if(novo_topo == NULL) return NULL;
	
	topo = topo->prox;
	
	free(novo_topo);

	return topo;
}

Pilha * push_valor(Pilha *topo, int info)
{
	Pilha *novo_topo = (Pilha *) malloc(sizeof(Pilha));
	
	novo_topo->info = info;
	novo_topo->prox = topo;
	
	return novo_topo;
}

void pop (Pilha **topo)
{
	Pilha *novo_topo = *topo;
	if(novo_topo == NULL) return;
	
	*topo = (*topo)->prox;
	
	free(novo_topo);
}

void push(Pilha **p_topo, int info)
{
	Pilha *novo_topo = (Pilha *) malloc(sizeof(Pilha));

	novo_topo->info = info;
	novo_topo->prox = *p_topo;
	
	if(*p_topo == NULL)
	{
		novo_topo->prox = NULL;
		*p_topo = novo_topo;
		return;
	}

	novo_topo->prox = *p_topo;
	*p_topo= novo_topo;
}

int topo(Pilha *topo)
{	
	if (topo == NULL) return -1;
	//printf("\n %c\n", topo->caractere);
	return topo->info;
}

Pilha * inicializa_pilha()
{
	return NULL;
}

int pilha_vazia(Pilha * topo)
{
	if (topo == NULL) return 1;

	return 0;
}

void libera_pilha(Pilha *topo) {
    Pilha *aux;

    // Itera enquanto a pilha não estiver vazia
    while (topo != NULL) {
        aux = topo;       // Guarda o nó atual
        topo = topo->prox; // Avança para o próximo nó
        free(aux);        // Libera o nó atual
    }
}

void print_stack(Pilha * topo)
{
	printf("\n");
	Pilha * aux = topo;
	if(aux == NULL){ printf("pilha vazia.\n"); return;}
	while(aux != NULL)
	{
		printf(" %d ", aux->info);
		printf("|");
		aux = aux->prox;
	}
	printf("\n");
}
