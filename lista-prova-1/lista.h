#ifndef LISTA_LIB
#define LISTA_LIB

typedef struct lista{
	int info;
	struct lista *prox;
}Lista;

Lista * insere_no_inicio(Lista * inicio, int info);

void insere_no_inicio_ref(Lista **p__inicio_lista, int info);

Lista * insere_no_fim(Lista * inicio, int info);

void insere_no_fim_ref(Lista **p_inicio_lista, int info);

Lista * retira_do_fim(Lista * inicio);

void retira_do_fim_ref(Lista **p_inicio_lista);

Lista * retira_do_inicio(Lista * inicio);

void retira_do_inicio_ref(Lista **p_inicio_lista);

Lista * inicializa();

void imprime_lista(Lista * inicio);

Lista * encontra_ultimo(Lista *inicio);

void preenche_lista(Lista **lista, int qtd_nos, int n);

#endif
