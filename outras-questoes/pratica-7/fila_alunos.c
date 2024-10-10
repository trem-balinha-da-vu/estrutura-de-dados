#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
	int info;
	struct fila * prox;
}Fila;

typedef struct lista
{
	int info;
	struct lista * prox;
}Lista;

Fila * inicializa_fila ()
{
	return NULL;
}

Lista *inicializa_lista()
{
	return NULL;
}

int front(Fila *ini)
{
    if (ini == NULL)
    {
        printf("Fila vazia.\n");
        return -1; // Ou outro valor que indique erro?
    }
    return ini->info;
}

Fila * encontra_ultimo_fila(Fila * ini)
{
	if(ini == NULL) return NULL;

	Fila *aux = ini;

	while(aux->prox != NULL)
	{
		aux = aux->prox;
	}

	return aux;
}

void enqueue(Fila **p_inicio_fila, int info)
{
    Fila * ult = encontra_ultimo_fila(*p_inicio_fila);

    Fila * novo = (Fila *) malloc(sizeof(Fila));
    novo->prox = NULL;
    novo->info = info;

    if(ult != NULL)
    {
        ult->prox = novo;
    }
    else
    {
        *p_inicio_fila = novo;
    }
}


void dequeue(Fila **p_inicio_fila)
{
	Fila * aux = *p_inicio_fila;

	if (aux == NULL) return;

	*p_inicio_fila = (*p_inicio_fila)->prox;

	free(aux);

	return;
}

void insere_ord_lista(Lista **p_inicio, int info)
{
	Lista *novo_no = (Lista *) malloc(sizeof(Lista));
	novo_no->info = info;

	//se a lista estiver vazia
	if(*p_inicio == NULL)
	{
		novo_no->prox = NULL;
		*p_inicio = novo_no;
		return;
	}

	//se só tiver um elemento
	if((*p_inicio)->prox == NULL)
	{
		//esse elemento é maior
		if((*p_inicio)->info > novo_no->info)
		{
			(*p_inicio)->prox = novo_no;
			novo_no->prox = NULL;
			return;
		}
		//novo nó é maior
		else
		{
			novo_no->prox = *p_inicio;
			*p_inicio = novo_no;
			return;
		}
	}

	Lista *no_anterior = NULL;
    Lista *no_atual = *p_inicio;
    Lista *no_seguinte = NULL;

	//caminha até o fim da lista com as informações do nó atual, anterior e seguinte
	while(no_atual != NULL && no_atual->info > novo_no->info)
	{
		no_seguinte = no_atual->prox;
		no_anterior = no_atual;
        no_atual = no_seguinte;
	}

	//sai por duas opções: ou o atual é null, ou o atual é menor que o novo nó

	//trata se chegou ao fim da lista
	if(no_atual == NULL){
		no_anterior->prox = novo_no;
		novo_no->prox = NULL;
		return;
	}

	//atual é menor que novo nó

	//maior que o primeiro nó
	if(no_anterior == NULL)
	{
		novo_no->prox = no_atual;
		*p_inicio = novo_no;
		return;
	}

	no_anterior->prox = novo_no;
	novo_no->prox = no_atual;
}

int compara_lista_e_fila(Fila * fila, Lista * lista)
{
	Fila *aux_f = fila;
	Lista * aux_l = lista;
	int n_corretos = 0;

	while(aux_l != NULL)
	{
		if(aux_l->info == front(fila))
		{
			n_corretos++;
		}

		dequeue(&fila);
		aux_l = aux_l->prox;
	}

	return n_corretos;
}

int main(int argc, char** argv) {



	int n_alunos, qtd_iteracoes;
	scanf("%d", &qtd_iteracoes);
	

	while(qtd_iteracoes != 0)
	{
		Fila * fila = inicializa_fila();
		Lista * lista = inicializa_lista();

		scanf("%d", &n_alunos);
		if(n_alunos == 0) break;
		printf("\n");

		int i, info;
		//enfileiro e preencho uma lista já ordenada
		for(i = 0; i < n_alunos; i++)
		{
			scanf("%d", &info);
			insere_ord_lista(&lista, info);
			enqueue(&fila, info);
			printf("\n");
		}



		//compara a fila com a lista ordenada e retorna o numero de alunos que não pecisam ser reorganizados
		printf("%d", compara_lista_e_fila(fila, lista));
		
		qtd_iteracoes--;
		printf("\nprox iteracao\n");
	}

	return 0;
}
