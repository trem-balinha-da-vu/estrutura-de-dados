#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define QTD_NOS 10

/**
 * Implemente uma função que receba como parâmetros uma lista encadeada e um 
 * número inteiro não negativo n. A função deve remover os n primeiros nós 
 * da lista e retornar a lista resultante.
 * */

Lista * remove_n_elementos(Lista * inicio, int n)
{
	//supondo que n sempre será maior ou igual a zero
	if(n == 0) return inicio;

	for(int i = n; i != 0; i--)
	{
		retira_do_inicio_ref(&inicio);
	}

	return inicio;
}

int main(int argc, char const *argv[])
{
	Lista * lista = inicializa();

	preenche_lista(&lista, 15, 1);

	imprime_lista(lista);

	printf("\nlista apos remover %d nos: \n", QTD_NOS);
	lista = remove_n_elementos(lista, QTD_NOS);

	imprime_lista(lista);
	getchar();
	return 0;
}