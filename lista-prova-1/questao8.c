#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

/**
 * Implemente um algoritmo que, utilizando uma pilha, inverta as letras de cada 
 * palavra em um texto que termina com um ponto (.), preservando a ordem das 
 * palavras. Por exemplo, para o texto: 
 * >> ESTE EXERCÍCIO É MUITO FÁCIL.
 * 
 * A saída deve ser:
 * >> ETSE OICÍCREXE É OTIUM LÍCÁF.
 * */

void inverte_palavras(char *frase)
{
    if (frase[strlen(frase) - 1] != '.')
    {
        printf("Frase invalida.\n");
        return;
    }

    PilhaC *palavra = inicializa_pilhaC(); 
    int i = 0, k = 0;
    char *frase_invertida = (char *)malloc(strlen(frase) + 1); 

    for (; frase[i] != '\0'; i++)
    {
        if (frase[i] == ' ' || frase[i] == '.')
        {
            while (!pilha_vaziaC(palavra))
            {
                frase_invertida[k++] = topoC(palavra);
                popC(&palavra);
            }

            frase_invertida[k++] = frase[i];
        }
        else
        {
            pushC(&palavra, frase[i]);
        }
    }

    frase_invertida[k] = '\0';

    printf("%s\n", frase_invertida);

    free(frase_invertida); // Libera a memória alocada.
}

int main(int argc, char const *argv[])
{
    inverte_palavras("ESTE EXERCICIO E MUITO FACIL.");

    getchar();
    return 0;
}
