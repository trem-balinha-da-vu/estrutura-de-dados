#include <stdio.h>
#include <stdlib.h>
#include "arvore-avl.h"

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
    if (arv == NULL) return -1; // Árvore vazia tem altura -1
    int altura_esq = altura(arv->esq);
    int altura_dir = altura(arv->dir);
    return (altura_esq > altura_dir ? altura_esq : altura_dir) + 1;
}

int fator_balanceamento(ArvAVL *arv) {
    if (arv == NULL) return 0; // Se a árvore é nó folha, o fator é 0
    return altura(arv->esq) - altura(arv->dir);
}

ArvAVL* balancear(int fb, ArvAVL* arv) {
    //simples à direita
    if (fb > 1 && fator_balanceamento(arv->esq) >= 0) {
        return rotacao_direita(arv);
    }
    //dupla para a direita
    if (fb > 1 && fator_balanceamento(arv->esq) < 0) {
        arv->esq = rotacao_esquerda(arv->esq);
        return rotacao_direita(arv);
    }
    //simples à esquerda
    if (fb < -1 && fator_balanceamento(arv->dir) <= 0) {
        return rotacao_esquerda(arv);
    }
    //dupla para a esquerda
    if (fb < -1 && fator_balanceamento(arv->dir) > 0) {
        arv->dir = rotacao_direita(arv->dir);
        return rotacao_esquerda(arv);
    }
    return arv; // Nenhum balanceamento necessário
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
    } else {
        return arv; //valor duplicado, não faz nada (só pra garantir né)
    }

    int fb = fator_balanceamento(arv);
    
    return balancear(fb, arv);
}

ArvAVL* remover_no(ArvAVL* arv, int info) {
    if (arv == NULL) {
        return NULL; // Nó não encontrado, não faz nada
    }

    if (info < arv->info) {
        arv->esq = remover_no(arv->esq, info);
    } else if (info > arv->info) {
        arv->dir = remover_no(arv->dir, info);
    } else {//nó encontrado
        if (arv->esq == NULL && arv->dir == NULL) {
            //caso 1: nó folha
            free(arv);
            return NULL;
        } else if (arv->esq == NULL || arv->dir == NULL) {
            //caso 2: nó com um filho
            ArvAVL* temp = arv->esq ? arv->esq : arv->dir;
            free(arv);
            return temp;
        } else {
            //caso 3: nó com dois filhos
            //encontrar o sucessor in-order (menor valor na subárvore direita)
            ArvAVL* sucessor = arv->dir;
            while (sucessor->esq != NULL) {
                sucessor = sucessor->esq;
            }
            //substituir o valor do nó a ser removido pelo valor do sucessor
            arv->info = sucessor->info;
            //remover o sucessor in-order
            arv->dir = remover_no(arv->dir, sucessor->info);
        }
    }

    int fb = fator_balanceamento(arv);
    
    return balancear(fb, arv);
}

void bsf_inOrder(ArvAVL* raiz) {
    if (raiz == NULL) {
        return;
    }

    bsf_inOrder(raiz->esq);
    printf("%d FB %d\n", raiz->info, fator_balanceamento(raiz));
    bsf_inOrder(raiz->dir);
}

void libera_arvore(ArvAVL* arv) {
    if (arv != NULL) {
        libera_arvore(arv->esq);
        libera_arvore(arv->dir);
        free(arv);
    }
}



