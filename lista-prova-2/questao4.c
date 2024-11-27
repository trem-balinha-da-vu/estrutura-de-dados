#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Para fabs()

/*
Dado um vetor de n�meros inteiros ordenado em ordem crescente, implemente uma fun��o que,
utilizando o algoritmo de busca bin�ria, identifique dois elementos consecutivos no vetor cuja
soma seja a mais pr�xima poss�vel de um n�mero inteiro x.
1. A fun��o deve retornar os dois elementos encontrados.
2. Se houver mais de um par com a mesma proximidade, retorne o primeiro par encontrado.
*/

int busca_binaria_consecutivos(int *vet, int n, int x) {
    int inicio = 0, fim = n - 2; // �ltimo par come�a no �ndice n-2
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int soma = vet[meio] + vet[meio + 1];

        if (soma == x) {
            return meio; // Achou a soma exata
        } else if (soma < x) {
            inicio = meio + 1; // Procurar � direita
        } else {
            fim = meio - 1; // Procurar � esquerda
        }
    }

    // Retorna o �ndice mais pr�ximo
    return inicio < n - 1 ? inicio : n - 2;
}

void encontra_consecutivos_bin(int *vet, int n, int x, int *resultado) {
    int indice = busca_binaria_consecutivos(vet, n, x);
    int menor_diferenca = abs(vet[indice] + vet[indice + 1] - x);

    resultado[0] = vet[indice];
    resultado[1] = vet[indice + 1];

    // Verificar se o pr�ximo par consecutivo tem soma mais pr�xima
    if (indice + 1 < n - 1) {
        int soma = vet[indice + 1] + vet[indice + 2];
        int diferenca = abs(soma - x);

        if (diferenca < menor_diferenca) {
            resultado[0] = vet[indice + 1];
            resultado[1] = vet[indice + 2];
        }
    }
}

int main() {
    int vet[] = {1, 3, 5, 8, 10, 12, 14};
    int n = sizeof(vet) / sizeof(vet[0]);
    int x = 7;
    int resultado[2];

    encontra_consecutivos_bin(vet, n, x, resultado);

    printf("Os dois elementos consecutivos cuja soma eh mais proxima de %d sao: %d e %d\n",
           x, resultado[0], resultado[1]);

    return 0;
}

