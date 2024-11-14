#include "arvore.h"
#include <stdio.h>

int main()
{
	ArvBin *arvore = inicializa();
	
	proc_cria_arvore(&arvore, 50);
	proc_cria_arvore(&arvore, 75);
	proc_cria_arvore(&arvore, 20);
	proc_cria_arvore(&arvore, 80);
	proc_cria_arvore(&arvore, 15);
	proc_cria_arvore(&arvore, 19);
	proc_cria_arvore(&arvore, 23);

	bsf_preOrder(arvore);
	
	//libera_arvore(&arvore);
	
	if (arvore == NULL) 
	{
        printf("\nA arvore foi liberada com sucesso!\n");
    } 
    
    ArvBin * elemento = encontra_subArv(arvore, 20);
    
    printf("\nGrau do noh %d: %d\n", (elemento != NULL) ? elemento->info : -1, conta_graus(elemento));
    //printf("Grau calculado de outra forma: %d\n", grau_arvore(arvore, 2));
    
    ArvBinC *arvoreC = inicializaC();
	cria_no_c(&arvoreC,'A');
	cria_no_c(&arvoreC,'B');
	cria_no_c(&arvoreC,'C');
	cria_no_c(&arvoreC,'D');
	cria_no_c(&arvoreC,'E');
	cria_no_c(&arvoreC,'F');
	cria_no_c(&arvoreC,'G');

    printf("\nPercurso em largura (BFS): ");
    bfs(arvoreC);
    printf("\n");

    return 0;

}
