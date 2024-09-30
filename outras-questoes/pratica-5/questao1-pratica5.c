#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

Expressao *inicializa_lista()
{
    return NULL;
}

Historico *inicializa_historico()
{
    return NULL;
}

Expressao *insere_fim(Expressao *ini, char *expressao, Expressao **fim)
{
    Expressao *novo = (Expressao *)malloc(sizeof(Expressao));
    strcpy(novo->descricao, expressao);
    novo->prox = NULL;

    if (ini == NULL) 
    {
        novo->ant = NULL;
        *fim = novo;  
        return novo;
    }

    Expressao *aux = ini;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }

    aux->prox = novo;
    novo->ant = aux;
    *fim = novo; 

    return ini;
}

Expressao *remove_ultimo(Expressao *inicio, Expressao **fim)
{
    if (inicio == NULL) return NULL;

    Expressao *aux = inicio;

    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }

    if (aux->ant != NULL)
    {
        aux->ant->prox = NULL;
    }
    else
    {
        inicio = NULL;
    }

    *fim = aux->ant;  
    free(aux);
    return inicio;
}

Expressao *muda_posicao(Expressao *exp, Expressao *inicio)
{
    if (exp->ant == NULL)
        return inicio;  

    Expressao *anterior = exp->ant;
    Expressao *anterior_anterior = anterior->ant;

    if (anterior_anterior != NULL)
        anterior_anterior->prox = exp;
    exp->ant = anterior_anterior;

    anterior->prox = exp->prox;
    if (exp->prox != NULL)
        exp->prox->ant = anterior;

    exp->prox = anterior;
    anterior->ant = exp;

    if (exp->ant == NULL)
        return exp;  

    return inicio; 
}

void insere_historico(char *expressao, Historico **historico)
{
	Historico *novo_hist = (Historico *)malloc(sizeof(Historico));
    strcpy(novo_hist->descricao, expressao);
    novo_hist->prox = *historico;
    *historico = novo_hist;
}

Expressao *procura_expressao(Expressao *inicio, char *expressao, int *posicao, int max_lista, int *tamanho_lista, Expressao **fim, Historico **historico)
{
    int cont = 1;
    Expressao *aux = inicio;

	insere_historico(expressao, historico);

    while (aux != NULL)
    {
        if (strcmp(expressao, aux->descricao) == 0)
        {
            *posicao = cont = 1 ? 1 : cont-1;  //a posição min eh 1
            inicio = muda_posicao(aux, inicio);
            return inicio;
        }
        cont++;
        aux = aux->prox;
    }

    *posicao = cont;
    inicio = insere_fim(inicio, expressao, fim);
    (*tamanho_lista)++;

    if (*tamanho_lista > max_lista)
    {
        inicio = remove_ultimo(inicio, fim);
        (*tamanho_lista)--;
    }

    return inicio;
}

void exibe_ordem_crescente(Expressao *fim)
{
    Expressao *aux = fim;

    while (aux != NULL)
    {
        printf("%s\n", aux->descricao);
        aux = aux->ant;
    }
}

void exibe_ordem_decrescente(Expressao *inicio)
{
    Expressao *aux = inicio;

    while (aux != NULL)
    {
        printf("%s\n", aux->descricao);
        aux = aux->prox;
    }
}

void exibe_historico(Historico *historico, int n)
{
    Historico *aux = historico;
    int cont = 0;

    while (aux != NULL && cont < n)
    {
        printf("%s\n", aux->descricao);
        aux = aux->prox;
        cont++;
    }

    if (cont == 0)
        printf("Nenhuma consulta foi feita.\n");
}

int menu()
{
    int opcao;
    printf("\nMenu:\n");
    printf("1. Consultar uma expressao\n");
    printf("2. Exibir todas as expressoes (ordem crescente)\n");
    printf("3. Exibir todas as expressoes (ordem decrescente)\n");
    printf("4. Exibir o historico das ultimas N consultas\n");
    printf("5. Encerrar o programa\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

int main()
{
    Expressao *lista = inicializa_lista();
    Expressao *fim = NULL;
    Historico *historico = inicializa_historico();
    int max_lista, tamanho_lista = 0;

    printf("Digite o tamanho maximo da lista de expressoes: ");
    scanf("%d", &max_lista);

    int opcao;
    char expressao[81];
    int posicao;
    int n;

    do
    {
        opcao = menu();
        switch (opcao)
        {
            case 1:
                printf("Digite a expressao: ");
                scanf(" %[^\n]s", expressao);//lê a string c espaços
                lista = procura_expressao(lista, expressao, &posicao, max_lista, &tamanho_lista, &fim, &historico);
                printf("Expressao '%s' está na posicao %d\n", expressao, posicao);
                break;
            case 2:
                printf("Expressoes em ordem crescente:\n");
                exibe_ordem_crescente(fim);
                break;
            case 3:
                printf("Expressoes em ordem decrescente:\n");
                exibe_ordem_decrescente(lista);
                break;
            case 4:
                printf("Digite o numero de consultas que deseja ver no historico: ");
                scanf("%d", &n);
                printf("Historico das ultimas %d consultas:\n", n);
                exibe_historico(historico, n);
                break;
            case 5:
                printf("Encerrando o programa. tchauu...\n");
                break;
            default:
                printf("Opção invalida!\n");
        }
    } while (opcao != 5);

    return 0;
}

