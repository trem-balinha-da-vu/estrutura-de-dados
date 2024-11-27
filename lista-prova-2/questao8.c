#include <stdio.h>

/*
Dado um vetor de números inteiros não ordenado, escreva um programa que determine se existem
dois elementos no vetor cuja soma seja exatamente igual a um número alvo x. O programa deve
retornar "Sim"se houver dois elementos com a soma igual a x , ou "Não"caso contrário.
*/

void soma_igual_a_x(int *vet, int tam, int x)
{
	int i, j;
	for(i = 0; i < tam; i++)
	{
		for(j = i+1; j<tam; j++)
		{
			if((vet[i] + vet[j]) == x)
			{
				printf("Sim.");
				return;
			}
		}
	}
	
	printf("Nao.");
	return;
}

int main() {
    int vet[] = {0, 3, 5, 18, 1, 15, 8};

    int tam = sizeof(vet) / sizeof(vet[0]);

	soma_igual_a_x(vet, tam, 17);

    return 0;
}

