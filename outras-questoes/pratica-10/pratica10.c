 #include<stdio.h>
 #include<stdlib.h>
 #include <string.h>
 #include "arvore-avl.h"
 
 /*
 
 Entrada: Uma sequ�ncia de opera��es:
	� I x: Insere o n�mero x na �rvore.
	� R x: Remove o n�mero x da �rvore.
	� P: Exibe os n�meros em ordem crescente.

Sa�da: Para cada opera��o:
	� Em caso de inser��o ou remo��o, nenhuma sa�da � necess�ria.
	� Para exibi��o, imprima os n�meros em ordem crescente.
	
 */
 
 int main()
{
	ArvAVL *raiz = NULL;
	char op[7];
	int n;
	
	printf("* O PROGRAMA VAI RECEBER AS ENTRADAS AT� QUE DIGITE S* \n");
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
