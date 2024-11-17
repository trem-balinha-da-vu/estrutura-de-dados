#include <stdio.h>
#include <stdlib.h>

/*
	1. Voc� tem uma fila de n�meros inteiros e precisa process�-la para remover todos os n�meros negativos.
	A ordem dos n�meros positivos e zeros deve ser mantida na fila.
	
	prot�tipo: void remove_negativo(Fila *F);
	
	requisitos:
	
		- a fun��o deve percorrer a fila e excluir todos os elementos negativos.
		- A posi��o relativa dos n�meros n�o-negativos deve ser preservada.
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

//fun��o front (retorna o valor que est� no primeiro n� da fila)
int front(Fila * front)
{
	return front->valor;
}

//fun��o principal
void remove_negativo(Fila ** F)
{
	Fila * fila_aux = NULL;// inicializei uma nova fila, que guardar� os valores positivos.
	Fila * aux = *F; // declarei uma vari�vel auxiliar que recebe inicialmente o come�o da fila e depois vai percorr�-la
	
	//para cada n�, se esse n� for positivo, ele ser� enfileirado. sen�o, ignorado
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

//criei essa fun��o s� pra visualizar a fila em casa
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
