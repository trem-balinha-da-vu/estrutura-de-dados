#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/**
 * Implemente uma função que receba como parâmetros um vetor V contendo n elementos
 * e construa uma lista encadeada a partir desses elementos. Caso n = 0, 
 * a função deve retornar uma lista vazia. 
 * Exemplo: dado o vetor V = {4, 1, 5, 9, 13, 26}, a função deve retornar uma
 * lista encadeada onde o primeiro nó contém o valor 4, o segundo contém 1, 
 * e o último contém 26.
 * */

Lista * lista_do_vet(int *V, int n)
{
	Lista * lista = inicializa();
	if (n == 0) return lista;

	for(int i = 0; i < n; i++)
	{
		insere_no_fim_ref(&lista, V[i]);
	}

	return lista;
}
       
int main(int argc, char const *argv[])
{
	int V[6] = {4, 1, 5, 9, 13, 26};
	Lista * lista;

	lista = lista_do_vet(V, 6);

	imprime_lista(lista);

	getchar();
	return 0;
}