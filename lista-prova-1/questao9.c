#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

/**
 * Função para verificar se duas pilhas, P1 e P2, são iguais.
 * Duas pilhas são iguais se tiverem o mesmo tamanho e os mesmos elementos na mesma ordem.
 */
void sao_iguais(Pilha *P1, Pilha *P2)
{
    if (P1 == NULL && P2 == NULL)
    {
        printf("Sao iguais. Ambas vazias.\n");
        return;
    }

    // Verifica se uma das pilhas é nula
    if (P1 == NULL)
    {
        printf("Pilha 1 eh vazia.\n");
        return;
    }
    if (P2 == NULL)
    {
        printf("Pilha 2 eh vazia.\n");
        return;
    }

    while (!pilha_vazia(P1) && !pilha_vazia(P2))
    {
        if (topo(P1) != topo(P2))
        {
            printf("Sao diferentes.\n");
            return;
        }

        pop(&P1);
        pop(&P2);
    }

    printf("Sao iguais.\n");
}

int main(int argc, char const *argv[])
{
    // Inicializa duas pilhas
    Pilha *P1 = inicializa_pilha();
    Pilha *P2 = inicializa_pilha();

    push(&P1, 1);
    push(&P1, 3);
    push(&P1, 4);

    push(&P2, 1);
    push(&P2, 3);
    push(&P2, 4);

    sao_iguais(P1, P2);

    libera_pilha(P1);
    libera_pilha(P2);

    getchar();

    return 0;
}
