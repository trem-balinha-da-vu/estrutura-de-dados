#include <stdio.h>
#include <stdlib.h>


/*
3. Considere os vetores abaixo. Construa uma Árvore AVL a partir da sequência de inserção de
seus elementos, seguindo rigorosamente as regras de balanceamento dessa estrutura. Para cada
vetor:
	1. Apresente a estrutura da árvore após todas as inserções, indicando os nós e o balanceamento
de cada um deles.
	2. Mostre o passo a passo de todas as rotações realizadas (simples ou duplas) para garantir o
balanceamento.
	3. Determine a altura final da árvore.
Vetores a serem considerados:
	• Vetor 1: 15, 10, 20, 5, 12, 18, 25
	• Vetor 2: 30, 40, 20, 10, 25, 35, 45, 5
*/


typedef struct arv {
    int info;
    struct arv *esq;
    struct arv *dir;
} ArvAVL;

//percurso em profundidade em-ordem (esquerda-raiz-direita)
void busca_profundidade_inOrder(ArvAVL* raiz)
{
	if (raiz == NULL)
	{
		return;
	}
	
	busca_profundidade_inOrder(raiz->esq);
	printf("no %d  balanceamento %d\n", raiz->info, fator_balanceamento(raiz));
	busca_profundidade_inOrder(raiz->dir);
}

ArvAVL* rotacao_direita(ArvAVL* y) {
    ArvAVL* x = y->esq;
    ArvAVL* T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    return x;
}

ArvAVL* rotacao_esquerda(ArvAVL* x) {
    ArvAVL* y = x->dir;
    ArvAVL* T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    return y;
}

int altura(ArvAVL *arv) {
    if (arv == NULL) return -1; // arvore vazia tem altura -1
    int altura_esq = altura(arv->esq);
    int altura_dir = altura(arv->dir);
    return (altura_esq > altura_dir ? altura_esq : altura_dir) + 1;
}

int fator_balanceamento(ArvAVL *arv) {
    if (arv == NULL) return 0; // Se a arvore eh no folha, o fator eh 0
    return altura(arv->esq) - altura(arv->dir);
}

ArvAVL* balancear(int fb, ArvAVL* arv) {
    //simples p/ direita
    if (fb > 1 && fator_balanceamento(arv->esq) >= 0) {
        return rotacao_direita(arv);
    }
    //dupla p/ direita
    if (fb > 1 && fator_balanceamento(arv->esq) < 0) {
        arv->esq = rotacao_esquerda(arv->esq);
        return rotacao_direita(arv);
    }
    //simples p/ esquerda
    if (fb < -1 && fator_balanceamento(arv->dir) <= 0) {
        return rotacao_esquerda(arv);
    }
    //dupla p/ esquerda
    if (fb < -1 && fator_balanceamento(arv->dir) > 0) {
        arv->dir = rotacao_direita(arv->dir);
        return rotacao_esquerda(arv);
    }
    return arv; // Nenhum balanceamento necessario
}

ArvAVL* cria_arvore(ArvAVL * arv, int info) {
    if (arv == NULL) {
        ArvAVL *novo = (ArvAVL *) malloc(sizeof(ArvAVL));

        novo->info = info;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }

    if (info < arv->info) {
        arv->esq = cria_arvore(arv->esq, info);
    } else if (info > arv->info) {
        arv->dir = cria_arvore(arv->dir, info);
    }

    int fb = fator_balanceamento(arv);
    
    return balancear(fb, arv);
}

int altura_arvore(ArvAVL *arv) {
    if (arv == NULL) return 0; // Árvore vazia tem altura 0
    int altura_esq = altura_arvore(arv->esq);
    int altura_dir = altura_arvore(arv->dir);
    return (altura_esq > altura_dir ? altura_esq : altura_dir) + 1; // Contar a raiz
}

int main()
{
	int vet1[] = {15, 10, 20, 5, 12, 18, 25}, tam1 = 7, vet2[] = {30, 40, 20, 10, 25, 35, 45, 5}, tam2 = 8;
	
	ArvAVL * arvore1 = NULL;
	int i;
	
	for(i = 0; i < tam1; i++)
	{
		arvore1 = cria_arvore(arvore1, vet1[i]);
	}
	
	printf("arvore 1: \n");
	busca_profundidade_inOrder(arvore1);
	printf("altura da arvore 1: %d\n\n", altura_arvore(arvore1));
	
	ArvAVL * arvore2 = NULL;
	
	for(i = 0; i < tam2; i++)
	{
		arvore2 = cria_arvore(arvore2, vet2[i]);
	}
	
	printf("arvore 2: \n");
	busca_profundidade_inOrder(arvore2);
	printf("altura da arvore 2: %d\n\n", altura_arvore(arvore2));
	
	return 0;
}
