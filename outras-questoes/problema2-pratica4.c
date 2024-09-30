#include <stdio.h>
#include<stdlib.h>
#include"lista.h"

/**
 * Implemente uma função que receba como parâmetro uma lista encadeada e 
 * um valor inteiro n. A função deve remover todas as ocorrências de n da
 *  lista e retornar a lista resultante. A função deve seguir o protótipo:
 * 			Lista* retira_n(Lista* l, int n);
 * Se o valor n não estiver presente na lista, a função deve retornar a lista original sem alterações.
 * */

Lista* retira_n(Lista* l, int n)
{
    // Verifica se a lista é vazia
    if (l == NULL) return NULL;

    Lista *aux = l;
    Lista *ant = NULL;

    // Percorrer a lista e remover todas as ocorrências de n
    while (aux != NULL)
    {
        if (aux->info == n)
        {
            Lista *temp = aux; // Guardar o nó a ser removido
            if (ant == NULL)   // Caso o elemento a ser removido seja o primeiro da lista
            {
                l = aux->prox; // Atualiza o início da lista
            }
            else
            {
                ant->prox = aux->prox; // Remove o nó do meio ou fim
            }
            aux = aux->prox; // Avança para o próximo nó
            free(temp);      // Libera o nó removido
        }
        else
        {
            ant = aux;       // Atualiza o ponteiro 'ant'
            aux = aux->prox; // Avança para o próximo nó
        }
    }

    return l; // Retorna a lista atualizada
}



int main(int argc, char const *argv[])
{
	Lista *l = NULL;

	insere_no_inicio_ref(&l, 2);
	insere_no_inicio_ref(&l, 4);
	insere_no_inicio_ref(&l, 3);
	insere_no_inicio_ref(&l, 9);
	insere_no_inicio_ref(&l, 3);
	insere_no_inicio_ref(&l, 0);
	insere_no_inicio_ref(&l, 3);
	insere_no_inicio_ref(&l, 3);

	imprime_lista(l);

	l = retira_n(l, 3);

	imprime_lista(l);

	getchar();
	return 0;
}