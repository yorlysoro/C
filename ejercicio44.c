#include <stdio.h>

int main(void)
{
	int numerador = 12, denominador = 2, producto = 0, cociente = 0, resto = 0;
	
	producto = numerador * denominador;
	cociente = numerador / denominador;
	resto = numerador % denominador;
	
	printf("producto es %d\n"
	"cociente es %d\n"
	"resto es %d\n", producto, cociente, resto);
	return 0;
	
}
