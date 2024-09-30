#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

char caractere_correspondente(char ch) {
    switch (ch) {
        case ')': return '(';
        case ']': return '[';
        case '}': return '{';
        default: return '\0'; // Retorna '\0' se o caractere não for válido
    }
}

void recebe_entrada(char *vet) {
    fflush(stdin);
    printf("Informe a sequencia de caracteres: \n");
    scanf("%[^\n]", vet);
}

PilhaC *verifica_seq(char *vet, int tam_vet, PilhaC *topo) {
    for (int i = 0; i < tam_vet-1; i++) {
        char ch = vet[i];

        // Se for um caractere de abertura, empilha
        if (ch == '(' || ch == '[' || ch == '{') {
            topo = push_valorC(topo, ch);
        } 
        // Se for um caractere de fechamento, verifica
        else if (ch == ')' || ch == ']' || ch == '}') {
            // Se a pilha está vazia ou o topo não corresponde ao caractere de abertura esperado
            if (topo == NULL || topo->caractere != caractere_correspondente(ch)) {
                return NULL; // Sequência inválida
            }
            // Se corresponder, desempilha
            popC(&topo);
        }
    }

    // Se a pilha estiver vazia no final, a sequência é bem-formada
    return topo; // Se a pilha estiver vazia, significa que todos os pares foram fechados corretamente.
}

int main() {
    PilhaC *pilha = NULL;

    do {
        char vet[100] = "\0";
        recebe_entrada(vet);
        if (strlen(vet) > 0) {
            pilha = verifica_seq(vet, strlen(vet), pilha);
            if (pilha == NULL) {
                printf("\nNao.\n"); // Sequência inválida
            } else {
                printf("\nSim.\n"); // Sequência válida
            }
            // Limpa a pilha após a verificação
            while (pilha != NULL) {
                popC(&pilha);
            }
        } else {
            break; // Termina se a linha estiver vazia
        }
    } while (1);

    return 0;
}
