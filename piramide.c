#include <stdio.h>

int main(void)
{
	int n, fila, col;
	printf("Tamaño de la piramide: ");
	scanf("%d", &n);

	for(fila=1; fila <= n; fila++)
	{
		for(col = 1; col <= n-fila; col++)
		{
			printf(" ");
		}
		for(col = 1; col <= 2 * fila-1; col++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
