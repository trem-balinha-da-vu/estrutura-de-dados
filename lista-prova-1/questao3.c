#include <stdio.h>
#include<stdlib.h>
#include "lista.h"

/**
 * Implemente uma função que receba duas listas, L1 e L2, como parâmetros 
 * e as concatene, anexando L1 ao final de L2. Utilize o seguinte protótipo: 
 * Lista* concatena(Lista *L1, Lista *L2).
 * */

Lista * concatena(Lista *L1, Lista *L2)
{
	Lista * p_l2;

	p_l2 = encontra_ultimo(L2);

	p_l2->prox=L1;

	return L2;
}

int main(int argc, char const *argv[])
{
	Lista *L1, *L2;

	L1 = inicializa();
	L2 = inicializa();

	preenche_lista(&L1, 5, 2);
	imprime_lista(L1);
	preenche_lista(&L2, 3, 10);
	imprime_lista(L2);
	L2 = concatena(L1, L2);

	imprime_lista(L2);
	getchar();
	return 0;
}