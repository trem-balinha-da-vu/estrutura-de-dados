#include<stdio.h>
#include<stdlib.h>

/*
Em estat�stica descritiva, a moda � o valor que det�m o maior n�mero de observa��es, ou seja,
o valor ou valores mais frequentes. Exemplos:
� A moda de ma��, banana, laranja, laranja, laranja, p�ssego � laranja.
� A s�rie 1, 3, 5, 5, 6, 6 apresenta duas modas (bimodal): 5 e 6.
� A s�rie 1, 3, 2, 5, 8, 7, 9 n�o apresenta moda. Bimodal: possui dois valores modais, amodal:
n�o possui moda. Fa�a uma fun��o que receba um vetor de n�meros inteiros ordenados e
retorne a moda (todas que existirem).
*/

int * moda(int *vet, int tam, int * tam_modas)
{
	int moda[1], i, j;//o vetor tem zero, uma ou duas modas
	int * ocorrencias = (int*) calloc(tam, sizeof(int));
	
	//preencho ocorrencias[] com a quantidade de vezes que cada numero aparece no vetor
	for(i = 0; i < tam; i++)
	{
		for(j = i+1; j < tam; j++)
		{
			if(vet[i] == vet[j])
			{
				ocorrencias[i]= ocorrencias[i]+1;
			}
		}	
	}
	
	//descubro qual o numero maximo de ocorrencias
	
	int max_ocorrencias = ocorrencias[0];
	
	for(i = 0; i < tam; i++)
	{
		if(ocorrencias[i] > max_ocorrencias)
		{
			max_ocorrencias = ocorrencias[i];
		}
	}
	
	// quantos numeros tem o mesmo tanto de ocorrencias max
	int num_modas = 0;
	
	
	for(i = 0; i < tam; i++)
    {
        if(ocorrencias[i] == max_ocorrencias)
        {
            num_modas++;
        }
    }
	
	int *modas = (int*) calloc(num_modas, sizeof(int));
    int moda_index = 0;
    
    // armazeno as modas
    for(i = 0; i < tam; i++)
    {
        if(ocorrencias[i] == max_ocorrencias)
        {
            modas[moda_index++] = vet[i];
        }
    }

    // Definir o n�mero de modas
    *tam_modas = num_modas;

    free(ocorrencias);
    
    return modas;
	
}

int main()
{
    int vet[] = {1, 3, 5, 5, 6, 7};
    int tam = sizeof(vet) / sizeof(vet[0]);
    int modasTam = 0, i;

    int *modasResult = moda(vet, tam, &modasTam);

    printf("Moda(s): ");
    for(i = 0; i < modasTam; i++)
    {
        printf("%d ", modasResult[i]);
    }
    printf("\n");

    free(modasResult);
    return 0;
}
