#ifndef FILA_LIB
#define FILA_LIB 

typedef struct fila
{
	int info;
	struct fila * prox;
}Fila;

Fila * inicializa_fila ();

Fila * encontra_ultimo_fila(Fila * ini);

Fila * enqueue (Fila * ini, int info);

void enqueue_ref (Fila **p_inicio_fila, int info);

Fila * dequeue (Fila * ini);

void dequeue_ref (Fila **p_inicio_fila);

int front (Fila * ini);

void print_queue(Fila * ini);

void fill_queue(Fila **p_front, int qtd_nos, int n);

#endif