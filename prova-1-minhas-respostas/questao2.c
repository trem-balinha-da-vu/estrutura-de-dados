#include <stdio.h>
#include <stdlib.h>

/*
	2. a função separa_lista deve receber como parâmetros uma lista encadeada e um valor inteiro n.
	A função deve separar a lista original em duas sublistas: a primeira com todos os nós até a primeira
	ocorrência de n, e a segunda que começa imediatamente depois desse nó.
	
		- Se n não estiver na lista, a primeira sublista deve permanecer inteira e a segunda deve ser vazia.
		- Se a lista estiver vazia, ambas as sublistas devem ser nulas.
		- Se n for o ultimo elemento, a segunda sublista deve ser vazia.
*/

//TAD da lista No
typedef struct No {
	int valor;
	struct No * proximo;
}No;

//nessa função, a sublista1 é alterada por referência, e a sublista2 é retornada.
No * separa_lista (No **inicio, int n)
{
	No * sub_lista1 = *inicio, *sub_lista2 = NULL;//sub_lista1 é a lista passada por parâmetro, e sublista2 receberá a nova lista criada
	No * aux = sub_lista1;
	
	//se a lista está vazia, ambas as listas retornam nulas.
	if(*inicio == NULL)
	{
		return sub_lista2;
	} 
	
	//percorre até chegar ao fim ou encontrar n
	while(aux != NULL)
	{
		
		if(aux->valor == n)
		{
			//encontrou n
			
			sub_lista2 = aux->proximo;//a sublista2 aponta para o nó logo após n
			aux->proximo = NULL;//na sublista1, os nós após n são excluidos
			return sub_lista2;
		} else
		{
			aux=aux->proximo;
		}
	}
	
	return sub_lista2;
}

//função para vizualizar a lista
void imprime(No * n)
{
	No * aux = n;
	
	if(aux == NULL)
	{
		printf("\nlista vazia.");
		return;
	}
	
	printf("\n");
	while(aux != NULL)
	{
		printf("%d  ", aux->valor);
		aux = aux->proximo;
	}
}

//função para adicionar itens na lista
void insere_inicio (No **p_inicio, int valor)
{
	No * novo_no = (No *) malloc(sizeof(No));
	novo_no->valor = valor;

	
	if(*p_inicio == NULL)
	{
		*p_inicio = novo_no;
		novo_no->proximo = NULL;
		return;
	}
	
	novo_no->proximo = *p_inicio;
	*p_inicio = novo_no;
}

int main()
{
	
	No * lista = NULL;
	
	insere_inicio(&lista, 4);
	insere_inicio(&lista, 3);
	insere_inicio(&lista, 5);
	insere_inicio(&lista, 2);
	insere_inicio(&lista, 10);
	insere_inicio(&lista, 1);
	
	imprime(lista);
	
	printf("\n\tnovas listas dps de remover separar %d", 5);
	
	No * lista2 = separa_lista(&lista, 5);
	
	printf("\nlista 1: ");
	imprime(lista);
	printf("\nlista2: ");
	imprime(lista2);
	
	return 0;
}

