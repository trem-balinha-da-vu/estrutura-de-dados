#include <stdio.h>

/*
6. Dado um vetor de números inteiros ordenado em ordem crescente, escreva um programa para
identificar todos os elementos dentro de um intervalo [a, b].
	1. O programa deve retornar os elementos encontrados em ordem crescente.
	2. Caso nenhum elemento esteja dentro do intervalo, retorne "Sem elementos no intervalo".
*/

//dúvida: retornar seria retornar o sub-vetor com o intervalo, ou printar os valores?

int busca_binaria_intervalo(int *vet, int n, int x) {
    int inicio = 0, fim = n - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        
        if (vet[meio] == x) {
            return meio; // Achou o número exato
        } else if (vet[meio] < x) {
            inicio = meio + 1; // Procurar à direita
        } else {
            fim = meio - 1; // Procurar à esquerda
        }
    }
    
    return inicio; // Retorna o índice onde o número mais próximo de x pode estar
}

void identifica_intervalo_print(int *vet, int n, int a, int b) {
    int indice_a = busca_binaria_intervalo(vet, n, a);
    int indice_b = busca_binaria_intervalo(vet, n, b);
    
    if (indice_a >= n || vet[indice_a] > b) {
        printf("Sem elementos no intervalo\n");
        return;
    }

    // Ajustar o limite de b para garantir que o índice não ultrapasse o fim do vetor
    if (indice_b >= n || vet[indice_b] > b) {
        indice_b = n - 1;
    }

    // Imprimir os elementos dentro do intervalo [a, b]
    int i;
    for (i = indice_a; i <= indice_b; i++) {
        if (vet[i] >= a && vet[i] <= b) {
            printf("%d ", vet[i]);
        }
    }
    printf("\n");
}

void busca_sequencial_intervalo(int *vet, int tam, int a, int b) {
    int i;
    int encontrou = 0;

    for (i = 0; i < tam; i++) {
        if (vet[i] >= a && vet[i] <= b) {
            printf("%d ", vet[i]);
            encontrou = 1;
        } else if (vet[i] > b) {
            // Como o vetor está ordenado, podemos interromper a busca ao passar do limite superior
            break;
        }
    }

    if (!encontrou) {
        printf("Sem elementos no intervalo");
    }
    printf("\n");
}

int main() {
    int vet[] = {1, 3, 5, 8, 10, 11, 14};
    int n = sizeof(vet) / sizeof(vet[0]);
    int a = 5, b = 12;

    busca_sequencial_intervalo(vet, n, a, b);

    return 0;
}

