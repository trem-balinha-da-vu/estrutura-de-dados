#include <stdio.h>
#include <stdlib.h>

/*
	3. Dadas duas pilhas de inteiros, P1 e P2, implemente um algoritmo que crie uma nova pilha P3 intercalando 
	os elementos de P1 e P2. O elemento do topo de P1 deve ser empilhado seguido pelo elemento do topo de p2, 
	alternadamente. O processo deve continuar até que ambas as pilhas estejam vazias.
	
	Importante: após a intercalação, P3 deve manter os elementos empilhados na ordem inversa à inserção, ou seja, 
	o último elemento de P3 será o primeiro elemento de P1.
	
		- Se uma das pilhas estiver vazia, a outra deve ser transferida diretamente para P3.
		- Não deve ser permitido o uso de estruturas de dados auxiliares, como listas ou vetores, apenas pilhas.
		
	protótipo: Pilha * intercala_lista(Pilha *p1, Pilha*p2);
*/

//TAD pilha
typedef struct pilha {
	int valor;
	struct pilha * prox;
}Pilha;

//função auxiliar que retorna o topo da pilha
int topo(Pilha * topo)
{
	return topo->valor;
}

//procedimento auxiliar: empilhar
void push(Pilha **p_topo, int valor)
{
	Pilha * novo_topo = (Pilha *) malloc(sizeof(Pilha));
	novo_topo-> valor = valor;
	
	if(*p_topo == NULL)
	{
		novo_topo -> prox = NULL;
		*p_topo = novo_topo;
		return;
	}
	
	novo_topo->prox = *p_topo;
	*p_topo = novo_topo;
}

//procedimento auxiliar: desempilhar
void pop (Pilha ** p_topo)
{
	if(*p_topo == NULL) return;
	
	Pilha * aux = *p_topo;
	*p_topo = (*p_topo)->prox;
	free(aux);
}

Pilha * intercala_lista(Pilha * p1, Pilha * p2)
{
	if(p1 == NULL && p2 == NULL) return NULL;//se forem duas pilhas vazias, nem tem o que fazer
	
	Pilha * p3 = NULL;//inicializo a nova pilha
	
	//só vai parar quando ambas as filas forem vazias. isso resolve o problema caso umas das pilhas for vazia, 
	//pq aí vai empilhar só a que tem elementos, ou se uma for menor que outra.
	while(p1 != NULL || p2 != NULL)
	{
		if(p1 != NULL)
		{
			push(&p3, topo(p1));//empilha em p3 o topo de p1;
			pop(&p1);//desempilha o topo atual de p1;
		}
		if(p2 != NULL)
		{
			push(&p3, topo(p2));
			pop(&p2);
		}
	}
	
	return p3;
}

//criei essa função só pra visualizar a pilha em casa
void imprime(Pilha * p)
{
	Pilha * aux = p;
	
	printf("\n");
	while(aux != NULL)
	{
		printf("%d  ", aux->valor);
		aux = aux->prox;
	}
}

int main()
{
	Pilha *p1 = NULL, *p2 = NULL, *p3 = NULL;
	
	push(&p1, 4);
	push(&p1, 3);
	push(&p1, 2);
	push(&p1, 1);
	
	printf("\npilha 1: ");
	imprime(p1);

	push(&p2, 8);
	push(&p2, 7);
	push(&p2, 6);
	push(&p2, 5);
	
	printf("\npilha 2: ");
	imprime(p2);

	p3 = intercala_lista(p1,p2);
	
	printf("\npilha 3: ");
	imprime(p3);
	
	return 0;
}
