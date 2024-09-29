#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/**
 * Implemente uma função que receba uma lista como parâmetro, crie uma cópia da lista 
 * original e retorne um ponteiro para a nova lista. 
 * A lista copiada deve manter a mesma ordem dos nós da lista original.
 * */

Lista * copia_lista(Lista *lista_ref)
{
    Lista *nova_lista = inicializa(); 
    Lista *aux = lista_ref; 
    
    while(aux != NULL)
    {
        Lista *novo_no_lista2 = (Lista *) malloc(sizeof(Lista)); 
        novo_no_lista2->info = aux->info; 
        novo_no_lista2->prox = NULL; 

        if(nova_lista == NULL)
        {
            nova_lista = novo_no_lista2; 
        }
        else
        {
            Lista *temp = nova_lista;
            while(temp->prox != NULL)
            {
                temp = temp->prox; 
            }
            temp->prox = novo_no_lista2;
        }
        aux = aux->prox;
    }

    return nova_lista; 
}

int main(){
	Lista * lista = inicializa();

	for(int i = 1; i <= 10; i++)
	{
		insere_no_inicio_ref(&lista, i*2);
	}

	printf("\n lista ref: ");
	imprime_lista(lista);

	Lista * nova_lista = copia_lista(lista);

	printf("\n nova lista: ");
	imprime_lista(nova_lista);

	getchar();
	return 0;
}