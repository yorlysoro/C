#include <stdio.h>

int main(void)
{
	int i = 0, j = 0, resultado = 0;
	j = 2;
	puts("Introduce un numero:");
	scanf("%i ", &i);
	resultado = i * j;
	printf("%i * %i = %i\n", i, j, resultado);
	return 0;
}
