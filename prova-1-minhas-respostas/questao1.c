#include <stdio.h>
#include <stdlib.h>

/*
	1. Você tem uma fila de números inteiros e precisa processá-la para remover todos os números negativos.
	A ordem dos números positivos e zeros deve ser mantida na fila.
	
	protótipo: void remove_negativo(Fila *F);
	
	requisitos:
	
		- a função deve percorrer a fila e excluir todos os elementos negativos.
		- A posição relativa dos números não-negativos deve ser preservada.
*/

//TAD Fila
typedef struct fila{
	int valor;
	struct fila *prox;
} Fila;

//procedimento auxiliar: enfileirar 
void enqueue(Fila **p_front, int valor)
{
	Fila * novo_no = (Fila *) malloc (sizeof(Fila));
	novo_no->valor = valor;
	novo_no->prox = NULL;
	
	if(*p_front == NULL)
	{
		*p_front = novo_no;
		return;
	}
	
	Fila * aux = *p_front;
	while(aux->prox != NULL) aux = aux ->prox;
	aux->prox = novo_no;
}

//função front (retorna o valor que está no primeiro nó da fila)
int front(Fila * front)
{
	return front->valor;
}

//função principal
void remove_negativo(Fila ** F)
{
	Fila * fila_aux = NULL;// inicializei uma nova fila, que guardará os valores positivos.
	Fila * aux = *F; // declarei uma variável auxiliar que recebe inicialmente o começo da fila e depois vai percorrê-la
	
	//para cada nó, se esse nó for positivo, ele será enfileirado. senão, ignorado
	while(aux != NULL)
	{
		if(front(aux) >= 0)
		{
			enqueue(&fila_aux, front(aux));
		}
		
		aux = aux->prox;
	}
	
	*F = fila_aux;
}

//criei essa função só pra visualizar a fila em casa
void imprime(Fila * f)
{
	Fila * aux = f;
	
	printf("\n");
	while(aux != NULL)
	{
		printf("%d  ", aux->valor);
		aux = aux->prox;
	}
}

int main()
{
	
	Fila * fila = NULL;
	
	enqueue(&fila, 1);
	enqueue(&fila, 2);
	enqueue(&fila, -3);
	enqueue(&fila, 4);
	enqueue(&fila, -5);
	enqueue(&fila, 5);
	enqueue(&fila, 8);
	enqueue(&fila, 10);
	enqueue(&fila, -9);

	imprime(fila);
	
	remove_negativo(&fila);
	
	imprime(fila);
	
	return 0;
}
