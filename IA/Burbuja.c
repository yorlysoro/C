#include <stdio.h>

int main(void)
{
	int x,y,aux;
	x = y = 0;
	int lista[6] = {4,2,6,5,1,3};
	
	printf("Lista desordenada\n");
	
	for(x = 0; x < 6; x++)
	{
		printf("%d ", lista[x]);
	}
	putchar('\n');
	printf("Lista ordenada\n");
	for(x = 0; x < 6; x++)
	{
		for(y = x + 1; y < 6; y++)
		{
			if(lista[y] < lista[x])
			{
				aux = lista[y];
				lista[y] = lista[x];
				lista[x] = aux;
			}
		}
	}
	
	for(x = 0; x < 6; x++)
	{
		printf("%d ", lista[x]);
	}
	putchar('\n');
	return 0;
}
