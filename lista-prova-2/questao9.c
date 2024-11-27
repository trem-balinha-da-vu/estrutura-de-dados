#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
	int info;
	struct arvore *esq;
	struct arvore *dir;
} ArvBin;

ArvBin * inicializa()
{
	return NULL;
}

ArvBin * cria_arvore(ArvBin *arvore, int info)
{
	if(arvore == NULL)
	{
		ArvBin * novo_no = (ArvBin *) malloc(sizeof(ArvBin));
		novo_no -> info = info;
		novo_no->esq = NULL;
		novo_no -> dir = NULL;
		
		return novo_no;
	}
	
	if(info > arvore->info)
	{
		arvore->dir = cria_arvore(arvore->dir, info);
	} else 
	{
		arvore->esq = cria_arvore(arvore->esq, info);
	}
	
	return arvore;
}


//percurso em profundidade em-ordem (esquerda-raiz-direita)
void bsf_inOrder(ArvBin* raiz)
{
	if (raiz == NULL)
	{
		return;
	}
	
	bsf_inOrder(raiz->esq);
	printf("%d ", raiz->info);
	bsf_inOrder(raiz->dir);
}

int main()
{
	int vet[] = {15, 10, 20, 5, 12, 18, 25};
	int tam = sizeof(vet) / sizeof(vet[0]);
	
	ArvBin * arvore = inicializa();
	int i;
	
	for(i = 0; i < tam; i++)
	{
		arvore = cria_arvore(arvore, vet[i]);
	}
	
	printf("arvore: \n");
	bsf_inOrder(arvore);
	return 0;
}
