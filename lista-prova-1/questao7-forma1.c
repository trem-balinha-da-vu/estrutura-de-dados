#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

/**
 * Considere uma pilha que armazena caracteres. Implemente uma função para 
 * verificar se uma string é da forma XY, onde X é uma sequência arbitrária 
 * de caracteres e Y é o reverso de X. Por exemplo, se X = ABCD, então Y = DCBA. 
 * Considere que X e Y são dua substrings distintas dentro da string original.
 * */

void eh_reverso(char * XY)
{

	//inicia fluxo 1: verifica tamanho da string e retorna caso seja ímpar.
		int tam_str = strlen(XY);
		int i = 0;

		if(tam_str % 2 != 0)
		{
			printf("\nnao eh da forma XY.\n");
			return;
		}
	//fim do fluxo 1.


	//inicia fluxo 2: criacao das substrings
		char *sub_str1 = (char *) malloc((tam_str/2) +1);
		
		for(; i < (tam_str/2); i++)
		{
			sub_str1[i] = XY[i];
		}
		sub_str1[i] = '\0';

		char *sub_str2 = (char *) malloc((tam_str/2)+1);
		int j = 0;
		for (; i < tam_str; i++, j++)
		{
			sub_str2[j] = XY[i];
		}
		sub_str2[j] = '\0';
	//fim do fluxo 2.


	//inicia fluxo 3: empilhar x.
		PilhaC *pilha = inicializa_pilhaC();

		i = 0;
		while(sub_str1[i] != '\0')
		{
			pushC(&pilha, sub_str1[i]);
			sub_str1++;
		}
	//fim do fluxo 3.

	//inicia fluxo 4: comparar pilha x com a substring y
		i = 0;
		while(sub_str2[i] != '\0')
		{
			if (sub_str2[i] == topoC(pilha))
			{
				popC(&pilha);
			}

			sub_str2++;
		}
	//fim do fluxo 4.
		
	if (pilha == NULL)
	{
		printf("\nA string eh da forma XY.\n");
		return;
	} 
	else 
	{
		printf("\nnao eh da forma XY.\n");
		return;
	}	

	free(sub_str1);
	free(sub_str2);

}

int main()
{

	eh_reverso("ABCDDCBA");

	getchar();

	return 0;
}