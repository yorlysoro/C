#include <stdio.h>

int main(void)
{
	int resto, cociente, producto, x, y;
	
	puts("Introduzca dos numeros");
	scanf("%d %d", &x, &y);
	
	producto = x * y;
	cociente = x / y;
	resto = x % y;
	
	printf("Producto = %d\n"
	"Cociente = %d\n"
	"Resto = %d\n", producto, cociente, resto);
	return 0;
}
