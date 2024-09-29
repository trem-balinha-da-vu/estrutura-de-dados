#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista * insere_no_inicio(Lista * inicio, int info)
{
	Lista * novo_no = (Lista *) malloc(sizeof(Lista));

	novo_no->info = info;

	if(inicio == NULL)
	{
		novo_no->prox = NULL;
		return novo_no;
	}

	novo_no->prox = inicio;
	printf("%d", novo_no->info);
	return novo_no;
}

void insere_no_inicio_ref(Lista **p_inicio_lista, int info)
{
	Lista *novo_no = (Lista *) malloc(sizeof(Lista));

	novo_no->info = info;

	if(*p_inicio_lista == NULL)
	{
		novo_no->prox = NULL;
		*p_inicio_lista = novo_no;
		return;
	}

	novo_no->prox = *p_inicio_lista;
	*p_inicio_lista = novo_no;
}

Lista * insere_no_fim(Lista * inicio, int info)
{
	Lista * novo_no = (Lista *)malloc(sizeof(Lista));
	novo_no->info = info;
	novo_no->prox = NULL;

	if(inicio == NULL) return novo_no;

	Lista *ultimo = encontra_ultimo(inicio);

	ultimo->prox = novo_no;

	return inicio;
}

void insere_no_fim_ref(Lista **p_inicio_lista, int info)
{
	Lista * novo_no = (Lista *)malloc(sizeof(Lista));
	novo_no->info = info;
	novo_no->prox = NULL;

	if(*p_inicio_lista == NULL) 
	{
		*p_inicio_lista = novo_no;
		return;
	}

	Lista *ultimo = encontra_ultimo(*p_inicio_lista);

	ultimo->prox = novo_no;
}

Lista * retira_do_fim(Lista * inicio)
{
	if (inicio == NULL) return NULL; //lista vazia

    if (inicio->prox == NULL) //apenas um nó
    {
        free(inicio);
        return NULL; // Retorna NULL
    }

	Lista * aux = inicio;

	while(aux->prox->prox !=NULL)
	{
		aux = aux->prox;
	}

	Lista * ultimo = aux -> prox;
	
	free(ultimo);
	aux->prox = NULL;

	return inicio;
}

void retira_do_fim_ref(Lista **p_inicio_lista)
{
	if (*p_inicio_lista == NULL) return; //lista vazia

    if ((*p_inicio_lista)->prox == NULL) //apenas um nó
    {
        free(*p_inicio_lista);
        *p_inicio_lista = NULL;
        return;
    }

	Lista * aux = *p_inicio_lista;

	while(aux->prox->prox !=NULL)
	{
		aux = aux->prox;
	}

	Lista * ultimo = aux -> prox;

	free(ultimo);

	aux->prox = NULL;

}

Lista * retira_do_inicio(Lista * inicio)
{
	if(inicio == NULL) return NULL;
	if(inicio->prox == NULL)
	{
		free(inicio);
		return NULL;
	}
	Lista * aux = inicio;

	inicio = inicio->prox;

	free(aux);

	return inicio;
}

void retira_do_inicio_ref(Lista **p_inicio_lista)
{
	if(*p_inicio_lista == NULL) return;
	if((*p_inicio_lista)->prox == NULL)
	{
		free(*p_inicio_lista);
		*p_inicio_lista = NULL;
        return;
	}

	Lista * aux = *p_inicio_lista;

	*p_inicio_lista = (*p_inicio_lista)->prox;

	free(aux);
}

Lista * inicializa()
{
	return NULL;
}

void imprime_lista(Lista * inicio)
{
	Lista * aux = inicio;

	while(aux != NULL)
	{

		printf("%d", aux->info);
		if(aux->prox != NULL) printf(" | ");
		aux = aux->prox;
	}

	printf(" \n ");
}

Lista * encontra_ultimo(Lista *inicio)
{
	if(inicio == NULL) return NULL;
	
	Lista * aux = inicio;

	while(aux->prox != NULL)
	{
		aux=aux->prox;
	}

	return aux;
}

void preenche_lista(Lista **lista, int qtd_nos, int n)
{
	if(qtd_nos <= 0) return;
	for(int i = 1; i <= qtd_nos; i++)
	{
		insere_no_inicio_ref(lista, i*n);
	}
}


