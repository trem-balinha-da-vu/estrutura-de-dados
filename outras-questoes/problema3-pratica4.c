#include <stdio.h>
#include<stdlib.h>
#include"lista.h"

/**
 * Dada uma lista simplesmente encadeada com N elementos, seu objetivo é reordenar
 * a lista de forma que os nós nas posições ímpares sejam movidos para o início 
 * da lista, seguidos pelos nós nas posições pares, mantendo a ordem relativa
 *  dos elementos dentro dos grupos de posições ímpares e pares.
 * A função deve seguir o protótipo:
 * 			
 * 			Lista* reordena_lista(Lista* l);
 * */
Lista* reordena_lista(Lista* l) {
    if (l == NULL || l->prox == NULL) return l;  // Se a lista for vazia ou tiver um só nó, não precisa reordenar.

    Lista *aux = l;   // Ponteiro auxiliar para percorrer a lista
    Lista *ant = NULL; // Ponteiro para o nó anterior

    while (aux != NULL) {
        // Se o valor do nó for ímpar, mova-o para o início
        if (aux->info % 2 != 0) {
            if (ant != NULL) {
                // Remover o nó da sua posição atual
                ant->prox = aux->prox;

                // Mover o nó atual (ímpar) para o início da lista
                aux->prox = l;
                l = aux;

                // Continuar verificando com o próximo nó
                aux = ant->prox;
            } else {
                // Se já estiver na primeira posição, apenas avance
                ant = aux;
                aux = aux->prox;
            }
        } else {
            // Se o nó for par, apenas avance
            ant = aux;
            aux = aux->prox;
        }
    }

    return l; // Retorna a lista reordenada
}

int main(int argc, char const *argv[])
{
    Lista *l = NULL;

    // Inserção de nós na lista (valores aleatórios)
    insere_no_inicio_ref(&l, 2);
    insere_no_inicio_ref(&l, 4);
    insere_no_inicio_ref(&l, 8);
    insere_no_inicio_ref(&l, 9);
    insere_no_inicio_ref(&l, 3);
    insere_no_inicio_ref(&l, 0);
    insere_no_inicio_ref(&l, 3);
    insere_no_inicio_ref(&l, 4);

    // Imprime a lista original
    imprime_lista(l);

    // Reordena a lista
    l = reordena_lista(l);

    // Imprime a lista reordenada
    imprime_lista(l);

    getchar();
    return 0;
}
