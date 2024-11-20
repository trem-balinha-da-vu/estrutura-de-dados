 #include<stdio.h>
 #include<stdlib.h>
 #include <string.h>
 #include "arvore-avl.h"
 
 /*
 
 Entrada: Uma sequência de operações:
	• I x: Insere o número x na árvore.
	• R x: Remove o número x da árvore.
	• P: Exibe os números em ordem crescente.

Saída: Para cada operação:
	• Em caso de inserção ou remoção, nenhuma saída é necessária.
	• Para exibição, imprima os números em ordem crescente.
	
 */
 
 int main()
{
	ArvAVL *raiz = NULL;
	char op[7];
	int n;
	
	printf("* O PROGRAMA VAI RECEBER AS ENTRADAS ATÉ QUE DIGITE S* \n");
	do
	{
		fflush(stdin);
		scanf("%[^\n]", op);
			
		switch(op[0])
		{
			case 'I':
			{
				int valor = atoi(&op[2]);
			
				if(valor < 0 || valor > 10000)
				{
					printf("\n valor invalido.\n");
					break;
				}
					
				raiz = cria_arvore(raiz, valor);
			} break;
			case 'R':
			{
				int valor = atoi(&op[2]);
					
				if(valor < 0 || valor > 10000)
				{
					printf("\n valor invalido.\n");
					break;
				}
					
				raiz = remover_no(raiz, valor);
			} break;
			case 'P':
			{
				bsf_inOrder(raiz);
			} break;
			case 'S':
			{
				printf("saindo..");
			} break;
			default :
			{
				printf("Entrada invalida\n");
			}break;
		}			
	}while(op[0] != 'S');

	libera_arvore(raiz);
	
	return 0;
}
