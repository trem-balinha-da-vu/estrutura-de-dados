#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

/**
	falta verificar se apos o 'E', é um numero ou nao

*/


Pilha * imprime_novo_topo (Pilha *topo, int info)
{
	push(&topo, info);
	
	printf("\n %d\n", topo->info);
	return topo;
}


void imprime_pop(Pilha ** topo)
{
	pop(topo);
	
	printf("\n *\n");
}

void imprime_pilha(Pilha * topo)
{
	Pilha *atual = topo;
	printf("\n*****************************************************");
	printf("\nIMPRIMINDO PILHA\n");
	if(atual == NULL)printf("\nPILHA VAZIA");
	while(atual != NULL)
	{
		printf("\n %d\n", atual->info);
		atual = atual->prox;
	}
	printf("\n*****************************************************\n");
}

void recebe_entrada(int *n)
{
	do 
	{
		printf("Informe N: \n");
		scanf("%d", n);
			
		if(*n < 0 || *n > 999)
		{
			printf("entrada invalida.\n");
		}
	}while(*n < 0 || *n > 999);
		
}


int main()
{
	Pilha *topo = NULL;
	char op[7];
	int n;
	
	do
	{
		recebe_entrada(&n);
		
		int count;
		for (count = 0; count < n; count++)
		{
			fflush(stdin);
			scanf("%[^\n]", op);
			
			switch(op[0])
			{
				case 'E':
				{
					int valor = atoi(&op[2]);
				
					if(valor < 0 || valor > 10000)
					{
						printf("\n valor invalido.\n");
						break;
					}
				
					topo = imprime_novo_topo(topo, valor);
				} break;
				case 'D':
				{
					imprime_pop(&topo);
				} break;
				default :
				{
					printf("Entrada invalida\n");
				}break;
			}
		}
		
		imprime_pilha(topo);
	}while(n != 0);

	
	
	return 0;
}