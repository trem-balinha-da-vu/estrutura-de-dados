#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/**
 * Implemente uma função que retorne o número de elementos ímpares 
 * presentes na pilha.
 * */

int conta_impares_fila(Fila * front)
{
	int cont = 0;

	if(front == NULL) return 0;

	Fila * aux = front;

	while(aux != NULL)
	{
		if(aux->info % 2 != 0) cont++;
		aux=aux->prox;
	}

	return cont;
}

int main(int argc, char const *argv[])
{
	Fila * fila = inicializa_fila();

	fill_queue(&fila, 10, 3);
	print_queue(fila);

	printf("Quantidade de numeros impares na fila: %d\n", conta_impares_fila(fila));

	getchar();
	return 0;
}