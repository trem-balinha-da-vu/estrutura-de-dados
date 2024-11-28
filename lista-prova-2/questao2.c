#include <stdio.h>
#include <stdlib.h>

/*
No caso do quicksort, considere que o piv� � o elemento central e apresente a ordena��o do vetor
A = 2, 5, 32, 21, 102, 1, 11, 24, 35, 44, 56. Informe a quantidade de compara��es e trocas
efetuadas.
*/

int comparacoes = 0;
int trocas = 0;

void quick_sort(int *vet, int inicio, int fim);
int particiona(int *vet, int inicio, int fim);

int particiona(int *vet, int inicio, int fim) {
    int pivo = vet[inicio]; // O piv� � o primeiro elemento
    int i = inicio + 1;
    int j = fim;

    while (i <= j) {
        // Move `i` para a direita enquanto os elementos forem menores ou iguais ao piv�
        while (i <= fim && vet[i] <= pivo) {
        	comparacoes++;
            i++;
        }
        if (i <= fim) comparacoes++; 

        // Move `j` para a esquerda enquanto os elementos forem maiores que o piv�
        while (j >= inicio && vet[j] > pivo) {
        	comparacoes++;
            j--;
        }
        if (j >= inicio) comparacoes++;

        if (i < j) {
            // Troca os elementos em `i` e `j`
            int temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
            trocas++;
        }
    }

    // Troca o piv� com o elemento em `j`, colocando o piv� em sua posi��o correta
    int temp = vet[inicio];
    vet[inicio] = vet[j];
    vet[j] = temp;
    trocas++;

    return j; // Retorna o �ndice do piv�
}

void quick_sort(int *vet, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particiona(vet, inicio, fim);
        quick_sort(vet, inicio, pivo - 1);
        quick_sort(vet, pivo + 1, fim);
    }
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

    // Imprime as quantidades de compara��es e trocas
    printf("Compara��es: %d\n", comparacoes);
    printf("Trocas: %d\n", trocas);

    return 0;
}

