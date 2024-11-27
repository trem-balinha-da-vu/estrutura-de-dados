#include <stdio.h>

//----------------------------------------------------------------------
// METODOS DE ORDENA�AO

//tipos de metodos: por inser��o, troca, sele��o e divis�o e conquista

//ordena��o por sele��o: selection sort
//consiste em ir ordenando do menor pro maior. acha o menor, coloca ele na posi��o correta e tira ele de vista.
/*
Passos:
	1. Percorra o vetor do in�cio ao fim.
	2. Para cada posi��o i:
		+ Encontre o menor elemento na parte n�o ordenada (�ndices de i at� o final).
		+ Troque esse menor elemento com o elemento na posi��o i.
	3. Repita at� que todo o vetor esteja ordenado.
*/
void selection_sort(int *vet, int tam)
{
	int i, j;
	//primeiro for: percorre o vetor do inicio ao fim
	for(i = 0; i < tam; i++)
	{
		int menor_indice = i;
		//segundo for: encontra o menor elemento de i ate o final. isso vai acontecer para cada i
		for (j = i + 1; j < tam; j++) {
			if (vet[j] < vet[menor_indice]) 
			{
				menor_indice = j;
			}
		}
		
		// troca o novo menor elemento com o elemento da posi��o i
		int temp = vet[menor_indice];
		vet[menor_indice] = vet[i];
		vet[i] = temp;
	}
}

//ordena��o por inser��o: insertion sort
//consiste em inserir os elementos da parte n�o-ordenada do vetor, na posi��o correta da parte ordenada
/*
Passos: 
	1. Imagine que o vetor tem uma parte ordenada e uma parte n�o ordenada.
	2. Comece com a parte ordenada contendo apenas o primeiro elemento.
	3. Pegue o pr�ximo elemento da parte n�o ordenada, compare-o com os elementos da parte ordenada e 
insira-o na posi��o correta.
	4. Repita at� que todos os elementos estejam na parte ordenada.
*/

void insertion_sort(int *vet, int tam)
{
	int i, j, chave;

    for (i = 1; i < tam; i++) {  // Itera do segundo elemento at� o �ltimo
        chave = vet[i];          // Seleciona o elemento a ser inserido
        j = i - 1;               // Come�a a compara��o com o elemento anterior

        // Move os elementos maiores que a chave para frente
        while (j >= 0 && vet[j] > chave) {
            vet[j + 1] = vet[j]; // Move o elemento maior uma posi��o � frente
            j--;                 // Continua a verificar os elementos anteriores
        }
        vet[j + 1] = chave;      // Insere a chave na posi��o correta
    }
}


//ordena��o por troca: bubble sort
// o maior elemento "flutua" para a posi��o final a cada intera��o. ordena do maior para o menor
/*
Passos: 
	Compare pares de elementos adjacentes.
Se o elemento � esquerda for maior que o da direita, troque-os.
Ap�s cada passagem pelo vetor, o maior elemento "borbulha" para sua posi��o correta no final.
Repita o processo para os elementos restantes at� que o vetor esteja ordenado.
*/
void bubble_sort(int *vet, int tam) {
    int i, j;

    for (i = 0; i < tam - 1; i++) { // N�mero de passagens
        for (j = 0; j < tam - 1 - i; j++) { // Compara��es em cada passagem
            if (vet[j] > vet[j + 1]) { // Verifica se � necess�rio trocar
                // Troca os elementos
                int temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }
    }
}

//ordena��o por divis�o e conquista: quick sort
//consiste em separar o vetor em duas metades a partir de um piv�, e ir repetindo recursivamente at� ordenar
/*
Passos:
	1.Divis�o: Escolha um piv� e reorganize os elementos de forma que os menores fiquem 
� esquerda e os maiores � direita.
	2. Conquista: Recursivamente aplique o Quick Sort nas subpartes (esquerda e direita).
	3. Combina��o: N�o � necess�rio combinar, pois o vetor � ordenado no lugar (in-place).
*/

//esse est� particionando do fim
void quick_sort(int *vet, int inicio, int fim) {
    if (inicio < fim) {
        // Particiona o vetor e obt�m o �ndice do piv�
        int pivo = particiona(vet, inicio, fim);

        // Recursivamente aplica o Quick Sort nas subpartes
        quick_sort(vet, inicio, pivo - 1);
        quick_sort(vet, pivo + 1, fim);
    }
}

int particiona(int *vet, int inicio, int fim) {
    int pivo = vet[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (vet[j] <= pivo) {
            i++;
            // Troca elementos
            int temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
        }
    }

    // Coloca o piv� na posi��o correta
    int temp = vet[i + 1];
    vet[i + 1] = vet[fim];
    vet[fim] = temp;

    return i + 1; // Retorna o �ndice do piv�
}

