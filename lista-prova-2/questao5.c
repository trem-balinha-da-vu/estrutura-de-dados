#include<stdio.h>
#include<stdlib.h>

/*
5. Dado um vetor de n�meros inteiros com n elementos, implemente um programa que encontre os
k menores elementos do vetor e os retorne em ordem crescente.
	1. O programa deve funcionar corretamente independentemente da ordem inicial dos elementos
no vetor.
	2. Utilize um algoritmo de ordena��o eficiente e justifique a escolha no seu c�digo.
*/

/*
    Justificativa para a escolha do algoritmo de ordena��o:

    O algoritmo de ordena��o QuickSort foi escolhido devido � sua efici�ncia m�dia de O(n log n),
    o que o torna uma excelente escolha para ordenar vetores de tamanho consider�vel. A principal 
    vantagem do QuickSort � seu desempenho em compara��o com outros algoritmos de ordena��o simples, 
    como Selection Sort, Bubble Sort e Insertion Sort (algoritmos vistos em aula), que t�m complexidade O(n^2) no pior caso.

    - Embora o Selection Sort seja f�cil de implementar, ele possui uma complexidade
      de tempo O(n^2), o que o torna ineficiente para grandes conjuntos de dados. Ele tamb�m n�o faz uso de 
      recursos de recurs�o ou divis�o de problemas, como o QuickSort, o que limita sua efici�ncia em compara��o.

    - O Bubble Sort, embora intuitivo, tamb�m tem complexidade O(n^2) no pior e no melhor 
      caso (caso de dados j� ordenados). Isso faz com que, mesmo em vetores pequenos, ele n�o seja t�o eficiente 
      quanto o QuickSort.

    - O Insertion Sort, embora eficiente para vetores pequenos ou quase ordenados (O(n) no melhor caso),
      possui complexidade O(n^2) no pior caso, o que o torna menos eficiente quando se lida com dados maiores e desordenados.

    Logo, o QuickSort, com sua efici�ncia m�dia de O(n log n), oferece um bom equil�brio entre simplicidade e desempenho, 
    tornando-o ideal para ordenar vetores de tamanho consider�vel, como o caso apresentado neste programa. Seu desempenho 
    superior em compara��o com algoritmos quadr�ticos como o Selection Sort, Bubble Sort e Insertion Sort justifica a escolha.
*/


int particiona(int *vet, int inicio, int fim) {
    int pivo = vet[inicio]; // O piv� � o primeiro elemento
    int i = inicio + 1;
    int j = fim;

    while (i <= j) {
        // Move `i` para a direita enquanto os elementos forem menores ou iguais ao piv�
        while (i <= fim && vet[i] <= pivo) {
            i++;
        }

        // Move `j` para a esquerda enquanto os elementos forem maiores que o piv�
        while (j >= inicio && vet[j] > pivo) {
            j--;
        }

        if (i < j) {
            // Troca os elementos em `i` e `j`
            int temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
        }
    }

    // Troca o piv� com o elemento em `j`, colocando o piv� em sua posi��o correta
    int temp = vet[inicio];
    vet[inicio] = vet[j];
    vet[j] = temp;

    return j; // Retorna o �ndice do piv�
}

void quick_sort(int *vet, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particiona(vet, inicio, fim);
        quick_sort(vet, inicio, pivo - 1);
        quick_sort(vet, pivo + 1, fim);
    }
}


// Fun��o que retorna os k menores elementos em ordem crescente
int *k_primeiros(int *vet_desord, int n, int k) {
    // Ordena o vetor com QuickSort
    quick_sort(vet_desord, 0, n - 1);
    
    // Aloca dinamicamente o vetor para armazenar os k menores
    int *novo_vet = (int *)malloc(k * sizeof(int));
    if (novo_vet == NULL) {
        printf("Erro de aloca��o de mem�ria!\n");
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

    printf("Os %d menores elementos s�o: ", k);
    int i;
    for (i = 0; i < k; i++) {
        printf("%d ", k_menores[i]);
    }
    printf("\n");

    // Libera a mem�ria alocada dinamicamente
    free(k_menores);

    return 0;
}

