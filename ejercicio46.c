#include <stdio.h>

int main(void)
{
	signed int x = 0;
	
	puts("Introduce un numero");
	scanf("%d", &x);
	x == -x ? puts("El numero es negativo") : puts("El numero es positivo");
	x == 0 ? puts("El numero es cero") : puts("El numero es diferente de 0");
	return 0;
}
