#include<stdio.h>
#include<stdlib.h>

/*
5. Dado um vetor de números inteiros com n elementos, implemente um programa que encontre os
k menores elementos do vetor e os retorne em ordem crescente.
	1. O programa deve funcionar corretamente independentemente da ordem inicial dos elementos
no vetor.
	2. Utilize um algoritmo de ordenação eficiente e justifique a escolha no seu código.
*/

/*
    Justificativa para a escolha do algoritmo de ordenação:

    O algoritmo de ordenação QuickSort foi escolhido devido à sua eficiência média de O(n log n),
    o que o torna uma excelente escolha para ordenar vetores de tamanho considerável. A principal 
    vantagem do QuickSort é seu desempenho em comparação com outros algoritmos de ordenação simples, 
    como Selection Sort, Bubble Sort e Insertion Sort (algoritmos vistos em aula), que têm complexidade O(n^2) no pior caso.

    - Embora o Selection Sort seja fácil de implementar, ele possui uma complexidade
      de tempo O(n^2), o que o torna ineficiente para grandes conjuntos de dados. Ele também não faz uso de 
      recursos de recursão ou divisão de problemas, como o QuickSort, o que limita sua eficiência em comparação.

    - O Bubble Sort, embora intuitivo, também tem complexidade O(n^2) no pior e no melhor 
      caso (caso de dados já ordenados). Isso faz com que, mesmo em vetores pequenos, ele não seja tão eficiente 
      quanto o QuickSort.

    - O Insertion Sort, embora eficiente para vetores pequenos ou quase ordenados (O(n) no melhor caso),
      possui complexidade O(n^2) no pior caso, o que o torna menos eficiente quando se lida com dados maiores e desordenados.

    Logo, o QuickSort, com sua eficiência média de O(n log n), oferece um bom equilíbrio entre simplicidade e desempenho, 
    tornando-o ideal para ordenar vetores de tamanho considerável, como o caso apresentado neste programa. Seu desempenho 
    superior em comparação com algoritmos quadráticos como o Selection Sort, Bubble Sort e Insertion Sort justifica a escolha.
*/


// Função de partição para o QuickSort
int particiona(int *vet, int inicio, int fim) {
    int meio = (inicio + fim) / 2;
    int pivo = vet[meio];
    int i = inicio, j;

    // Troca o pivô com o último elemento
    int temp = vet[meio];
    vet[meio] = vet[fim];
    vet[fim] = temp;

    for (j = inicio; j < fim; j++) {
        if (vet[j] <= pivo) {
            // Troca os elementos
            temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
            i++;
        }
    }

    // Coloca o pivô na posição correta
    temp = vet[i];
    vet[i] = vet[fim];
    vet[fim] = temp;

    return i;
}

// Função de ordenação QuickSort
void quick_sort(int *vet, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particiona(vet, inicio, fim);
        quick_sort(vet, inicio, pivo - 1);
        quick_sort(vet, pivo + 1, fim);
    }
}

// Função que retorna os k menores elementos em ordem crescente
int *k_primeiros(int *vet_desord, int n, int k) {
    // Ordena o vetor com QuickSort
    quick_sort(vet_desord, 0, n - 1);
    
    // Aloca dinamicamente o vetor para armazenar os k menores
    int *novo_vet = (int *)malloc(k * sizeof(int));
    if (novo_vet == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
	int i;
    // Copia os k menores elementos para o novo vetor
    for (i = 0; i < k; i++) {
        novo_vet[i] = vet_desord[i];
    }

    return novo_vet;
}

int main() {
    int vet[] = {10, 30, 19, 5, 50, 4, 60, 9, 90, 45, 28, 1, 22, 2};
    int n = sizeof(vet) / sizeof(vet[0]);
    int k = 3;

    int *k_menores = k_primeiros(vet, n, k);

    printf("Os %d menores elementos são: ", k);
    int i;
    for (i = 0; i < k; i++) {
        printf("%d ", k_menores[i]);
    }
    printf("\n");

    // Libera a memória alocada dinamicamente
    free(k_menores);

    return 0;
}

