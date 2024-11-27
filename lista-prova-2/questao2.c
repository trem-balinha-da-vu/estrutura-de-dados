#include <stdio.h>
#include <stdlib.h>

/*
No caso do quicksort, considere que o pivô é o elemento central e apresente a ordenação do vetor
A = 2, 5, 32, 21, 102, 1, 11, 24, 35, 44, 56. Informe a quantidade de comparações e trocas
efetuadas.
*/

int comparacoes = 0;
int trocas = 0;

void quick_sort(int *vet, int inicio, int fim);
int particiona(int *vet, int inicio, int fim);

void quick_sort(int *vet, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particiona(vet, inicio, fim);
        quick_sort(vet, inicio, pivo - 1);
        quick_sort(vet, pivo + 1, fim);
    }
}

int particiona(int *vet, int inicio, int fim) {
    int meio = (inicio + fim) / 2;
    int pivo = vet[meio];
    int i = inicio, j;

    // Troca o pivô com o último elemento
    int temp = vet[meio];
    vet[meio] = vet[fim];
    vet[fim] = temp;
    trocas++;  // Contabiliza a troca do pivô com o último elemento

    for (j = inicio; j < fim; j++) {
        comparacoes++;
        if (vet[j] <= pivo) {
            // Troca os elementos
            temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
            i++;
            trocas++;
        }
    }

    // Coloca o pivô na posição correta
    temp = vet[i];
    vet[i] = vet[fim];
    vet[fim] = temp;
    trocas++;  // Contabiliza a troca do pivô para a posição correta

    return i;
}



int main() {
    int vet[] = {2, 5, 32, 21, 102, 1, 11, 24, 35, 44, 56};
    int tam = sizeof(vet) / sizeof(vet[0]);
    int i;

    quick_sort(vet, 0, tam - 1);

    printf("Vetor ordenado: ");
    for (i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");

    // Imprime as quantidades de comparações e trocas
    printf("Comparações: %d\n", comparacoes);
    printf("Trocas: %d\n", trocas);

    return 0;
}

