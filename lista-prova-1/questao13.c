#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

/**
 * A conversão de números inteiros da base decimal para outras bases numéricas é 
 * realizada por meio de sucessivas divisões do valor n pela base desejada. 
 * Desenvolva um programa que execute essa conversão de acordo com a escolha do 
 * usuário, utilizando uma pilha:
 * 		a) Decimal para Binário.
 * 		b) Decimal para Octal.
 * 		c) Decimal para Hexadecimal.
 * */

PilhaC * dec_to_bin(int dec)
{
	PilhaC * pilha = inicializa_pilhaC();

	if (dec == 0)
    {
        pushC(&pilha, '0');
        return pilha; 
    }

	while (dec > 0)
    {
        if (dec % 2 != 0)
        {
            pushC(&pilha, '1');
        }
        else
        {
            pushC(&pilha, '0');
        }

        dec /= 2;
    }

    return pilha;
}

PilhaC * dec_to_oct(int dec)
{
    PilhaC * pilha = inicializa_pilhaC();

    if (dec == 0)
    {
        pushC(&pilha, '0');
        return pilha; 
    }

    while (dec > 0)
    {
        if (dec % 8 != 0)
        {
            pushC(&pilha, '1');
        }
        else
        {
            pushC(&pilha, '0');
        }
        dec /= 8;              
    }

    return pilha; 
}

PilhaC * dec_to_hex(int dec)
{
    PilhaC * pilha = inicializa_pilhaC();

    if (dec == 0)
    {
        pushC(&pilha, '0');
        return pilha; 
    }

    while (dec > 0)
    {
        int resto = dec % 16;

        if (resto < 10)
        {
            if (dec % 16 != 0)
        	{
            	pushC(&pilha, '1');
        	}
        	else
        	{
            	pushC(&pilha, '0');
        	}  
        }
        else
        {
            pushC(&pilha, resto + 'A' - 10); // Para valores de A a F
        }

        dec /= 16;
    }

    return pilha; 
}

int main(int argc, char const *argv[])
{
	int opt;
	int dec;
	PilhaC * pilha_convertida;

	do
	{
		printf("\nInforme a conversao desejada:\n\t 1 - dec para binario\n\t 2 - dec para octal\n\t 3 - dec para hexadecimal\n\t 0 - sair\n");
		scanf("%d", &opt);

		if(opt == 0) break;

		switch (opt) {
		    case 1:
		        {
		        	printf("Informe o numero decimal: \n");
		        	scanf("%d", &dec);
		        	pilha_convertida = dec_to_bin(dec);
		        }
		        break;
		    case 2:
		        {
					printf("Informe o numero decimal: \n");
		        	scanf("%d", &dec);
		        	pilha_convertida = dec_to_oct(dec);		        	
		        }
		        break;
		    case 3:
		        {
					printf("Informe o numero decimal: \n");
		        	scanf("%d", &dec);
		        	pilha_convertida = dec_to_hex(dec);		        	
		        }
		        break;
		    default:
			    printf("Opcao invalida.\n");
		        break;
		}

		print_stackC(pilha_convertida);
		
	}while(1);


	return 0;
}