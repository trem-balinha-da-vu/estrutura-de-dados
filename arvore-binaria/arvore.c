#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"


//--------------------------------------------------------
//--------------------------------------------------------
//PERCURSO EM LARGURA

ArvBinC * inicializaC()
{
	return NULL;
}

FilaArv* cria_fila() {
    return NULL;
}

void cria_no_c(ArvBinC **p_arvore, char info) {
    
   	if(*p_arvore == NULL)
	{
		ArvBinC* novo_no = (ArvBinC*)malloc(sizeof(ArvBinC));
		novo_no -> info = info;
		novo_no->esq = NULL;
		novo_no -> dir = NULL;
		*p_arvore = novo_no;
		
		return;
	}
	
	if(info > (*p_arvore)->info)
	{
		cria_no_c(&((*p_arvore)->dir), info);
	} else 
	{
		cria_no_c(&((*p_arvore)->esq), info);
	}
}

FilaArv* enqueueC(FilaArv *fila, ArvBinC *no) {
    FilaArv *novo = (FilaArv*)malloc(sizeof(FilaArv));
    novo->no_arvore = no;
    novo->prox = NULL;
    
    if (fila == NULL) {
        return novo; // Retorna o novo nó como início da fila
    }
    
    // Caso contrário, encontra o final da fila e adiciona o novo nó lá
    FilaArv *temp = fila;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = novo;
    return fila;
}

// Função para desenfileirar o nó da frente da fila
FilaArv* dequeueC(FilaArv *fila) {
    if (fila == NULL) return NULL;
    
    FilaArv *temp = fila;
    fila = fila->prox;
    free(temp);
    return fila;
}

// Função para obter o primeiro nó da árvore na fila (front)
ArvBinC* front(FilaArv *fila) {
    if (fila == NULL) return NULL;
    return fila->no_arvore;
}

// Função para verificar se a fila está vazia
int fila_vazia(FilaArv *fila) {
    return (fila == NULL);
} 

void bfs(ArvBinC *arvore) {
    if (arvore == NULL) return;
    
    FilaArv *fila = cria_fila();
    fila = enqueueC(fila, arvore); // Enfileira a raiz inicialmente
    
    while (!fila_vazia(fila)) {
        ArvBinC *no_atual = front(fila); // Obtém o nó atual (frente da fila)
        fila = dequeueC(fila); // Remove o nó atual da fila
        
        printf("%c ", no_atual->info); // Visita o nó atual
        
        // Enfileira os filhos do nó atual, se existirem
        if (no_atual->esq != NULL) fila = enqueueC(fila, no_atual->esq);
        if (no_atual->dir != NULL) fila = enqueueC(fila, no_atual->dir);
    }
}

//--------------------------------------------------------
//--------------------------------------------------------

void busca_em_largura_aux(ArvBin * arvore,Fila * fila)
{
	if(arvore == NULL) return;
	
	enqueue_ref(&fila, arvore->info);
	printf("%d  ", front(fila));
	dequeue_ref(&fila);
	
	busca_em_largura_aux(arvore->esq, fila);
	busca_em_largura_aux(arvore->dir, fila);
}
void busca_em_largura(ArvBin * arvore)
{
	Fila * fila = NULL;
	
	busca_em_largura_aux(arvore, fila);
}

ArvBin * inicializa()
{
	return NULL;
}

//precurso em profundidade pre-ordem (raiz-esquerda-direita)
void bsf_preOrder(ArvBin *raiz)
{
	if (raiz == NULL)
	{
		return;
	}
	
	printf("%d ", raiz->info);
	bsf_preOrder(raiz->esq);
	bsf_preOrder(raiz->dir);
}

//percurso em profundidade em-ordem (esquerda-raiz-direita)
void bsf_inOrder(ArvBin* raiz)
{
	if (raiz == NULL)
	{
		printf("arvore vazia.");
		return;
	}
	
	bsf_inOrder(raiz->esq);
	printf("%d ", raiz->info);
	bsf_inOrder(raiz->dir);
}

