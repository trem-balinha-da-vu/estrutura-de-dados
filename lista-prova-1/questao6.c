#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/**
 * Implemente uma função que inverta a ordem dos nós de uma lista encadeada, 
 * de modo que o primeiro nó se torne o último, o segundo se torne o penúltimo, 
 * e assim sucessivamente. A inversão deve ser feita diretamente, alterando apenas
 *  os ponteiros da lista, sem utilizar espaço auxiliar adicional.
 * */

/**
 * OBSERVAÇÃO: ao pesquisar o que seria utilizar espaço auxiliar adicional, 
 * entendi que se refere à memória extra alocada além da memória que já está 
 * sendo usada pela estrutura de dados. Por exemplo:
 * 
 * -> Se você usar um array ou uma lista adicional para armazenar elementos enquanto 
 * inverte a lista, isso seria considerado uso de espaço auxiliar.
 * -> Se você alocar novas estruturas (como nós ou arrays) para armazenar os dados 
 * enquanto faz a inversão, isso também contaria como espaço auxiliar.
 * 
 * logo, o que resta é usar ponteiros para posições diversas da estrutura.
 * */

void inverte_lista(Lista **p_inicio_lista)
{
	if(*p_inicio_lista == NULL) return ;
	if((*p_inicio_lista)->prox == NULL) return;


	Lista *no_anterior = NULL;
    Lista *no_atual = *p_inicio_lista;
    Lista *no_seguinte = NULL;

    while (no_atual != NULL) 
    {
        no_seguinte = no_atual->prox; // Armazena o próximo nó
        no_atual->prox = no_anterior; // Inverte o ponteiro do nó atual
        no_anterior = no_atual; // Move o ponteiro anterior para o nó atual
        no_atual = no_seguinte; // Move para o próximo nó
    }

    *p_inicio_lista = no_anterior; // Atualiza o ponteiro de início da lista
}

int main(int argc, char const *argv[])
{
	Lista * lista = inicializa();

	preenche_lista(&lista, 2, 1);

	imprime_lista(lista);

	printf("\nlista depois de invertida: \n");
	inverte_lista(&lista);

	imprime_lista(lista);
	getchar();
	return 0;
}
