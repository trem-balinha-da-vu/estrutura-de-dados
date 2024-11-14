#ifndef ARVORE_LIB
#define ARVORE_LIB

typedef struct arvore {
	int info;
	struct arvore *esq;
	struct arvore *dir;
} ArvBin;

typedef struct ArvBinC {
    char info;
    struct ArvBinC *esq;
    struct ArvBinC *dir;
} ArvBinC;

typedef struct FilaArv {
    ArvBinC *no_arvore;
    struct FilaArv *prox;
} FilaArv;



ArvBin * inicializa();


//--------------------------------------------------------
//algoritmos de busca em profundidade

//precurso em profundidade pre-ordem (raiz-esquerda-direita)
void bsf_preOrder(ArvBin *raiz);

//percurso em profundidade em-ordem (esquerda-raiz-direita)
void bsf_inOrder(ArvBin* raiz);

//percurso em profundidade pos-ordem (esquerda-direita-raiz)
void bsf_posOrder(ArvBin* raiz);
//--------------------------------------------------------



//--------------------------------------------------------
//algoritmo de busca em largura
ArvBinC * inicializaC();

FilaArv* cria_fila();

void cria_no_c(ArvBinC **p_arvore, char info);

FilaArv* enqueueC(FilaArv *fila, ArvBinC *no);

FilaArv* dequeueC(FilaArv *fila);

ArvBinC* front(FilaArv *fila);

int fila_vazia(FilaArv *fila);

void bfs(ArvBinC *arvore);

//--------------------------------------------------------


//--------------------------------------------------------
//algoritmos de criacão e destruição de arvore
ArvBin * cria_arvore_recursivo(ArvBin *arvore, int info);

void proc_cria_arvore(ArvBin ** p_arvore, int info);

void cria_arvore_iterativo( ArvBin** p_arvore, int info);

void libera_no(ArvBin * no_arvore);

void libera_arvore(ArvBin ** arvore);

//--------------------------------------------------------


//--------------------------------------------------------
//algoritmos auxiliares
void imprime_filhos(ArvBin ** arvore);

int altura(ArvBin *arvore);

int estah_vazia(ArvBin *arvore);

int conta_graus(ArvBin *arvore);

int grau_arvore(ArvBin * arvore, int info);

ArvBin* encontra_subArv(ArvBin * arvore, int info);
//--------------------------------------------------------
#endif