//percurso em profundidade pos-ordem (esquerda-direita-raiz)
void bsf_posOrder(ArvBin* raiz)
{
	if (raiz == NULL)
	{
		return;
	}
	
	bsf_posOrder(raiz->esq);
	bsf_posOrder(raiz->dir);
	printf("%d ", raiz->info);
}


ArvBin * cria_arvore_recursivo(ArvBin *arvore, int info)
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
		arvore->dir = cria_arvore_recursivo(arvore->dir, info);
	} else 
	{
		arvore->esq = cria_arvore_recursivo(arvore->esq, info);
	}
	
	return arvore;
}

//ver se está certo depois
void proc_cria_arvore(ArvBin ** p_arvore, int info)
{
	if(*p_arvore == NULL)
	{
		ArvBin * novo_no = (ArvBin *) malloc(sizeof(ArvBin));
		novo_no -> info = info;
		novo_no->esq = NULL;
		novo_no -> dir = NULL;
		*p_arvore = novo_no;
		
		return;
	}
	
	if(info > (*p_arvore)->info)
	{
		proc_cria_arvore(&((*p_arvore)->dir), info);
	} else 
	{
		proc_cria_arvore(&((*p_arvore)->esq), info);
	}
}

void cria_arvore_iterativo( ArvBin** p_arvore, int info)
{
	ArvBin * novo_no = (ArvBin *) malloc(sizeof(ArvBin));
	
	novo_no -> info = info;
	novo_no->esq = NULL;
	novo_no -> dir = NULL;
	
	if(*p_arvore == NULL)
	{
		*p_arvore = novo_no;
		return;
	}
	
	ArvBin *aux = *p_arvore;
	ArvBin *pai = NULL;
	
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

//imprime filhos da árvore
void imprime_filhos(ArvBin * arvore)
{
	ArvBin * aux = arvore;
	
	if(aux == NULL)
	{
		printf("\arvore vazia\n");
		return;
	}
	
	printf("\n%d\n", aux->info);
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

int altura(ArvBin *arvore) {
	if (arvore == NULL) return 0;
	int altura_esq = altura(arvore->esq);
	int altura_dir = altura(arvore->dir);
	return (altura_esq > altura_dir ? altura_esq : altura_dir) + 1;
}

int conta_graus(ArvBin *arvore) {
	if (arvore == NULL) return -1;

	int grau = 0;
	if (arvore->esq != NULL) grau++;
	if (arvore->dir != NULL) grau++; 

	return grau;
}

int grau_arvore(ArvBin * arvore, int info)
{
	
	ArvBin * aux = arvore;
	
	while(aux != NULL)
	{
		if(aux->info == info)
		{
			return conta_graus(aux);
		}
		
		if(aux->info < info)
		{
			aux = aux->dir;
		} else if(aux->info > info)
		{
			aux = aux->esq;
		}
	}
	
	return -1;
}

void libera_no(ArvBin **no_arvore)
{
	if (no_arvore == NULL || *no_arvore == NULL) return;
	
	libera_no(&((*no_arvore)->esq));
	libera_no(&((*no_arvore)->dir));
	
	free(*no_arvore);
	*no_arvore = NULL; // Definir o ponteiro do nó como NULL após liberar
}

void libera_arvore(ArvBin **arvore)
{
	if (arvore == NULL || *arvore == NULL) return;
	
	libera_no(arvore);
	*arvore = NULL; // Garantir que o ponteiro raiz fique NULL após liberar a árvore
}

int estah_vazia(ArvBin *arvore)
{
	//deu problema na alocação da árvore ou a árvore está vazia
	return arvore == NULL ? 1 : 0;
}

ArvBin* encontra_subArv(ArvBin * arvore, int info)
{
	if(arvore == NULL) return NULL;
	
	if(arvore->info == info) return arvore;
	
	if(arvore->info < info) encontra_subArv(arvore->dir, info);
	else if (arvore->info > info) encontra_subArv(arvore->esq, info);

}


			


