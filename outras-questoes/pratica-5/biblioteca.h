#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

typedef struct listaDupla1 
{
	char descricao[81];
	struct listaDupla1 *ant;
	struct listaDupla1 *prox;
} Expressao;

typedef struct historicoConsultas
{
    char descricao[81];
    struct historicoConsultas *prox;
} Historico;

#endif
