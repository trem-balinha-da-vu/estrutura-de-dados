#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "fila.h"

/**
 * Escreva um programa que leia um número indefinido de valores inteiros, encerrando 
 * a entrada de dados ao encontrar o valor zero (0). Para cada número lido, 
 * determine se ele é par ou ímpar. Se o número for par, insira-o na FILA PAR;
 * caso contrário, insira-o na FILA ÍMPAR. Após finalizar a entrada de dados, retire 
 * elementos de cada fila alternativamente, começando pela FILA ÍMPAR, até que ambas
 *  as filas estejam vazias. Se o elemento retirado de uma das filas
 * for positivo, adicione-o a uma PILHA; caso contrário, remova um elemento da
 *  PILHA. Por fim, exiba o conteúdo da PILHA.
 * */

void processa_nums()
{
    int num;
    int eh_par;
    Fila *fila_impar = inicializa_fila();
    Fila *fila_par = inicializa_fila();

    // Fluxo 1: Receber números e inserir nas filas
    do
    {
        printf("Entre com um numero (0 para sair)...\n");
        scanf("%d", &num);
        
        if(num == 0) break; // interrompe se o número for zero

        eh_par = (num % 2 == 0) ? 1 : 0;

        if (eh_par)
        {
            enqueue_ref(&fila_par, num);
        }
        else
        {
            enqueue_ref(&fila_impar, num);
        }
    } while (1);

    // Fluxo 2: Desenfileirar de maneira alternada
    Pilha *pilha = inicializa_pilha();
    
    while (fila_impar != NULL || fila_par != NULL)
    {
        // Lidar com a FILA ÍMPAR
        if (fila_impar != NULL)
        {
            if (front(fila_impar) > 0)
            {
                push(&pilha, front(fila_impar));
            }
            else
            {
                pop(&pilha);
            }
            dequeue_ref(&fila_impar);
        }

        // Lidar com a FILA PAR
        if (fila_par != NULL)
        {
            if (front(fila_par) > 0)
            {
                push(&pilha, front(fila_par)); 
            }
            else
            {
                pop(&pilha);
            }
            dequeue_ref(&fila_par);
        }
    }

    print_stack(pilha);
    getchar();
}

int main(int argc, char const *argv[])
{
	processa_nums();
	getchar();
	return 0;
}