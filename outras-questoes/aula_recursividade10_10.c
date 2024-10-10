#include <stdio.h>
#include <stdlib.h>

int somatorio_aux(int n, int soma)
{
	if(n == 1) return soma;
	
	return somatorio_aux(n-1, soma+n);
}

int somatorio(int n)
{
	return somatorio_aux(n, 1);
}

int somatorio2(int n)
{
	if(n == 1) return 1;
	
	return n + somatorio2(n-1);
}

long long int fatorial(long long int n)
{
	if(n == 0 || n == 1) return 1;
	
	return fatorial(n-1) *n;
}

int multiplica_aux(int a, int b, int acumulador)
{
    if(b == 0) return acumulador;
    
    return multiplica_aux(a, b - 1, acumulador + a);
}

int multiplica_neg(int a, int b)
{
    if(b < 0) return multiplica_aux(-a, -b, 0);
    
    return multiplica_aux(a, b, 0);
}

int multiplica (int a, int b)
{
	if(a == 0 || b == 0) return 0;
	if (a == 1) b;
	if(b == 1) a;
	
	return a + multiplica(a, b - 1);
}

int main(){
	
	//recursao na cauda
	printf("%d", fatorial(5));
	
	//recursao normal 
	printf("\n%d", multiplica_neg(15, -12));
	
	
	return 0;
}
