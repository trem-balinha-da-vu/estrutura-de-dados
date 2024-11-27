#include <stdio.h>
#include <stdlib.h>

/*
7. Dado um vetor de n�meros inteiros, implemente um programa que ordene o vetor seguindo a
seguinte regra:
1. N�meros pares devem aparecer antes dos n�meros �mpares.

2. Dentro de cada grupo (pares e �mpares), os n�meros devem ser ordenados em ordem cres-
cente.
*/
void bubble_sort(int *vet, int tam) {
    int i, j;
    for (i = 0; i < tam - 1; i++) { // n�mero de passagens
        for (j = 0; j < tam - 1 - i; j++) { // compara��es em cada passagem
            // Troca os elementos adjacentes
            if (vet[j] > vet[j + 1]) {
                int temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }
    }
}

void concatenar_vetores(int *pares, int *impares, int num_pares, int num_impares) {
    int i;
    for (i = 0; i < num_impares; i++) {
        pares[num_pares + i] = impares[i]; // Coloca os �mpares no final de pares
    }
}

void ordenar_pares_impares(int *vet, int n) {
    int i, j = 0;
    int* pares = (int*) malloc(n * sizeof(int)); // Vetor para armazenar pares
    int* impares = (int*) malloc(n * sizeof(int)); // Vetor para armazenar �mpares
    int num_pares = 0, num_impares = 0;

    // Separando os n�meros pares e �mpares
    for (i = 0; i < n; i++) {
        if (vet[i] % 2 == 0) {
            pares[num_pares++] = vet[i]; // Adiciona o n�mero par ao vetor de pares
        } else {
            impares[num_impares++] = vet[i]; // Adiciona o n�mero �mpar ao vetor de �mpares
        }
    }

    // Ordenando os vetores de pares e �mpares
    bubble_sort(pares, num_pares);
    bubble_sort(impares, num_impares);

    // Concatenando os vetores
    concatenar_vetores(pares, impares, num_pares, num_impares);

    // Copiando o vetor concatenado de volta para o vetor original
    for (i = 0; i < num_pares + num_impares; i++) {
        vet[i] = pares[i];
    }

    // Liberando a mem�ria alocada
    free(pares);
    free(impares);
}

int main() {
    int vet[] = {0, 3, 5, 18, 77, 1, 9, 2, 4, 7, 6, 11, 15, 8};

    int tam = sizeof(vet) / sizeof(vet[0]);

	ordenar_pares_impares(vet, tam);

    // Imprime o vetor resultante
    printf("Vetor concatenado (pares seguidos de �mpares):\n");
    int i;
    for (i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;
}

