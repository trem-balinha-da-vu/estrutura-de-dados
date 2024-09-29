#ifndef PILHA_LIB
#define PILHA_LIB 


typedef struct pilhaChar{
	char caractere;
	struct pilhaChar * prox;
} PilhaC;

typedef struct pilha{
	int info;
	struct pilha * prox;
} Pilha;

PilhaC * pop_valorC(PilhaC *topo);

PilhaC * push_valorC(PilhaC *topo, char caractere);

void popC (PilhaC **topo);

void pushC(PilhaC **topo, char caractere);

char topoC(PilhaC *topo);

PilhaC * inicializa_pilhaC();

int pilha_vaziaC(PilhaC * topo);

void libera_pilhaC(PilhaC *topo);





Pilha * pop_valor(Pilha *topo);

Pilha * push_valor(Pilha *topo, int info);

void pop (Pilha **topo);

void push(Pilha **topo, int info);

int topo(Pilha *topo);

Pilha * inicializa_pilha();

int pilha_vazia(Pilha * topo);

void libera_pilha(Pilha *topo);

void print_stack(Pilha * topo);

#endif