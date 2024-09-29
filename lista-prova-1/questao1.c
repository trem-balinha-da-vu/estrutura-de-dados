#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#ifndef QTD_NOS
#define QTD_NOS 12
#endif

/**
 * 1. Implemente uma função que receba como parâmetro um ponteiro para uma lista encadeada e
 * 	retorne a quantidade de nós presentes nessa lista.
 * */

int conta_nos(Lista *inicio)
{
	int contador = 0;
	Lista *aux = inicio;

	while (aux != NULL)
	{
		contador++;
		aux = aux->prox;
	}

	return contador;
}


int main()
{
	Lista * lista = inicializa();

	preenche_lista(&lista, QTD_NOS, 3);

	printf("Quantidade de nos adicionados: %d\n", conta_nos(lista));

	imprime_lista(lista);

	getchar();  // Aguarda uma nova entrada para manter o console aberto

	return 0;
}


