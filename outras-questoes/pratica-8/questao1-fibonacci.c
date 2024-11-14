#include <stdio.h>
#include <stdlib.h>

int valida_x(int x)
{
	if(x < 1 || x > 39) return 0;
	return 1;
}

int fibonacci(int x, int *calls)
{
    (*calls)++;
	if (x == 0) return 0;
	if (x == 1) return 1;
	
	return fibonacci(x-1, calls) + fibonacci(x-2, calls);
}


int main()
{
	int n_casos, x, calls;
	
	scanf("%d", &n_casos);
	printf("\n");
	
	int i;
	for(i = 0; i < n_casos; i++)
	{
		calls = -1;
		
		do 
		{
			scanf("%d", &x);
			if(!valida_x(x)) printf("x invalido. \n");	
		}while(!valida_x(x));
		
		int result = fibonacci(x, &calls);
		
		printf("\nfib(%d) = %d", x, result);
		printf("\tcalls = %d\n", calls);
	}
	
	return 0;
}
