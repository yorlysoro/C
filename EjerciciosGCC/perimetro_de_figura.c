#include <stdio.h>

int main(void)
{
	int lados, total;
	
	printf("Programa que mide el perimetro de una figura de 4 lados iguales\n");
	printf("Cuanto miden los lados del cuadrado?\n");
	scanf("%d", &lados);
	total=lados*4;
	printf("Perimetro: %d", total);
	return 0;
	
}
