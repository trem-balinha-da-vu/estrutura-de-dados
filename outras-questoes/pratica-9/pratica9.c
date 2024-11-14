#include <stdio.h>
#include<stdlib.h>

typedef struct TNo 
{
	int info;
	struct TNo *esq;
	struct TNo *dir;	
} ArvoreBin;

ArvoreBin * inicializa_arvore()
{
	return NULL;
}

void cria_arvore(ArvoreBin ** p_arvore, int info)
{
	ArvoreBin * novo_no = (ArvoreBin *) malloc(sizeof(ArvoreBin));
	
	novo_no -> info = info;
	novo_no->esq = NULL;
	novo_no -> dir = NULL;
	
	if(*p_arvore == NULL)
	{
		*p_arvore = novo_no;
		return;
	}
	
	ArvoreBin *aux = *p_arvore;
	ArvoreBin *pai = NULL;
	
	while(aux != NULL)
	{
		pai = aux;
		
		if(novo_no -> info > pai->info)
		{
			aux = pai->dir;
		} else if(novo_no -> info < pai->info)
		{
			aux = pai->esq;
		}
	}
	
	if(novo_no -> info > pai->info)
	{
		pai->dir = novo_no;
	} else if(novo_no -> info < pai->info)
	{
		pai->esq = novo_no;
	}
}

/*
Dada uma árvore binária e um valor inteiro fornecido pelo usuário, o
programa deve retornar qualquer inteiro se o valor for encontrado na árvore. Caso contrário,
deve retornar 0.
*/
int encontra_valor(ArvoreBin * arvore, int info)
{
	ArvoreBin * aux = arvore;
	
	while(aux != NULL)
	{
		if(aux->info == info)
		{
			return 1;
		}
		
		if(aux->info < info)
		{
			aux = aux->dir;
		} else if(aux->info > info)
		{
			aux = aux->esq;
		}
	}
	
	return 0;
}

//imprime filhos da árvore
void imprime_arvore(ArvoreBin * arvore)
{
	ArvoreBin * aux = arvore;
	
	if(aux == NULL)
	{
		printf("\arvore vazia\n");
		return;
	}
	
	printf("  [");
	if(aux->esq != NULL)
	{
		printf("%d", aux ->esq->info);
		if(aux->dir != NULL)
		{
			printf(", %d]\n", aux->dir->info);
		} else 
		{
			printf("]\n");
		}
	} else
	{
		if(aux->dir != NULL)
		{
			printf(" %d]\n", aux->dir->info);
		} else 
		{
			printf("]\n");
		}
	}
}

/*
filhos: Dado um valor inteiro fornecido pelo usuário, o programa deve encontrar
e imprimir os filhos desse valor. Se o valor não tiver filhos, uma mensagem apropriada deve
ser retornada.
*/
void encontra_filhos(ArvoreBin * arvore, int info)
{
	
	ArvoreBin * aux = arvore;
	
	while(aux != NULL)
	{
		if(aux->info == info)
		{
			imprime_arvore(aux);
			return;
		}
		
		if(aux->info < info)
		{
			aux = aux->dir;
		} else if(aux->info > info)
		{
			aux = aux->esq;
		}
	}
}


int main()
{
	int casos_teste, i, j, valor_busca;
	
	scanf("%d", &casos_teste);	
	printf("\n");
	for(i = 0; i < casos_teste; i++)
	{
		ArvoreBin * arvore = inicializa_arvore();

		int num_nos;
		scanf("%d", &num_nos);
		printf("\n");
		for(j = 0; j < num_nos; j++)
		{
			int valor_no;
			scanf("%d", &valor_no);
			cria_arvore(&arvore, valor_no);
		}
		
		scanf("%d", &valor_busca);
		
		int valor_encontrado = encontra_valor(arvore, valor_busca);
		
		if(valor_encontrado)
		{
			printf("%d", valor_encontrado);
			encontra_filhos(arvore, valor_busca);
		} else 
		{
			printf("%d\n", valor_encontrado);
		}
	}
	
		
	return 0;
}
