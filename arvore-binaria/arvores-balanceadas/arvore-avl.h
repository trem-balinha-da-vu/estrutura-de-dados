#ifndef ARVORE_AVL_LIB
#define ARVORE_AVL_LIB

typedef struct arv {
    int info;
    struct arv *esq;
    struct arv *dir;
} ArvAVL;

ArvAVL* rotacao_direita(ArvAVL* y);

ArvAVL* rotacao_esquerda(ArvAVL* x);

int altura(ArvAVL *arv);

int fator_balanceamento(ArvAVL *arv);

ArvAVL* balancear(int fb, ArvAVL* arv);

ArvAVL* cria_arvore(ArvAVL * arv, int info);

ArvAVL* remover_no(ArvAVL* arv, int info);

void bsf_inOrder(ArvAVL* raiz);

void libera_arvore(ArvAVL* arv);

#endif
