#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void eh_reverso2(char *XY)
{
    // Fluxo 1: Verifica se o tamanho da string é par
    int tam_str = strlen(XY);
    if (tam_str % 2 != 0)
    {
        printf("\nA string nao eh da forma XY.\n");
        return;
    }

    // Fluxo 2: Empilhar a primeira metade da string (X)
    PilhaC *pilha = inicializa_pilhaC();
    int i;

    for (i = 0; i < tam_str / 2; i++)
    {
        pushC(&pilha, XY[i]);
    }

    // Fluxo 3: Comparar a segunda metade da string (Y) com a pilha
    for (; i < tam_str; i++)
    {
        if (XY[i] != topoC(pilha))
        {
            printf("\nA string nao eh da forma XY.\n");
            return;
        }
        popC(&pilha);
    }

    // Fluxo 4: Se a pilha estiver vazia, a string está no formato XY
    if (pilha_vaziaC(pilha))
    {
        printf("\nA string eh da forma XY.\n");
    }
    else
    {
        printf("\nA string nao eh da forma XY.\n");
    }
}

int main()
{
    eh_reverso2("ABCDDCBA");

    getchar();

    return 0;
}
