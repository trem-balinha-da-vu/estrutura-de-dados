#include <stdio.h>
#include <stdlib.h>

/*
Escreva uma função que retorne a soma dos números inteiros armazenados em nós que são folhas
da árvore (isto é, nós que não têm filhos). O protótipo da função deve ser:

	int soma_info_folhas (Arv* a);
*/

typedef struct arv {
	int info;
	struct arv* esq;
	struct arv* dir;
}Arv;

Arv * inicializa()
{
	return NULL;
}

Arv * cria_arvore(Arv *arvore, int info)
{
	if(arvore == NULL)
	{
		Arv * novo_no = (Arv *) malloc(sizeof(Arv));
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

int soma_info_folhas (Arv* a)
{
	// Se a árvore está vazia, a soma é 0
    if (a == NULL) {
        return 0;
    }
    
    // Se o nó é uma folha (não tem filhos), retorna o valor do nó
    if (a->esq == NULL && a->dir == NULL) {
        return a->info;
    }
    
    // Caso contrário, soma os valores das folhas das subárvores esquerda e direita
    return soma_info_folhas(a->esq) + soma_info_folhas(a->dir);
}

int main() {
    // Testando a função com uma árvore de exemplo
    Arv* arvore = inicializa();
    
    // Inserindo elementos na árvore
    arvore = cria_arvore(arvore, 10);
    arvore = cria_arvore(arvore, 5);
    arvore = cria_arvore(arvore, 15);
    arvore = cria_arvore(arvore, 3);
    arvore = cria_arvore(arvore, 7);
    arvore = cria_arvore(arvore, 12);
    arvore = cria_arvore(arvore, 18);
    
    // Calculando a soma dos valores dos nós folha
    int soma = soma_info_folhas(arvore);
    
    // Imprimindo o resultado
    printf("A soma dos valores nos nós folha é: %d\n", soma);
    
    return 0;
}
