#include <stdio.h>
#include <stdlib.h>

/*
Escreva uma fun��o que retorne a soma dos n�meros inteiros armazenados em n�s que s�o folhas
da �rvore (isto �, n�s que n�o t�m filhos). O prot�tipo da fun��o deve ser:

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
	// Se a �rvore est� vazia, a soma � 0
    if (a == NULL) {
        return 0;
    }
    
    // Se o n� � uma folha (n�o tem filhos), retorna o valor do n�
    if (a->esq == NULL && a->dir == NULL) {
        return a->info;
    }
    
    // Caso contr�rio, soma os valores das folhas das sub�rvores esquerda e direita
    return soma_info_folhas(a->esq) + soma_info_folhas(a->dir);
}

int main() {
    // Testando a fun��o com uma �rvore de exemplo
    Arv* arvore = inicializa();
    
    // Inserindo elementos na �rvore
    arvore = cria_arvore(arvore, 10);
    arvore = cria_arvore(arvore, 5);
    arvore = cria_arvore(arvore, 15);
    arvore = cria_arvore(arvore, 3);
    arvore = cria_arvore(arvore, 7);
    arvore = cria_arvore(arvore, 12);
    arvore = cria_arvore(arvore, 18);
    
    // Calculando a soma dos valores dos n�s folha
    int soma = soma_info_folhas(arvore);
    
    // Imprimindo o resultado
    printf("A soma dos valores nos n�s folha �: %d\n", soma);
    
    return 0;
}
