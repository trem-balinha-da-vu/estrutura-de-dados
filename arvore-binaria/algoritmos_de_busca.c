#include <stdio.h>
#include <stdlib.h>

typedef struct ArvBinC {
    char info;
    struct ArvBinC *esq;
    struct ArvBinC *dir;
} ArvBinC;

typedef struct FilaArv {
    ArvBinC *no_arvore;
    struct FilaArv *prox;
} FilaArv;

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
        return novo; // Retorna o novo no como inicio da fila
    }
    
    // Caso contr�rio, encontra o final da fila e adiciona o novo no
    FilaArv *temp = fila;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = novo;
    return fila;
}

// Funcao para desenfileirar o na da frente da fila
FilaArv* dequeueC(FilaArv *fila) {
    if (fila == NULL) return NULL;
    
    FilaArv *temp = fila;
    fila = fila->prox;
    free(temp);
    return fila;
}

// Funcao para obter o primeiro no da arvore na fila (front)
ArvBinC* front(FilaArv *fila) {
    if (fila == NULL) return NULL;
    return fila->no_arvore;
}

// Funcao para verificar se a fila esta vazia
int fila_vazia(FilaArv *fila) {
    return (fila == NULL);
} 


//busca em largura
void busca_largura(ArvBinC *arvore) {
    if (arvore == NULL) return;
    
    FilaArv *fila = cria_fila();
    fila = enqueueC(fila, arvore); // Enfileira a raiz inicialmente

    while (!fila_vazia(fila)) {
        ArvBinC *no_atual = front(fila); // Obtem o no atual (frente da fila)
        fila = dequeueC(fila); // Remove o no atual da fila
        
        printf("%c ", no_atual->info); // Visita o no atual
        
        // Enfileira os filhos do no atual, se existirem
        if (no_atual->esq != NULL) fila = enqueueC(fila, no_atual->esq);
        if (no_atual->dir != NULL) fila = enqueueC(fila, no_atual->dir);
    }
}

//precurso em profundidade pre-ordem (raiz-esquerda-direita)
void busca_profundidade_preOrder(ArvBinC *raiz)
{
	if (raiz == NULL)
	{
		return;
	}
	
	printf("%c  ", raiz->info);
	bsf_preOrder(raiz->esq);
	bsf_preOrder(raiz->dir);
}

//percurso em profundidade em-ordem (esquerda-raiz-direita)
void busca_profundidade_inOrder(ArvBinC* raiz)
{
	if (raiz == NULL)
	{
		printf("arvore vazia.");
		return;
	}
	
	bsf_inOrder(raiz->esq);
	printf("%c  ", raiz->info);
	bsf_inOrder(raiz->dir);
}

//percurso em profundidade pos-ordem (esquerda-direita-raiz)
void busca_profundidade_posOrder(ArvBinC* raiz)
{
	if (raiz == NULL)
	{
		return;
	}
	
	bsf_posOrder(raiz->esq);
	bsf_posOrder(raiz->dir);
	printf("%c  ", raiz->info);
}