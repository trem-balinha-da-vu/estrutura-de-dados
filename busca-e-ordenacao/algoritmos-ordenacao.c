#include <stdio.h>

//----------------------------------------------------------------------
// METODOS DE ORDENAÇAO

//tipos de metodos: por inserção, troca, seleção e divisão e conquista

//ordenação por seleção: selection sort
//consiste em ir ordenando do menor pro maior. acha o menor, coloca ele na posição correta e tira ele de vista.
/*
Passos:
	1. Percorra o vetor do início ao fim.
	2. Para cada posição i:
		+ Encontre o menor elemento na parte não ordenada (índices de i até o final).
		+ Troque esse menor elemento com o elemento na posição i.
	3. Repita até que todo o vetor esteja ordenado.
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
		
		// troca o novo menor elemento com o elemento da posição i
		int temp = vet[menor_indice];
		vet[menor_indice] = vet[i];
		vet[i] = temp;
	}
}

//ordenação por inserção: insertion sort
//consiste em inserir os elementos da parte não-ordenada do vetor, na posição correta da parte ordenada
/*
Passos: 
	1. Imagine que o vetor tem uma parte ordenada e uma parte não ordenada.
	2. Comece com a parte ordenada contendo apenas o primeiro elemento.
	3. Pegue o próximo elemento da parte não ordenada, compare-o com os elementos da parte ordenada e 
insira-o na posição correta.
	4. Repita até que todos os elementos estejam na parte ordenada.
*/

void insertion_sort(int *vet, int tam)
{
	int i, j, chave;

    for (i = 1; i < tam; i++) {  // Itera do segundo elemento até o último
        chave = vet[i];          // Seleciona o elemento a ser inserido
        j = i - 1;               // Começa a comparação com o elemento anterior

        // Move os elementos maiores que a chave para frente
        while (j >= 0 && vet[j] > chave) {
            vet[j + 1] = vet[j]; // Move o elemento maior uma posição à frente
            j--;                 // Continua a verificar os elementos anteriores
        }
        vet[j + 1] = chave;      // Insere a chave na posição correta
    }
}


//ordenação por troca: bubble sort
// o maior elemento "flutua" para a posição final a cada interação. ordena do maior para o menor
/*
Passos: 
	Compare pares de elementos adjacentes.
Se o elemento à esquerda for maior que o da direita, troque-os.
Após cada passagem pelo vetor, o maior elemento "borbulha" para sua posição correta no final.
Repita o processo para os elementos restantes até que o vetor esteja ordenado.
*/
void bubble_sort(int *vet, int tam) {
    int i, j;

    for (i = 0; i < tam - 1; i++) { // Número de passagens
        for (j = 0; j < tam - 1 - i; j++) { // Comparações em cada passagem
            if (vet[j] > vet[j + 1]) { // Verifica se é necessário trocar
                // Troca os elementos
                int temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }
    }
}

//ordenação por divisão e conquista: quick sort
//consiste em separar o vetor em duas metades a partir de um pivô, e ir repetindo recursivamente até ordenar
/*
Passos:
	1.Divisão: Escolha um pivô e reorganize os elementos de forma que os menores fiquem 
à esquerda e os maiores à direita.
	2. Conquista: Recursivamente aplique o Quick Sort nas subpartes (esquerda e direita).
	3. Combinação: Não é necessário combinar, pois o vetor é ordenado no lugar (in-place).
*/

//esse está particionando do fim
void quick_sort(int *vet, int inicio, int fim) {
    if (inicio < fim) {
        // Particiona o vetor e obtém o índice do pivô
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

    // Coloca o pivô na posição correta
    int temp = vet[i + 1];
    vet[i + 1] = vet[fim];
    vet[fim] = temp;

    return i + 1; // Retorna o índice do pivô
}

