#include <stdio.h>

//----------------------------------------------------
// METODOS DE BUSCA


//a busca sequencial percorre o vetor do incio ao fim ate encontrar o valor esperado:
int busca_seq_iterativo(int * vet, int tam, int n)
{
	int i;
	for(i = 0; i <tam; i++)
	{
		if(vet[i] == n)
		{
			printf("numero %d encontrado. ", vet[i]);
			return i;//retorna a posicao
		}
	}
	
	return -1;//não encontrado
}

//essa vai do fim pro começo (não sei se pode)
int busca_seq_recursivo(int * vet, int tam, int n)
{
	if (tam == 0) return -1;
	
	if (vet[tam -1] == n)
	{
		printf("numero %d encontrado. ", vet[tam-1]);	
		return tam-1;
	}
	
	return busca_seq_recursivo(vet, tam-1, n); 
}

//a busca binaria so pode ser utilizada em um vetor ordenado.
//consiste em dividir o intervalo de busca a cada iteração/chamada recursiva
//informações importantes: inicio, meio ([inicio+fim]/2) e fim

//busca binaria iterativa
int busca_bin_iterativo(int *vet, int tam, int n)
{
	int inicio = 0, fim = tam-1, meio;
	
	while(inicio <= fim)
	{
		meio = (inicio + fim)/2;
		
		if(vet[meio] == n)
		{
			printf("numero %d encontrado. ", vet[meio]);
			return meio;//posição encontrada
		} else 
		{
			if (vet[meio] < n)//meio < n: garanto que n está depois do meio
			{
				inicio = meio +1;
			} else //meio > n: garanto que n está entre o inicio e o meio
			{
				fim = meio -1;
			}
		}
	}
	
	return -1;//não entcontrou
}

int busca_bin_recursivo(int *vet, int n, int inicio, int fim)
{
	int meio;
	if(inicio <= fim)
	{
		meio = (inicio + fim)/2;
		if(vet[meio] == n)
		{
			printf("numero %d encontrado. ", vet[meio]);
			return meio;//posição encontrada
		} else 
		{
			if (vet[meio] < n)//meio < n: garanto que n está depois do meio
			{
				return busca_bin_recursivo(vet, n, meio +1, fim);
			} else //meio > n: garanto que n está entre o inicio e o meio
			{
				return busca_bin_recursivo(vet, n, inicio, meio -1);
			}
		}
	}
}











